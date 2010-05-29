// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Module.cpp: Rcpp R/C++ interface class library -- Rcpp modules
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

#ifdef RCPP_ENABLE_MODULES

#define MAX_ARGS 65

typedef Rcpp::XPtr<Rcpp::Module> XP_Module ; 
typedef Rcpp::XPtr<Rcpp::class_Base> XP_Class ; 

RCPP_FUNCTION_2( bool, Class__has_method, XP_Class cl, std::string m){
	return cl->has_method(m) ;
}
RCPP_FUNCTION_1( std::string, Class__name, XP_Class cl){
	return cl->name ;
}

RCPP_FUNCTION_2( bool, Module__has_function, XP_Module module, std::string met ){
	return module->has_function( met ) ;
}
RCPP_FUNCTION_2( bool, Module__has_class, XP_Module module, std::string cl ){
	return module->has_class( cl ) ;
}
RCPP_FUNCTION_2( Rcpp::CppClass, Module__get_class, XP_Module module, std::string cl ){
	return module->get_class( cl ) ;
}

extern "C" SEXP Module__funtions_arity( SEXP mod_xp ){
	Rcpp::XPtr<Rcpp::Module> module(mod_xp) ;
	return module->	functions_arity() ;
}

extern "C" SEXP Module__name( SEXP mod_xp ){
	Rcpp::XPtr<Rcpp::Module> module(mod_xp) ;
	return Rcpp::wrap( module->name );
}

extern "C" SEXP Module__classes_info( SEXP mod_xp ){
	Rcpp::XPtr<Rcpp::Module> mod(mod_xp) ;
	return mod->classes_info() ;
}



// .External functions
extern "C" SEXP Module__invoke( SEXP args){
	SEXP p = CDR(args) ;
	XP_Module module( CAR(p) ) ; p = CDR(p) ;
	std::string fun = Rcpp::as<std::string>( CAR(p) ) ; p = CDR(p) ;
	
	SEXP cargs[MAX_ARGS] ;
    int nargs = 0 ;
   	for(; nargs<MAX_ARGS; nargs++){
   		if( p == R_NilValue ) break ;
   		cargs[nargs] = CAR(p) ;
   		p = CDR(p) ;
   	}
   	return module->invoke( fun, cargs, nargs ) ;
}

extern "C" SEXP class__newInstance(SEXP args){
	SEXP p = CDR(args) ;
	
	XP_Module module( CAR(p) ) ; p = CDR(p) ;
	XP_Class clazz( CAR(p) ) ; p = CDR(p);
	SEXP cargs[MAX_ARGS] ;
    int nargs = 0 ;
   	for(; nargs<MAX_ARGS; nargs++){
   		if( p == R_NilValue ) break ;
   		cargs[nargs] = CAR(p) ;
   		p = CDR(p) ;
   	}
   	return clazz->newInstance(cargs, nargs ) ;
}

extern "C" SEXP Class__invoke_method(SEXP args){
	SEXP p = CDR(args) ;
	
	XP_Class clazz( CAR(p) ) ; p = CDR(p);
	std::string met = Rcpp::as<std::string>( CAR(p) ) ; p = CDR(p) ;
	SEXP obj = CAR(p); p = CDR(p) ;
	
	SEXP cargs[MAX_ARGS] ;
    int nargs = 0 ;
   	for(; nargs<MAX_ARGS; nargs++){
   		if( p == R_NilValue ) break ;
   		cargs[nargs] = CAR(p) ;
   		p = CDR(p) ;
   	}
   	
   	return clazz->invoke( met, obj, cargs, nargs ) ;
}


namespace Rcpp{
	static Module* current_scope  ;
}

Rcpp::Module* getCurrentScope(){ return Rcpp::current_scope ; }
void setCurrentScope( Rcpp::Module* scope ){ Rcpp::current_scope = scope ; }
void R_init_Rcpp( DllInfo* info){
	Rcpp::current_scope = 0 ;
}

namespace Rcpp{
	
	Module::Module() : name(), functions(), classes() {}
	Module::Module(const char* name_) : name(name_), functions(), classes() {}
	
	SEXP Module::invoke( const std::string& name, SEXP* args, int nargs){
		BEGIN_RCPP
			MAP::iterator it = functions.find( name );
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
		END_RCPP
	}                                                                                  
	
	Rcpp::List Module::classes_info(){
		int n = classes.size() ;
		Rcpp::CharacterVector names(n) ;
		Rcpp::List info(n);
		CLASS_MAP::iterator it = classes.begin() ;
		for( int i=0; i<n; i++, ++it){
			names[i] = it->first ;
			info[i]  = CppClass( this , it->second ) ;
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
	
	CppClass::CppClass( SEXP x) : S4(x){}
	
	CppClass::CppClass( Module* p, class_Base* cl ) : S4("C++Class") {
		slot( "module"  ) = XP( p, false ) ;
		slot( "pointer" ) = XP_Class( cl ) ;
	}

	CppObject::CppObject( Module* p, class_Base* clazz, SEXP xp ) : S4("C++Object") {
		slot( "module" )   = XP( p, false ) ;
		slot( "cppclass" ) = Rcpp::XPtr<class_Base>( clazz, false ) ;
		slot( "pointer" )  = xp ;
	}
	
	CppClass Module::get_class( const std::string& cl ){
		BEGIN_RCPP
			CLASS_MAP::iterator it = classes.find(cl) ;
			if( it == classes.end() ) throw std::range_error( "no such class" ) ;
			return CppClass( this, it->second ) ;
		END_RCPP
	}
	
}

#else
/* quiet ranlib */ 
void dummy(){}
#endif

