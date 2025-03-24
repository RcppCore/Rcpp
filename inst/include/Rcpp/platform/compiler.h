// compiler.h: Rcpp R/C++ interface class library -- check compiler
//
// Copyright (C) 2012 - 2025  Dirk Eddelbuettel, Romain Francois, and Kevin Ushey
// Copyright (C) 2025         Dirk Eddelbuettel, Romain Francois, Kevin Ushey and Iñaki Ucar
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

#ifndef Rcpp__platform__compiler_h
#define Rcpp__platform__compiler_h

// NB: A vast list valid identifiers is at these wiki pages:
//     http://sourceforge.net/p/predef/wiki/Home/
#if !defined(__GNUC__) && !defined(__SUNPRO_CC) && !defined(__clang__) && !defined(__INTEL_COMPILER)
#error "This compiler is not supported"
#endif

// Simpler test and minimal standard: C++11 or else we die
#if __cplusplus < 201103L
#error "The C++ compilation standard is too old: use C++11 or newer."
#endif

// C++11 features -- that used to be carefully tested for or worked around via CXX0X / TR1
// These defines are all planned to get removed just how a number have already been removed. One at a time...
#include <cmath>
#include <initializer_list>
#include <unordered_map>
#define RCPP_UNORDERED_MAP std::unordered_map // TODO deprecate
#include <unordered_set>
#define RCPP_UNORDERED_SET std::unordered_set // TODO deprecate

#if defined(__GNUC__)
  #define RCPP_HAS_DEMANGLING
#endif

#endif
