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
                
namespace Rcpp{
    namespace internal{   
    SEXP get_Rcpp_namespace(){ 
        maybe_init() ;
        return VECTOR_ELT( Rcpp_cache , 0 ) ;
    }                         
    
}
}

// only used for debugging
SEXP get_rcpp_cache() { return Rcpp_cache ; }

SEXP maybe_init() { 
    if( ! Rcpp_cache_ready )  init_Rcpp_cache() ;
}

SEXP init_Rcpp_cache(){   
    Rcpp_cache = PROTECT( Rf_allocVector( VECSXP, 10 ) );
	
    // the Rcpp namespace
    SET_VECTOR_ELT( Rcpp_cache, 0,  Rf_eval( Rf_lcons( Rf_install("getNamespace"), Rf_cons( Rf_mkString("Rcpp") , R_NilValue) ), R_GlobalEnv ) ) ;
	R_PreserveObject( Rcpp_cache ) ;
	UNPROTECT(1) ;  
	Rcpp_cache_ready = true ;
	return Rcpp_cache ;
}

