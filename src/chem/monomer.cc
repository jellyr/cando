/*
    File: monomer.cc
*/
/*
Open Source License
Copyright (c) 2016, Christian E. Schafmeister
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 
This is an open source license for the CANDO software from Temple University, but it is not the only one. Contact Temple University at mailto:techtransfer@temple.edu if you would like a different license.
*/
/* -^- */

#define	DEBUG_LEVEL_FULL
//
// (C) 2004 Christian E. Schafmeister
//


//#include	<iostream>
#include <iterator>
#include <vector>
#include <set>
#include <stdio.h>
#include <clasp/core/common.h>
#include <cando/adapt/stringSet.h>
#include <cando/adapt/adapters.h>
#include <clasp/core/holder.h>
#include <clasp/core/environment.h>
#include <cando/chem/monomer.h>
#include <cando/chem/matter.h>
#include <cando/chem/atom.h>
#include <cando/chem/residue.h>
#include <cando/chem/loop.h>
#include <cando/chem/oligomer.h>
#include <cando/adapt/adapters.h>
#include <cando/adapt/symbolList.h>
#include <cando/chem/coupling.h>
#include <cando/chem/candoDatabase.h>
#include <cando/chem/monomerPack.h>
#include <cando/chem/monomerContext.h>
#include <cando/chem/representedEntityNameSet.h>
#include <cando/chem/plug.h>
#include <cando/chem/constitution.h>
#include <clasp/core/numerics.h>
#include <cando/chem/alias.h>
#include <cando/chem/topology.h>
#include <clasp/core/wrappers.h>



namespace chem {



#if 0 //[
    void	MonomerPlanInfo::defineYourselfFromMonomerPlanInfo(MonomerPlanInfo* info)
    {
	this->_SpanningBackToRoot = info->_SpanningBackToRoot;
	this->_SpanningNext = info->_SpanningNext;
	this->_SpanningTouched = info->_SpanningTouched;
	this->_CouplingBackToRoot = info->_CouplingBackToRoot;
    }


#endif //]










#ifdef XML_ARCHIVE
    void	Monomer_O::archiveBase(core::ArchiveP node)
    {
	this->Base::archiveBase(node);
	node->archiveWeakPointer("oligomer",this->_WeakOligomer);
	node->archiveWeakPointer("tempResidue",this->_TempResidue);
	node->archiveWeakSymbolMultiMap<Coupling_O>("couplings",this->_WeakCouplings);
	node->attribute("comment", this->_Comment);
	node->attributeIfNotNil("id", this->_Id);
	node->attributeIfNotNil("aliases", this->_Aliases);
	node->attribute("verbose", this->_Verbose);
	node->attributeIfNotDefault("tempInt", this->_TemporaryInt,0);
	node->attribute("sequenceNumber",this->_SequenceNumber);
	node->attributeIfNotNil("status",this->_Status);
	node->archivePlainObject<geom::Vector2>( "pos2","Vector2",
						 this->_Position2D );
	node->attribute("selected",this->_Selected );
	if ( node->loading() )
	{
	    if ( this->_Status.nilp() )	
	    {
		this->_Status = StatusTracker_O::create();
	    }
	}
    }
#endif



//HERE HERE HERE   copy this and make it general

CL_LISPIFY_NAME("getGeneralMonomerContext");
CL_DEFMETHOD     MonomerContext_sp Monomer_O::getGeneralMonomerContext()
    {
	MonomerContext_sp	context;
	EntityNameSetWithCap_sp	selfRecognizer, neighborRecognizer;
	CandoDatabase_sp	db;
	Monomer_O::Couplings::iterator	ci;
	Coupling_sp		coupling;
	Monomer_sp		neighborMonomer;
	context = _Nil<MonomerContext_O>();
	if ( !this->isMonomerContextValid() )
	{
	    SIMPLE_ERROR(BF("Monomer context is invalid: %s") % this->sharedThis<Monomer_O>()->description() );
	}
	db = getCandoDatabase();
	context = MonomerContext_O::create();
	selfRecognizer = EntityNameSetWithCap_O::create(); //,db);
	selfRecognizer->addGroupName(this->getGroupName());
	context->setFocus(selfRecognizer);
	for ( ci=this->_Couplings.begin(); ci!=this->_Couplings.end(); ci++ )
	{
	    coupling = (ci->second);
	    //
	    // Skip RingClosing couplings, they aren't part of the context
	    //
	    if ( coupling->isAssignableTo<RingCoupling_O>() ) continue;
	    neighborRecognizer = EntityNameSetWithCap_O::create(); //,db);
	    neighborMonomer = coupling->getOtherSideMonomer(this->sharedThis<Monomer_O>());
	    neighborRecognizer->addGroupName(neighborMonomer->getGroupName());
	    context->addNeighbor(ci->first,neighborRecognizer);
	}
	return context;
    }

    void	Monomer_O::clearError()	{_OF();ASSERTNOTNULL(this->_Status);this->_Status->reset();};
CL_LISPIFY_NAME("getHasError");
CL_DEFMETHOD     bool	Monomer_O::getHasError()	{ return this->_Status->hasError();};
CL_LISPIFY_NAME("getStatusMessage");
CL_DEFMETHOD     string	Monomer_O::getStatusMessage() { return this->_Status->getStatus();};
    void	Monomer_O::addErrorMessage(const string& s) { this->_Status->addError(s);};
    void	Monomer_O::addStatusMessage(const string& s) {this->_Status->addMessage(s);};
    StatusTracker_sp	Monomer_O::getStatusTracker() { return this->_Status;};

CL_LISPIFY_NAME("plugNamesAndCouplingsAsCons");
CL_DEFMETHOD     core::List_sp	Monomer_O::plugNamesAndCouplingsAsCons()
    {
	core::Cons_sp first = core::Cons_O::create(_Nil<core::T_O>(),_Nil<core::T_O>());
	core::Cons_sp cur = first;
	Monomer_O::Couplings::iterator	ci;
	for ( ci=this->_Couplings.begin(); ci!=this->_Couplings.end(); ci++ )
	{
	    Coupling_sp coupling = (ci->second);
	    core::Cons_sp oneOne = core::Cons_O::createList(ci->first,coupling);
	    core::Cons_sp one = core::Cons_O::create(oneOne);
	    cur->setCdr(one);
	    cur = one;
	}
	return first->cdr();
    }


    bool Monomer_O::hasRingClosingOutPlug() const
    {_OF();
	Couplings::const_iterator it;
	for ( it=this->_Couplings.begin(); it!=this->_Couplings.end(); it++ )
	{
	    if ( it->second->isRingClosing() ) return true;
	}
	return false;
    }



    adapt::SymbolSet_sp Monomer_O::plugNames() const
    {_OF();
        adapt::SymbolSet_sp ss = adapt::SymbolSet_O::create();
        for ( Couplings::const_iterator it = this->_Couplings.begin(); it!=this->_Couplings.end(); ++it ) {
            ss->insert(it->first);
        }
        return ss;
    }


CL_LISPIFY_NAME("setAliasesFromCons");
CL_DEFMETHOD     void	Monomer_O::setAliasesFromCons(core::List_sp aliases)
    {
	this->_Aliases->clear();
	this->_Aliases->insertConsSymbols(aliases);
    }


CL_LISPIFY_NAME("hasTemporaryResidue");
CL_DEFMETHOD     bool Monomer_O::hasTemporaryResidue()
    {_OF();
	ASSERTNOTNULL(this->_TempResidue);
	return this->_TempResidue.notnilp();
    };



#if 0
    AtomBoundFrame_sp Monomer_O::getAtomBoundFrameForInCoupling()
    {
	if ( !this->hasInCoupling() )
	{
	    return _Nil<AtomBoundFrame_O>();
	}
	DirectionalCoupling_sp coupling = this->getInCoupling();
	OutPlug_sp preceedingPlug = coupling->getPlugForOtherMonomer(this->sharedThis<Monomer_O>()).as<OutPlug_O>();
	Monomer_sp preceedingMonomer = coupling->getOtherSideMonomer(this->sharedThis<Monomer_O>());
	Frame_sp frame = preceedingPlug->getExportFrame();
	if ( frame.nilp() )
	{
	    stringstream ss;
	    ss << "In getAtomBoundFrameForInCoupling current monomer=";
	    ss << this->description() << std::endl;
	    ss << " coupling = " << coupling->description() << std::endl;
	    ss << " preceeding monomer is = " << preceedingMonomer->description() << std::endl;
	    ss << " preceeding plug = " << preceedingPlug->description() << std::endl;
	    ss << " It doesn't export a frame but it has to!!!!" << std::endl;
	    SIMPLE_ERROR(BF("%s")%ss.str());
	}
	BoundFrame_sp bound = frame->getBoundFrame(preceedingMonomer);
	if ( !bound.isA<AtomBoundFrame_O>() )
	{
	    SIMPLE_ERROR(BF("The frame must return an AtomBoundFrame but instead it returned a "+bound->description()));
	}
	return bound.as<AtomBoundFrame_O>();
    }
#endif

#if 0
    void Monomer_O::setAliasesFromString(const string& s)
    {_OF();
	ASSERTNOTNULL(this->_Aliases);
	this->_Aliases->setFromString(s);
    };
#endif


CL_LISPIFY_NAME("getAliasesAsString");
CL_DEFMETHOD     string Monomer_O::getAliasesAsString()
    {_OF();
	ASSERTNOTNULL(this->_Aliases);
	return this->_Aliases->asString();
    };



    void	Monomer_O::setAliasesFromSymbolList(adapt::SymbolList_sp aliases)
    {
	this->_Aliases->clear();
	this->_Aliases->insertSymbolList(aliases);
    }

CL_LISPIFY_NAME("checkForBadConnections");
CL_DEFMETHOD     bool	Monomer_O::checkForBadConnections()
    {
	Couplings::iterator	it;
	Coupling_sp		coup;
	bool			badConnections;
	badConnections = false;
	LOG(BF("Check for bad connections %s") % this->description().c_str() );
	for ( it=this->_Couplings.begin(); it!=this->_Couplings.end(); it++ )
	{
	    if ( it->second.nilp() )
	    {
		this->addErrorMessage("Coupling with plug("+it->first->__repr__()+") is Null");
		badConnections = true;
		continue;
	    }
	    coup = it->second;
	    if ( !coup->containsMonomer(this->sharedThis<Monomer_O>()) )
	    {
		this->addErrorMessage("The coupling through plug("+it->first->__repr__()+") doesn't contain me");
		badConnections = true;
	    }
	}
	return badConnections;
    }

CL_LISPIFY_NAME("throwIfBadConnections");
CL_DEFMETHOD     void	Monomer_O::throwIfBadConnections()
    {
	if ( this->checkForBadConnections() )
	{
	    LOG(BF("Found bad connections in %s  error: %s") % this->description().c_str() % this->getStatusMessage().c_str()  );
	    SIMPLE_ERROR(BF("Bad connections for monomer: %s") % this->sharedThis<Monomer_O>()->description());
	}
    }




CL_LISPIFY_NAME("checkForErrorsAndUnknownContexts");
CL_DEFMETHOD     void	Monomer_O::checkForErrorsAndUnknownContexts(CandoDatabase_sp cdb)
    {
	string			lastPlugName;
	Coupling_sp		coup;
	this->clearError();
	this->checkForBadConnections();
    }


CL_LISPIFY_NAME("getSpecificMonomerContext");
CL_DEFMETHOD     MonomerContext_sp Monomer_O::getSpecificMonomerContext()
    {
	MonomerContext_sp	context;
	EntityNameSet_sp	selfRecognizer, neighborRecognizer;
	CandoDatabase_sp db;
	Monomer_O::Couplings::iterator	ci;
	Coupling_sp		coupling;
	Monomer_sp		neighborMonomer;
	context = _Nil<MonomerContext_O>();
	if ( !this->isMonomerContextValid() )
	{
	    SIMPLE_ERROR(BF("Monomer context is invalid: %s") %this->sharedThis<Monomer_O>()->description() );
	}
	db = getCandoDatabase();
	context = MonomerContext_O::create();
	selfRecognizer = EntityNameSet_O::create();
	selfRecognizer->setMonomerNameOrPdb(this->getName());
	context->setFocus(selfRecognizer);
	for ( ci=this->_Couplings.begin(); ci!=this->_Couplings.end(); ci++ )
	{
	    coupling = (ci->second);
	    if ( coupling.isA<DirectionalCoupling_O>() )
	    {
		neighborRecognizer = EntityNameSet_O::create();
		neighborMonomer = coupling->getOtherSideMonomer(this->sharedThis<Monomer_O>());
		neighborRecognizer->setMonomerNameOrPdb(neighborMonomer->getName());
		context->addNeighbor(ci->first,neighborRecognizer);
	    } else
	    {
		RingCoupling_sp rc = coupling.as<RingCoupling_O>();
                (void)rc;
		LOG(BF("Ignoring out coupling for RingCoupling: %s") % rc->getName()->__repr__() );
	    }
	}
	return context;
    }




    RingClosingPlug_sp Monomer_O::getMissingRingClosingPlug(Monomer_sp mate)
    {
	CandoDatabase_sp	bdb;
	Constitution_sp	constitution;
	MonomerContext_sp	context;
	Topology_sp		topology;
	bdb = getCandoDatabase();
	constitution = bdb->constitutionForNameOrPdb(this->getName());
	return constitution->getMissingRingClosingPlug(this->sharedThis<Monomer_O>(),mate);
    }

    uint Monomer_O::numberOfCouplings() const {
        return this->_Couplings.size();
    }


CL_LISPIFY_NAME("getTopology");
CL_DEFMETHOD     Topology_sp	Monomer_O::getTopology()
    {
	CandoDatabase_sp	bdb;
	Constitution_sp	constitution;
	MonomerContext_sp	context;
	Topology_sp		topology;
	bdb = getCandoDatabase();
	constitution = bdb->constitutionForNameOrPdb(this->getName());
	ASSERTNOTNULL(constitution);
	ASSERT(constitution.notnilp());
	topology = constitution->getTopologyForMonomerEnvironment(this->sharedThis<Monomer_O>());
	return topology;
    }





    void	Monomer_O::setOligomer(Oligomer_sp o )
    {
	this->_Oligomer = o;
    };

    void Monomer_O::initialize()
    {
	this->Base::initialize();
	this->_Oligomer = _Nil<Oligomer_O>();
	this->_TempResidue = _Nil<Residue_O>();
//        this->_Couplings = core::HashTableEq_O::create_default();
	this->setComment("");
	this->_Id = _Nil<core::Symbol_O>();
	this->_Aliases = adapt::SymbolSet_O::create();
	this->_Verbose = false;
	this->_TemporaryInt = 0;
	this->_SequenceNumber = 0;
	this->_Status = StatusTracker_O::create();
	this->_Status->reset();
	this->_Selected = false;
	this->setPosition2D_xy(0.0,0.0);
    }


//
// Destructor
//


CL_LISPIFY_NAME("getInCoupling");
CL_DEFMETHOD     DirectionalCoupling_sp	Monomer_O::getInCoupling()
    {
	Monomer_O::Couplings::iterator	it;
	DirectionalCoupling_sp			coup;
	for ( it=this->_Couplings.begin(); it!=this->_Couplings.end(); it++ ) {
	    if ( DirectionalCoupling_O::isInPlugName(it->first) )
	    {
		ASSERTNOTNULL(it->second);
		coup = it->second.as<DirectionalCoupling_O>();
		return coup;
	    }
	}
	return _Nil<DirectionalCoupling_O>();
    };


/*! Return the name of the inCoupling.
 * If it doesn't exist return ""
 */
    core::Symbol_sp Monomer_O::getInCouplingName()
    {
	Monomer_O::Couplings::iterator	it;
	for ( it=this->_Couplings.begin(); it!=this->_Couplings.end(); it++ ) 
	{
	    ASSERTNOTNULL(it->second);
	    Coupling_sp coup = it->second;
	    if ( coup.isA<DirectionalCoupling_O>() )
	    {
		DirectionalCoupling_sp dc = coup.as<DirectionalCoupling_O>();
		if ( dc->isInCouplingToMonomer(this->sharedThis<Monomer_O>()) ) return it->first;
	    }
	}
	return _Nil<core::Symbol_O>();
    };


CL_LISPIFY_NAME("hasInCoupling");
CL_DEFMETHOD     bool	Monomer_O::hasInCoupling()
    {
	Coupling_sp	coup;
	coup = this->getInCoupling();
	return (coup.notnilp() );
    };


    bool	Monomer_O::hasOutCouplings()
    {
	Coupling_sp	coup;
	coup = this->getInCoupling();
	return (coup.notnilp());
    };



    Plug_sp	Monomer_O::getPlugNamed(core::Symbol_sp pn)
    {
	Constitution_sp con;
	Plug_sp		plug;
	con = getCandoDatabase()->constitutionForNameOrPdb(this->getName());
	ASSERTNOTNULL(con);
	if ( !con->hasPlugNamed(pn) )
	{
	    stringstream ss;
	    ss << "Constitution(" << con->getName();
	    ss << ") does not have plug named(" << pn->__repr__() << ")";
	    ss << "  available plugs(" << con->getPlugNames()->asString() << ")";
	    SIMPLE_ERROR(BF("%s")%ss.str());
	}
	plug = con->getPlugNamed(pn);
	ASSERTNOTNULL(plug);
	return plug;
    }


CL_LISPIFY_NAME("getConstitution");
CL_DEFMETHOD     Constitution_sp Monomer_O::getConstitution()
    {
	CandoDatabase_sp db;
	core::Symbol_sp nm;
	LOG(BF("status") );
	db = getCandoDatabase();
	LOG(BF("status") );
	nm = this->getName();
	LOG(BF("status") );
	LOG(BF("Monomer name (%s)") % nm->__repr__() );
	return db->constitutionForNameOrPdb(nm);
    }





    Coupling_sp Monomer_O::getCouplingWithPlugName( core::Symbol_sp s)
    {_OF();
	if ( this->_Couplings.contains(s) ) {
	    Coupling_wp	coup;
	    coup = this->_Couplings.get(s);
	    ASSERTNOTNULL(coup);
	    return coup;
	}
	return _Nil<Coupling_O>();
    }

    bool	Monomer_O::hasCouplingWithPlugName( core::Symbol_sp s )
    {
	Coupling_sp	c;
	c = this->getCouplingWithPlugName(s);
	return c.notnilp();
    }


    bool	Monomer_O::hasMatchingPlugNameAndCoupling( core::Symbol_sp plugName, Coupling_sp coup)
    {
	Couplings::iterator	it;
	pair<Couplings::iterator,Couplings::iterator>	range;
	int					count;
	Coupling_sp				myCoup;
	bool					foundIt;
	LOG(BF("Looking for plug name: %s and coupling: %s") % plugName->__repr__() % coup->description() );
	count = 0;
	foundIt = false;
	range = this->_Couplings.equal_range(plugName);
	for ( it=range.first; it!=range.second; it++ )
	{
	    count++;
	    ASSERTNOTNULLP(it->second,"Coupling is undefined");
	    myCoup = it->second;
	    LOG(BF("Looking at coupling: %s") % myCoup->description().c_str()  );
	    if ( myCoup == coup )
	    {
		LOG(BF("Found match,setting foundIt to true") );
		foundIt = true;
		break;
	    }
	}
	LOG(BF("There were %d couplings with that plug name") % count );
	return foundIt;
    }



CL_LISPIFY_NAME("addCoupling");
CL_DEFMETHOD     void	Monomer_O::addCoupling( core::Symbol_sp plugName,  Coupling_sp coup)
    {
	LOG(BF("add coupling to %s") % this->description() );
	LOG(BF("Adding plug(%s) coupling: %s") % plugName->__repr__() % coup->description() );
	this->_Couplings.insert2(plugName, coup->sharedThis<Coupling_O>());
	LOG(BF("After add monomer is %s") % this->description() );
    };



    void	Monomer_O::resetInCoupling( )
    {
	LOG(BF("resetting in coupling of %s") % this->description() );
	Coupling_sp inCoup;
	if ( this->hasInCoupling() ) {
	    LOG(BF("Had to remove old coupling") );
	    // Remove the current in coupling
	    inCoup = this->getInCoupling();
	    this->removeCoupling(inCoup);
	}
    }


CL_LISPIFY_NAME("setInCoupling");
CL_DEFMETHOD     void	Monomer_O::setInCoupling( Coupling_sp coup)
    {
	core::Symbol_sp inCoupName;
	LOG(BF("setting in coupling of %s") % this->description() );
	ASSERTNOTNULL(coup);
	this->resetInCoupling();
	LOG(BF("Adding in coupling: %s") % coup->description() );
	inCoupName = DirectionalCoupling_O::inPlugName(coup->getName());
	this->addCoupling( inCoupName, coup );
    }



CL_LISPIFY_NAME("addOutCoupling");
CL_DEFMETHOD     void	Monomer_O::addOutCoupling( Coupling_sp coup )
    {
	ASSERTNOTNULL(coup);
	LOG(BF("adding out coupling to %s") % this->description()  );
	core::Symbol_sp outPlugName = DirectionalCoupling_O::outPlugName(coup->getName());
	LOG(BF("Adding out coupling: %s") % coup->description() );
	this->addCoupling( outPlugName, coup );
    }


CL_LISPIFY_NAME("removeCouplingToMonomer");
CL_DEFMETHOD     void	Monomer_O::removeCouplingToMonomer(Monomer_sp mon )
    {
	Couplings::iterator		wci;
	bool				foundIt;
	Coupling_sp			coup;
	Monomer_sp			otherMonomer;
	foundIt = false;
	for ( wci=this->_Couplings.begin(); wci!=this->_Couplings.end(); wci++ )
	{
	    coup = wci->second;
	    otherMonomer = coup->getOtherSideMonomer(this->sharedThis<Monomer_O>());
	    if ( otherMonomer == mon )
	    {
		foundIt = true;
		break;
	    }
	}
	if ( !foundIt )
	{
	    SIMPLE_ERROR(BF("Could not find coupling to monomer: %s %s") % mon->description() % this->sharedThis<Monomer_O>()->description() );
	}
	LOG(BF("Removing coupling: %s") % coup->description() );
	this->_Couplings.erase(wci);
    };




    void	Monomer_O::fixPlugNameForCoupling(Coupling_sp coup)
    {
	Couplings::iterator		wci;
	bool				foundIt, isInPlug;
	Coupling_sp			myCoup;
	Monomer_sp			otherMonomer;
	core::Symbol_sp			plugName;
	foundIt = false;
	for ( wci=this->_Couplings.begin(); wci!=this->_Couplings.end(); wci++ )
	{
	    myCoup = (wci->second);
	    if ( coup == myCoup )
	    {
		foundIt = true;
		isInPlug = DirectionalCoupling_O::isInPlugName(wci->first);
		LOG(BF("Original plug name: %s") % wci->first->__repr__() );
		break;
	    }
	}
	if ( !foundIt )
	{
	    SIMPLE_ERROR(BF("Could not find coupling : %s %s") % coup->description() % this->sharedThis<Monomer_O>()->description() );
	}
	LOG(BF("Fixing the PlugName key for coupling: %s") % coup->description().c_str()  );
	this->_Couplings.erase(wci);
	if ( isInPlug)
	{
	    plugName = DirectionalCoupling_O::inPlugName(coup->getName());
	} else
	{
	    plugName = DirectionalCoupling_O::outPlugName(coup->getName());
	}
	LOG(BF("Changing plug name to: %s") % plugName->__repr__() );
	this->addCoupling( plugName, coup );
    }












CL_LISPIFY_NAME("removeCoupling");
CL_DEFMETHOD     void	Monomer_O::removeCoupling(Coupling_sp coup)
    {
	bool				foundIt = false;
	Coupling_sp			myCoup;
	Couplings::iterator		wci;
	for ( wci=this->_Couplings.begin(); wci!=this->_Couplings.end(); wci++ )
	{
	    myCoup = wci->second;
	    if ( coup == myCoup  )
	    {
		foundIt = true;
		break;
	    }
	}
	if ( !foundIt )
	{
	    SIMPLE_ERROR(BF("Could not find coupling: %s %s") % coup->description() % this->sharedThis<Monomer_O>()->description() );
	}
	LOG(BF("Removing coupling: %s") % myCoup->description().c_str()  );
	this->_Couplings.erase(wci);
    }



//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------

#ifdef XML_ARCHIVE
    void	OneMonomer_O::archiveBase(core::ArchiveP node )
    {
	node->attribute("name",this->_Name);
    }
#endif

//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------


    void MultiMonomer_O::initialize()
    {
	this->Base::initialize();
	this->_Monomers.clear();
	this->_CurrentMonomerIndex = -1;
    }


#if INIT_TO_FACTORIES

#define ARGS_MultiMonomer_O_make "(name comment)"
#define DECL_MultiMonomer_O_make ""
#define DOCS_MultiMonomer_O_make "make ChemDraw"
    MultiMonomer_sp MultiMonomer_O::make(core::Symbol_sp name, const string& comment)
  {
      GC_ALLOCATE(MultiMonomer_O, me );
    if ( name.notnilp() ) me->setGroupName(name);
    if ( comment != "" ) me->setComment(comment);
    return me;
  };

#else

    core::T_sp MultiMonomer_O::__init__(core::Function_sp exec, core::List_sp args,
				  core::Environment_sp env, core::Lisp_sp lisp)
    {
	core::Symbol_sp name = translate::from_object<core::Symbol_O>::convert(env->lookup(Package(),"name"));
	if ( name.notnilp() ) this->setGroupName(name);
	string comment = translate::from_object<string>::convert(env->lookup(Package(),"comment"));
	if ( comment != "" ) this->setComment(comment);
	return _Nil<core::T_O>();
    }

#endif
#ifdef XML_ARCHIVE
    void	MultiMonomer_O::archiveBase(core::ArchiveP node)
    {
	this->Monomer_O::archiveBase(node);
	node->attribute("currentMonomerIndex",this->_CurrentMonomerIndex );
	node->attribute("groupName",this->_GroupName);
	node->archiveVector0("monomers",this->_Monomers);
    }
#endif


    core::Symbol_sp MultiMonomer_O::getName() const
    {_OF();
	if ( this->_Monomers.size() == 0 ) return _Nil<core::Symbol_O>();
	return this->getOneMonomer()->getName();
    }


    void	MultiMonomer_O::_expandGroupName()
    {
	adapt::SymbolSet_sp		monomerNames;
	CandoDatabase_sp	bdb;
	core::Symbol_sp			name;

	name = this->_GroupName;
	this->_Monomers.clear();
	bdb = getCandoDatabase();
	this->clearError();
	if ( !bdb->recognizesSetOrConstitutionOrMonomerName(name) )
	{
	    LOG(BF("Illegal group name(%s)") % name->__repr__() );
	    this->addErrorMessage("Illegal group name: "+name->__repr__());
	    return;
	}
	LOG(BF("Legal group name(%s)") % name->__repr__() );
	monomerNames = bdb->expandEntityNameToTerminals(name);
	LOG(BF("Got %d monomer names") % monomerNames->size() );
	monomerNames->map( [this] (core::Symbol_sp si) {
	    LOG(BF("Adding monomer named(%s)") % (si)->__repr__() );
	    this->addMonomerName(si);
          } );
	if ( this->_CurrentMonomerIndex >= this->_Monomers.size() )
	{
	    this->_CurrentMonomerIndex = 0;
	}
    }




CL_LISPIFY_NAME("setGroupName");
CL_DEFMETHOD     void	MultiMonomer_O::setGroupName(core::Symbol_sp name)
    {
	CandoDatabase_sp	bdb;
	this->_GroupName = name;
	this->_expandGroupName();
    }

/*! Check for errors and if any of the specific MonomerContexts that
 * this Monomer represents are not found in the CandoDatabase
 */
    void	MultiMonomer_O::checkForErrorsAndUnknownContexts(CandoDatabase_sp cdb)
    {
	adapt::SymbolSet_sp	allSpecificContextKeys;
	MonomerContext_sp	context;
	bool			allContextsRecognized = true;
	this->addStatusMessage("MultiMonomer_O::checkForErrorsAndUnknownContexts");
	ASSERTNOTNULLP(cdb,"CandoDatabase is undefined");
	this->Monomer_O::checkForErrorsAndUnknownContexts(cdb);
	if ( this->getHasError() ) return;
	if ( this->numberOfPossibleMonomers() == 0 )
	{
	    this->addErrorMessage("This MultiMonomer is empty");
	    return;
	}
	if ( !this->isMonomerContextValid() )
	{
	    this->addErrorMessage("The MonomerContext is invalid");
	    return;
	}
	context = this->getGeneralMonomerContext();
	allSpecificContextKeys = context->getAllSpecificKeys();
	stringstream ss;
	ss.str("");
	ss << "There are " << allSpecificContextKeys->size() << " specific contexts" << std::endl;
	this->addStatusMessage(ss.str());
	if ( allSpecificContextKeys->size() == 0 )
	{
	    this->addErrorMessage("There are no legal specific contexts");
	} else
	{
          allSpecificContextKeys->map_while_true( [&cdb,this,&allContextsRecognized] (core::Symbol_sp sit) {
              if ( !cdb->recognizesMonomerCoordinatesKey(sit) ) {
                this->addErrorMessage("Monomer->Unrecognized context: "+_rep_(sit));
                allContextsRecognized = false;
                return false;
              }
              return true;
	    } );
	    if ( allContextsRecognized ) {
		this->addStatusMessage("All contexts are recognized.");
	    }
	}
    }




    void	MultiMonomer_O::addMonomerName(core::Symbol_sp name)
    {
	GC_ALLOCATE(OneMonomer_O, om );
	om->setName(name);
	this->_Monomers.push_back(om);
    }




    void	MultiMonomer_O::randomizeMonomer()
    {
	ASSERT(this->_Monomers.size()>=1);
	if ( this->_Monomers.size()==1 )
	{
	    SIMPLE_ERROR(BF("I cannot randomize a MultiMonomer that has only one member"));
	    return;
	}
	uint newMonomerIndex = core::randomNumber01()*this->_Monomers.size();
	if ( newMonomerIndex != this->_CurrentMonomerIndex )
	{
	    this->_CurrentMonomerIndex = newMonomerIndex;
	} else
	{
	    this->_CurrentMonomerIndex++;
	    if ( this->_CurrentMonomerIndex >= this->_Monomers.size() )
	    {
		this->_CurrentMonomerIndex = 0;
	    }
	}
	LOG(BF("Randomized monomer(%s) to %d out of %d") % this->getComment().c_str()
	    % this->_CurrentMonomerIndex % this->_Monomers.size()  );
    }




CL_LISPIFY_NAME("getOneMonomer");
CL_DEFMETHOD     OneMonomer_sp	MultiMonomer_O::getOneMonomer() const
    {
	if ( this->_Monomers.size() < 1 ) {
	    SIMPLE_ERROR(BF("There are no monomers defined for MultiMonomer group("+this->_GroupName->__repr__()+")"));
	}
	LOG(BF("Looking up monomer: %d") % this->_CurrentMonomerIndex  );
	return this->_Monomers[this->_CurrentMonomerIndex];
    };


    Residue_sp	MultiMonomer_O::createResidue()
    {
	Residue_sp	orig;
	Constitution_sp	con;
	core::Symbol_sp		monName;
	monName = this->getName();
	con = getCandoDatabase()->constitutionForNameOrPdb(monName);
	Residue_sp res = con->createResidueForStereoisomerName(monName);
	Constitution_sp residueConstitution = res->getConstitution();
	if ( residueConstitution != con )
	{
	    SIMPLE_ERROR(BF("Residue created with a different constitution(%s) from the one it was created from constitution(%s)") % residueConstitution->__repr__() % con->__repr__() );
	}
    	//
	// WORKING WORKING WORKING
	//
	// Here we should set the Monomer alias names for the residue
	// and the atom alias names for the atoms of the residue
	// according to the _GroupName
	//
	res->setMonomerAliases(this->_Aliases);
	res->setUniqueLabel(this->_Id);
	if ( getCandoDatabase()->recognizesEntityNameSetName(this->_GroupName) )
	{
	    EntityNameSet_sp monomerPack = getCandoDatabase()->getEntity(this->_GroupName).as<EntityNameSet_O>();
	    if ( monomerPack->supportsInterestingAtomAliases() )
	    {
              core::List_sp atomAliases = monomerPack->getInterestingAtomAliases();
		AtomIndexer_sp aliasAtoms = monomerPack->getAtomIndexerForMonomerName(this->getName());
		ASSERTP(core::cl__length(atomAliases) == aliasAtoms->numberOfAtomNames(),
			"The number of atom names has to match the number of atom aliases");
		AtomIndexer_O::atomNameIterator ii;
                core::List_sp ai;
		for ( ii = aliasAtoms->begin_AtomNames(), ai=atomAliases;
		      ii != aliasAtoms->end_AtomNames(); ii++ )
		{
		    Atom_sp atom = res->atomWithName(*ii);
		    atom->setAlias(oCar(ai));
                    ai = oCdr(ai);
		}
#if 0
		{
		    stringstream ss;
		    ss << "    At this point you should set the aliases of the atoms of this residue"<<std::endl;
		    ss << "    Source file: " << __FILE__ << " line number: " << __LINE__ << std::endl;
		    ss << "    The _GroupName is ("<<this->_GroupName<<") and the monomer has the aliases("<<this->_Aliases->asString()<< ")"<< std::endl;
		    ss << "    The monomer name is ("<<this->getName()<<")"<<std::endl;
		    ss << "    The atoms interesting atom names are ("<<monomerPack->getInterestingAtomNamesForMonomerName(this->getName())<<")"<<std::endl;
		    ss << "    The atom aliases are ("<<monomerPack->getInterestingAtomAliasesAsString() <<")"<<std::endl;
		    _lisp->print(BF("%s"), ss.str());
		}
#endif
	    }
	}
	this->setTempResidue(res);
	return res;
    }



    string MultiMonomer_O::description() const
    {//
	stringstream			ss;
	ss.str("");
	ss << "MultiMonomer(";
	ss << "["<<this->getGroupName()<<" id:" << this->_Id->__repr__() << "]=";
	ss << " plugs: ";
	Couplings::const_iterator	ci;
	for ( ci=this->_Couplings.begin(); ci!=this->_Couplings.end(); ci++ ) {
          ss << _rep_(ci->first) << ",";
	}
	ss << ")";
	return ss.str();
    }


CL_LISPIFY_NAME("isMonomerContextValid");
CL_DEFMETHOD     bool Monomer_O::isMonomerContextValid()
    {
	LOG(BF("status") );
        adapt::SymbolSet_sp keys = adapt::SymbolSet_O::create();
        for ( Couplings::const_iterator it = this->_Couplings.begin(); it!=this->_Couplings.end(); ++it ) {
            keys->insert(it->first);
        }
	LOG(BF("status") );
    	// If a plug name is duplicated then we don't have a valid context and we can't return the context
	if ( keys->size() < this->_Couplings.size() )
	{
	    return false;
	}
	return true;
    }




CL_LISPIFY_NAME("getOneMonomerWithName");
CL_DEFMETHOD     OneMonomer_sp	MultiMonomer_O::getOneMonomerWithName(core::Symbol_sp name) const
    {
	Monomers::const_iterator	mi;
	for ( mi=this->_Monomers.begin(); mi!=this->_Monomers.end(); mi++ )
	{
	    if ( (*mi)->getName() == name ) return *mi;
	}
	return _Nil<OneMonomer_O>();
    }



CL_LISPIFY_NAME("getInterestingAtomIndexer");
CL_DEFMETHOD     AtomIndexer_sp	MultiMonomer_O::getInterestingAtomIndexer()
    {
	AtomIndexer_sp		atomIndexer;
	EntityNameSet_sp		entityNameSet;
	CandoDatabase_sp	bdb;
	bdb = getCandoDatabase();
	if ( bdb->recognizesEntityNameSetName(this->getGroupName()) )
	{
	    entityNameSet = bdb->getEntityNameSet(this->getGroupName());
	    if ( entityNameSet->supportsInterestingAtomAliases() )
	    {
		atomIndexer = entityNameSet->getAtomIndexerForMonomerName(this->getName());
		return atomIndexer;
	    }
	}
	atomIndexer = AtomIndexer_O::create();
	return atomIndexer;
    }



core::List_sp MultiMonomer_O::allAtomAliases()
    {
	EntityNameSet_sp		entityNameSet;
	CandoDatabase_sp	bdb;
	bdb = getCandoDatabase();
	ASSERTNOTNULL(bdb);
	ASSERTP(bdb.notnilp(),"Can't get atom aliases because the CandoDatabase is undefined");
	if ( bdb->recognizesEntityNameSetName(this->getGroupName()) )
	{
	    LOG(BF("Recognized the EntityNameSetName(%s)")% this->getGroupName() );
	    entityNameSet = bdb->getEntityNameSet(this->getGroupName());
            core::List_sp aliases = entityNameSet->getInterestingAtomAliases();
	    LOG(BF("Returning with aliases(%s)")% aliases->asString() );
	    return aliases;
	} else 
	{
	    LOG(BF("Did not recognize the EntityNameSetName(%s)")% this->getGroupName());
	}
	LOG(BF("Returning with nothing"));
	return _Nil<core::T_O>();
    }



    class AliasWrapper : public adapt::SymbolSetCartesianProductWrapper
    {
    public:
	core::T_sp operator()(core::Symbol_sp obj1, core::Symbol_sp obj2) const
	{
	    Alias_sp alias = Alias_O::create(obj1,obj2);
	    return alias;
	}
    };


    adapt::ObjectSet_sp Monomer_O::getAllAliases()
    {
	ASSERTNOTNULL(this->_Aliases);
	if ( this->_Aliases->size() == 0 )
	{
          if ( core::cl__length(this->allAtomAliases()) != 0 )
	    {
              SIMPLE_ERROR(BF("The monomer[%s] doesn't have monomer aliases but it has atom aliases(%s) - this should never happen") % this->getName() % _rep_(this->allAtomAliases()) );
	    }
	    return _Nil<adapt::ObjectSet_O>();
	}
	ASSERT_gt(this->_Aliases->size(),0);
	adapt::SymbolSet_sp atomAliases = adapt::SymbolSet_O::create();
        core::List_sp atomAliasesList = this->allAtomAliases();
	atomAliases->insertConsSymbols(atomAliasesList);
	AliasWrapper wrapper;
	adapt::ObjectSet_sp allAliases = this->_Aliases->cartesianProductWrapped(atomAliases,wrapper);
	return allAliases;
    }





    bool MultiMonomer_O::recognizesAlias(Alias_sp alias)
    {
	AtomIndexer_sp		atomIndexer;
	EntityNameSet_sp		entityNameSet;
	CandoDatabase_sp	bdb;
	LOG(BF("Checking if %s recognizes alias(%s)") % this->description().c_str() % alias->__repr__().c_str()  );
	if ( !this->_Aliases->contains(alias->getMonomerAlias()) )
	{
	    LOG(BF("It does not") );
	    LOG(BF("The monomer aliases that it recognizes are: %s") % this->_Aliases->asString().c_str()  );
	    return false;
	}
	LOG(BF("%s does recognize monomer alias(%s)") % this->description().c_str() % alias->__repr__().c_str() );
	bdb = getCandoDatabase();
	if ( bdb->recognizesEntityNameSetName(this->getGroupName()) )
	{
	    LOG(BF("Checking if represents a EntityNameSet with interesting atom alias(%s)") % alias->getAtomAlias()->__repr__()  );
	    entityNameSet = bdb->getEntityNameSet(this->getGroupName());
	    if ( entityNameSet->hasInterestingAtomAlias( alias ) )
	    {
		LOG(BF("EntityNameSet does have interesting atom with alias(%s)") % alias->getAtomAlias()->__repr__()  );
		return true;
	    } else
	    {
		LOG(BF("EntityNameSet does not have interesting atom with alias(%s)") % alias->getAtomAlias()->__repr__()  );
	    }

	}
	LOG(BF("Fail,does not recognize alias") );
	return false;
    }




    bool MultiMonomer_O::incrementMonomerIndex()
    {
	this->_CurrentMonomerIndex++;
	if ( this->_CurrentMonomerIndex == this->_Monomers.size() )
	{
	    LOG(BF("Increment overflow -- resetting to zero") );
	    this->_CurrentMonomerIndex = 0;
	    return false;
	}
	LOG(BF("After increment index(%d)  monomer=%s") % this->_CurrentMonomerIndex % this->description().c_str()  );
	return true;
    }



    gctools::Vec0<Coupling_sp>	Monomer_O::getOutCouplings()
    {_OF();
        gctools::Vec0<Coupling_sp>	outCouplings;
	Monomer_O::Couplings::iterator wci;
	Coupling_sp		coup;
	for ( wci=this->_Couplings.begin();
	      wci!=this->_Couplings.end(); wci++ ) {
	    if ( DirectionalCoupling_O::isOutPlugName(wci->first) )
	    {
		ASSERTNOTNULL(wci->second);
		coup = wci->second;
		outCouplings.push_back(coup);
	    }
	}
	return outCouplings;
    }















};
