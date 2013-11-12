// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// exceptions.h: Rcpp R/C++ interface class library -- exceptions
//
// Copyright (C) 2010 - 2012 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__exceptions__h
#define Rcpp__exceptions__h

#define R_NO_REMAP
#include <Rinternals.h>
#include <sstream>

SEXP stack_trace( const char *file, int line) ;
#define GET_STACKTRACE() stack_trace( __FILE__, __LINE__ )

namespace Rcpp{

class exception : public std::exception {
public:
    explicit exception(const char* message_) : message(message_){}
    exception(const char* message_, const char* file, int line ) : message(message_){
        rcpp_set_stack_trace( stack_trace(file,line) ) ;
    }
    virtual ~exception() throw(){}
    virtual const char* what() const throw() {
        return message.c_str() ;    
    }
private:
    std::string message ;
} ;

// simple helper
static std::string toString(const int i) { 
    std::ostringstream ostr;
    ostr << i;
    return ostr.str();
}

class no_such_env : public std::exception{                                     
public:                                                                        
    no_such_env( const std::string& name ) throw() : message( std::string("no such environment: '") + name + "'" ){} ;
    no_such_env( int pos ) throw() : message( "no environment in given position '" + toString(pos) + "'") {} ;
    virtual ~no_such_env() throw(){} ;                                         
    virtual const char* what() const throw(){ return message.c_str() ; } ;     
private:                                                                       
    std::string message ;                                                      
} ;

class file_io_error : public std::exception {                                      
public:                                                                        
    file_io_error(const std::string& file) throw() : message( std::string("file io error: '") + file + "'" ), file(file) {} ;
    file_io_error(int code, const std::string& file) throw() : message( "file io error " + toString(code) + ": '" + file + "'"), file(file) {} ;
    file_io_error(const std::string& msg, const std::string& file) throw() : message( msg + ": '" + file + "'"), file(file) {} ;
    virtual ~file_io_error() throw(){} ;                                         
    virtual const char* what() const throw(){ return message.c_str() ; } ; 
    std::string filePath() const throw(){ return file ; } ;
private:                                                                       
    std::string message ;                                                      
    std::string file;
} ;

class file_not_found : public file_io_error {
public:
    file_not_found(const std::string& file) throw() : file_io_error("file not found", file) {}
};

class file_exists : public file_io_error {
public:
    file_exists(const std::string& file) throw() : file_io_error("file already exists", file) {}
};

#define RCPP_EXCEPTION_CLASS(__CLASS__,__WHAT__)                               \
class __CLASS__ : public std::exception{                                       \
public:                                                                        \
	__CLASS__( const std::string& message ) throw() : message( __WHAT__ ){} ;  \
	virtual ~__CLASS__() throw(){} ;                                           \
	virtual const char* what() const throw() { return message.c_str() ; }      \
private:                                                                       \
	std::string message ;                                                      \
} ;

#define RCPP_SIMPLE_EXCEPTION_CLASS(__CLASS__,__MESSAGE__)                     \
class __CLASS__ : public std::exception{                                       \
public:                                                                        \
	__CLASS__() throw() {} ;                                                   \
	virtual ~__CLASS__() throw(){} ;                                           \
	virtual const char* what() const throw() { return __MESSAGE__ ; }          \
} ;

RCPP_SIMPLE_EXCEPTION_CLASS(not_a_matrix, "not a matrix")
RCPP_SIMPLE_EXCEPTION_CLASS(index_out_of_bounds, "index out of bounds")
RCPP_SIMPLE_EXCEPTION_CLASS(parse_error, "parse error") 
RCPP_SIMPLE_EXCEPTION_CLASS(not_s4, "not an S4 object")
RCPP_SIMPLE_EXCEPTION_CLASS(not_reference, "not an S4 object of a reference class")
RCPP_SIMPLE_EXCEPTION_CLASS(not_initialized, "C++ object not initialized (missing default constructor?)")
RCPP_SIMPLE_EXCEPTION_CLASS(no_such_slot, "no such slot")
RCPP_SIMPLE_EXCEPTION_CLASS(no_such_field, "no such field")
RCPP_SIMPLE_EXCEPTION_CLASS(not_a_closure, "not a closure")
RCPP_SIMPLE_EXCEPTION_CLASS(no_such_function, "no such function")
RCPP_SIMPLE_EXCEPTION_CLASS(unevaluated_promise, "promise not yet evaluated")

RCPP_EXCEPTION_CLASS(not_compatible, message )
RCPP_EXCEPTION_CLASS(S4_creation_error, std::string("error creating object of S4 class : ") + message )
RCPP_EXCEPTION_CLASS(reference_creation_error, std::string("error creating object of reference class : ") + message )
RCPP_EXCEPTION_CLASS(no_such_binding, std::string("no such binding : '") + message + "'" )
RCPP_EXCEPTION_CLASS(binding_not_found, std::string("binding not found: '") + message + "'" )
RCPP_EXCEPTION_CLASS(binding_is_locked, std::string("binding is locked: '") + message + "'" )
RCPP_EXCEPTION_CLASS(no_such_namespace, std::string("no such namespace: '") + message + "'" )
RCPP_EXCEPTION_CLASS(function_not_exported, std::string("function not exported: ") + message)
RCPP_EXCEPTION_CLASS(eval_error, message )

#undef RCPP_EXCEPTION_CLASS
#undef RCPP_SIMPLE_EXCEPTION_CLASS

} // namespace Rcpp
       
inline SEXP get_last_call(){
    SEXP sys_calls_symbol = Rf_install( "sys.calls" ) ;
    Shield<SEXP> sys_calls_expr = Rf_lang1(sys_calls_symbol);   
    Shield<SEXP> calls = Rf_eval( sys_calls_expr, R_GlobalEnv ) ;
    SEXP res = calls ;
    while( !Rf_isNull(CDR(res)) ) res = CDR(res); 
    return CAR(res) ;
}

inline SEXP get_exception_classes( const std::string& ex_class) {
    Shield<SEXP> res = Rf_allocVector( STRSXP, 4 );
    SET_STRING_ELT( res, 0, Rf_mkChar( ex_class.c_str() ) ) ;
    SET_STRING_ELT( res, 1, Rf_mkChar( "C++Error" ) ) ;
    SET_STRING_ELT( res, 2, Rf_mkChar( "error" ) ) ;
    SET_STRING_ELT( res, 3, Rf_mkChar( "condition" ) ) ;
    return res;
}

inline void forward_exception_to_r( const std::exception& ex){
    SEXP stop_sym  = Rf_install( "stop" ) ;
    Shield<SEXP> condition = exception_to_r_condition(ex) ;
    Shield<SEXP> expr = Rf_lang2( stop_sym , condition ) ;
    Rf_eval( expr, R_GlobalEnv ) ;
}

inline SEXP exception_to_try_error( const std::exception& ex){
    return string_to_try_error(ex.what());
}

inline SEXP make_condition(const std::string& ex_msg, SEXP call, SEXP cppstack, SEXP classes){
    Shield<SEXP> res = Rf_allocVector( VECSXP, 3 ) ;
    
    SET_VECTOR_ELT( res, 0, Rf_mkString( ex_msg.c_str() ) ) ;
    SET_VECTOR_ELT( res, 1, call ) ;
    SET_VECTOR_ELT( res, 2, cppstack ) ;
    
    Shield<SEXP> names = Rf_allocVector( STRSXP, 3 ) ;
    SET_STRING_ELT( names, 0, Rf_mkChar( "message" ) ) ;
    SET_STRING_ELT( names, 1, Rf_mkChar( "call" ) ) ;
    SET_STRING_ELT( names, 2, Rf_mkChar( "cppstack" ) ) ;
    Rf_setAttrib( res, R_NamesSymbol, names ) ;
    Rf_setAttrib( res, R_ClassSymbol, classes ) ;
    return res ;
}

inline SEXP exception_to_r_condition( const std::exception& ex){
    std::string ex_class = demangle( typeid(ex).name() ) ;
    std::string ex_msg   = ex.what() ; 
    
    Shield<SEXP> cppstack = rcpp_get_stack_trace() ;
    Shield<SEXP> call = get_last_call() ;
    Shield<SEXP> classes = get_exception_classes(ex_class) ;
    Shield<SEXP> condition = make_condition( ex_msg, call, cppstack, classes) ; 
    rcpp_set_stack_trace( R_NilValue ) ;
    return condition ;
}

inline SEXP string_to_try_error( const std::string& str){
    using namespace Rcpp;
    
    Shield<SEXP> simpleErrorExpr = Rf_lang2(::Rf_install("simpleError"), Rf_mkString(str.c_str()));
    Shield<SEXP> simpleError = Rf_eval(simpleErrorExpr, R_GlobalEnv);
    Shield<SEXP> tryError = Rf_mkString( str.c_str() ) ;
    Rf_setAttrib( tryError, R_ClassSymbol, Rf_mkString("try-error") ) ; 
    Rf_setAttrib( tryError, Rf_install( "condition") , simpleError ) ; 
    
    return tryError;
}

std::string demangle( const std::string& name) ;
#define DEMANGLE(__TYPE__) demangle( typeid(__TYPE__).name() ).c_str() 

namespace Rcpp {
    inline void stop(const std::string& message) { 
        throw Rcpp::exception(message.c_str()); 
    }
} // namespace Rcpp

#endif
