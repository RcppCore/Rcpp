// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Evaluator.cpp: Rcpp R/C++ interface class library -- evaluator
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

#include <Rcpp/Evaluator.h>

void maybe_init() ;

namespace Rcpp {

    SEXP Evaluator::run(SEXP expr, SEXP env) {
        PROTECT(expr);

        maybe_init() ;
        reset_current_error() ; 

        Environment RCPP = Environment::Rcpp_namespace(); 
        static SEXP rcpp_tryCatchSym = NULL, evalqSym, errorOccuredSym, getCurrentErrorMessageSym;
        if (!rcpp_tryCatchSym) {
            rcpp_tryCatchSym          = ::Rf_install("rcpp_tryCatch");
            evalqSym                  = ::Rf_install("evalq");
            errorOccuredSym           = ::Rf_install("errorOccured");
            getCurrentErrorMessageSym = ::Rf_install("getCurrentErrorMessage");
        }

        SEXP call = PROTECT(::Rf_lang2(rcpp_tryCatchSym, PROTECT(::Rf_lang3(evalqSym, expr, env))));
        /* call the tryCatch call */
        SEXP res  = PROTECT(::Rf_eval( call, RCPP ) );
        
        /* was there an error ? */
        int error = ::Rf_asLogical(PROTECT(::Rf_eval(PROTECT(::Rf_lang1(errorOccuredSym)), RCPP)));
        UNPROTECT(2) ;
        
        if( error ) {
            std::string 
                message(CHAR(::Rf_asChar(PROTECT(::Rf_eval(
                                                     PROTECT(::Rf_lang1(getCurrentErrorMessageSym)),
                                                     RCPP)))));
            UNPROTECT( 6 ) ;
            throw eval_error(message) ;
        }

        UNPROTECT(4) ;
        return res ;
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
