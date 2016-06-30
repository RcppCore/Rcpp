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

#include <Rcpp/Interrupt.h>

namespace Rcpp {

inline SEXP Rcpp_eval(SEXP expr, SEXP env) {

    SEXP identity = Rf_findFun(
        ::Rf_install("identity"),
        R_BaseNamespace
    );

    SEXP tryCatch = Rf_findFun(
        ::Rf_install("tryCatch"),
        R_BaseNamespace
    );

    // define the call -- enclose with `tryCatch` so we can record
    // and later forward error messages
    Shield<SEXP> call(Rf_lang4(
        tryCatch,
        expr,
        identity,
        identity
    ));
    SET_TAG(CDDR(call), ::Rf_install("error"));
    SET_TAG(CDDR(CDR(call)), ::Rf_install("interrupt"));

    // execute the call
    Shield<SEXP> res(::Rf_eval(call, env));

    // check for condition results (errors, interrupts)
    if (Rf_inherits(res, "condition")) {
        
        if (Rf_inherits(res, "error")) {
            
            Shield<SEXP> conditionMessageCall(::Rf_lang2(
                    ::Rf_install("conditionMessage"),
                    res
            ));
            
            Shield<SEXP> conditionMessage(::Rf_eval(conditionMessageCall, R_GlobalEnv));
            throw eval_error(CHAR(STRING_ELT(conditionMessage, 0)));
        }
        
        // check for interrupt
        if (Rf_inherits(res, "interrupt")) {
            throw internal::InterruptedException();
        }
        
    }
    
    return res;
}

} // namespace Rcpp

#endif
