// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// check_sizes.h: Rcpp R/C++ interface class library -- operand length checks
//
// Copyright (C) 2026 Kevin Ushey
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

#ifndef Rcpp__sugar__tools__check_sizes_h
#define Rcpp__sugar__tools__check_sizes_h

#include <Rcpp/config.h>

namespace Rcpp{
namespace sugar{

#if RCPP_SUGAR_LENGTH_CHECKS

    // Kept out of line: inlining the error path keeps the compiler from
    // optimizing the loops that follow these checks.
#if defined(__GNUC__)
    __attribute__((noinline, cold))
#endif
    inline void NORET stop_sizes(const char* fmt, R_xlen_t n1, R_xlen_t n2) {
        stop(fmt, n1, n2);
    }

    // Sugar doesn't recycle the way R does: the vectors an expression
    // combines must all have the same length.
    inline void check_sizes(R_xlen_t n1, R_xlen_t n2) {
        if (n1 != n2)
            stop_sizes("sugar operands have different lengths (%d and %d)", n1, n2);
    }

    // Likewise, a vector assigned into a range, row or column must have the
    // same length as that target.
    inline void check_assign_size(R_xlen_t target, R_xlen_t value) {
        if (target != value)
            stop_sizes("cannot assign a vector of length %d to a target of length %d", value, target);
    }

#else

    // Checks disabled (the default in released versions, see config.h): the
    // result is sized by the first operand, or by the target, as it always
    // was, and a longer operand is cut short.
    inline void check_sizes(R_xlen_t, R_xlen_t) {}
    inline void check_assign_size(R_xlen_t, R_xlen_t) {}

#endif

    inline void check_sizes(R_xlen_t n1, R_xlen_t n2, R_xlen_t n3) {
        check_sizes(n1, n2);
        check_sizes(n1, n3);
    }

} // sugar
} // Rcpp

#endif
