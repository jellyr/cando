#define	DEBUG_LEVEL_FULL

#include "core/common.h"
#include "core/environment.h"
#include "vector3.h"
#include "core/ovector3.h"
#include "xyz.h"
#include "float.h"
#include "system.h"
#include "singleDimension.h"
#include "core/wrappers.h"
namespace units
{

// ----------------------------------------------------------------------
//

    EXPOSE_CLASS(Xyz_O);

    void Xyz_O::exposeCando(::core::Lisp_sp lisp)
    {
	::core::class_<Xyz_O>()
	    .def_raw("__init__",&Xyz_O::__init__,"(self &rest args)")
	    .def("mul-by-float",&Xyz_O::mulByFloat)
	;
    }

    void Xyz_O::exposePython(core::Lisp_sp lisp)
    {_G();
	PYTHON_CLASS(UnitsPkg,Xyz,"","",_lisp)
	    .def("mul-by-float",&Xyz_O::mulByFloat)
	;
    }



    Xyz_sp Xyz_O::create(Vector3 pos, Quantity_sp temp, core::Lisp_sp lisp)
    {_G();	
	Xyz_sp x = _lisp->create<Xyz_O>();
	for ( int i=0; i<NumBaseDimensions; i++ ) x->_Powers[i] = temp->_Powers[i];
	x->_Pos = pos;
	x->_System = temp->_System;
	return x;
    }


    /*! If last argument is a System then use that system, otherwise use the default units:*SI* */
    Object_sp Xyz_O::__init__(::core::Executable_sp exec, ::core::Cons_sp allargs, ::core::Environment_sp env, ::core::Lisp_sp lisp)
    {_G();
//      this->Base::__init__(exec,args,env,lisp);
//      arg = from_object<XXXX>::convert(env->lookup(this->Package(),"YYY"));
	core::Cons_sp args = allargs->cdr();
	LOG(BF("Initializing Xyz_O with args[%s]") % args->__repr__() );
	double amount = 1.0;
	core::OVector3_sp vamount = args->ocar().as<core::OVector3_O>();
	/*Set the default system as units:*SI* */
	this->_System = this->parseDimensionSymbolList(this->_Powers,amount,args->cdr().as<core::Cons_O>(),true);
	this->_Pos = vamount->timesScalar(amount);
	return _lisp->onil();
    }

    void Xyz_O::archiveBase(::core::ArchiveP node)
    {
        this->Base::archiveBase(node);
	node->archivePlainObjectIfDefined<Vector3>( "pos","Vector3",
						    this->_Pos.isDefined(), this->_Pos );
    }


    void Xyz_O::initialize()
    {_OF();
        this->Base::initialize();
	this->_Pos.set(0.0,0.0,0.0);
    }


    Object_sp Xyz_O::amount_matchUnits(core::Executable_sp exec, core::Cons_sp args, core::Environment_sp env, core::Lisp_sp lisp)
    {_OF();
	int matchPowers[NumBaseDimensions] = {0,0,0,0,0,0,0};
	double amountScale = 1.0;
	this->parseDimensionSymbolList(matchPowers,amountScale,args->cdr(),false);
	if ( !this->powersMatch(matchPowers) )
	{
	    Xyz_sp temp = RP_Create<Xyz_O>(_lisp);
	    for (int ii=0; ii<NumBaseDimensions; ii++) temp->_Powers[ii] = matchPowers[ii];
	    temp->_System = this->_System;
	    THROW(_lisp->error(BF("You tried to get the amount of the quantity[%s] in terms of units[%s]"
				  "- cannot get the amount of a Quantity unless you match the units")
			       % this->__repr__()
			       % temp->__repr__() ));
	}
	return core::OVector3_O::create(this->_Pos.multiplyByScalar(1.0/amountScale),_lisp);
    }




    Object_sp Xyz_O::amount() const
    {_OF();
	int zeroPowers[NumBaseDimensions] = {0,0,0,0,0,0,0};
	if ( this->powersMatch(zeroPowers) )
	{
	    return core::OVector3_O::create(this->_Pos,_lisp);
	}
	THROW(_lisp->error(BF("You cannot get the amount of a Quantity unless it is unit-less!")));
    }







    Object_sp Xyz_O::unsafeAmount() const
    {_OF();
	return core::OVector3_O::create(this->_Pos,_lisp);
    }


    string Xyz_O::__repr__() const
    {_OF();
	double amount = 1.0;
	Vector3 pos = this->_Pos;
	stringstream units;
	units << "*" << this->system()->unitsAsString(amount,this->sharedThis<Xyz_O>());
	pos = pos.multiplyByScalar(amount);
	stringstream result;
	result << pos.asString() << units.str();
	return result.str();
    }







    Quantity_sp Xyz_O::add(Quantity_sp other) const
    {_OF();
	Xyz_sp result = RP_Copy(this);
	if ( other->notNil() )
	{
	    if ( !this->dimensionsMatch(other) )
	    {
		THROW(_lisp->error(BF("Mismatch in dimensions in add - you tried to add[%s] to [%s]") % this->__repr__() % other->__repr__()));
	    }
	    result->_Pos = result->_Pos +  (other.as<Xyz_O>()->_Pos);
	}
	return result;
    }

	
    Quantity_sp Xyz_O::sub(Quantity_sp other) const
    {_OF();
	Xyz_sp result = RP_Copy(this);
	if ( other->notNil() )
	{
	    if ( !this->dimensionsMatch(other) )
	    {
		THROW(_lisp->error(BF("Mismatch in dimensions in sub - you tried to sub[%s] to [%s]") % this->__repr__() % other->__repr__()));
	    }
	    result->_Pos = result->_Pos - other.as<Xyz_O>()->_Pos;
	}
	return result;
    }





    Quantity_sp Xyz_O::mulByFloat(Float_sp f) const
    {_OF();
	Xyz_sp result = RP_Copy(this);
	for ( int i=0; i<NumBaseDimensions; i++ )
	{
	    result->_Powers[i] += f->_Powers[i];
	}
	result->_Pos = result->_Pos.multiplyByScalar(f->_Amount);
	return result;
    }





    bool Xyz_O::isnan() const
    {_OF();
	return (
	    (this->_Pos.getX() != this->_Pos.getX())||
	    (this->_Pos.getY() != this->_Pos.getY())||
	    (this->_Pos.getZ() != this->_Pos.getZ()));
    }





}; /* units */