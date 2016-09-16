(in-package :amber.pdb)

(defparameter *pdb-res-map* (make-hash-table :test #'equal)
  "Map (residue name . terminus) from pdb files to form names")

(defun lookup-pdb-res-map (name terminalflag)
  (gethash (cons name terminalflag) *pdb-res-map*))

(defun add-pdb-res-map (mappings)
  "* Arguments
- mappings :: A list of two or three element lists.
* Description
The Name Map is used to map residue names read from PDB files to variable
names within LEaP.  The LIST is a LIST of LISTs:
      { {sublist} {sublist} ... }
Each sublist contains two or three entries to add to the Name Map:
      { [terminalflag] PDBName LEaPVar }
where the PDBName will be mapped to the LEaPVar. The terminalflag indicates
the special cases of terminal residues: allowable values are 0 or :head for beginning
residues (N-terminal for proteins, 5' for nucleic acids) and 1 or :tail for ending
residues (C-terminal for proteins, 3' for nucleic acids).  If the
terminalflag is given, the PDBName->LEaPVar name map will only be applied
for the appropriate terminal residue.  The `leaprc' file included with
the distribution contains default mappings."
  (unless (core:proper-list-p mappings)
    (error "You must provide a list of lists of mappings"))
  (labels ((ensure-symbol (name)
             (if (symbolp name) name (intern name :keyword)))
           (do-add-map (res-name term-sym var-name)
             (let* ((res-sym (ensure-symbol res-name))
                    (var-sym (ensure-symbol var-name))
                    (key (cons res-sym term-sym))
                    (var-old (gethash key *pdb-res-map*)))
               (when (and var-old (not (eq var-old var-sym)))
                 (warn "The PDB residue name/terminalflag ~a/~a was changed to ~a from ~a"
                       res-sym term-sym var-sym var-old))
               (setf (gethash key *pdb-res-map*) var-sym))))
    (dolist (mapping mappings)
      (cond
        ((= (length mapping) 3)
         (destructuring-bind (terminus res-name var-name)
             mapping
           (let ((term-sym (case terminus
                             (0 :head)
                             (1 :tail)
                             (:head :head)
                             (:tail :tail)
                             (otherwise (error "Illegal terminalflag ~a" terminus)))))
             (do-add-map res-name term-sym var-name))))
        ((= (length mapping) 2)
         (destructuring-bind (res-name var-name)
             mapping
           (do-add-map res-name :main var-name)))
        (t (error "Illegal argument ~a" mapping))))))
                                             
(defparameter *pdb-atom-map* (make-hash-table :test #'eq)
  "Old PDB files may contain atom names that have been renamed in the common convention.
For instance old DNA ribose rings were named C1*, C2*, C3*, C4* etc.
The PDB renamed them to C1', C2', C3', C4' respectively.
This hash table maps old names to new names.
There can only be one mapping from an old name and if a name is
ever replaced then a warning is generated.")

(defun add-pdb-atom-map (name-list)
  "* Arguments
- name-list :: A list of two element lists.
* Description
The atom Name Map is used to try to map atom names read from PDB files
to atoms within residues when the atom name in the PDB file does
not match a atom in the residue.  This enables PDB files to be read
in without extensive editing of atom names.  The LIST is a LIST of LISTs:
      { {sublist} {sublist} ... }
where each sublist is of the form
      { \"OddAtomName\" \"LibAtomName\" }
Many `odd' atom names can map to one `standard' atom name, but any single
odd atom name maps only to the last standard atom name it was mapped to."
  (unless (core:proper-list-p name-list)
    (error "You must provide a list of lists of names"))
  (dolist (old-new name-list)
    (destructuring-bind (old-name new-name)
        old-new
      (unless (and (= (length old-new) 2) old-name new-name)
        (error "Illegal argument - you must provide (\"old-name\" \"new-name\") pairs - you gave: ~a" old-new))
      (flet ((ensure-symbol (name)
               (if (symbolp name) name (intern name :keyword))))
        (let* ((old-sym (ensure-symbol old-name))
               (new-sym (ensure-symbol new-name))
               (old-map (gethash old-sym *pdb-atom-map*)))
          (when (and old-map (not (eq old-map new-sym)))
            (warn "The PDB atom name ~a was mapped to ~a and is now being mapped to ~a"
                  old-sym old-map new-sym))
          (setf (gethash old-sym *pdb-atom-map*) new-sym))))))

(defstruct pdb-id name context)
           
(defclass pdb-residue ()
  ((chain-id :initarg :chain-id :accessor chain-id)
   (res-seq :initarg :res-seq :accessor res-seq)
   (topology :initform nil :accessor topology)
   (name :initarg :name :accessor name)
   (context :initform nil :initarg :context :accessor context)
   (atom-serial-first :initform nil :initarg :atom-serial-first :accessor atom-serial-first)
   (atom-serial-last :initform nil :accessor atom-serial-last))
  (:documentation
     "Keep track of residue and context (:head :main :tail)"))

  
(defmethod print-object ((obj pdb-residue) stream)
  (print-unreadable-object (obj stream :type t)
    (format stream "~a" (name obj))))

(defclass disulphide ()
  ((chain-id1 :initarg :chain-id1 :reader chain-id1)
   (res-seq1 :initarg :res-seq1 :reader res-seq1)
   (chain-id2 :initarg :chain-id2 :reader chain-id2)
   (res-seq2 :initarg :res-seq2 :reader res-seq2)))

(defclass connect ()
  ((from :initarg :from :reader from)
   (to :initarg :to :reader to)))


(defun find-pdb-residue (layout res-seq chain-id)
  (block found
    (loop for seq in (sequences layout)
       do (loop for res in seq
             when (and (= res-seq (res-seq res))
                       (eq chain-id (chain-id res)))
             do (return-from found res)))))

(defclass pdb-reader ()
  ((stream :initarg :stream :reader stream)
   (current-residue-number :initform nil :initarg :current-residue-number :accessor current-residue-number)
   ))


(defclass layout ()
  ((sequences :initform nil :accessor sequences)
   (matrices :initform nil  :accessor matrices)
   (disulphides :initform nil :initarg :disulphides :accessor disulphides)
   (unknown-residues :initform (make-hash-table :test #'equal) :accessor unknown-residues)
   (connects :initform nil :accessor connects)))

(defun layout-unknown-residue-key (res)
  (cons (name res) (context res)))

(defclass pdb-scanner (pdb-reader)
  ((previous-atom-serial :initform nil :accessor previous-atom-serial)
   (previous-residue :initform nil :accessor previous-residue)
   (current-reverse-sequence :initform nil :accessor current-reverse-sequence
                             :documentation "Accumulate the current sequence in reverse order")
   (reversed-sequences :initform nil :accessor reversed-sequences
                       :documentation "A list of sequences (proper order) in pushed in reverse order")
   (layout :initarg :layout :reader layout))
  (:documentation " Keep track of sequence and matrix info while scanning a PDB file"))

(defclass pdb-atom-reader (pdb-reader)
  ((sequences :initarg :sequences :accessor sequences)
   (previous-residue :initarg :previous-residue :accessor previous-residue)
   (previous-topology :initarg :previous-topology :accessor previous-topology)
   (aggregate :initform (chem:make-aggregate) :reader aggregate)
   (molecule :initform nil :initarg :molecule :accessor molecule)
   (current-residue :initform nil :initarg :current-residue :accessor current-residue)
   (current-topology :initform nil :initarg :current-topology :accessor current-topology)
   (connect-atoms :initarg :connect-atoms :reader connect-atoms)
   (serial-to-atom :initarg :serial-to-atom :reader serial-to-atom)
   ))

(defun new-residue-p (residue-number pdb-atom-reader)
  (not (eq residue-number (current-residue-number pdb-atom-reader))))
  
(defun parse-line (line pdb-atom-reader)
  (flet ((read-one-char (line start)
           (let ((s (subseq line start (1+ start))))
             (when (not (string= s " "))
               (read-from-string s)))))
    (let* ((*package* (find-package :keyword))
           (head (read-from-string line)))
      (case head
        ((:mtrix1 :mtrix2 :mtrix3)
         (list head
               (read-from-string line t nil :start 7 :end 10)
               (read-from-string line t nil :start 10 :end 20)
               (read-from-string line t nil :start 20 :end 30)
               (read-from-string line t nil :start 30 :end 40)
               (read-from-string line t nil :start 45 :end 55)
               (read-from-string line t nil :start 59 :end 60)))
        (:atom
         (list :atom
               (read-from-string line t nil :start 6 :end 11)
               (let ((*readtable* (copy-readtable)))
                 (set-syntax-from-char #\' #\A)
                 (read-from-string line t nil :start 12 :end 16))
               (read-from-string line t nil :start 17 :end 20)
               (read-one-char line 21)                       ; chainid
               (read-from-string line t nil :start 22 :end 26) ; res-seq
               (read-one-char line 26)                       ; chainid
               (read-from-string line t nil :start 30 :end 38) ; x
               (read-from-string line t nil :start 38 :end 46) ; y
               (read-from-string line t nil :start 46 :end 54))) ; z
        (:conect
         (list* :conect
                (read-from-string line t nil :start 6 :end 11)
                (with-input-from-string (sin (subseq line 12))
                  (loop for serial = (read sin nil :eof)
                     until (eq serial :eof)
                       collect serial))))
        (:ssbond
         (list :ssbond
               (read-one-char line 15)
               (read-from-string line t nil :start 17 :end 21)
               (read-one-char line 29)
               (read-from-string line t nil :start 31 :end 35)))
        (:ter (list :ter))
        (:anisou nil)
        (t nil)))))

(defun pop-sequence-pdb-residue (pdb-atom-reader &optional (errorp t) error-val)
  "* Arguments
- pdb-atom-reader :: A pdb-reader
- errorp :: bool
- errorp :: T
* Description
Pop and return the next residue in the sequence.
If we run out of residues and errorp is NIL then return error-val
otherwise signal an error."
  (let ((sequence (car (sequences pdb-atom-reader))))
    (unless (car (sequences pdb-atom-reader))
      (pop (sequences pdb-atom-reader)))
    (unless (car (sequences pdb-atom-reader))
      (if errorp
          (error "Ran out of sequence information")
          (return-from pop-sequence-pdb-residue error-val)))
    (pop (car (sequences pdb-atom-reader)))))

(defun finish-previous-sequence (pdb &optional (assign-tail t))
  "* Arguments
- pdb :: a pdb-scanner
- assign-tail :: bool
* Description
Finish off the current sequence and prepare to start another.
If assign-tail is NIL then don't assign the last read residue as
a tail - this is used when partial sequences are loaded to avoid
treating :main residues as :tail residues when that wont make sense and
create more problems."
  (when (current-reverse-sequence pdb)
    (when assign-tail
      (let ((tail-residue (car (current-reverse-sequence pdb))))
        (setf (context tail-residue) :tail)
        (try-to-assign-form tail-residue (layout pdb))))
    (push (nreverse (current-reverse-sequence pdb)) (reversed-sequences pdb))
    (setf (current-reverse-sequence pdb) nil)))

(defun try-to-assign-form (res layout)
  (let* ((form (or (amber:lookup-variable (lookup-pdb-res-map (name res) (context res)) nil nil)
                   (amber:lookup-variable (name res) nil nil))))
    (if form
        (setf (topology res) form)
        (let ((key (layout-unknown-residue-key res)))
          (unless (gethash key (unknown-residues layout))
            (warn "Could not identify form for ~a" key)
            (setf (gethash key (unknown-residues layout)) t))))))
        
(defun pdb-scanner-read-line (pdb eof-errorp eof)
  "* Arguments
- pdb : A pdb-scanner
* Description
Scan through the PDB file and build a high level description
of the contents that will be used later to read the PDB file.
The records that are read from the PDB file are:
ATOM - used to build a list of residues and whether they are :first :main :last.
TER  - Used to identify the ends of chains.
MTRIX- Used to build a list of matrices."
  (let* ((line (read-line (stream pdb) eof-errorp eof))
         (layout (layout pdb)))
    (unless (eq line eof)
      (let ((line-data (parse-line line pdb)))
        (when line-data
          (case (car line-data)
            (:atom
             (destructuring-bind (head atom-serial atom-name residue-name chain-id res-seq i-code x y z)
                 line-data
               (declare (ignore i-code))
               ;; Deal with the current line of data
               (when (new-residue-p res-seq pdb)
                 (setf (current-residue-number pdb) res-seq)
                 (let* ((context-guess (if (null (current-reverse-sequence pdb))
                                          :head
                                          :main))
                        (new-residue (make-instance 'pdb-residue
                                                    :chain-id chain-id
                                                    :res-seq res-seq
                                                    :name residue-name
                                                    :context context-guess
                                                    :atom-serial-first atom-serial)))
                   (try-to-assign-form new-residue (layout pdb))
                   (when (previous-residue pdb)
                     (setf (atom-serial-last (previous-residue pdb)) (previous-atom-serial pdb)))
                   (push new-residue (current-reverse-sequence pdb))
                   ;; Set things up for the next new residue
                   (setf (previous-residue pdb) new-residue)))
               ;; Now set things up for the next atom record
               (setf (previous-atom-serial pdb) atom-serial)))
            (:ter
             (finish-previous-sequence pdb))
            (:ssbond
             (destructuring-bind (head chain-id1 res-seq1 chain-id2 res-seq2)
                 line-data
               (push (make-instance 'disulphide
                                    :chain-id1 chain-id1
                                    :res-seq1 res-seq1
                                    :chain-id2 chain-id2
                                    :res-seq2 res-seq2) (disulphides layout))))
            (:conect
             (destructuring-bind (head from &rest to)
                 line-data
                 (push (make-instance 'connect
                                      :from from
                                      :to to)
                       (connects layout))))
            (:mtrix1
             (destructuring-bind (head serial x y z t)
                 line-data
               (let ((matrix (geom:make-matrix-identity)))
                 (geom:at-row-col-put matrix 0 0 x)
                 (geom:at-row-col-put matrix 0 1 y)
                 (geom:at-row-col-put matrix 0 2 z)
                 (geom:at-row-col-put matrix 0 3 t)
                 (push matrix (matrices layout)))))
            (:mtrix2
             (destructuring-bind (head serial x y z t)
                 line-data
               (let ((matrix (car (matrices layout))))
                 (geom:at-row-col-put matrix 1 0 x)
                 (geom:at-row-col-put matrix 1 1 y)
                 (geom:at-row-col-put matrix 1 2 z)
                 (geom:at-row-col-put matrix 1 3 t))))
            (:mtrix3
             (destructuring-bind (head serial x y z t)
                 line-data
               (let ((matrix (car (matrices layout))))
                 (geom:at-row-col-put matrix 2 0 x)
                 (geom:at-row-col-put matrix 2 1 y)
                 (geom:at-row-col-put matrix 2 2 z)
                 (geom:at-row-col-put matrix 2 3 t))))
            (otherwise nil)))))
    line))
  
(defun scanpdb (filename &key progress)
  "* Arguments
- filename : A pathname
* Description
Scan the PDB file and use the ATOM records to build a list of residue sequences and matrices.
* Return
values residue-sequences matrices"
  (with-open-file (fin filename :direction :input)
    (let ((pdb-scanner (make-instance 'pdb-scanner
                                      :stream fin
                                      :layout (make-instance 'layout)))
          (bar (cando:make-progress-bar :message "Scanned" :total (file-length fin) :divisions 100 :on progress)))
      (restart-case
          (progn
            (loop for x = (pdb-scanner-read-line pdb-scanner nil :eof)
               for skip from 0
               do (when (= (mod skip 1024) 0) (cando:progress-advance bar (file-position fin)))
               until (eq x :eof))
            (finish-previous-sequence pdb-scanner)
            (cando:progress-done bar))
        (read-partial-sequence ()
          :report "Construct a partial structure"
          ;; Drop the current residue and proceed
          (format t "Terminating sequence read")
          (when (current-reverse-sequence pdb-scanner)
            (pop (current-reverse-sequence pdb-scanner)))
          (finish-previous-sequence pdb-scanner nil)))
      (let* ((sequences (nreverse (reversed-sequences pdb-scanner)))
             (layout (layout pdb-scanner)))
        (setf (sequences layout) sequences)
        (finish-layout layout)
        layout))))

(defun warn-of-unknown-topology (res layout)
  (let* ((name (name res))
         (context (context res))
         (key (cons name context)))
    (unless (gethash key (unknown-residues layout))
      (setf (gethash key (unknown-residues layout)) t)
      (warn "No topology was found for ~a~%" key))))

(defun finish-layout (layout)
  ;; Reverse the matrices
  (setf (matrices layout) (nreverse (matrices layout)))
  ;; Form the disulfide bonds
  (mapc (lambda (dis)
          (let ((res1 (find-pdb-residue layout (res-seq1 dis)
                                        (chain-id1 dis)))
                (res2 (find-pdb-residue layout (res-seq2 dis)
                                        (chain-id2 dis))))
            (setf (topology res1) (amber:lookup-pdb-topology :CYX (context res1))
                  (topology res2) (amber:lookup-pdb-topology :CYX (context res2)))))
        (disulphides layout))
  layout)


(defun read-and-process-line (reader eof-errorp eof)
  "* Arguments
- reader : pdb-atom-reader
- eof-errorp : boolean
- eof : T
* Description 
Read the next line from the PDB file and process it, 
filling in the information in the pdb-atom-reader." 
  (let* ((line (read-line (stream reader) eof-errorp eof)))
    (unless (eq line eof)
      (let ((line-data (parse-line line reader)))
        (when line-data
          (case (car line-data)
            (:atom
             (destructuring-bind (head atom-serial atom-name residue-name chain-id res-seq i-code x y z)
                 line-data
               (when (null (molecule reader))
                 (setf (molecule reader) (chem:make-molecule nil))
                 (chem:add-matter (aggregate reader) (molecule reader)))
               (when (new-residue-p res-seq reader)
                 (setf (current-residue-number reader) res-seq)
                 (let ((pdb-residue (pop-sequence-pdb-residue reader nil nil)))
                   (unless pdb-residue
                     (invoke-restart 'ran-out-of-sequence))
                   (setf (previous-topology reader) (current-topology reader)
                         (previous-residue reader) (current-residue reader)
                         (current-topology reader) (topology pdb-residue))
                   (unless (eq (name pdb-residue) residue-name)
                     (error "There is a mismatch between the pdb-residue ~a and the expected residue ~a for ~a"
                            pdb-residue residue-name line-data))
                   (let ((prev-top (previous-topology reader))
                         (cur-top (current-topology reader)))
                     (if cur-top
                         ;; There is a topology - use it
                         (let ((cur-res (chem:build-residue cur-top)))
                           (setf (current-residue reader) cur-res)
                           (let ((prev-res (previous-residue reader)))
                             (chem:add-matter (molecule reader) cur-res)
                             (when prev-res
                               (chem:connect-residues prev-top
                                                      prev-res
                                                      :+default
                                                      cur-top
                                                      cur-res
                                                      :-default))))
                         ;; There is no topology, create an empty residue
                         (let ((cur-res (chem:make-residue residue-name)))
                           (setf (current-residue reader) cur-res)
                           (chem:add-matter (molecule reader) cur-res) cur-res)))))
               (let ((atom (or (chem:content-with-name-or-nil (current-residue reader) atom-name)
                               (chem:content-with-name-or-nil (current-residue reader) (gethash atom-name *pdb-atom-map*)))))
                 (cond
                   (atom    ; there is an atom - fill it
                    ;; If there is a serial-to-atom hash-table
                    ;; then update it
                    (when (serial-to-atom reader)
                      (let ((in-connect (gethash atom-serial (serial-to-atom reader))))
                        (when in-connect
                          (setf (gethash atom-serial (serial-to-atom reader)) atom))))
                    (chem:set-position atom (geom:vec x y z))
                    (chem:setf-needs-build atom nil))
                   ((current-topology reader) ; there is a topology
                    (warn "Amber form ~a does not contain atom ~a" (current-residue reader) atom-name))
                   (t                  ; Add a new atom to the residue
                    (let ((atom (chem:make-atom atom-name (chem:element-from-atom-name-string (string atom-name)))))
                      (chem:add-matter (current-residue reader) atom)
                      (chem:set-position atom (geom:vec x y z))
                      (chem:setf-needs-build atom nil)))))))
            (:ter (setf (molecule reader) nil
                        (current-residue reader) nil
                        (current-topology reader) nil))
            (otherwise nil))))
      line)))

(defun connect-atoms-hash-table (layout)
  (when (connects layout)
    (let ((ht (make-hash-table :test #'eql)))
      (loop for connect in (connects layout)
         do (setf (gethash (from connect) ht) :from)
         do (mapc (lambda (to) (setf (gethash to ht) :to))
                  (to connect)))
      ht)))
(defparameter *serial-to-atoms* nil)
(defun loadpdb (filename &key layout progress)
  (with-open-file (fin filename :direction :input)
    (let* ((layout (or layout (scanpdb filename :progress progress)))
           (serial-to-atoms (connect-atoms-hash-table layout)))
      (setq *serial-to-atoms* serial-to-atoms)
      (let ((pdb-atom-reader (make-instance 'pdb-atom-reader :stream fin
                                            :sequences (mapcar (lambda (seq)
                                                                 (copy-list seq))
                                                               (sequences layout))
                                            :connect-atoms (connects layout)
                                            :serial-to-atom serial-to-atoms)))
        (let ((bar (cando:make-progress-bar :message "Load pdb" :total (file-length fin) :divisions 100 :on progress)))
          (restart-case
              (loop for x = (read-and-process-line pdb-atom-reader nil :eof)
                 for skip from 0
                 do (when (= (mod skip 1024) 0) (cando:progress-advance bar (file-position fin)))
                 until (eq x :eof))
            (ran-out-of-sequence ()
              :report "Ran out of sequence while filling residues"
              (format t "Continuing with partial sequence~%"))))
        (loop for connect in (connects layout)
           for from-atom = (gethash (from connect) serial-to-atoms)
           for to-atoms = (mapcar (lambda (c) (gethash c serial-to-atoms)) (to connect))
           do (mapc (lambda (to-atom)
                      (when (and (typep from-atom 'chem:atom)
                                 (typep to-atom 'chem:atom)
                                 (not (chem:is-bonded-to from-atom to-atom)))
                        (chem:bond-to from-atom to-atom :single-bond)) to-atoms)
                    to-atoms))
        (let ((aggregate (aggregate pdb-atom-reader)))
          (cando:build-unbuilt-hydrogens aggregate)
          aggregate)))))


      

#|
(defun read-line (pdb-atom-reader)
  
(defun read-atom (pdb-atom-reader)
  (

(get-macro-character #\A)
(let ((*readtable* (copy-readtable)))
  (set-syntax-from-char #\' #\A)
  (read-from-string "AB'C"))

(read-from-string "A'1")
(defun parse-atom (line)
  (
|#
