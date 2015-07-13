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

struct EvalCall {
    
    // Related to call object
    SEXP expr;
    SEXP env;
    SEXP result;
    
    // Related to error recording / forwarding
    bool error_occurred;
    std::string error_message;
};

inline void Rcpp_eval(void* data) {

    EvalCall* evalCall = (EvalCall*) data;

    SEXP tryCatchSym               = ::Rf_install("tryCatch");
    SEXP evalqSym                  = ::Rf_install("evalq");
    SEXP conditionMessageSym       = ::Rf_install("conditionMessage");
    SEXP errorSym                  = ::Rf_install("error");
    
    // get the Rcpp error recorder
    SEXP errorRecorder = Rf_findFun(
        Rf_install(".rcpp_error_recorder"),
        Environment::Rcpp_namespace()
    );
    
    if (errorRecorder == R_UnboundValue) {
        evalCall->error_occurred = true;
        evalCall->error_message =
            "Failed to find Rcpp error recorder: please ensure\n"
            "you have the latest version of Rcpp installed.";
        return;
    }

    // define the evalq call -- the actual R evaluation we
    // want to execute
    Shield<SEXP> evalqCall(Rf_lang3(
        evalqSym,
        evalCall->expr,
        evalCall->env
    ));
    
    // define the call -- enclose with `tryCatch` so we can record
    // and later forward error messages
    Shield<SEXP> call(Rf_lang3(
        tryCatchSym,
        evalqCall,
        errorRecorder
    ));
    SET_TAG(CDDR(call), errorSym);

    // execute the call
    Shield<SEXP> res(::Rf_eval(call, R_GlobalEnv));

    // check for error
    if (error_occured()) {
        Shield<SEXP> current_error        (rcpp_get_current_error());
        Shield<SEXP> conditionMessageCall (::Rf_lang2(conditionMessageSym, current_error));
        Shield<SEXP> condition_message    (::Rf_eval(conditionMessageCall, R_GlobalEnv));
        evalCall->error_occurred = true;
        evalCall->error_message = std::string(CHAR(::Rf_asChar(condition_message)));
    } else {
        evalCall->error_occurred = false;
        evalCall->result = res;
    }
    
    // Reset the current error for the next evaluation
    reset_current_error();

}

inline SEXP Rcpp_eval(SEXP expr, SEXP env) {

    // create the call object
    EvalCall call;
    call.expr = expr;
    call.env = env;

    // execute it
    Rboolean completed = R_ToplevelExec(Rcpp_eval, (void*) &call);

    // handle error or result if it completed, else throw interrupt
    if (completed) {
        if (call.error_occurred) {
            throw eval_error(call.error_message);
        } else {
            return call.result;
        }
    } else {
        throw internal::InterruptedException();
    }
}

} // namespace Rcpp

#endif
