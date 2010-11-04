// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// cache.cpp: Rcpp R/C++ interface class library -- Rcpp cache
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

static SEXP Rcpp_cache = R_NilValue ;
static bool Rcpp_cache_ready = false ;
  
void maybe_init() { 
    if( ! Rcpp_cache_ready ) init_Rcpp_cache() ;
}

namespace Rcpp{
    namespace internal{   
    SEXP get_Rcpp_namespace(){ 
        maybe_init() ; return VECTOR_ELT( Rcpp_cache , 0 ) ;
    }
    SEXP get_rcpptrycatch(){
       // maybe_init() ; return VECTOR_ELT( Rcpp_cache, 4 ) ; 
       return Rf_install("rcpp_tryCatch") ;
    }                              
    SEXP get_evalq(){
        // maybe_init() ; return VECTOR_ELT( Rcpp_cache, 5 ) ;
        return Rf_install("evalq");
    }
}
}

// only used for debugging
SEXP get_rcpp_cache() { return Rcpp_cache ; }


SEXP init_Rcpp_cache(){   
    Rcpp_cache = PROTECT( Rf_allocVector( VECSXP, 10 ) );
	
    // the Rcpp namespace
    SEXP RCPP = PROTECT( Rf_eval( Rf_lcons( Rf_install("getNamespace"), Rf_cons( Rf_mkString("Rcpp") , R_NilValue) ), R_GlobalEnv ) ) ;
    SET_VECTOR_ELT( Rcpp_cache, 0, RCPP ) ;
	reset_current_error() ;
	// SET_VECTOR_ELT( Rcpp_cache, 4, Rf_install("rcpp_tryCatch") ) ;
	// SET_VECTOR_ELT( Rcpp_cache, 5, Rf_install("evalq") ) ;
	
    R_PreserveObject( Rcpp_cache ) ;
	UNPROTECT(2) ;  
	Rcpp_cache_ready = true ;
	return Rcpp_cache ;
}

SEXP reset_current_error(){
    // error occured
    SET_VECTOR_ELT( Rcpp_cache, 1, Rf_ScalarLogical(FALSE) ) ;
	
    // current error
    SET_VECTOR_ELT( Rcpp_cache, 2, R_NilValue ) ;
	
    // stack trace
    SET_VECTOR_ELT( Rcpp_cache, 3, R_NilValue ) ;
	
    return R_NilValue ;
}

SEXP rcpp_error_recorder(SEXP e){
    maybe_init() ;
    
    // error occured
    SET_VECTOR_ELT( Rcpp_cache, 1, Rf_ScalarLogical(TRUE) ) ;
	
    // current error
    rcpp_set_current_error(e ) ;
    
    return R_NilValue ;
	
}

SEXP rcpp_set_current_error(SEXP e){
    SET_VECTOR_ELT( Rcpp_cache, 2, e ) ;
    return R_NilValue ;
}

SEXP rcpp_get_current_error(){
    return VECTOR_ELT( Rcpp_cache, 2 ) ;
}

SEXP rcpp_set_error_occured(SEXP e){
    SET_VECTOR_ELT( Rcpp_cache, 1, e ) ;
    return R_NilValue ;
}

SEXP rcpp_get_error_occured(){
    return VECTOR_ELT( Rcpp_cache, 1 ) ;
}

SEXP rcpp_set_stack_trace(SEXP e){
    SET_VECTOR_ELT( Rcpp_cache, 3, e ) ;
    return R_NilValue ;
}

SEXP rcpp_get_stack_trace(){
    return VECTOR_ELT( Rcpp_cache, 3 ) ;
}

