// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Evaluator.cpp: Rcpp R/C++ interface class library -- evaluator
//
// Copyright (C) 2009 - 2010	Dirk Eddelbuettel and Romain Francois
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

#include <Rcpp/Evaluator.h>

namespace Rcpp {

   SEXP Evaluator::run(SEXP expr, SEXP env) throw(eval_error) {
	SEXP call = PROTECT( Rf_lang3( Rf_install("rcpp_tryCatch") , expr, env ) ) ;
	
   	Environment RCPP = Environment::Rcpp_namespace(); 
   	
	/* call the tryCatch call */
	SEXP res = PROTECT( Rf_eval( call, RCPP ) );
	
	/* was there an error ? */
	int error = LOGICAL( Rf_eval( Rf_lang1( Rf_install("errorOccured") ), RCPP ) )[0];
	
	if( error ){
		SEXP err_msg = PROTECT( Rf_eval( 
			Rf_lang1( Rf_install("getCurrentErrorMessage")), 
			RCPP ) );
		std::string message = CHAR(STRING_ELT(err_msg,0)) ;
		UNPROTECT( 3 ) ;
		throw eval_error(message) ;
	} else {
		UNPROTECT(2) ;
		return res ;
	}
    }
    
    SEXP Evaluator::run( SEXP expr) throw(eval_error){
    	return run(expr, R_GlobalEnv );
    }
    
namespace internal{
/* this is defined here because we need to be sure that Evaluator is 
   defined */
    SEXP convert_using_rfunction(SEXP x, const char* const fun) throw(::Rcpp::not_compatible) {
    	SEXP res = R_NilValue ;
    	try{    
    		res = Evaluator::run( Rf_lcons( Rf_install(fun), Rf_cons(x, R_NilValue) ) ) ;
    	} catch( eval_error& e){
    		throw ::Rcpp::not_compatible( std::string("could not convert using R function : ") + fun  ) ;
    	}
    	return res;
    }
    
    SEXP try_catch( SEXP expr, SEXP env ) throw(::Rcpp::eval_error) {
    	    return Evaluator::run(expr, env) ;
    }
    SEXP try_catch( SEXP expr ) throw(::Rcpp::eval_error) {
    	    return Evaluator::run(expr) ;
    }
    
} // namespace internal
    
} // namespace Rcpp
