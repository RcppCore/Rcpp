
// sugar_safe_math.cpp: Rcpp R/C++ interface class library -- safe math unit tests
//
// Copyright (C) 2026         Iñaki Ucar
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

#define safe_math__has_builtin(x) 0
#include <Rcpp.h>

// [[Rcpp::export]]
int safe_add_fallback(int a, int b){
    return RCPP_SAFE_ADD(a, b);
}

// [[Rcpp::export]]
int safe_sub_fallback(int a, int b){
    return RCPP_SAFE_SUB(a, b);
}

// [[Rcpp::export]]
int safe_mul_fallback(int a, int b){
    return RCPP_SAFE_MUL(a, b);
}
