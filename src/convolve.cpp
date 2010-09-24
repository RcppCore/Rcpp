// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// convolve.cpp: Rcpp R/C++ interface class library -- coercion
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

#define LOOPMACRO_C(name)                   \
SEXP name##__loop(SEXP n_, SEXP a, SEXP b){ \
    int n = INTEGER(n_)[0] ;                \
    SEXP res  = R_NilValue ;                \
    for( int i=0; i<n; i++){                \
       res = name( a, b ) ;                 \
    }                                       \
    return res ;                            \
}                                          

#define LOOPMACRO_CPP(name) RcppExport LOOPMACRO_C(name)

RcppExport SEXP convolve3cpp(SEXP a, SEXP b){
    Rcpp::NumericVector xa(a);
    Rcpp::NumericVector xb(b);
    int n_xa = xa.size() ;
    int n_xb = xb.size() ;
    int nab = n_xa + n_xb - 1;
    Rcpp::NumericVector xab(nab);

    for (int i = 0; i < n_xa; i++)
        for (int j = 0; j < n_xb; j++) 
            xab[i + j] += xa[i] * xb[j];

    return xab ;
}

LOOPMACRO_CPP(convolve3cpp)

#undef LOOPMACRO_C
#undef LOOPMACRO_CPP
