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

// [[Rcpp::export]]
NumericVector alias_rev(NumericVector x) {
    x = rev(x);
    return x;
}

// [[Rcpp::export]]
NumericVector alias_rev_copy(NumericVector x) {
    NumericVector y = x;
    y = rev(x);
    return y;
}

// [[Rcpp::export]]
NumericVector alias_mixed(NumericVector x) {
    x = x + rev(x);
    return x;
}

// [[Rcpp::export]]
NumericVector alias_sapply(NumericVector x) {
    x = sapply(x, [&](double v) { return v - x[0]; });
    return x;
}

// [[Rcpp::export]]
NumericVector alias_elementwise(NumericVector x) {
    x = x * 2.0 + x;
    return x;
}

// [[Rcpp::export]]
NumericVector alias_range_shift(NumericVector x) {
    R_xlen_t n = x.size();
    x[Range(1, n - 1)] = head(x, n - 1);
    return x;
}

// [[Rcpp::export]]
NumericVector alias_range_rev(NumericVector x) {
    R_xlen_t n = x.size();
    x[Range(0, n - 1)] = rev(x);
    return x;
}

// [[Rcpp::export]]
NumericVector alias_range_add_rev(NumericVector x) {
    R_xlen_t n = x.size();
    x[Range(0, n - 1)] += rev(x);
    return x;
}

// [[Rcpp::export]]
NumericMatrix alias_column_rev(NumericMatrix m) {
    m(_, 0) = rev(m(_, 0));
    return m;
}

// [[Rcpp::export]]
NumericMatrix alias_row_rev(NumericMatrix m) {
    m(0, _) = rev(m(0, _));
    return m;
}

// [[Rcpp::export]]
LogicalVector elementwise_flags(NumericVector x, NumericMatrix m) {
    // copy into locals, since binding the static `value` members by
    // reference would require them to have definitions
    bool vector    = traits::is_elementwise<decltype(x)>::value;
    bool arith     = traits::is_elementwise<decltype(x * 2.0 + x)>::value;
    bool math      = traits::is_elementwise<decltype(sqrt(x))>::value;
    bool if_else   = traits::is_elementwise<decltype(ifelse(x > 0.0, x, -x))>::value;
    bool reversed  = traits::is_elementwise<decltype(rev(x))>::value;
    bool arith_rev = traits::is_elementwise<decltype(x + rev(x))>::value;
    bool first     = traits::is_elementwise<decltype(head(x, 1))>::value;
    bool column    = traits::is_elementwise<decltype(m(_, 0) + 1.0)>::value;

    return LogicalVector::create(
        _["vector"]    = vector,
        _["arith"]     = arith,
        _["math"]      = math,
        _["ifelse"]    = if_else,
        _["rev"]       = reversed,
        _["arith_rev"] = arith_rev,
        _["head"]      = first,
        _["column"]    = column
    );
}

// [[Rcpp::export]]
NumericVector length_plus(NumericVector x, NumericVector y) {
    return x + y;
}

// [[Rcpp::export]]
NumericVector length_plus_scalar(NumericVector x) {
    return x + 1.0;
}

// [[Rcpp::export]]
LogicalVector length_compare(NumericVector x, NumericVector y) {
    return x < y;
}

// [[Rcpp::export]]
LogicalVector length_and(LogicalVector x, LogicalVector y) {
    return x & y;
}

// [[Rcpp::export]]
NumericVector length_pmax(NumericVector x, NumericVector y) {
    return pmax(x, y);
}

// [[Rcpp::export]]
NumericVector length_ifelse(LogicalVector cond, NumericVector x, NumericVector y) {
    return ifelse(cond, x, y);
}

// [[Rcpp::export]]
NumericVector length_range(NumericVector x, NumericVector y) {
    x[Range(0, 2)] = y;
    return x;
}

// [[Rcpp::export]]
NumericMatrix length_column(NumericMatrix m, NumericVector y) {
    m(_, 0) = y;
    return m;
}

// [[Rcpp::export]]
NumericMatrix length_row(NumericMatrix m, NumericVector y) {
    m(0, _) = y;
    return m;
}
