#ifndef	OMATRIX_H
#define	OMATRIX_H

#include <clasp/core/foundation.h>
#include <clasp/core/object.h>
#include <cando/candoBase/candoBasePackage.fwd.h>
#include <cando/candoBase/matrix.h>

namespace candoBase {

    SMART(OMatrix );
    class OMatrix_O : public core::T_O
    {
	LISP_BASE1(core::T_O);
	LISP_CLASS(candoBase,CandoBasePkg,OMatrix_O,"OMatrix");
public:
	Matrix	_Value;
public:
//	void	archiveBase(core::ArchiveP node);
public:
	string __repr__() const;
	string __str__() ;

	//! Create a clone of this matrix
	OMatrix_sp clone() const;

	void setToIdentity();
	void setToIndexAsValue();
	void translate(Vector3 pos);

	void setFromString(const string& s);
	void setFromStringFast(const string& s);
	string asString();
	string asStringFast();

	void rotationX(double radians);
	void rotationY(double radians);
	void rotationZ(double radians);

	Matrix mul(const Matrix& other) const;
	Vector3 mul(const Vector3& vec) const;

	Matrix extract3x3() const { return this->_Value.extract3x3();};
	Matrix transposed3x3() const { return this->_Value.transposed3x3();};

	double atRowColGet(int row, int col) { return this->_Value.atRowCol(row,col);};
	void atRowColPut(int row, int col, double v) { return this->_Value.atRowColPut(row,col,v);};
	Matrix getMatrix() { return this->_Value; };
	void setAll(const Matrix& m);
	const Matrix& ref() const { return this->_Value;};

	/*! Return true if the upper 3x3 rotation matrix is orthogonal */
	bool is3x3Orthogonal(double tol) const { return this->_Value.is3x3Orthogonal(tol);};

	DEFAULT_CTOR_DTOR(OMatrix_O);
    };




}; // namespace candoBase
TRANSLATE(candoBase::OMatrix_O);



namespace translate
{

    template <>
    struct	from_object<Matrix>
    {
	typedef	Matrix		ExpectedType;
	typedef	Matrix		DeclareType;
	DeclareType _v;
	from_object(core::T_sp o) : _v(o.as<candoBase::OMatrix_O>()->ref()) {};
    };

    template <>
    struct	from_object<const Matrix&>
    {
	typedef	Matrix		ExpectedType;
	typedef	const Matrix&		DeclareType;
	DeclareType _v;
	from_object(core::T_sp o) : _v(o.as<candoBase::OMatrix_O>()->ref()) {};
#if 0
	{
	    candoBase::OMatrix_sp v = o.as<candoBase::OMatrix_O>();
	    _v.setAll(v->getMatrix());
	}
#endif
    };


    template <>
    struct	to_object<Matrix>
    {
	typedef	candoBase::OMatrix_sp ExpectedType;
	typedef	candoBase::OMatrix_sp DeclareType;
	static core::T_sp convert(Matrix pos)
	{_G();
	    candoBase::OMatrix_sp ov = candoBase::OMatrix_O::create();
	    ov->setAll(pos);
	    return (ov);
	}
    };




    template <>
    struct	to_object<const Matrix& >
    {
	typedef	candoBase::OMatrix_sp ExpectedType;
	typedef	candoBase::OMatrix_sp DeclareType;
	static core::T_sp convert(const Matrix& pos)
	{_G();
	    candoBase::OMatrix_sp ov = candoBase::OMatrix_O::create();
	    ov->setAll(pos);
	    return (ov);
	}
    };



    template <>
    struct	to_object<Matrix& >
    {
	typedef	candoBase::OMatrix_sp ExpectedType;
	typedef	candoBase::OMatrix_sp DeclareType;
	static core::T_sp convert(Matrix& pos)
	{_G();
	    candoBase::OMatrix_sp ov = candoBase::OMatrix_O::create();
	    ov->setAll(pos);
	    return (ov);
	}
    };


};





#endif

