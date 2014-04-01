// Copyright (C) 2013 Romain Francois
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

#ifndef Rcpp_api_meat_Rcpp_eval_h
#define Rcpp_api_meat_Rcpp_eval_h

namespace Rcpp{

    inline SEXP Rcpp_eval(SEXP expr_, SEXP env) {
        Shield<SEXP> expr( expr_) ;

        reset_current_error() ;

        Environment RCPP = Environment::Rcpp_namespace();
        SEXP tryCatchSym               = ::Rf_install("tryCatch");
        SEXP evalqSym                  = ::Rf_install("evalq");
        SEXP conditionMessageSym       = ::Rf_install("conditionMessage");
        SEXP errorRecorderSym          = ::Rf_install(".rcpp_error_recorder");
        SEXP errorSym                  = ::Rf_install("error");

        Shield<SEXP> call( Rf_lang3(
            tryCatchSym,
            Rf_lang3( evalqSym, expr, env ),
            errorRecorderSym
        ) ) ;
        SET_TAG( CDDR(call), errorSym ) ;
        /* call the tryCatch call */
        Shield<SEXP> res(::Rf_eval( call, RCPP ) );

        if( error_occured() ) {
            Shield<SEXP> current_error        ( rcpp_get_current_error() ) ;
            Shield<SEXP> conditionMessageCall (::Rf_lang2(conditionMessageSym, current_error)) ;
            Shield<SEXP> condition_message    (::Rf_eval(conditionMessageCall, R_GlobalEnv)) ;
            std::string message(CHAR(::Rf_asChar(condition_message)));
            throw eval_error(message) ;
        }

        return res ;
    }

}

#endif
