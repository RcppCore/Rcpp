// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// sugar_expressions.cpp: Rcpp R/C++ interface class library -- sugar
// expression lifetime, aliasing, and operand length unit tests
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

#include <Rcpp.h>
using namespace Rcpp;

// Overwrite the stack where any destroyed temporaries used to live, so that
// an expression still referring to them reads garbage.
#if defined(__GNUC__)
__attribute__((noinline))
#endif
void clobber_stack() {
    volatile char buffer[16384];
    for (size_t i = 0; i < sizeof(buffer); i++)
        buffer[i] = 0x7f;
}

// [[Rcpp::export]]
NumericVector lifetime_arith(NumericVector x) {
    auto e = x + x * 2.0;
    clobber_stack();
    return e;
}

// [[Rcpp::export]]
NumericVector lifetime_unary(NumericVector x) {
    auto e = -(x * 2.0);
    clobber_stack();
    return e;
}

// [[Rcpp::export]]
NumericVector lifetime_math(NumericVector x) {
    auto e = sqrt(x * 4.0);
    clobber_stack();
    return e;
}

// [[Rcpp::export]]
LogicalVector lifetime_compare(NumericVector x) {
    auto e = (x * 2.0) > (x + 1.0);
    clobber_stack();
    return e;
}

// [[Rcpp::export]]
NumericVector lifetime_ifelse(NumericVector x) {
    auto e = ifelse(x > 1.0, x * 10.0, x * 0.0);
    clobber_stack();
    return e;
}

// [[Rcpp::export]]
NumericVector lifetime_rev(NumericVector x) {
    auto e = rev(x * 2.0);
    clobber_stack();
    return e;
}

// [[Rcpp::export]]
NumericVector lifetime_rep_scalar() {
    auto e = rep(2.5, 3);
    clobber_stack();
    return e;
}

// [[Rcpp::export]]
NumericVector lifetime_pmax(NumericVector x) {
    auto e = pmax(x * 2.0, x + 1.0);
    clobber_stack();
    return e;
}

// [[Rcpp::export]]
double lifetime_sum(NumericVector x) {
    auto e = sum(x * 2.0);
    clobber_stack();
    return e;
}

// [[Rcpp::export]]
NumericVector lifetime_column(NumericMatrix m) {
    auto e = m(_, 0) + 1.0;
    clobber_stack();
    return e;
}

// [[Rcpp::export]]
NumericVector lifetime_dnorm(NumericVector x) {
    auto e = dnorm(x * 1.0, 0.0, 1.0);
    clobber_stack();
    return e;
}
