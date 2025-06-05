// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// lgrow.h: Rcpp R/C++ interface class library -- grow a (LANGSXP) pairlist
//
// Copyright (C) 2010 - 2025 Dirk Eddelbuettel, Romain Francois, and Kevin Ushey
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

#ifndef Rcpp_lgrow_h
#define Rcpp_lgrow_h

#include <RcppCommon.h>
#include <Rcpp/Named.h>

namespace Rcpp {

inline SEXP lgrow(SEXP head, SEXP tail) {
    return Rf_lcons(head, tail);
}

namespace internal {

// for Named objects
template <typename T>
inline SEXP lgrow__dispatch(Rcpp::traits::true_type, const T& head, SEXP tail) {
    Shield<SEXP> y(wrap(head.object));
    Shield<SEXP> x(Rf_lcons(y, tail));
    SEXP headNameSym = Rf_install(head.name.c_str());
    SET_TAG(x, headNameSym);
    return x;
}

// for all other objects
template <typename T>
inline SEXP lgrow__dispatch(Rcpp::traits::false_type, const T& head, SEXP tail) {
    return lgrow(wrap(head), tail);
}

} // internal

template <typename T>
SEXP lgrow(const T& head, SEXP tail) {
    Shield<SEXP> y(tail);
    return internal::lgrow__dispatch(typename traits::is_named<T>::type(), head, y);
}

inline SEXP lgrow(const char* head, SEXP tail) {
    Shield<SEXP> y(tail);
    return lgrow(Rf_mkString(head), y);
}

template <typename T1>
SEXP langlist(const T1& t1) {
    return lgrow(t1, R_NilValue);
}

template <typename T, typename... TArgs>
SEXP langlist(const T& t1, const TArgs&... args) {
    return lgrow(t1, langlist(args...));
}

} // namespace Rcpp

#endif
