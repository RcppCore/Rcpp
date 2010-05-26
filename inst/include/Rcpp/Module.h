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

class CppClass ;
class CppObject ;

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
	class_Base() :name(){} ;
	class_Base(const char* name_) : name(name_){} ;
	
	virtual bool has_method( const std::string& m ){ return false ; }
	virtual SEXP newInstance(SEXP *args, int nargs){  return R_NilValue; }
	virtual SEXP invoke( const std::string& method_name, SEXP obj, SEXP *args, int nargs ){ 
		return R_NilValue ;
	}
	virtual ~class_Base(){}
	
	std::string name ;
} ;

class Module {
	public:    
		typedef std::map<std::string,CppFunction*> MAP ;
		typedef std::pair<const std::string,CppFunction*> FUNCTION_PAIR ;
		
		typedef std::map<std::string,class_Base*> CLASS_MAP ;
		typedef std::pair<const std::string,class_Base*> CLASS_PAIR ;
	
		Module()  ;
		Module(const char* name_)  ;
		      
		SEXP invoke( const std::string& name, SEXP* args, int nargs) ;                        
		SEXP newClassInstance( const std::string& clazz, SEXP* args, int nargs) ;                        
		SEXP invokeMethod( const std::string& clazz, const std::string& meth, SEXP obj, SEXP* args, int nargs ) ;
		
		Rcpp::IntegerVector functions_arity() ;
		Rcpp::CharacterVector class_names() ;
		Rcpp::List classes_info() ;
		
		inline void Add( const char* name, CppFunction* ptr){
			functions.insert( FUNCTION_PAIR( name, ptr ) ) ;
		}
		
		inline void AddClass(const char* name, class_Base* cptr){
			classes.insert( CLASS_PAIR( name, cptr ) ) ;
		}

		inline bool has_function( const std::string& m){
			return functions.find(m) != functions.end() ;
		}
		
		inline bool has_class( const std::string& m){
			return classes.find(m) != classes.end() ;
		}
		
		Rcpp::CppClass get_class(const std::string& ) ;
		
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
		typedef Rcpp::XPtr<Class> XP ;   
	
		CppMethod() {}
		virtual SEXP operator()(Class* object, SEXP* args) { return R_NilValue ; }
		virtual ~CppMethod(){}
		virtual int nargs(){ return 0 ; }
		virtual bool is_void(){ return false ; }
	
} ;

#include <Rcpp/module/Module_generated_CppMethod.h>


template <typename Class>
class class_ : public class_Base {
public:
	typedef class_<Class> self ;
	typedef CppMethod<Class> method_class ;
	typedef std::map<std::string,method_class*> METHOD_MAP ;
	typedef std::pair<const std::string,method_class*> PAIR ;
	typedef Rcpp::XPtr<Class> XP ;   
	
	class_( const char* name_ ) : class_Base(name_), methods() {
		if( !singleton ){
			singleton = new self ;
			singleton->name = name_ ;
			getCurrentScope()->AddClass( name_, singleton ) ;
		}
	}
	
	SEXP newInstance( SEXP* args, int nargs ){
		SEXP out = XP( new Class, true ) ;
		return out ;
	}
	
	SEXP invoke( const std::string& method_name, SEXP object, SEXP *args, int nargs ){ 
		BEGIN_RCPP
		typename METHOD_MAP::iterator it = methods.find( method_name ) ;
		if( it == methods.end() ){
			throw std::range_error( "no such method" ) ; 
		}
		method_class* met =  it->second ;
		if( met->nargs() > nargs ){
			throw std::range_error( "incorrect number of arguments" ) ; 	
		}
		return Rcpp::List::create( 
				Rcpp::Named("result") = met->operator()( XP(object), args ), 
				Rcpp::Named("void")   = met->is_void() 
			) ;
		END_RCPP	
	}
	
	self& AddMethod( const char* name, method_class* m){
		singleton->methods.insert( PAIR( name,m ) ) ;  
		return *this ;
	}

#include <Rcpp/module/Module_generated_method.h>
		
	inline bool has_method( const std::string& m){
		return methods.find(m) != methods.end() ;
	}
	
private:
	METHOD_MAP methods ;
	static self* singleton ;
	
	class_( ) : class_Base(), methods(){}; 
	
} ;   

template <typename Class> 
class_<Class>* class_<Class>::singleton ;


// function factories
#include <Rcpp/module/Module_generated_function.h>

class CppClass : public S4{
public:
	typedef Rcpp::XPtr<Rcpp::Module> XP ;
	CppClass( Module* p, const std::string& name ) ;
} ;

class CppObject : public S4{
public:
	typedef Rcpp::XPtr<Rcpp::Module> XP ;
	CppObject( Module* p, class_Base*, SEXP xp ) ;
} ;

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

