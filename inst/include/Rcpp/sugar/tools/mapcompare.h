// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// mapcompare.h: Rcpp R/C++ interface class library -- comparator for table
//
// Copyright (C) 2012 - 2013   Dirk Eddelbuettel, Romain Francois, and Kevin Ushey
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

#ifndef Rcpp__sugar__tools__mapcompare_h
#define Rcpp__sugar__tools__mapcompare_h

namespace Rcpp {
namespace sugar {

union DoublePunner {
  double d;
  uint64_t p;
};

static const DoublePunner NA_REAL_PUN = { NA_REAL };
static const DoublePunner NAN_REAL_PUN = { R_NaN };

inline bool Rcpp_IsNA(double x) {
  DoublePunner xp = { x };
  return xp.p == NA_REAL_PUN.p;
}

inline bool Rcpp_IsNaN(double x) {
  DoublePunner xp = { x };
  return xp.p == NAN_REAL_PUN.p;
}

inline int StrCmp(SEXP x, SEXP y) {
    if (x == NA_STRING) return (y == NA_STRING ? 0 : 1);
    if (y == NA_STRING) return -1;
    if (x == y) return 0;  // same string in cache
    return strcmp(CHAR(x), CHAR(y));
}

template <typename T>
struct MapCompare {
  inline bool operator()(T left, T right) const {
    return left < right;
  }
};

template <>
struct MapCompare<int> {
  inline bool operator()(int left, int right) const {
    if (left == NA_INTEGER) return false;
    if (right == NA_INTEGER) return true;
    return left < right;
  }
};

template <>
struct MapCompare<double> {  
  inline bool operator()(double left, double right) const {
        
    bool leftNaN = (left != left);
    bool rightNaN = (right != right);
    
    // this branch inspired by data.table: see
    // https://github.com/arunsrinivasan/datatable/commit/1a3e476d3f746e18261662f484d2afa84ac7a146#commitcomment-4885242
    if (Rcpp_IsNaN(right) and Rcpp_IsNA(left)) return true;
    
    if (leftNaN != rightNaN) {
      return leftNaN < rightNaN;
    } else {
      return left < right;
    }

  }
  
};

template <>
struct MapCompare<SEXP> {
  inline bool operator()(SEXP left, SEXP right) const {
    return StrCmp(left, right) < 0;
  }
};

}
}

#endif
