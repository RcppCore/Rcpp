// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// exceptions.cpp: R/C++ interface class library -- exception handling
//
// Copyright (C) 2009 - 2012  Dirk Eddelbuettel and Romain Francois
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

#include <typeinfo>
#include <Rcpp/platform/compiler.h>
#define R_NO_REMAP
#include <Rinternals.h>
#include <Rcpp/exceptions.h>
#include <cstdlib>
#include "internal.h"

namespace Rcpp{
    
    exception::exception(const char* message_) : message(message_) {}
    exception::exception( const char* message_, const char* file, int line) : message(message_){
	rcpp_set_stack_trace( stack_trace(file,line) ) ;
    }
    exception::~exception() throw(){}

#define RCPP_EXCEPTION_WHAT(__CLASS__)					\
    const char* __CLASS__::what() const throw(){ return message.c_str(); }

    RCPP_EXCEPTION_WHAT(exception)
    RCPP_EXCEPTION_WHAT(not_compatible)
    RCPP_EXCEPTION_WHAT(S4_creation_error)
    RCPP_EXCEPTION_WHAT(reference_creation_error)
    RCPP_EXCEPTION_WHAT(no_such_binding)
    RCPP_EXCEPTION_WHAT(binding_not_found)
    RCPP_EXCEPTION_WHAT(binding_is_locked)
    RCPP_EXCEPTION_WHAT(no_such_namespace)
    RCPP_EXCEPTION_WHAT(function_not_exported)
    RCPP_EXCEPTION_WHAT(eval_error)

#undef RCPP_EXCEPTION_WHAT

#define RCPP_SIMPLE_EXCEPTION_WHAT(__CLASS__,__MESSAGE__)		\
const char* __CLASS__::what() const throw(){ return __MESSAGE__ ; }

    RCPP_SIMPLE_EXCEPTION_WHAT(not_a_matrix, "not a matrix" )
    RCPP_SIMPLE_EXCEPTION_WHAT(index_out_of_bounds, "index out of bounds" )
    RCPP_SIMPLE_EXCEPTION_WHAT(parse_error, "parse error") 
    RCPP_SIMPLE_EXCEPTION_WHAT(not_s4, "not an S4 object" )
    RCPP_SIMPLE_EXCEPTION_WHAT(not_reference, "not a reference S4 object" )
    RCPP_SIMPLE_EXCEPTION_WHAT(not_initialized, "C++ object not initialized" )
    RCPP_SIMPLE_EXCEPTION_WHAT(no_such_slot, "no such slot" )
    RCPP_SIMPLE_EXCEPTION_WHAT(no_such_field, "no such field" )
    RCPP_SIMPLE_EXCEPTION_WHAT(not_a_closure, "not a closure" )
    RCPP_SIMPLE_EXCEPTION_WHAT(no_such_function, "no such function" )
    RCPP_SIMPLE_EXCEPTION_WHAT(unevaluated_promise, "promise not yet evaluated" )

#undef RCPP_SIMPLE_EXCEPTION_WHAT
}
        
SEXP get_last_call(){
    SEXP sys_calls_symbol = Rf_install( "sys.calls" ) ;
    SEXP sys_calls_expr = PROTECT( Rf_lang1(sys_calls_symbol) ) ;   
    SEXP calls = PROTECT( Rf_eval( sys_calls_expr, R_GlobalEnv ) ) ;
    SEXP res = calls ;
    while( !Rf_isNull(CDR(res)) ) res = CDR(res); 
    UNPROTECT(2);
    return CAR(res) ;
}

SEXP get_exception_classes( const std::string& ex_class) {
    SEXP res = PROTECT( Rf_allocVector( STRSXP, 4 ) );
    SET_STRING_ELT( res, 0, Rf_mkChar( ex_class.c_str() ) ) ;
    SET_STRING_ELT( res, 1, Rf_mkChar( "C++Error" ) ) ;
    SET_STRING_ELT( res, 2, Rf_mkChar( "error" ) ) ;
    SET_STRING_ELT( res, 3, Rf_mkChar( "condition" ) ) ;
    UNPROTECT(1) ;
    return res;
}

SEXP make_condition(const std::string& ex_msg, SEXP call, SEXP cppstack, SEXP classes){
    SEXP res = PROTECT( Rf_allocVector( VECSXP, 3 ) ) ;
    SEXP message = PROTECT( Rf_mkString( ex_msg.c_str() ) ) ;
    SET_VECTOR_ELT( res, 0, message ) ;
    SET_VECTOR_ELT( res, 1, call ) ;
    SET_VECTOR_ELT( res, 2, cppstack ) ;
    SEXP names = PROTECT( Rf_allocVector( STRSXP, 3 ) ) ;
    SET_STRING_ELT( names, 0, Rf_mkChar( "message" ) ) ;
    SET_STRING_ELT( names, 1, Rf_mkChar( "call" ) ) ;
    SET_STRING_ELT( names, 2, Rf_mkChar( "cppstack" ) ) ;
    Rf_setAttrib( res, R_NamesSymbol, names ) ;
    Rf_setAttrib( res, R_ClassSymbol, classes ) ;
    UNPROTECT(3) ;
    return res ;
}

SEXP exception_to_r_condition( const std::exception& ex){
    std::string ex_class = demangle( typeid(ex).name() ) ;
    std::string ex_msg   = ex.what() ; 
    
    SEXP cppstack = PROTECT( rcpp_get_stack_trace() ) ;
    SEXP call = PROTECT( get_last_call() ) ;
    SEXP classes = PROTECT( get_exception_classes(ex_class) ) ;
    SEXP condition = PROTECT( make_condition( ex_msg, call, cppstack, classes ) ) ; 
    rcpp_set_stack_trace( R_NilValue ) ;
    UNPROTECT(4) ;
    return condition ;
}
void forward_exception_to_r( const std::exception& ex){
    SEXP condition = PROTECT(exception_to_r_condition(ex)) ;
    SEXP stop_sym  = Rf_install( "stop" ) ;
    SEXP expr = PROTECT( Rf_lang2( stop_sym , condition ) );
    UNPROTECT(2) ;
    Rf_eval( expr, R_GlobalEnv ) ;
}

