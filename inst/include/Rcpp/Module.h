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
		virtual SEXP operator()(SEXP*) { 
			return R_NilValue ;
		}
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
	
	virtual Rcpp::List fields(SEXP){ return Rcpp::List(0); }
	virtual bool has_method( const std::string& ){ 
		return false ; 
	}
	virtual bool has_property( const std::string& ) { 
		return false ;
	}
	virtual SEXP newInstance(SEXP *, int){ 
		return R_NilValue;
	}
	virtual SEXP invoke( const std::string&, SEXP, SEXP *, int ){ 
		return R_NilValue ;
	}
	virtual Rcpp::CharacterVector method_names(){ return Rcpp::CharacterVector(0) ; }
	virtual Rcpp::CharacterVector property_names(){ return Rcpp::CharacterVector(0) ; }
	virtual bool property_is_readonly(const std::string& ) throw(std::range_error) { return false ; }
	virtual std::string property_class(const std::string& ) throw(std::range_error){ return "" ; }
	virtual Rcpp::IntegerVector methods_arity(){ return Rcpp::IntegerVector(0) ; }
	virtual Rcpp::LogicalVector methods_voidness(){ return Rcpp::LogicalVector(0); }
	virtual Rcpp::List property_classes(){ return Rcpp::List(0); }
	
	virtual Rcpp::CharacterVector complete(){ return Rcpp::CharacterVector(0) ; }
	virtual ~class_Base(){}
	
	virtual SEXP getProperty( SEXP, SEXP ) {
		throw std::range_error( "cannot retrieve property" ) ;
	}
	virtual void setProperty( SEXP, SEXP, SEXP) {
		throw std::range_error( "cannot set property" ) ;
	}
	
	
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
		      
		SEXP invoke( const std::string& /* name */,  SEXP* /* args */, int /* nargs */ ) ;                        
		
		Rcpp::IntegerVector functions_arity() ;
		Rcpp::CharacterVector class_names() ;
		Rcpp::List classes_info() ;
		Rcpp::CharacterVector complete() ;
		
		inline void Add( const char* name_ , CppFunction* ptr){
			functions.insert( FUNCTION_PAIR( name_ , ptr ) ) ;
		}
		
		inline void AddClass(const char* name_ , class_Base* cptr){
			classes.insert( CLASS_PAIR( name_ , cptr ) ) ;
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
#include <Rcpp/module/Module_generated_Pointer_CppMethod.h>

template <typename Class>
class CppProperty {
	public:
		typedef Rcpp::XPtr<Class> XP ;
		
		CppProperty(){} ;
		virtual SEXP get(Class* ) throw(std::range_error){ throw std::range_error("cannot retrieve property"); }
		virtual void set(Class*, SEXP) throw(std::range_error,Rcpp::not_compatible){ throw std::range_error("cannot set property"); }
		virtual bool is_readonly(){ return false; }
		virtual std::string get_class(){ return ""; }
} ;

template <typename Class>
class S4_field : public Rcpp::Reference {
public:             
    S4_field( CppProperty<Class>* p, SEXP class_xp ) : Reference( "C++Field" ){
        field( "read_only" )     = p->is_readonly() ;
        field( "cpp_class" )     = p->get_class();
        field( "pointer" )       = Rcpp::XPtr< CppProperty<Class> >( p, false ) ;
        field( "class_pointer" ) = class_xp ;
    }
} ;


#include <Rcpp/module/Module_Property.h>

template <typename Class>
class class_ : public class_Base {
public:
	typedef class_<Class> self ;
	typedef CppMethod<Class> method_class ;
	typedef std::map<std::string,method_class*> METHOD_MAP ;
	typedef std::pair<const std::string,method_class*> PAIR ;
	typedef Rcpp::XPtr<Class> XP ;
	
	typedef CppProperty<Class> prop_class ;
	typedef std::map<std::string,prop_class*> PROPERTY_MAP ;
	typedef std::pair<const std::string,prop_class*> PROP_PAIR ;
	
	class_( const char* name_ ) : class_Base(name_), methods(), properties(), specials(0) {
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
	
	self& AddMethod( const char* name_, method_class* m){
		singleton->methods.insert( PAIR( name_,m ) ) ;  
		if( *name_ == '[' ) singleton->specials++ ;
		return *this ;
	}
	
	self& AddProperty( const char* name_, prop_class* p){
		singleton->properties.insert( PROP_PAIR( name_, p ) ) ;
		return *this ;
	}

#include <Rcpp/module/Module_generated_method.h>
#include <Rcpp/module/Module_generated_Pointer_method.h>
	
	bool has_method( const std::string& m){
		return methods.find(m) != methods.end() ;
	}
	bool has_property( const std::string& m){
		return properties.find(m) != properties.end() ;
	}
	bool property_is_readonly( const std::string& p) throw(std::range_error) {
		typename PROPERTY_MAP::iterator it = properties.find( p ) ;
		if( it == properties.end() ) throw std::range_error( "no such property" ) ;
		return it->second->is_readonly() ;
	}
	std::string property_class(const std::string& p) throw(std::range_error) {
		typename PROPERTY_MAP::iterator it = properties.find( p ) ;
		if( it == properties.end() ) throw std::range_error( "no such property" ) ;
		return it->second->get_class() ;
	}
	
	Rcpp::CharacterVector method_names(){
		int n = methods.size() ;
		Rcpp::CharacterVector out(n) ;
		typename METHOD_MAP::iterator it = methods.begin( ) ;
		for( int i=0; i<n; i++, ++it){
			out[i] = it->first ;
		} 
		return out ;
	}
	
	Rcpp::IntegerVector methods_arity(){
		int n = methods.size() ;
		Rcpp::CharacterVector mnames(n) ;
		Rcpp::IntegerVector res( n );
		typename METHOD_MAP::iterator it = methods.begin( ) ;
		for( int i=0; i<n; i++, ++it){
			mnames[i] = it->first ;
			res[i] = it->second->nargs() ;
		}
		res.names( ) = mnames ;
		return res ;
	}
	Rcpp::LogicalVector methods_voidness(){
		int n = methods.size() ;
		Rcpp::CharacterVector mnames(n) ;
		Rcpp::LogicalVector res( n );
		typename METHOD_MAP::iterator it = methods.begin( ) ;
		for( int i=0; i<n; i++, ++it){
			mnames[i] = it->first ;
			res[i] = it->second->is_void() ;
		}
		res.names( ) = mnames ;
		return res ;
	}
	
	
	Rcpp::CharacterVector property_names(){
		int n = properties.size() ;
		Rcpp::CharacterVector out(n) ;
		typename PROPERTY_MAP::iterator it = properties.begin( ) ;
		for( int i=0; i<n; i++, ++it){
			out[i] = it->first ;
		} 
		return out ;
	}
	
	Rcpp::List property_classes(){
		int n = properties.size() ;
		Rcpp::CharacterVector pnames(n) ;
		Rcpp::List out(n) ;
		typename PROPERTY_MAP::iterator it = properties.begin( ) ;
		for( int i=0; i<n; i++, ++it){
			pnames[i] = it->first ;
			out[i] = it->second->get_class() ; 
		} 
		out.names() = pnames ;
		return out ;
	}
	
	Rcpp::CharacterVector complete(){
		int n = methods.size() - specials ;
		int ntotal = n + properties.size() ;
		Rcpp::CharacterVector out(ntotal) ;
		typename METHOD_MAP::iterator it = methods.begin( ) ;
		std::string buffer ;
		int i=0 ;
		for( ; i<n; ++it){  
			buffer = it->first ;
			if( buffer[0] == '[' ) continue ;
			if( (it->second)->nargs() == 0){
				buffer += "() " ;
			} else {
				buffer += "( " ;
			}
			out[i] = buffer ;
			i++ ;
		}
		typename PROPERTY_MAP::iterator prop_it = properties.begin(); 
		for( ; i<ntotal; i++, ++prop_it){
			out[i] = prop_it->first ;
		}
		return out ;
	}
	
	SEXP getProperty( SEXP field_xp , SEXP object) {
	BEGIN_RCPP
		prop_class* prop = reinterpret_cast< prop_class* >( EXTPTR_PTR( field_xp ) ) ;
	    return prop->get( XP(object) ); 
	END_RCPP
	}
	
	void setProperty( SEXP field_xp, SEXP object, SEXP value)  {
	BEGIN_RCPP
		prop_class* prop = reinterpret_cast< prop_class* >( EXTPTR_PTR( field_xp ) ) ;
	    return prop->set( XP(object), value ); 
	VOID_END_RCPP
	}
	
	
	Rcpp::List fields( SEXP class_xp ){
	    int n = properties.size() ;
		Rcpp::CharacterVector pnames(n) ;
		Rcpp::List out(n) ;
		typename PROPERTY_MAP::iterator it = properties.begin( ) ;
		for( int i=0; i<n; i++, ++it){
			pnames[i] = it->first ;
			out[i] = S4_field<Class>( it->second, class_xp ) ; 
		} 
		out.names() = pnames ;
		return out ;
	}

#include <Rcpp/module/Module_Field.h>

#include <Rcpp/module/Module_Add_Property.h>


private:
	METHOD_MAP methods ;
	PROPERTY_MAP properties ;
	static self* singleton ;
	int specials ;
	
	class_( ) : class_Base(), methods(), properties(), specials(0) {}; 
	
} ;   

template <typename Class> 
class_<Class>* class_<Class>::singleton ;

// function factories
#include <Rcpp/module/Module_generated_function.h>

class CppClass : public S4{
public:
	typedef Rcpp::XPtr<Rcpp::Module> XP ;
	CppClass( Module* p, class_Base* clazz ) ;
	CppClass( SEXP x) ;
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
  ::setCurrentScope( & _rcpp_module_##name ) ;                       \
  _rcpp_module_##name##_init( ) ;                                    \
  Rcpp::XPtr<Rcpp::Module> mod_xp( & _rcpp_module_##name , false ) ; \
  ::setCurrentScope( 0 ) ;                                           \
  return mod_xp ;                                                    \
}                                                                    \
void _rcpp_module_##name##_init()

#define LOAD_RCPP_MODULE(NAME) Rf_eval( Rf_lang2( Rf_install("Module"), _rcpp_module_boot_##NAME() ), R_GlobalEnv )

#endif  

#endif

