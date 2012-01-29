// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Evaluator.cpp: Rcpp R/C++ interface class library -- evaluator
//
// Copyright (C) 2009 - 2011 Dirk Eddelbuettel and Romain Francois
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

    SEXP Evaluator::run(SEXP expr, SEXP env) {
        SEXP call = PROTECT( 
                            Rf_lang2( 
                                     internal::get_rcpptrycatch() , 
                                     Rf_lang3( internal::get_evalq() , expr, env )
                                      )
                             ) ;
        Environment RCPP = Environment::Rcpp_namespace(); 
        
        /* call the tryCatch call */
        SEXP res = PROTECT( Rf_eval( call, RCPP ) );
        
        /* was there an error ? */
        SEXP errorOccuredSym = Rf_install("errorOccured");
        SEXP err_call = PROTECT( Rf_lang1( errorOccuredSym ) ) ;
        SEXP err_res  = PROTECT( Rf_eval( err_call, RCPP ) ) ;
        int error = LOGICAL( err_res )[0];
        UNPROTECT(2) ;
        
        if( error ) {
            SEXP getCurrentErrorMessageSym = Rf_install("getCurrentErrorMessage");
            SEXP err_msg = PROTECT( Rf_eval( Rf_lang1(getCurrentErrorMessageSym),  RCPP ) );
            std::string message = CHAR(STRING_ELT(err_msg,0)) ;
            UNPROTECT( 3 ) ;
            throw eval_error(message) ;
        } else {
            UNPROTECT(2) ;
            return res ;
        }
    }
    
    SEXP Evaluator::run( SEXP expr) {
        return run(expr, R_GlobalEnv );
    }
    
    namespace internal{
        /* this is defined here because we need to be sure that Evaluator is defined */
        SEXP convert_using_rfunction(SEXP x, const char* const fun) {
            SEXP res = R_NilValue ;
            try{
                SEXP funSym = Rf_install(fun);
                res = Evaluator::run( Rf_lang2( funSym, x ) ) ;
            } catch( eval_error& e){
                throw ::Rcpp::not_compatible( std::string("could not convert using R function : ") + fun  ) ;
            }
            return res;
        }
    
        SEXP try_catch( SEXP expr, SEXP env ) {
            return Evaluator::run(expr, env) ;
        }
        SEXP try_catch( SEXP expr ) {
            return Evaluator::run(expr) ;
        }
    
    } // namespace internal
    
} // namespace Rcpp
