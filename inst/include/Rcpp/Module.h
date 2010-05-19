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

template <typename OUT>
class CppFunction0 : public CppFunction {
	public:
		CppFunction0(OUT (*fun)(void) ) : CppFunction(), ptr_fun(fun){}
		SEXP operator()(SEXP* args){
			SEXP res = R_NilValue ;
			try{
				res = Rcpp::wrap( ptr_fun() ) ;
			} catch( std::exception& __ex__ ){
				forward_exception_to_r( __ex__ ) ;
			}
			return res ;
		}
		
		inline int nargs(){ return 0; }
		
	private:
		OUT (*ptr_fun)(void) ;	
} ;

template <>
class CppFunction0<void> : public CppFunction {
	public:
		CppFunction0(void (*fun)(void) )  ;
		
		SEXP operator()(SEXP* args) ;
		
		inline int nargs(){ return 0; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(void) ;	
} ;


template <typename OUT, typename U0>
class CppFunction1 : public CppFunction {
	public:
		CppFunction1(OUT (*fun)(U0 u0) ) : CppFunction(), ptr_fun(fun){}
		SEXP operator()(SEXP* args){
			SEXP res = R_NilValue ;
			try{
				res = Rcpp::wrap( ptr_fun( Rcpp::as<U0>( args[0] ) ) ) ;
			} catch( std::exception& __ex__ ){
				forward_exception_to_r( __ex__ ) ;
			}
			return res ;
		}
		
		inline int nargs(){ return 1; }
		
	private:
		OUT (*ptr_fun)(U0 u0) ;	
} ;

template <typename U0>
class CppFunction1<void,U0> : public CppFunction {
	public:
		CppFunction1(void (*fun)(U0 u0) ) : CppFunction(), ptr_fun(fun){}
		SEXP operator()(SEXP* args){
			try{
				ptr_fun( Rcpp::as<U0>( args[0] ) ) ;
			} catch( std::exception& __ex__ ){
				forward_exception_to_r( __ex__ ) ;
			}
			return R_NilValue ;
		}
		
		inline int nargs(){ return 1; }
		inline bool is_void(){ return true; }
		
	private:
		void (*ptr_fun)(U0 u0) ;	
} ;



template <typename OUT, typename U0, typename U1>
class CppFunction2 : public CppFunction {
	public:
		CppFunction2(OUT (*fun)(U0 u0, U1 u1) ) : CppFunction(), ptr_fun(fun){}
		SEXP operator()(SEXP* args){
			SEXP res = R_NilValue ;
			try{
				res = Rcpp::wrap( ptr_fun( 
					Rcpp::as<U0>( args[0] ), 
					Rcpp::as<U1>( args[1] )
					) ) ;
			} catch( std::exception& __ex__ ){
				forward_exception_to_r( __ex__ ) ;
			}
			return res ;
		}
		inline int nargs(){ return 2; }
		
		
	private:
		OUT (*ptr_fun)(U0 u0, U1 u1) ;	
} ;

template <typename U0, typename U1>
class CppFunction2<void,U0,U1> : public CppFunction {
	public:
		CppFunction2(void (*fun)(U0 u0, U1 u1) ) : CppFunction(), ptr_fun(fun){}
		SEXP operator()(SEXP* args){
			try{
				ptr_fun( 
					Rcpp::as<U0>( args[0] ), 
					Rcpp::as<U1>( args[1] )
					);
			} catch( std::exception& __ex__ ){
				forward_exception_to_r( __ex__ ) ;
			}
			return R_NilValue ;
		}
		inline int nargs(){ return 2; }
		inline bool is_void(){ return true; }
		
		
	private:
		void (*ptr_fun)(U0 u0, U1 u1) ;	
} ;

template <typename OUT>
CppFunction* make_function( OUT (*fun)(void) ){
	return new CppFunction0<OUT>( fun ) ;
}

template <typename OUT, typename U0>
CppFunction* make_function( OUT (*fun)(U0 u0) ){
	return new CppFunction1<OUT,U0>( fun ) ;
}

template <typename OUT, typename U0, typename U1>
CppFunction* make_function( OUT (*fun)(U0 u0, U1 u1) ){
	return new CppFunction2<OUT,U0,U1>( fun ) ;
}
	
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

template <typename OUT>
void function( const char* name,  OUT (*fun)(void)){
	if( Rcpp::current_scope ){
		Rcpp::current_scope->Add( name, new CppFunction0<OUT>( fun ) ) ;
	}
}

template <typename OUT, typename U0>
void function( const char* name,  OUT (*fun)(U0 u0)){
	if( Rcpp::current_scope ){
		Rcpp::current_scope->Add( name, new CppFunction1<OUT,U0>( fun ) ) ;
	}
}

template <typename OUT, typename U0, typename U1>
void function( const char* name,  OUT (*fun)(U0 u0, U1 u1)){
	if( Rcpp::current_scope ){
		Rcpp::current_scope->Add( name, new CppFunction2<OUT,U0,U1>( fun ) ) ;
	}
}


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

