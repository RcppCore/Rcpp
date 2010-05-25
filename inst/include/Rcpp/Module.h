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
   
#include <Rcpp/config.h>
#ifdef RCPP_ENABLE_MODULES

namespace Rcpp{

class CppFunction {
	public:
		CppFunction() {}
		virtual SEXP operator()(SEXP* args) { return R_NilValue ; } ;
		virtual ~CppFunction(){} ;
		virtual int nargs(){ return 0 ; }
		virtual bool is_void(){ return false ; }
};


// templates CppFunction0, ..., CppFunction65
#include <Rcpp/module/Module_generated_CppFunction.h>

// make_function factories
#include <Rcpp/module/Module_generated_make_function.h>

class class_Base {
public:
	class_Base(const char* name_) : name(name_){} ;
	
	virtual SEXP invoke( const std::string& method_name, SEXP *args, int nargs ) = 0 ;
	
private:
	std::string name ;
} ;

class Module {
	public:    
		typedef std::map<std::string,CppFunction*> MAP ;
		typedef std::pair<const std::string,CppFunction*> FUNCTION_PAIR ;
		
		typedef std::map<std::string,class_Base*> CLASS_MAP ;
		typedef std::pair<const std::string,class_Base*> CLASS_PAIR ;
	
		Module() : name(), functions() {}
		Module(const char* name_) : name(name_), functions(), classes() {}
		      
		SEXP invoke( const std::string& name, SEXP* args, int nargs){
			try{
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
			} catch( std::exception& __ex__ ){
				forward_exception_to_r( __ex__ ); 
			}
			return R_NilValue ; // -Wall
		}                                                                                  
		
		Rcpp::IntegerVector functions_arity() ;
		Rcpp::CharacterVector class_names() ;
		
		inline void Add( const char* name, CppFunction* ptr){
			functions.insert( FUNCTION_PAIR( name, ptr ) ) ;
		}
		
		inline void AddClass(const char* name, class_Base* cptr){
			classes.insert( CLASS_PAIR( name, cptr ) ) ;
		}

		std::string name ;
		
	private:
		MAP functions ;
		CLASS_MAP classes ;
		           
};

}
extern "C" Rcpp::Module* getCurrentScope() ;
extern "C" void setCurrentScope( Rcpp::Module* ) ;

namespace Rcpp{
	
template <typename Class>
class CppMethod {
	public:
		CppMethod() {}
		virtual SEXP operator()(SEXP* args) { return R_NilValue ; }
		virtual ~CppMethod(){}
		virtual int nargs(){ return 0 ; }
		virtual bool is_void(){ return false ; }
	
} ;

template <typename Class>
class class_ : public class_Base {
public:
	typedef class_ self ;
	typedef CppMethod<Class> method ;
	typedef std::map<std::string,method*> METHOD_MAP ;
	typedef std::pair<const std::string,method*> PAIR ;
	
	class_( const char* name_ ) : class_Base(name_), methods() {
		getCurrentScope()->AddClass( name_, this ) ;
	}
	
	SEXP invoke( const std::string& method_name, SEXP *args, int nargs ){ 
		BEGIN_RCPP
			typename METHOD_MAP::iterator it = methods.find( method_name ) ;
			if( it == methods.end() ){
				throw std::range_error( "no such method" ) ; 
			}
			method* met =  it->second ;
			if( met->nargs() > nargs ){
				throw std::range_error( "incorrect number of arguments" ) ; 	
			}
			return Rcpp::List::create( 
					Rcpp::Named("result") = met->operator()( args ), 
					Rcpp::Named("void")   = met->is_void() 
				) ;
		END_RCPP	
	}
	
	self& AddMethod( const char* name, method* m){
		methods.insert( PAIR( name,m ) ) ;  
		return *this ;
	}
	
private:
	METHOD_MAP methods ;
} ;

// function factories
#include <Rcpp/module/Module_generated_function.h>

}


#define RCPP_MODULE(name)                                            \
void _rcpp_module_##name##_init() ;                                  \
static Rcpp::Module _rcpp_module_##name( # name ) ;                  \
extern "C" SEXP _rcpp_module_boot_##name(){                          \
  ::setCurrentScope( & _rcpp_module_##name ) ;                   \
  _rcpp_module_##name##_init( ) ;                                    \
  Rcpp::XPtr<Rcpp::Module> mod_xp( & _rcpp_module_##name , false ) ; \
  ::setCurrentScope( 0 ) ;                                       \
  return mod_xp ;                                                    \
}                                                                    \
void _rcpp_module_##name##_init()
#endif  

#endif

