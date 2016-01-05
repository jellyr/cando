#define	DEBUG_LEVEL_FULL


//
// (C) 2004 Christian E. Schafmeister
//
#include <clasp/core/common.h>
#include <cando/adapt/adapters.h>
#include <cando/adapt/stringSet.h>
#include <cando/chem/monomerContext.h>
//#include	"monomerCoordinates.h"
#include <cando/chem/specificContext.h>
#include <cando/chem/monomer.h>
#include <cando/chem/coupling.h>
#include <clasp/core/wrappers.h>


#define	COUPLING_CHAR	"."



namespace chem
{


//
// Constructor
//


//
// Copy constructor
//
    MonomerContext_O::MonomerContext_O(const MonomerContext_O& mc) : core::CxxObject_O(mc)
    {_G();
	NeighborMap::const_iterator	mi;
	GC_COPY(EntityNameSetBase_O, temp , *mc._Self); // = RP_Copy<EntityNameSetBase_O>(mc._Self);
	this->_Self = temp;
	for ( mi=mc._Neighbors.begin(); mi!=mc._Neighbors.end(); mi++ ) {
	    GC_COPY(EntityNameSetBase_O, rec , *mi->second); // = RP_Copy<EntityNameSetBase_O>(mi->second);
	    this->_Neighbors.set(mi->first,rec);
	}
    }

//
// Destructor
//

#ifdef XML_ARCHIVE
    void	MonomerContext_O::archiveBase(core::ArchiveP node)
    {_OF();
#ifdef DEBUG_ON
	if ( node->saving() )
	{
	    NeighborMap::iterator mi;
	    for ( mi=this->_Neighbors.begin(); mi!=this->_Neighbors.end(); mi++ )
	    {
		ASSERTF(DirectionalCoupling_O::isPlugName(mi->first,_lisp),BF("About to save Bad plug name in MonomerContext Neighbor: %s")% mi->first );
	    }
	}
#endif
	node->attribute("self",this->_Self);
	node->archiveSymbolMap("neighbors", this->_Neighbors );
#ifdef DEBUG_ON
	if ( node->loading() )
	{
	    NeighborMap::iterator mi;
	    for ( mi=this->_Neighbors.begin(); mi!=this->_Neighbors.end(); mi++ )
	    {
		ASSERTF(DirectionalCoupling_O::isPlugName(mi->first,_lisp), BF("Loaded Bad plug name in MonomerContext Neighbor: %s")% mi->first );
	    }
	}
#endif
    }
#endif


    string	MonomerContext_O::description() const
    {
	stringstream desc;
	desc << this->core::T_O::description();
	return desc.str();
    }


CL_LISPIFY_NAME("addNeighbor");
CL_DEFMETHOD     void	MonomerContext_O::addNeighbor( core::Symbol_sp cn, EntityNameSetBase_sp r)
    {_OF();
	LOG(BF("Added neighbor with key plug: %s") % cn->__repr__()  );
	getCandoDatabase();
	ASSERTF(DirectionalCoupling_O::isPlugName(cn), BF("addNeighbor ILLEGAL PLUG NAME plugName=(%s)")% cn );
	ASSERTF(this->_Neighbors.count(cn) == 0, BF("MonomerContext already has a key: %s")% cn );
	this->_Neighbors.set(cn,r);
    }



    void	MonomerContext_O::expandOutsSpecificContexts(
	NeighborMap::iterator mit,
	SpecificContextSet_sp list,
	SpecificContext_sp name )
    {_G();
	IMPLEMENT_ME(); // work with new Symbol names
#if 0
	NeighborMap::iterator mitNext;
	if ( mit==this->_Neighbors.end() ) {
	    SpecificContext_sp final = name->copy();
	    list->add(final);
	} else {
	    if ( mit->second->getOptional() )
	    {
		LOG(BF("This is an optional EntityNameSetBase so we first skipping this EntityNameSetBase expanding the rest") );
		mitNext = mit;
		mitNext++;
		this->expandOutsSpecificContexts(mitNext, list, name );
	    }
	    LOG(BF("Handle neighbors") );
	    IMPLEMENT_ME();
	    // Deal with pushNeighbor second argument
	    name->pushNeighbor(mit->first,_Nil<core::Symbol_O>());
//	name->pushNeighbor(mit->first,"");
	    LOG(BF("Getting equivalent names") );
	    adapt::SymbolSet_sp ss = mit->second->getMonomerNames();
	    LOG(BF("There are %d equivalent names") % ss->size() );
//	ASSERTP(ss->size()!=0,"Problem, there are no equivalent names");
	    if ( ss->size() == 0 )
	    {
		ss = adapt::StringSet_O::create();
		ss->insert(_lisp->intern("undef"));
	    }
	    for (adapt::SymbolSet_O::iterator it=ss->begin(); it!=ss->end(); it++ ) 
	    {
		name->setLastNeighborName(*it);
		LOG(BF("Pushed equivalent name: %s") % (*it)->__repr__() );
		mitNext = mit;
		mitNext++;
		this->expandOutsSpecificContexts(mitNext, list, name );
	    }
	    name->popNeighbor();
	}
#endif
    }




    void	MonomerContext_O::expandOuts(NeighborMap::iterator mit,
					     adapt::StringSet_sp list,
					     MCStringStack& name )
    {_G();
	IMPLEMENT_ME(); // work with new symbol based names
#if 0
	adapt::SymbolSet_O::iterator	it;
	adapt::SymbolSet_sp		ss;
	NeighborMap::iterator mitNext;
	if ( mit==this->_Neighbors.end() ) {
	    LOG(BF("Pushing back name: %s") % name.all().c_str()  );
	    list->insert(name.all());
	} else {
	    LOG(BF("We have neighbors") );
	    name.push(mit->first->symbolNameAsString());
	    name.push(COUPLING_CHAR);
	    LOG(BF("Getting equivalent names") );
	    ss = mit->second->getMonomerNames();
	    LOG(BF("There are %d equivalent names") % ss->size() );
//	ASSERTP(ss->size()!=0,"Problem, there are no equivalent names");
	    if ( ss->size() == 0 )
	    {
		ss = adapt::StringSet_O::create();
		ss->insert(_lisp->intern("undef"));
	    }
	    for ( it=ss->begin(); it!=ss->end(); it++ ) {
		name.push("[");
		name.push((*it)->symbolNameAsString());
		name.push("]");
		LOG(BF("Pushed equivalent name: %s") % (*it)->__repr__() );
		mitNext = mit;
		mitNext++;
		this->expandOuts(mitNext, list, name );
		name.pop();
		name.pop();
		name.pop();
	    }
	    name.pop();
	    name.pop();
	}
#endif
    }


CL_LISPIFY_NAME("getKey");
CL_DEFMETHOD core::Symbol_sp MonomerContext_O::getKey()
    {_G();
	stringstream	ss, si, so;
	NeighborMap::iterator	ci;
	ss << "!"
	   << core::_rep_(this->_Self->getKey());
	for ( ci=this->_Neighbors.begin(); ci!=this->_Neighbors.end(); ci++ ) {
	    ss << ci->first->symbolNameAsString() << COUPLING_CHAR << _rep_(ci->second->getKey());
	}
        core::Symbol_sp keyAsSymbol = chemkw_intern(ss.str());
	return keyAsSymbol;
    }




CL_LISPIFY_NAME("getAllSpecificKeys");
CL_DEFMETHOD     adapt::SymbolSet_sp	MonomerContext_O::getAllSpecificKeys()
    {_G();
	adapt::SymbolSet_sp	expandedList;
	adapt::SymbolSet_sp	selfNames;
	MCStringStack	name;
	LOG(BF("Getting context strings for context: %s") % this->asXmlString().c_str()  );
	expandedList = adapt::StringSet_O::create();
	name.clear();
	selfNames = this->_Self->getMonomerNames();
	LOG(BF("There are %d selfNames") % selfNames->size()  );
	selfNames->map( [&name,this,&expandedList] (core::Symbol_sp si) {
	    LOG(BF("Push self name: %s") % (*si)->__repr__() );
	    name.push("![");
	    name.push((si)->symbolNameAsString());
	    name.push("]");
	    this->expandOuts(this->_Neighbors.begin(), expandedList, name );
	    name.pop();
	    name.pop();
	    name.pop();
          });
	return expandedList;
    }

CL_LISPIFY_NAME("getAllSpecificContexts");
CL_DEFMETHOD     SpecificContextSet_sp MonomerContext_O::getAllSpecificContexts()
    {_G();
	adapt::SymbolSet_sp	selfNames;
	LOG(BF("Getting context strings for context: %s") % this->asXmlString().c_str()  );
	SpecificContextSet_sp expandedList = SpecificContextSet_O::create();
	SpecificContext_sp one = SpecificContext_O::create();
	one->clear();
	selfNames = this->_Self->getMonomerNames();
	LOG(BF("There are %d selfNames") % selfNames->size()  );
	selfNames->map( [&one,this,&expandedList] (core::Symbol_sp si) {
	    LOG(BF("Push self name: %s") % (si)->__repr__() );
	    one->setSelfName(si);
	    this->expandOutsSpecificContexts(this->_Neighbors.begin(), expandedList, one );
          } );
	return expandedList;
    }





core::Symbol_sp MonomerContext_O::getFirstSpecificKey()
    {_G();
	adapt::StringSet_sp	selfNames;
	adapt::StringSet_sp	inNames;
	adapt::StringSet_sp	outNames;
	MCStringStack	name;
	adapt::StringSet_sp	expandedList;
	adapt::StringSet_O::iterator	si, ii;
	string		res;
	expandedList = adapt::StringSet_O::create();
	expandedList = this->getAllSpecificKeys();
	res = *(expandedList->begin());
//RETURN:
	LOG(BF("Returning") );
        return chemkw_intern(res);
    }





/*! Return true if this monomerContext recognizes a superset of the
 * contexts that testSub recognizes.
 */
    bool	MonomerContext_O::containsMonomerContext(MonomerContext_sp testSub)
    {_G();
	EntityNameSetBase_sp			testSubRecognizer;
	adapt::SymbolSet_sp				monomerNames;
	if ( !this->_Self->recognizesNameOrPdb(
		 testSub->_Self->getMonomerNames()->first()) ) {
	    LOG(BF("MonomerContext doesn't recognize self") );
	    return false;
	}
	if ( this->_Neighbors.size() != testSub->_Neighbors.size() ) {
	    LOG(BF("MonomerContexts have different number of neighbors") );
	    return false;
	}
	for ( auto ti = this->_Neighbors.begin();
	      ti != this->_Neighbors.end(); ti++ ) 
	{
	    if ( !testSub->_Neighbors.contains(ti->first) ) {
		LOG(BF("testSub doesn't have a neighbor: %s") % ti->first->__repr__()  );
		return false;
	    }
	    testSubRecognizer = testSub->_Neighbors.get(ti->first);
	    adapt::SymbolSet_sp myNames = ti->second->getMonomerNames();
	    adapt::SymbolSet_sp testSubNames = testSubRecognizer->getMonomerNames();
	    if ( !myNames->containsSubset(testSubNames) )
	    {
		LOG(BF("testSub is not a subset of this monomer context") );
		LOG(BF("I recognize (%s)-> names: %s") % ti->first->__repr__() % myNames->asString()  );
		LOG(BF("testSub recognizes (%s)-> names: %s") % ti->first->__repr__() % testSubNames->asString() );
		return false;
	    }
	}
	LOG(BF("Yes, its a subset") );
	return true;
    }



CL_LISPIFY_NAME("recognizesMonomerAndEnvironment");
CL_DEFMETHOD     bool	MonomerContext_O::recognizesMonomerAndEnvironment(Monomer_sp mon)
    {_G();
      IMPLEMENT_MEF(BF("Handle new symbol names and monomer couplings are supposed to be a multimap!!!!!!"));
#if 0
	NeighborMap::iterator	ti;
	Coupling_sp			coup;
	if ( !this->_Self->recognizesNameOrPdb(mon->getName() )) {
	    LOG(BF("MonomerContext doesn't recognize central monomer: %s") % (mon->getName()->__repr__() ));
	    return false;
	}
	LOG(BF("STATUS") );
	if ( this->_Neighbors.size() != mon->numberOfCouplings() ) {
	    LOG(BF("MonomerContexts have different number of couplings") );
	    return false;
	}
	LOG(BF("STATUS monomer = %s") % (mon->getName()->__repr__() ) );
	LOG(BF("Monomer has %d couplings") % (mon->numberOfCouplings() ) );
	LOG(BF("MonomerContext has %d neighbors") % (this->_Neighbors.size() ) );
	for ( auto oi=mon->begin_WeakCouplings(); oi!=mon->end_WeakCouplings(); oi++ )
	{
	    Coupling_sp coup = (oi->second);
	    if (coup.isA<DirectionalCoupling_O>() )
	    {
		DirectionalCoupling_sp dc = coup.as<DirectionalCoupling_O>();
		LOG(BF("Looking at dc->getName()= %s") % (dc->getName()->__repr__() ) );
		if ( !this->_Neighbors.contains(dc->getName()) )
		{
		    LOG(BF("MonomerContext doesn't recognize out.coupling=%s ") % dc->getName()->__repr__() );
		    return false;
		}
	    } else
	    {
		RingCoupling_sp rc = coup.as<RingCoupling_O>();
		LOG(BF("Ignoring out coupling for RingCoupling: %s") % rc->getName()->__repr__() );
	    }
	}
	return true;
#endif
    }



CL_LISPIFY_NAME("setFocusFromMonomer");
CL_DEFMETHOD     void	MonomerContext_O::setFocusFromMonomer(Monomer_sp mon)
    {_G();
	EntityNameSet_sp	ss;
	ss = EntityNameSet_O::create();
	LOG(BF("status") );
	ss->setMonomerNameOrPdb(mon->getName());
	LOG(BF("status") );
	this->_Self = ss;
    }


CL_LISPIFY_NAME("getPlugNames");
CL_DEFMETHOD     adapt::SymbolSet_sp MonomerContext_O::getPlugNames() const
    {_OF();
	adapt::SymbolSet_sp names = adapt::SymbolSet_O::create();
	for ( NeighborMap::const_iterator it=this->_Neighbors.begin();
	      it!=this->_Neighbors.end(); it++ )
	{
	    names->insert(it->first);
	}
	return names;
    }


CL_LISPIFY_NAME("getNeighbor");
CL_DEFMETHOD     EntityNameSetBase_sp MonomerContext_O::getNeighbor(core::Symbol_sp name) const
    {_OF();
	if ( this->_Neighbors.count(name) == 0 )
	{
	    SIMPLE_ERROR(BF("Unknown MonomerContext-plugName[%s]") % name->__repr__() );
	}
	return this->_Neighbors.get(name);
    }












    void MonomerContext_O::exposeCando(core::Lisp_sp lisp)
    {
	core::class_<MonomerContext_O>()
	    .def("setFocusFromMonomer", &MonomerContext_O::setFocusFromMonomer)
	    .def("getFocus", &MonomerContext_O::getFocus)
	    .def("setFocus", &MonomerContext_O::setFocus)
	    .def("addNeighbor", &MonomerContext_O::addNeighbor)
	    .def("getAllSpecificKeys", &MonomerContext_O::getAllSpecificKeys)
	    .def("getKey", &MonomerContext_O::getKey)
	    .def("getAllSpecificContexts", &MonomerContext_O::getAllSpecificContexts)
	    .def("recognizesMonomerAndEnvironment",&MonomerContext_O::recognizesMonomerAndEnvironment)
	    .def("getPlugNames",&MonomerContext_O::getPlugNames)
	    .def("getNeighbor",&MonomerContext_O::getNeighbor)
	    ;
    }

    void MonomerContext_O::exposePython(core::Lisp_sp lisp)
    {_G();
#ifdef	USEBOOSTPYTHON //[
	PYTHON_CLASS(ChemPkg,MonomerContext,"","",_lisp)
	.def("setFocusFromMonomer", &MonomerContext_O::setFocusFromMonomer)
	.def("getFocus", &MonomerContext_O::getFocus)
	.def("setFocus", &MonomerContext_O::setFocus)
	.def("addNeighbor", &MonomerContext_O::addNeighbor)
	.def("description", &MonomerContext_O::description)
	//	.def("getIn", &MonomerContext_O::boost_getIn)
	//	.def("setIn", &MonomerContext_O::setIn)
	//	.def("addOut", &MonomerContext_O::addOut)
	//	.def("getOuts", &MonomerContext_O::boost_getOuts)
	.def("getAllSpecificKeys", &MonomerContext_O::getAllSpecificKeys)
	.def("getAllSpecificContexts", &MonomerContext_O::getAllSpecificContexts)
	.def("getKey", &MonomerContext_O::getKey)
	.def("recognizesMonomerAndEnvironment",&MonomerContext_O::recognizesMonomerAndEnvironment)
	;

//    boost::python::def("create_MonomerContext",&create_MonomerContext1);
//    boost::python::def("create_MonomerContext",&create_MonomerContext2);
#endif //]
}

    EXPOSE_CLASS(chem, MonomerContext_O );
};

