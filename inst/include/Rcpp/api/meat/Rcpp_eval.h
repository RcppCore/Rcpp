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
#include <Rversion.h>

#if (defined(RCPP_PROTECTED_EVAL) && defined(R_VERSION) && R_VERSION >= R_Version(3, 5, 0))
#define RCPP_USE_PROTECT_UNWIND
#include <csetjmp>
#endif


namespace Rcpp {
namespace internal {

#ifdef RCPP_USE_PROTECT_UNWIND

    struct EvalData {
        SEXP expr;
        SEXP env;
        EvalData(SEXP expr_, SEXP env_) : expr(expr_), env(env_) { }
    };
    struct EvalUnwindData {
        std::jmp_buf jmpbuf;
    };

    // First jump back to the protected context with a C longjmp because
    // `Rcpp_protected_eval()` is called from C and we can't safely throw
    // exceptions across C frames.
    inline void Rcpp_maybe_throw(void* unwind_data, Rboolean jump) {
        if (jump) {
            EvalUnwindData* data = static_cast<EvalUnwindData*>(unwind_data);
            longjmp(data->jmpbuf, 1);
        }
    }

    inline SEXP Rcpp_protected_eval(void* eval_data) {
        EvalData* data = static_cast<EvalData*>(eval_data);
        return ::Rf_eval(data->expr, data->env);
    }

    // This is used internally instead of Rf_eval() to make evaluation safer
    inline SEXP Rcpp_eval_impl(SEXP expr, SEXP env) {
        return Rcpp_fast_eval(expr, env);
    }

#else // R < 3.5.0

    // Fall back to Rf_eval() when the protect-unwind API is unavailable
    inline SEXP Rcpp_eval_impl(SEXP expr, SEXP env) {
        return ::Rf_eval(expr, env);
    }

#endif

} // namespace internal


#ifdef RCPP_USE_PROTECT_UNWIND

    inline SEXP Rcpp_fast_eval(SEXP expr, SEXP env) {
        internal::EvalData data(expr, env);
        internal::EvalUnwindData unwind_data;
        Shield<SEXP> token(::R_MakeUnwindCont());

        if (setjmp(unwind_data.jmpbuf)) {
            // Keep the token protected while unwinding because R code might run
            // in C++ destructors. Can't use PROTECT() for this because
            // UNPROTECT() might be called in a destructor, for instance if a
            // Shield<SEXP> is on the stack.
            ::R_PreserveObject(token);

            throw internal::LongjumpException(token);
        }

        return ::R_UnwindProtect(internal::Rcpp_protected_eval, &data,
                                 internal::Rcpp_maybe_throw, &unwind_data,
                                 token);
    }

#else

    inline SEXP Rcpp_fast_eval(SEXP expr, SEXP env) {
        return Rcpp_eval(expr, env);
    }

#endif


inline SEXP Rcpp_eval(SEXP expr, SEXP env) {

    // 'identity' function used to capture errors, interrupts
    SEXP identity = Rf_findFun(::Rf_install("identity"), R_BaseNamespace);

    if (identity == R_UnboundValue) {
        stop("Failed to find 'base::identity()'");
    }

    // define the evalq call -- the actual R evaluation we want to execute
    Shield<SEXP> evalqCall(Rf_lang3(::Rf_install("evalq"), expr, env));

    // define the call -- enclose with `tryCatch` so we can record and forward error messages
    Shield<SEXP> call(Rf_lang4(::Rf_install("tryCatch"), evalqCall, identity, identity));
    SET_TAG(CDDR(call), ::Rf_install("error"));
    SET_TAG(CDDR(CDR(call)), ::Rf_install("interrupt"));

    Shield<SEXP> res(internal::Rcpp_eval_impl(call, R_GlobalEnv));

    // check for condition results (errors, interrupts)
    if (Rf_inherits(res, "condition")) {

        if (Rf_inherits(res, "error")) {

            Shield<SEXP> conditionMessageCall(::Rf_lang2(::Rf_install("conditionMessage"), res));

            Shield<SEXP> conditionMessage(internal::Rcpp_eval_impl(conditionMessageCall, R_GlobalEnv));
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
