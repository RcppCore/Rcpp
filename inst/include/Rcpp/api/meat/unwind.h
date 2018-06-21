// unwind.h: Rcpp R/C++ interface class library -- Unwind Protect
//
// Copyright (C) 2018 RStudio
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

#ifndef RCPP_API_MEAT_UNWIND_H
#define RCPP_API_MEAT_UNWIND_H

#include <csetjmp>


namespace Rcpp { namespace internal {

struct UnwindData {
    std::jmp_buf jmpbuf;
};

// First jump back to the protected context with a C longjmp because
// `Rcpp_protected_eval()` is called from C and we can't safely throw
// exceptions across C frames.
inline void maybeJump(void* unwind_data, Rboolean jump) {
    if (jump) {
        UnwindData* data = static_cast<UnwindData*>(unwind_data);
        longjmp(data->jmpbuf, 1);
    }
}

}} // namespace Rcpp::internal


namespace Rcpp {

SEXP unwindProtect(SEXP (*callback)(void* data), void* data) {
    internal::UnwindData unwind_data;
    Shield<SEXP> token(::R_MakeUnwindCont());

    if (setjmp(unwind_data.jmpbuf)) {
        // Keep the token protected while unwinding because R code might run
        // in C++ destructors. Can't use PROTECT() for this because
        // UNPROTECT() might be called in a destructor, for instance if a
        // Shield<SEXP> is on the stack.
        ::R_PreserveObject(token);

        throw internal::LongjumpException(token);
    }

    return ::R_UnwindProtect(callback, data,
                             internal::maybeJump, &unwind_data,
                             token);
}

} // namespace Rcpp

#endif
