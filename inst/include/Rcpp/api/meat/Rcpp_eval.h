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

namespace Rcpp{

    struct EvalCall {
        SEXP expr;
        SEXP env;
        SEXP result;
        std::vector<std::string> warnings;
        std::string error_message;
    };

    inline void Rcpp_eval(void* data) {

        EvalCall* evalCall = (EvalCall*)data;
        SEXP env = evalCall->env;

        Shield<SEXP> expr(evalCall->expr) ;

        reset_current_error() ;

        Environment RCPP = Environment::Rcpp_namespace();
        SEXP withCallingHandlersSym    = ::Rf_install("withCallingHandlers");
        SEXP tryCatchSym               = ::Rf_install("tryCatch");
        SEXP evalqSym                  = ::Rf_install("evalq");
        SEXP conditionMessageSym       = ::Rf_install("conditionMessage");
        SEXP errorRecorderSym          = ::Rf_install(".rcpp_error_recorder");
        SEXP warningRecorderSym        = ::Rf_install(".rcpp_warning_recorder");
        SEXP collectWarningsSym        = ::Rf_install(".rcpp_collect_warnings");
        SEXP errorSym                  = ::Rf_install("error");
        SEXP warningSym                = ::Rf_install("warning");

        // define the tryCatchCall
        Shield<SEXP> tryCatchCall( Rf_lang3(
            tryCatchSym,
            Rf_lang3( evalqSym, expr, env ),
            errorRecorderSym
        ) ) ;
        SET_TAG( CDDR(tryCatchCall), errorSym ) ;

        // encose it in withCallingHandlers
        Shield<SEXP> call( Rf_lang3(
            withCallingHandlersSym,
            tryCatchCall,
            warningRecorderSym
        ) ) ;
        SET_TAG( CDDR(call), warningSym ) ;

        // execute the call
        Shield<SEXP> res(::Rf_eval( call, RCPP ) );

        // collect warnings
        Shield<SEXP> warningCall(Rf_lang1(collectWarningsSym));
        Shield<SEXP> warnings(::Rf_eval(warningCall, RCPP));
        
        evalCall->warnings = Rcpp::as<std::vector<std::string> >(warnings);

        // check for error
        if( error_occured() ) {
            Shield<SEXP> current_error        ( rcpp_get_current_error() ) ;
            Shield<SEXP> conditionMessageCall (::Rf_lang2(conditionMessageSym, current_error)) ;
            Shield<SEXP> condition_message    (::Rf_eval(conditionMessageCall, R_GlobalEnv)) ;
            evalCall->error_message = std::string(CHAR(::Rf_asChar(condition_message)));
        } else {
            evalCall->result = res;
        }
    }

    inline SEXP Rcpp_eval(SEXP expr_, SEXP env) {

        // create the call object
        EvalCall call;
        call.expr = expr_;
        call.env = env;

        // execute it
        Rboolean completed = R_ToplevelExec(Rcpp_eval, (void*)&call);

        // print warnings
        for (size_t i = 0; i<call.warnings.size(); i++)
            Rf_warning(call.warnings[i].c_str());

        // handle error or result if it completed, else throw interrupt
        if (completed) {
            if (!call.error_message.empty())
                throw eval_error(call.error_message);
            else
                return call.result;
        } else {
            throw internal::InterruptedException();
        }
    }

}

#endif
