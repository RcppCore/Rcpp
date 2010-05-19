// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Module.h: Rcpp R/C++ interface class library -- Rcpp modules
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

#ifndef Rcpp_Module_h
#define Rcpp_Module_h

namespace Rcpp{

class CppFunction {
	public:
		CppFunction() {}
		virtual SEXP operator()(SEXP* args) { return R_NilValue ; } ;
		virtual ~CppFunction(){} ;
		virtual int nargs(){ return 0 ; }
		virtual bool is_void(){ return false ; }
};

#include <Rcpp/module/Module_generated_CppFunction.h>

#include <Rcpp/module/Module_generated_make_function.h>

class Module {
	public:    
		typedef std::map<std::string,CppFunction*> MAP ;
	
		Module() : name(), functions() {}
		Module(const char* name_) : name(name_), functions() {}
		      
		SEXP invoke( const std::string& name, SEXP* args, int nargs){
			MAP::iterator it = functions.find( name );
			if( it == functions.end() ){
				::Rf_error( "no such function" ) ;
			}
			CppFunction* fun = it->second ;
			if( fun->nargs() > nargs ){
				::Rf_error( "expecting %d arguments", fun->nargs() ) ;	
			}
			return Rcpp::List::create( 
				Rcpp::Named("result") = fun->operator()( args ), 
				Rcpp::Named("void")   = fun->is_void() 
			) ;
		}
		
		Rcpp::IntegerVector functions_arity() ;
		
		inline void Add( const char* name, CppFunction* ptr){
			functions.insert( std::pair<std::string,CppFunction*>( name, ptr ) ) ;
		}

		std::string name ;
		
	private:
		std::map<std::string,CppFunction*> functions ;
		           
};

extern Rcpp::Module* current_scope ;

#include <Rcpp/module/Module_generated_function.h>


}


#define RCPP_MODULE(name)                                            \
void _rcpp_module_##name##_init() ;                                  \
static Rcpp::Module _rcpp_module_##name( # name ) ;                  \
extern "C" SEXP _rcpp_module_boot_##name(){                          \
  ::Rcpp::current_scope =  & _rcpp_module_##name ;                   \
  _rcpp_module_##name##_init( ) ;                                    \
  Rcpp::XPtr<Rcpp::Module> mod_xp( & _rcpp_module_##name , false ) ; \
  ::Rcpp::current_scope =  0 ;                                       \
  return mod_xp ;                                                    \
}                                                                    \
void _rcpp_module_##name##_init()
  

#endif

