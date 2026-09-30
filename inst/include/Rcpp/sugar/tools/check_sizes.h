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

namespace Rcpp{
namespace sugar{

    // Sugar doesn't recycle the way R does: the vectors an expression
    // combines must all have the same length.
    inline void check_sizes(R_xlen_t n1, R_xlen_t n2) {
        if (n1 != n2)
            stop("sugar operands have different lengths (%d and %d)", n1, n2);
    }

    inline void check_sizes(R_xlen_t n1, R_xlen_t n2, R_xlen_t n3) {
        if (n1 != n2 || n1 != n3)
            stop("sugar operands have different lengths (%d, %d and %d)", n1, n2, n3);
    }

    // Likewise, a vector assigned into a range, row or column must have the
    // same length as that target.
    inline void check_assign_size(R_xlen_t target, R_xlen_t value) {
        if (target != value)
            stop("cannot assign a vector of length %d to a target of length %d", value, target);
    }

} // sugar
} // Rcpp

#endif
