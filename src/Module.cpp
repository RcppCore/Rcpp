// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// Module.cpp: Rcpp R/C++ interface class library -- Rcpp modules
//
// Copyright (C) 2010 - 2013 Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#include <Rcpp.h>
#include "internal.h"

#define MAX_ARGS 65

#define UNPACK_EXTERNAL_ARGS(__CARGS__,__P__)    \
SEXP __CARGS__[MAX_ARGS] ;                       \
int nargs = 0 ;                                  \
for(; nargs<MAX_ARGS; nargs++){                  \
	if( __P__ == R_NilValue ) break ;            \
	__CARGS__[nargs] = CAR(__P__) ;              \
	__P__ = CDR(__P__) ;                         \
}

typedef Rcpp::XPtr<Rcpp::Module> XP_Module ; 
typedef Rcpp::XPtr<Rcpp::class_Base> XP_Class ; 
typedef Rcpp::XPtr<Rcpp::CppFunction> XP_Function ; 


#define RCPP_FUN_1(__OUT__,__NAME__, ___0)        \
__OUT__ RCPP_DECORATE(__NAME__)(___0) ;               \
extern "C" SEXP __NAME__(SEXP x0){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0)


#define RCPP_FUN_2(__OUT__,__NAME__, ___0, ___1)        \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1)

#define RCPP_FUN_3(__OUT__,__NAME__, ___0, ___1, ___2)        \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2)

#define RCPP_FUN_4(__OUT__,__NAME__, ___0, ___1, ___2, ___3)        \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3)


RCPP_FUN_1( bool, Class__has_default_constructor, XP_Class cl ){
    return cl->has_default_constructor() ;
}
RCPP_FUN_2( SEXP, Module__get_function, XP_Module module, std::string fun ){
    return module->get_function( fun ) ;
}
RCPP_FUN_2( bool, Class__has_method, XP_Class cl, std::string m){
	return cl->has_method(m) ;
}
RCPP_FUN_2( bool, Class__has_property, XP_Class cl, std::string m){
	return cl->has_property(m) ;
}
RCPP_FUN_1( std::string, Class__name, XP_Class cl){
	return cl->name ;
}
RCPP_FUN_2( bool, Module__has_function, XP_Module module, std::string met ){
	return module->has_function( met ) ;
}
RCPP_FUN_2( bool, Module__has_class, XP_Module module, std::string cl ){
	return module->has_class( cl ) ;
}
RCPP_FUN_2( Rcpp::CppClass, Module__get_class, XP_Module module, std::string cl ){
	return module->get_class( cl ) ;
}
RCPP_FUN_1( bool, CppObject__needs_init, SEXP xp ){
	return EXTPTR_PTR(xp) == 0 ;
}
RCPP_FUN_1( Rcpp::CharacterVector, CppClass__methods, XP_Class cl){
	return cl->method_names() ;
}
RCPP_FUN_1( Rcpp::CharacterVector, CppClass__properties, XP_Class cl){
	return cl->property_names() ;
}
RCPP_FUN_1( Rcpp::List, CppClass__property_classes, XP_Class cl){
	return cl->property_classes() ;
}

RCPP_FUN_1( Rcpp::IntegerVector, CppClass__methods_arity, XP_Class cl){
	return cl->methods_arity() ;
}
RCPP_FUN_1( Rcpp::LogicalVector, CppClass__methods_voidness, XP_Class cl){
	return cl->methods_voidness() ;
}


RCPP_FUN_2( bool, CppClass__property_is_readonly, XP_Class cl, std::string p){
	return cl->property_is_readonly(p) ;
}
RCPP_FUN_2( std::string, CppClass__property_class, XP_Class cl, std::string p){
	return cl->property_class(p) ;
}

RCPP_FUN_1( Rcpp::IntegerVector, Module__functions_arity, XP_Module module ){
	return module->	functions_arity() ;
}
RCPP_FUN_1( Rcpp::CharacterVector, Module__functions_names, XP_Module module ){
	return module->	functions_names() ;
}
RCPP_FUN_1( std::string, Module__name, XP_Module module ){
	return module->name;
}
RCPP_FUN_1( Rcpp::List, Module__classes_info, XP_Module module ){
	return module->classes_info() ;
}
RCPP_FUN_1( Rcpp::CharacterVector, Module__complete, XP_Module module ){
	return module->complete() ;
}
RCPP_FUN_1( Rcpp::CharacterVector, CppClass__complete, XP_Class cl){
	return cl->complete(); 
}

// these operate directly on the external pointers, rather than 
// looking up the property in the map
RCPP_FUN_3(SEXP, CppField__get, XP_Class cl, SEXP field_xp, SEXP obj){
	return cl->getProperty( field_xp, obj ) ;
}
RCPP_FUN_4(SEXP, CppField__set, XP_Class cl, SEXP field_xp, SEXP obj, SEXP value){
	cl->setProperty( field_xp, obj, value ) ;
	return R_NilValue ;
}
RCPP_FUN_2(SEXP, CppObject__finalize, XP_Class cl, SEXP obj){
	cl->run_finalizer( obj ) ;
	return R_NilValue ;
}

// .External functions
extern "C" SEXP InternalFunction_invoke( SEXP args ){
BEGIN_RCPP
	SEXP p = CDR(args) ;
	XP_Function fun( CAR(p) ) ; p = CDR(p) ;
	UNPACK_EXTERNAL_ARGS(cargs,p)
	return fun->operator()( cargs ) ;
END_RCPP
}

extern "C" SEXP Module__invoke( SEXP args){
BEGIN_RCPP
	SEXP p = CDR(args) ;
	XP_Module module( CAR(p) ) ; p = CDR(p) ;
	std::string fun = Rcpp::as<std::string>( CAR(p) ) ; p = CDR(p) ;
	
	UNPACK_EXTERNAL_ARGS(cargs,p)
	return module->invoke( fun, cargs, nargs ) ;
END_RCPP
}

extern "C" SEXP class__newInstance(SEXP args){
	SEXP p = CDR(args) ;
	
	XP_Module module( CAR(p) ) ; p = CDR(p) ;
	XP_Class clazz( CAR(p) ) ; p = CDR(p);
	UNPACK_EXTERNAL_ARGS(cargs,p)
	return clazz->newInstance(cargs, nargs ) ;
}

SEXP rcpp_dummy_pointer = R_NilValue; // relies on being set in .onLoad()

#define CHECK_DUMMY_OBJ(p) if(p == rcpp_dummy_pointer) forward_exception_to_r ( Rcpp::not_initialized())
	


extern "C" SEXP class__dummyInstance(SEXP args) {
	SEXP p;

	if(args == R_NilValue)
		return rcpp_dummy_pointer;
	p  = CDR(args);

	if(p != R_NilValue)
		rcpp_dummy_pointer = CAR(p);
	return rcpp_dummy_pointer;
}

extern "C" SEXP CppMethod__invoke(SEXP args){
	SEXP p = CDR(args) ;
	
	// the external pointer to the class
	XP_Class clazz( CAR(p) ) ; p = CDR(p);
	
	// the external pointer to the method
	SEXP met = CAR(p) ; p = CDR(p) ;
	
	// the external pointer to the object
	SEXP obj = CAR(p); p = CDR(p) ;
	CHECK_DUMMY_OBJ(obj);
	
	// additional arguments, processed the same way as .Call does
	UNPACK_EXTERNAL_ARGS(cargs,p)
	
   	return clazz->invoke( met, obj, cargs, nargs ) ;
}

extern "C" SEXP CppMethod__invoke_void(SEXP args){
	SEXP p = CDR(args) ;
	
	// the external pointer to the class
	XP_Class clazz( CAR(p) ) ; p = CDR(p);
	
	// the external pointer to the method
	SEXP met = CAR(p) ; p = CDR(p) ;
	
	// the external pointer to the object
	SEXP obj = CAR(p); p = CDR(p) ;
	CHECK_DUMMY_OBJ(obj);
	
	// additional arguments, processed the same way as .Call does
	UNPACK_EXTERNAL_ARGS(cargs,p)
	clazz->invoke_void( met, obj, cargs, nargs ) ;
   	return R_NilValue ;
}

extern "C" SEXP CppMethod__invoke_notvoid(SEXP args){
	SEXP p = CDR(args) ;
	
	// the external pointer to the class
	XP_Class clazz( CAR(p) ) ; p = CDR(p);
	
	// the external pointer to the method
	SEXP met = CAR(p) ; p = CDR(p) ;
	
	// the external pointer to the object
	SEXP obj = CAR(p); p = CDR(p) ;
	CHECK_DUMMY_OBJ(obj);
	
	// additional arguments, processed the same way as .Call does
	UNPACK_EXTERNAL_ARGS(cargs,p)
	
   	return clazz->invoke_notvoid( met, obj, cargs, nargs ) ;
}


namespace Rcpp{
	static Module* current_scope  ;
}

Rcpp::Module* getCurrentScope(){ return Rcpp::current_scope ; }
void setCurrentScope( Rcpp::Module* scope ){ Rcpp::current_scope = scope ; }
extern "C" void R_init_Rcpp( DllInfo* info){
	Rcpp::current_scope = 0 ;
	
	// init the cache
	init_Rcpp_cache() ;
	
	// init routines
	init_Rcpp_routines(info) ;
}

namespace Rcpp{
	
	Module::Module() : name(), functions(), classes(), prefix() {}
	Module::Module(const char* name_) : name(name_), functions(), classes(), prefix("Rcpp_module_") {
	    prefix += name ;
	}
	
	SEXP Module::invoke( const std::string& name_, SEXP* args, int nargs){
		MAP::iterator it = functions.find( name_ );
		if( it == functions.end() ){
			throw std::range_error( "no such function" ) ; 
		}
		CppFunction* fun = it->second ;
		if( fun->nargs() > nargs ){
			throw std::range_error( "incorrect number of arguments" ) ; 	
		}
		 
		return Rcpp::List::create( 
			Rcpp::Named("result") = fun->operator()( args ), 
			Rcpp::Named("void")   = fun->is_void() 
		) ;
	}                                                                                  
	
	SEXP Module::get_function( const std::string& name ){
	    MAP::iterator it = functions.begin() ;
	    int n = functions.size() ;
	    CppFunction* fun = 0 ;
	    for( int i=0; i<n; i++, ++it){
	        if( name.compare( it->first ) == 0){
	            fun = it->second ;
	            break ;
	        }
	    }
	    std::string sign ;
	    fun->signature( sign, name.data() ) ;
	    return Rcpp::List::create( 
	        Rcpp::XPtr<CppFunction>( fun, false ), 
	        fun->is_void(), 
	        fun->docstring, 
	        sign, 
	        fun->get_formals(), 
	        fun->nargs()
	        ) ;
	}
	
	DL_FUNC Module::get_function_ptr( const std::string& name ){
	    MAP::iterator it = functions.begin() ;
	    int n = functions.size() ;
	    CppFunction* fun = 0 ;
	    for( int i=0; i<n; i++, ++it){
	        if( name.compare( it->first ) == 0){
	            fun = it->second ;
	            break ;
	        }
	    }
	    return fun->get_function_ptr() ;
	}
	
	Rcpp::List Module::classes_info(){
		int n = classes.size() ;
		Rcpp::CharacterVector names(n) ;
		Rcpp::List info(n);
		CLASS_MAP::iterator it = classes.begin() ;
		std::string buffer ;
		for( int i=0; i<n; i++, ++it){
		    names[i] = it->first ;
			info[i]  = CppClass( this , it->second, buffer ) ;
		}
		info.names() = names ;
		return info ;
	}
	
	Rcpp::CharacterVector Module::class_names(){
		int n = classes.size() ;
		Rcpp::CharacterVector names( n );
		CLASS_MAP::iterator it = classes.begin() ;
		for( int i=0; i<n; i++, ++it){
			names[i] = it->first ;
		}
		return names ;
	}
	
	Rcpp::IntegerVector Module::functions_arity(){
		int n = functions.size() ;
		Rcpp::IntegerVector x( n ) ;
		Rcpp::CharacterVector names( n );
		MAP::iterator it = functions.begin() ;
		for( int i=0; i<n; i++, ++it){
			x[i] = (it->second)->nargs() ;
			names[i] = it->first ;
		}
		x.names() = names ;
		return x ;
	}
	
	Rcpp::CharacterVector Module::functions_names(){
		int n = functions.size() ;
		Rcpp::CharacterVector names( n );
		MAP::iterator it = functions.begin() ;
		for( int i=0; i<n; i++, ++it){
			names[i] = it->first ;
		}
		return names ;
	}
	
	Rcpp::CharacterVector Module::complete(){
		int nf = functions.size() ;
		int nc = classes.size() ;
		int n = nf + nc ;
		Rcpp::CharacterVector res( n ) ;
		int i=0;
		MAP::iterator it = functions.begin();
		std::string buffer ;
		for( ; i<nf; i++, ++it) {
			buffer = it->first ;
			if( (it->second)->nargs() == 0 ) {
				buffer += "() " ;
			} else {
				buffer += "( " ;
			}
			res[i] = buffer ;
		}
		CLASS_MAP::iterator cit = classes.begin() ;
		for( int j=0; j<nc; j++, i++, ++cit){
			res[i] = cit->first ;
		}
		return res ;
	}
	
	void Module::add_enum( const std::string& parent_class_typeinfo_name, const std::string& enum_name, const std::map<std::string, int>& value ){
	    // find the parent class
	    CLASS_ITERATOR it ;
	    class_Base* target_class = NULL;
	    for( it = classes.begin(); it != classes.end(); it++){
	        if( it->second->has_typeinfo_name(parent_class_typeinfo_name) ){
	            target_class = it->second ;
	        }
	    }
	    
	    // TODO: add the enum to the class
	    target_class->add_enum( enum_name, value ) ;
	}
	
	void class_Base::add_enum( const std::string& enum_name, const std::map<std::string, int>& value ){
	    enums.insert( ENUM_MAP_PAIR( enum_name, value ) ) ;
	}
    
	CppClass::CppClass( SEXP x) : S4(x){}
	
	CppClass::CppClass( const CppClass& other) : S4(other.asSexp()){}
	CppClass& CppClass::operator=( const CppClass& other){
	    setSEXP( other.asSexp() ) ;
	    return *this ;
	}
	
	CppClass::CppClass( Module* p, class_Base* cl, std::string& buffer ) : S4("C++Class") {
		XP_Class clxp( cl, false, R_NilValue, R_NilValue ) ;
		RCPP_DEBUG_2( "CppClass::CppClass( cl->name = %s ), clxp = <%p>", cl->name.c_str(), clxp.asSexp() ) ;
		#if RCPP_DEBUG_LEVEL > 0
		Rf_PrintValue( clxp ) ;
		#endif
		slot( "module"  ) = XP( p, false ) ;
		slot( "pointer" ) = clxp ;
		
		buffer = "Rcpp_" ;
		buffer += cl->name ;
		slot( ".Data" ) = buffer ;
		
		slot( "fields" )      = cl->fields( clxp ) ;
		
		slot( "methods" )     = cl->getMethods( clxp, buffer ) ;
		slot( "constructors") = cl->getConstructors( clxp, buffer ) ;
		slot( "docstring"   ) = cl->docstring ;
		slot( "typeid" )      = cl->get_typeinfo_name() ;
		slot( "enums"  )      = cl->enums ;
		slot( "parents" )     = cl->parents ;
	}

	CppObject::CppObject( Module* p, class_Base* clazz, SEXP xp ) : S4("C++Object") {
		slot( "module" )   = XP( p, false ) ;
		slot( "cppclass" ) = Rcpp::XPtr<class_Base>( clazz, false ) ;
		slot( "pointer" )  = xp ;
	}
	CppObject::CppObject( const CppObject& other) : S4(other.asSexp()){}
	CppObject& CppObject::operator=( const CppObject& other){
	    setSEXP( other.asSexp() ) ;
	    return *this ;
	}
	
	
	CppClass Module::get_class( const std::string& cl ){
		BEGIN_RCPP
			CLASS_MAP::iterator it = classes.find(cl) ;
			if( it == classes.end() ) throw std::range_error( "no such class" ) ;
			std::string buffer ;
			return CppClass( this, it->second, buffer ) ;
		END_RCPP
	}
	
	class_Base* Module::get_class_pointer(const std::string& cl){
        CLASS_MAP::iterator it = classes.find(cl) ;
        if( it == classes.end() ) throw std::range_error( "no such class" ) ;
        return it->second ;	
	}
	
	namespace internal{
	    void* as_module_object_internal(SEXP obj){
	        Environment env(obj) ;
	        SEXP xp = env.get(".pointer") ;
	        return R_ExternalPtrAddr(xp );
	    }
	    bool is_module_object_internal(SEXP obj, const char* clazz){
	        Environment env(obj) ;
	        XPtr<class_Base> xp( env.get(".cppclass") );
	        return xp->has_typeinfo_name( clazz ) ;
	    }
	}
	
	FunctionProxy GetCppCallable( const std::string& pkg, const std::string& mod, const std::string& fun){
        Rcpp::Function require = Rcpp::Environment::base_env()["require"];
        require(pkg, Rcpp::Named("quietly") = true);
        std::string pack( "Rcpp_module_" ) ;
        pack += mod ;
        return R_GetCCallable( pack.c_str(), fun.c_str() ) ;     
    }
	
}

