// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// barrier.cpp: Rcpp R/C++ interface class library -- write barrier
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
// Copyright (C) 2011 Google Inc.  All rights reserved.
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

namespace Rcpp{
    namespace int64{

        SEXP int2(int x, int y){
            SEXP res = PROTECT( Rf_allocVector(INTSXP, 2) ) ;
            int* p = INTEGER(res) ;
            p[0] = x;
            p[1] = y ;
            UNPROTECT(1) ;
            return res ;
        }
        
    }
}
