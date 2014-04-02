// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// DateVector.h: Rcpp R/C++ interface class library -- Date vector support
//
// Copyright (C) 2010 - 2013    Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__DateVector_h
#define Rcpp__DateVector_h

#include <RcppCommon.h>
#include <Rcpp/internal/GreedyVector.h>

namespace Rcpp {

    class DateVector : public GreedyVector<Date, DateVector> {
    public:
        DateVector(SEXP vec) : GreedyVector<Date, DateVector>(vec){}
        DateVector(int n) : GreedyVector<Date, DateVector>(n){}

        inline std::vector<Date> getDates() const{
            return v ;
        }

    };
}

#endif
