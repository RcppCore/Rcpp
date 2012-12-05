// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// cache.cpp: Rcpp R/C++ interface class library -- Rcpp cache
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

#define USE_RINTERNALS 1
#include <Rinternals.h>
#include <Rcpp/routines.h>
#include <Rcpp/cache.h>
#include <algorithm>

static bool Rcpp_cache_know = false ;
static SEXP Rcpp_cache = R_NilValue ;

#define RCPP_HASH_CACHE_INDEX 4
#define RCPP_CACHE_SIZE 5

#ifndef RCPP_HASH_CACHE_INITIAL_SIZE
#define RCPP_HASH_CACHE_INITIAL_SIZE 1024
#endif 

SEXP reset_current_error__(SEXP) ;

namespace Rcpp {
    namespace internal {   
		SEXP get_Rcpp_namespace(){ 
			return VECTOR_ELT( Rcpp_cache , 0 ) ;
		}
	}
}

// only used for debugging
SEXP get_rcpp_cache() {
    if( ! Rcpp_cache_know ){
        
        SEXP getNamespaceSym = Rf_install("getNamespace"); // cannot be gc()'ed  once in symbol table
        SEXP RCPP = PROTECT( Rf_eval(Rf_lang2( getNamespaceSym, Rf_mkString("Rcpp") ), R_GlobalEnv) ) ;
        
        Rcpp_cache = Rf_findVarInFrame( RCPP, Rf_install(".rcpp_cache") ) ;
        Rcpp_cache_know = true ;
        UNPROTECT(1) ;
    }
    return Rcpp_cache ;
}

SEXP init_Rcpp_cache(){   
    SEXP getNamespaceSym = Rf_install("getNamespace"); // cannot be gc()'ed  once in symbol table
    SEXP RCPP = PROTECT( Rf_eval(Rf_lang2( getNamespaceSym, Rf_mkString("Rcpp") ), R_GlobalEnv) ) ;
    SEXP cache = PROTECT( Rf_allocVector( VECSXP, RCPP_CACHE_SIZE ) );
    
    // the Rcpp namespace
	SET_VECTOR_ELT( cache, 0, RCPP ) ;
	reset_current_error__(cache) ;
	SET_VECTOR_ELT( cache, RCPP_HASH_CACHE_INDEX, Rf_allocVector(INTSXP, RCPP_HASH_CACHE_INITIAL_SIZE) ) ;
	
	Rf_defineVar( Rf_install(".rcpp_cache"), cache, RCPP );
    
    UNPROTECT(2) ;  
	return cache ;
}

SEXP reset_current_error__(SEXP cache){
    
    SET_VECTOR_ELT( cache, 1, Rf_ScalarLogical(FALSE) ) ;
	
    // current error
    SET_VECTOR_ELT( cache, 2, R_NilValue ) ;
	
    // stack trace
    SET_VECTOR_ELT( cache, 3, R_NilValue ) ;
	
    return R_NilValue ;
}
SEXP reset_current_error(){ return reset_current_error__( get_rcpp_cache() ) ; }

SEXP rcpp_error_recorder(SEXP e, SEXP cache){
    // error occured
    SET_VECTOR_ELT( cache, 1, Rf_ScalarLogical(TRUE) ) ;
	
    // current error
    rcpp_set_current_error(e ) ;
    
    return R_NilValue ;
	
}
SEXP rcpp_error_recorder(SEXP e){ return rcpp_error_recorder(e, get_rcpp_cache() ) ;}

SEXP rcpp_set_current_error(SEXP e, SEXP cache){
    SET_VECTOR_ELT( cache, 2, e ) ;
    return R_NilValue ;
}
SEXP rcpp_set_current_error(SEXP e){ return rcpp_set_current_error(e, get_rcpp_cache() ) ; }

SEXP rcpp_get_current_error(){
    return VECTOR_ELT( get_rcpp_cache(), 2 ) ;
}

SEXP rcpp_set_error_occured(SEXP e){
    SET_VECTOR_ELT( get_rcpp_cache(), 1, e ) ;
    return R_NilValue ;
}

SEXP rcpp_get_error_occured(){
    return VECTOR_ELT( get_rcpp_cache(), 1 ) ;
}

SEXP rcpp_set_stack_trace(SEXP e){
    SET_VECTOR_ELT( get_rcpp_cache(), 3, e ) ;
    return R_NilValue ;
}

SEXP rcpp_get_stack_trace(){
    return VECTOR_ELT( get_rcpp_cache(), 3 ) ;
}

int* get_cache( int m){
    SEXP cache = get_rcpp_cache() ;
    SEXP hash_cache = VECTOR_ELT( cache, RCPP_HASH_CACHE_INDEX) ;
    int n = Rf_length(hash_cache) ;
    if( m > n ){
        hash_cache = PROTECT( Rf_allocVector( INTSXP, m) ) ;
        SET_VECTOR_ELT(cache,RCPP_HASH_CACHE_INDEX, hash_cache); 
        UNPROTECT(1) ;
    }
    int *res = INTEGER(hash_cache) ;
    std::fill(res, res+m, 0 ) ;
    return res ;
}

