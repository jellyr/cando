#define	DEBUG_LEVEL_FULL


//
// (C) 2004 Christian E. Schafmeister
//


#include <string>
#include <clasp/core/common.h>
#include <cando/adapt/stringSet.h>
#include <clasp/core/environment.h>
//#include "core/archiveNode.h"
#include <cando/adapt/stringList.h>
#include <cando/adapt/adapters.h>
#include <cando/adapt/symbolList.h>
//#include "core/archive.h"
#include <cando/chem/entityNameSet.h>
#include <cando/chem/candoDatabase.h>
#include <cando/chem/alias.h>
#include <clasp/core/wrappers.h>



#define	IN_CHAR		"-"
#define	OUT_CHAR	"+"
#define	COUPLING_CHAR	"."


namespace chem
{





    EntityNameSetBase_sp EntityNameSetBase_O::create2(core::Symbol_sp nm)
    {
	EntityNameSetBase_sp	rec;
	rec = EntityNameSetBase_O::create();
	rec->setMonomerNameOrPdb(nm);
	return rec;
    }





    void	EntityNameSetBase_O::initialize()
    {
	this->Base::initialize();
	this->_EntityNames = adapt::SymbolSet_O::create();
	this->_Optional = false;
    };

CL_LISPIFY_NAME("getUnExpandedNames");
CL_DEFMETHOD     adapt::SymbolSet_sp	EntityNameSetBase_O::getUnExpandedNames()
    {
	return this->_EntityNames;
    }

#if INIT_TO_FACTORIES

#define ARGS_EntityNameSetBase_O_make "(entity_names_cons)"
#define DECL_EntityNameSetBase_O_make ""
#define DOCS_EntityNameSetBase_O_make "make EntityNameSetBase"
  EntityNameSetBase_sp EntityNameSetBase_O::make(core::List_sp entityNamesCons)
  {_G();
      GC_ALLOCATE(EntityNameSetBase_O, me );
    if ( entityNamesCons.notnilp() )
      {
	  adapt::SymbolSet_sp entityNames = adapt::SymbolSet_O::create();
	entityNames->insertConsSymbols(entityNamesCons);
	me->_EntityNames = entityNames;
      }
    return me;
  };

#else

    core::T_sp EntityNameSetBase_O::__init__(core::Function_sp exec, core::Cons_sp args, core::Environment_sp environ, core::Lisp_sp lisp)
    {_OF();
	core::List_sp entityNamesCons = translate::from_object<core::List_V>::convert(environ->lookup(Pkg(),"entityNames"));
	if ( entityNamesCons.notnilp() )
	{
	    adapt::SymbolSet_sp entityNames = adapt::SymbolSet_O::create();
	    entityNames->insertConsSymbols(entityNamesCons);
	    this->_EntityNames = entityNames;
	}
	// Do nothing
	return _Nil<core::T_O>();
    }

#endif

    string EntityNameSetBase_O::description() const
    {
	stringstream ss;
	ss << "EntityNameSetBase@"<< std::hex << this;
	ss << " contains:(" << this->_EntityNames->asString() << ")";
	return ss.str();
    }

    EntityNameSetBase_O::EntityNameSetBase_O( const EntityNameSetBase_O& emr ) : Base(emr)
    {
	this->_Optional = emr._Optional;
	GC_COPY(adapt::SymbolSet_O, symset , *emr._EntityNames); // = RP_Copy<adapt::SymbolSet_O>(emr._EntityNames);
	this->_EntityNames = symset;
    }





    adapt::SymbolList_sp EntityNameSetBase_O::getInterestingAtomAliases()
    {
	return _Nil<adapt::SymbolList_O>();
    }


CL_LISPIFY_NAME("getInterestingAtomAliasIndex");
CL_DEFMETHOD     int	EntityNameSetBase_O::getInterestingAtomAliasIndex(Alias_sp alias)
    {_G();
	SIMPLE_ERROR(BF("Subclass must implement for alias: "+alias->__repr__()));
    }

#if 0
    void	EntityNameSetBase_O::setCandoDatabase( CandoDatabase_sp bdb)
    {_G();
	this->CandoDatabase_ODependent::setCandoDatabase(bdb);
    }
#endif





CL_LISPIFY_NAME("expandedNameSet");
CL_DEFMETHOD     adapt::SymbolSet_sp	EntityNameSetBase_O::expandedNameSet()
    {_G();
	adapt::SymbolSet_sp		allNames;
	CandoDatabase_sp	bdb;
	allNames = adapt::SymbolSet_O::create();
	bdb = getCandoDatabase();
        this->_EntityNames->map([&bdb,&allNames] (core::Symbol_sp key) {
	    Entity_sp entity = bdb->getEntity(key);
            adapt::SymbolSet_sp names = entity->expandedNameSet();
	    allNames->insertSymbolSet(names);
          } );
	return allNames;
    }



CL_LISPIFY_NAME("expandToTerminalEntityNames");
CL_DEFMETHOD     void EntityNameSetBase_O::expandToTerminalEntityNames()
    {_OF();
	adapt::SymbolSet_sp expandedEntityNames = this->expandedNameSet();
	this->_EntityNames = expandedEntityNames;
    }


CL_LISPIFY_NAME("contractEntityNames");
CL_DEFMETHOD     void EntityNameSetBase_O::contractEntityNames(adapt::SymbolSet_sp entityNames)
    {_OF();
	adapt::SymbolSet_sp myExpanded = this->expandedNameSet();
	CandoDatabase_sp cdb = getCandoDatabase();
        entityNames->map([&cdb,&myExpanded] (core::Symbol_sp it) {
	    core::Symbol_sp otherName = (it);
	    EntityNameSetBase_sp other = cdb->getEntity(otherName).as<EntityNameSetBase_O>();
	    adapt::SymbolSet_sp otherExpanded = other->expandedNameSet();
	    if ( myExpanded->containsSubset(otherExpanded) )
	    {
		myExpanded = myExpanded->relativeComplement(otherExpanded);
		myExpanded->insert(otherName);
	    }
          } );
	this->_EntityNames = myExpanded;
    }


    void EntityNameSetBase_O::mergeEntityNames(Entity_sp other)
    {_OF();
	adapt::SymbolSet_sp os = other->expandedNameSet();
	this->_EntityNames->insertSymbolSet(os);
    }




    RepresentativeList_sp	EntityNameSetBase_O::expandedRepresentativeList() const
    {
      RepresentativeList_sp		allRepresentatives;
      CandoDatabase_sp	bdb;
      allRepresentatives = RepresentativeList_O::create();
      bdb = getCandoDatabase();
      this->_EntityNames->map( [&bdb,&allRepresentatives] (core::Symbol_sp ni) {
          ASSERT(bdb->recognizesEntityName(ni));
          Entity_sp entity = bdb->getEntity(ni);
          RepresentativeList_sp objs = entity->expandedRepresentativeList();
          LOG(BF("Expanded representative list for entity[%s] is: %s") % entity->__repr__()
              % objs->__repr__() );
          allRepresentatives->vectorPushExtend(objs);
        } );
      return allRepresentatives;
    }





#if 0
    void	EntityNameSetBase_O::_insertStringSet(adapt::StringSet_sp ss)
    {_G();
	adapt::StringSet_O::iterator	si;
	CandoDatabase_sp	bdb;
	ASSERTNOTNULL(this->_EntityNames);
	bdb = getCandoDatabase();
	for ( si=ss->begin(); si!=ss->end(); si++ )
	{
	    if ( !bdb->recognizesMonomerName(*si) )
	    {
		this->_StatusTracker->addError("Tried to add unknown monomer name: "+*si);
	    } else {
		this->_EntityNames->insert(*si);
	    }
	}
    }
#endif




CL_LISPIFY_NAME("addMonomerName");
CL_DEFMETHOD     void	EntityNameSetBase_O::addMonomerName(core::Symbol_sp nm)
    {_G();
	CandoDatabase_sp	bdb;
	adapt::StringSet_sp		monomerNames;
	ASSERTNOTNULL(this->_EntityNames);
	if ( this->recognizesMonomerName(nm) ) return;
	bdb = getCandoDatabase();
	if ( !bdb->recognizesEntityName(nm) )
	{
	    SIMPLE_ERROR(BF("Unknown monomer name: "+nm->__repr__()));
	}
	this->_EntityNames->insert(nm);
    }


CL_LISPIFY_NAME("setGroupNames");
CL_DEFMETHOD     void	EntityNameSetBase_O::setGroupNames(adapt::SymbolSet_sp s)
    {
	this->_EntityNames = s;
    }


CL_LISPIFY_NAME("addMonomerNameNoChecks");
CL_DEFMETHOD     void	EntityNameSetBase_O::addMonomerNameNoChecks(core::Symbol_sp nm)
    {_G();
	ASSERTNOTNULL(this->_EntityNames);
	this->_EntityNames->insert(nm);
    }

    void EntityNameSetBase_O::_clear()
    {_OF();
	this->_EntityNames->clear();
    };


    void	EntityNameSetBase_O::_removeMonomerName(core::Symbol_sp nm)
    {_G();
	ASSERTNOTNULL(this->_EntityNames);
	if ( !this->recognizesMonomerName(nm) ) return;
	this->_EntityNames->remove(nm);
    }

#if 0
    adapt::StringSet_sp	EntityNameSetBase_O::combineMonomerNames(string coupling, EntityNameSetBase_sp e )
    {_G();
	adapt::SymbolSet_sp	s1, s2, s3;
	string		ins;
	s1 = this->getMonomerNames();
	s2 = e->getMonomerNames();
	ins = "="+coupling+IN_CHAR;
	s3 = s1->cartesianProductInsert(ins,s2);
	return s3;
    }
#endif


core::Symbol_sp EntityNameSetBase_O::getKey()
    {_G();
	stringstream			ss;
	set<string>			keys;
	set<string>::iterator		ki;
	bool 				first;
	adapt::SymbolSet_sp		expanded;
	ss << "[";
	keys.clear();
	expanded = this->expandedNameSet();
	ASSERTF(expanded->size()>0,
		BF("There must be at least one monomer name in the EntityNameSet"
		   " %s but it is completely empty")% this->description() );
        expanded->map( [&keys] (core::Symbol_sp si) {
	    keys.insert((si)->symbolNameAsString());
          } );
	first=true;
	for ( ki=keys.begin(); ki!=keys.end(); ki++ ) {
	    if ( first ) {
		first = false;
	    } else {
		ss << ",";
	    }
//	ss << "@" << *ki;
	    ss << *ki;
	}
	ss << "]";
	return chemkw_intern(ss.str());
    }




CL_LISPIFY_NAME("getMonomerNames");
CL_DEFMETHOD     adapt::SymbolSet_sp	EntityNameSetBase_O::getMonomerNames()
    {_G();
	adapt::SymbolSet_sp names;
	names = this->expandedNameSet();
	return names;
    }

CL_LISPIFY_NAME("getMonomerNamesAsString");
CL_DEFMETHOD     string	EntityNameSetBase_O::getMonomerNamesAsString()
    {_G();
	adapt::SymbolSet_sp names;
	names = this->expandedNameSet();
	return names->asString();
// OLD   return this->_MonomerNames->asString();
    }

CL_LISPIFY_NAME("getOnlyMonomerName");
CL_DEFMETHOD     core::Symbol_sp EntityNameSetBase_O::getOnlyMonomerName()
    {_G();
	adapt::SymbolSet_sp names;
	names = this->expandedNameSet();
	if ( names->size() != 1 ) {
	    SIMPLE_ERROR(BF("There must be only one equivalent name"));
	}
	return names->first();
    }



/*!	Set this EntityNameSetBase to recognize a single monomer
 */
CL_LISPIFY_NAME("setMonomerNameOrPdb");
CL_DEFMETHOD     void	EntityNameSetBase_O::setMonomerNameOrPdb(core::Symbol_sp mn)
    {_G();
	CandoDatabase_sp db;
//    this->setName(mn);
//    LOG(BF("Set name of EntityNameSetBase to: %s") % mn.c_str()  );
	if ( getCandoDatabase()->recognizesNameOrPdb(mn) ) {
	    db = getCandoDatabase();
	    LOG(BF("status") );
	    core::Symbol_sp full = db->getMonomerNameForNameOrPdb(mn);
	    this->_EntityNames->clear();
	    this->_EntityNames->insert(full);
	    LOG(BF("Added monomer name(%s) to EntityNameSetBase") % mn->__repr__()  );
	} else {
	    stringstream serr;
	    serr << "setMonomerNameOrPdb"
		 << " trying to add monomer but it isn't recognized: "
		 << mn->__repr__();
	    LOG(BF("%s") % serr.str() );
	}
    }




/*!	Return true if this EntityNameSetBase_sp
  recognizes the monomer name
*/
    bool	EntityNameSetBase_O::recognizesMonomerName(core::Symbol_sp nm)
    {_G();
	adapt::SymbolSet_sp		names;
	names = this->expandedNameSet();
	return names->contains(nm);
    }




/*!	Return true if this EntityNameSetBase_sp
  recognizes the monomer nameOrPdb
*/
CL_LISPIFY_NAME("recognizesNameOrPdb");
CL_DEFMETHOD     bool	EntityNameSetBase_O::recognizesNameOrPdb(core::Symbol_sp nm)
    {_G();
	CandoDatabase_sp	bdb;
	bdb = getCandoDatabase();
	ASSERT(bdb->recognizesNameOrPdb(nm));
	core::Symbol_sp name = bdb->getMonomerNameForNameOrPdb(nm);
	adapt::SymbolSet_sp names = this->expandedNameSet();
	return names->contains(name);
    }



#ifdef XML_ARCHIVE
    void	EntityNameSetBase_O::archiveBase(core::ArchiveP node)
    {_G();
	this->Base::archiveBase(node);
	node->attributeIfNotNil("names",this->_EntityNames);
	node->attributeIfNotDefault("optional",this->_Optional,false);
    }
#endif


CL_LISPIFY_NAME("getUnrecognizedMonomerNamesOrdered");
CL_DEFMETHOD     adapt::StringList_sp	EntityNameSetBase_O::getUnrecognizedMonomerNamesOrdered()
    {
	IMPLEMENT_ME();
#if 0
	adapt::StringList_sp	res, allNames;
	CandoDatabase_sp	bdb;
	adapt::StringList_O::iterator	sli;
	bdb = getCandoDatabase();
	allNames = bdb->allMonomerNamesOrdered();
	res = adapt::StringList_O::create();
	for(sli=allNames->begin();sli!=allNames->end();sli++ )
	{
	    if ( !this->_MonomerNames->contains(*sli) )
	    {
		res->append(*sli);
	    }
	}
	return res;
#endif
    }

CL_LISPIFY_NAME("hasInterestingAtomAlias");
CL_DEFMETHOD     bool EntityNameSetBase_O::hasInterestingAtomAlias(Alias_sp alias)
    {_G();
	LOG(BF("EntityNameSetBase_O always returns false") );
	return false;
    };


CL_LISPIFY_NAME("getMonomerNamesOrdered");
CL_DEFMETHOD     adapt::StringList_sp	EntityNameSetBase_O::getMonomerNamesOrdered()
    {
	IMPLEMENT_ME();
#if 0
	adapt::StringList_sp	res, allNames;
	CandoDatabase_sp	bdb;
	adapt::StringList_O::iterator	sli;
	bdb = getCandoDatabase();
	allNames = bdb->allMonomerNamesOrdered();
	res = adapt::StringList_O::create();
	for(sli=allNames->begin();sli!=allNames->end();sli++ )
	{
	    if ( this->_MonomerNames->contains(*sli) )
	    {
		res->append(*sli);
	    }
	}
	return res;
#endif
    }




    EntityNameSet_sp EntityNameSet_O::create2(core::Symbol_sp nm)
    {
	EntityNameSet_sp rec;
	rec = EntityNameSet_O::create();
	rec->setMonomerNameOrPdb(nm);
	return rec;
    }





    void	EntityNameSet_O::initialize()
    {_OF();
	this->Base::initialize();
	this->_Name = _lisp->intern("undefinedEntityNameSetName");
    };

#if INIT_TO_FACTORIES

#define ARGS_EntityNameSet_O_make "(name)"
#define DECL_EntityNameSet_O_make ""
#define DOCS_EntityNameSet_O_make "make EntityNameSet"
  EntityNameSet_sp EntityNameSet_O::make(core::Symbol_sp name)
  {_G();
      GC_ALLOCATE(EntityNameSet_O, me );
    me->_Name = name;
    return me;
  };

#else

    core::T_sp EntityNameSet_O::__init__(core::Function_sp exec, core::Cons_sp args, core::Environment_sp env, core::Lisp_sp lisp)
    {_OF();
	this->Base::__init__(exec,args,env,lisp);
	this->_Name = translate::from_object<core::Symbol_O>::convert(env->lookup(Pkg(),"name"));
	return _Nil<core::T_O>();
    }

#endif

    EntityNameSet_O::EntityNameSet_O( const EntityNameSet_O & emr ) : Base(emr)
    {_G();
	this->_Name = emr._Name;
    }



    string EntityNameSet_O::description() const
    {
	stringstream ss;
	ss << "EntityNameSet("<<this->_Name<<")@" << std::hex << this;
	ss << " contains:(" << this->_EntityNames->asString() << ")";
	return ss.str();
    }


#ifdef XML_ARCHIVE
    void	EntityNameSet_O::archiveBase(core::ArchiveP node)
    {_G();
	this->Base::archiveBase(node);
	node->attributeIfNotNil("name",this->_Name);
    }
#endif













    void EntityNameSetWithCap_O::initialize()
    {
	this->Base::initialize();
    }

    EntityNameSetWithCap_O::EntityNameSetWithCap_O(const EntityNameSetWithCap_O& emr ) : Base(emr)
    {
	
    }


#ifdef XML_ARCHIVE
    void	EntityNameSetWithCap_O::archiveBase(core::ArchiveP node)
    {_G();
	this->Base::archiveBase(node);
    }
#endif


    string EntityNameSetWithCap_O::description() const
    {
	stringstream ss;
	ss << this->className() << "[" << this->getName()->__repr__() << "]";
	return ss.str();
    }

CL_LISPIFY_NAME("addGroupName");
CL_DEFMETHOD     void	EntityNameSetWithCap_O::addGroupName(core::Symbol_sp nm)
    {_G();
	CandoDatabase_sp	bdb;
	adapt::StringSet_sp		monomerNames;
	this->addMonomerName(nm);
    }










    void EntityNameSetBase_O::exposeCando(core::Lisp_sp lisp)
    {
	core::class_<EntityNameSetBase_O>()
//	    .def_raw("core:__init__",&EntityNameSetBase_O::__init__,"(self &key entityNames optional)")
	    .def("expandToTerminalEntityNames",&EntityNameSetBase_O::expandToTerminalEntityNames)
	    .def("contractEntityNames",&EntityNameSetBase_O::contractEntityNames)
	    .def("setMonomerNameOrPdb", &EntityNameSetBase_O::setMonomerNameOrPdb)
	    .def("recognizesNameOrPdb",
		 &EntityNameSetBase_O::recognizesNameOrPdb)
//	.def("setNames", &EntityNameSetBase_O::python_setNames)
	    .def("getMonomerNames", &EntityNameSetBase_O::getMonomerNames)
	    .def("setGroupNames", &EntityNameSetBase_O::setGroupNames)
//    .def("setCandoDatabase", &EntityNameSetBase_O::setCandoDatabase)
	    .def("getOnlyMonomerName", &EntityNameSetBase_O::getOnlyMonomerName)
	    .def("getUnExpandedNames",&EntityNameSetBase_O::getUnExpandedNames)
	    .def("addMonomerName",&EntityNameSetBase_O::addMonomerName)
	    .def("addMonomerNameNoChecks",&EntityNameSetBase_O::addMonomerNameNoChecks)
	    .def("expandedNameSet", &EntityNameSetBase_O::expandedNameSet)
	    .def("getMonomerNamesAsString",
		 &EntityNameSetBase_O::getMonomerNamesAsString)
//    .def("combineMonomerNames",    &EntityNameSetBase_O::combineMonomerNames)
	    .def("getMonomerNameWithAtoms", &EntityNameSetBase_O::getMonomerNameWithAtoms)
	    .def("getMonomerNamesOrdered",
		 &EntityNameSetBase_O::getMonomerNamesOrdered)
	    .def("getUnrecognizedMonomerNamesOrdered",
		 &EntityNameSetBase_O::getUnrecognizedMonomerNamesOrdered)
	    .def("supportsInterestingAtomAliases",&EntityNameSetBase_O::supportsInterestingAtomAliases)
	    .def("hasInterestingAtomAlias",&EntityNameSetBase_O::hasInterestingAtomAlias)
	    .def("getInterestingAtomAliasIndex",&EntityNameSetBase_O::getInterestingAtomAliasIndex)
	    .def("getInterestingAtomAliasesAsString",&EntityNameSetBase_O::getInterestingAtomAliasesAsString)
	    .def("setInterestingAtomNamesForMonomerName",&EntityNameSetBase_O::setInterestingAtomNamesForMonomerName)
	    .def("getInterestingAtomNamesForMonomerName",&EntityNameSetBase_O::getInterestingAtomNamesForMonomerName)
	    .def("testEntityNameSetBase",&EntityNameSetBase_O::testEntityNameSetBase)
	    ;
    }

    void EntityNameSetBase_O::exposePython(core::Lisp_sp lisp)
    {_G();
#ifdef USEBOOSTPYTHON
	PYTHON_CLASS(ChemPkg,EntityNameSetBase,"","",_lisp)
	    .def("expandToTerminalEntityNames",&EntityNameSetBase_O::expandToTerminalEntityNames)
	    .def("contractEntityNames",&EntityNameSetBase_O::contractEntityNames)
	    .def("setMonomerNameOrPdb", &EntityNameSetBase_O::setMonomerNameOrPdb)
	    .def("recognizesNameOrPdb",
		 &EntityNameSetBase_O::recognizesNameOrPdb)
//	.def("setNames", &EntityNameSetBase_O::python_setNames)
	    .def("getMonomerNames", &EntityNameSetBase_O::getMonomerNames)
	    .def("setGroupNames", &EntityNameSetBase_O::setGroupNames)
//    .def("setCandoDatabase", &EntityNameSetBase_O::setCandoDatabase)
	    .def("getOnlyMonomerName", &EntityNameSetBase_O::getOnlyMonomerName)
	    .def("getUnExpandedNames",&EntityNameSetBase_O::getUnExpandedNames)
	    .def("addMonomerName",&EntityNameSetBase_O::addMonomerName)
	    .def("addMonomerNameNoChecks",&EntityNameSetBase_O::addMonomerNameNoChecks)
	    .def("expandedNameSet", &EntityNameSetBase_O::expandedNameSet)
	    .def("getMonomerNamesAsString",
		 &EntityNameSetBase_O::getMonomerNamesAsString)
//    .def("combineMonomerNames",    &EntityNameSetBase_O::combineMonomerNames)
	    .def("getMonomerNameWithAtoms", &EntityNameSetBase_O::getMonomerNameWithAtoms)
	    .def("getMonomerNamesOrdered",
		 &EntityNameSetBase_O::getMonomerNamesOrdered)
	    .def("getUnrecognizedMonomerNamesOrdered",
		 &EntityNameSetBase_O::getUnrecognizedMonomerNamesOrdered)
	    .def("supportsInterestingAtomAliases",&EntityNameSetBase_O::supportsInterestingAtomAliases)
	    .def("hasInterestingAtomAlias",&EntityNameSetBase_O::hasInterestingAtomAlias)
	    .def("getInterestingAtomAliasIndex",&EntityNameSetBase_O::getInterestingAtomAliasIndex)
	    .def("getInterestingAtomAliasesAsString",&EntityNameSetBase_O::getInterestingAtomAliasesAsString)
	    .def("setInterestingAtomNamesForMonomerName",&EntityNameSetBase_O::setInterestingAtomNamesForMonomerName)
	    .def("getInterestingAtomNamesForMonomerName",&EntityNameSetBase_O::getInterestingAtomNamesForMonomerName)
	    .def("testEntityNameSetBase",&EntityNameSetBase_O::testEntityNameSetBase)
	    ;
#endif
    }




    void EntityNameSet_O::exposeCando(core::Lisp_sp lisp)
    {
	core::class_<EntityNameSet_O>()
//	    .def_raw("core:__init__",&EntityNameSet_O::__init__,"(self &key name entityNames optional)") // added name argument to those of EntityNameSetBase_O
	    .def("setName", &EntityNameSet_O::setName,"","","",false)
	    .def("getName", &EntityNameSet_O::getName,"","","",false)
	    ;
    }

    void EntityNameSet_O::exposePython(core::Lisp_sp lisp)
    {_G();
#ifdef USEBOOSTPYTHON
	PYTHON_CLASS(ChemPkg,EntityNameSet,"","",_lisp)
	    .def("setName", &EntityNameSet_O::setName)
	    .def("getName", &EntityNameSet_O::getName)
	    ;
#endif
    }








    void EntityNameSetWithCap_O::exposeCando(core::Lisp_sp lisp)
    {
	core::class_<EntityNameSetWithCap_O>()
//	    .def_raw("core:__init__",&EntityNameSetWithCap_O::__init__,"(self &key entityNames optional)")
	    .def("addGroupName",&EntityNameSetWithCap_O::addGroupName)
	    ;
    }

    void EntityNameSetWithCap_O::exposePython(core::Lisp_sp lisp)
    {_G();
#ifdef USEBOOSTPYTHON
	PYTHON_CLASS(ChemPkg,EntityNameSetWithCap,"","",_lisp)
	    .def("addGroupName",&EntityNameSetWithCap_O::addGroupName)
	    ;
#endif
    }

    EXPOSE_CLASS(chem,EntityNameSetBase_O);
    EXPOSE_CLASS(chem,EntityNameSet_O);
    EXPOSE_CLASS(chem,EntityNameSetWithCap_O);

}; //namespace chem
