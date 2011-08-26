// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// DateVector.cpp: Rcpp R/C++ interface class library -- Date vector support
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
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

#include <Rcpp/DateVector.h>
#include <Rcpp/Date.h>

namespace Rcpp {

    DateVector::DateVector(SEXP vec) : v()  {
        int i;
        if (!Rf_isNumeric(vec) || Rf_isMatrix(vec) || Rf_isLogical(vec))
            throw std::range_error("DateVector: invalid numeric vector in constructor");
        int len = Rf_length(vec);
        if (len == 0)
            throw std::range_error("DateVector: null vector in constructor");
        v.resize(len);
        for (i = 0; i < len; i++)
            v[i] = Date( static_cast<int>(REAL(vec)[i]));
    }


    DateVector::DateVector(int n) : v(n){}

    const Date & DateVector::operator()(int i) const {
        if (i < 0 || i >= static_cast<int>(v.size())) {
            std::ostringstream oss;
            oss << "DateVector: subscript out of range: " << i;
            throw std::range_error(oss.str());
        }
        return v[i];
    }

    Date & DateVector::operator()(int i) {
        if (i < 0 || i >= static_cast<int>(v.size())) {
            std::ostringstream oss;
            oss << "DateVector: subscript out of range: " << i;
            throw std::range_error(oss.str());
        }
        return v[i];
    }

    const Date & DateVector::operator[](int i) const {
        if (i < 0 || i >= static_cast<int>(v.size())) {
            std::ostringstream oss;
            oss << "DatetimeVector: subscript out of range: " << i;
            throw std::range_error(oss.str());
        }
        return v[i];
    }

    Date & DateVector::operator[](int i) {
        if (i < 0 || i >= static_cast<int>(v.size())) {
            std::ostringstream oss;
            oss << "DatetimeVector: subscript out of range: " << i;
            throw std::range_error(oss.str());
        }
        return v[i];
    }

    int DateVector::size() const { 
        return v.size(); 
    }

    std::vector<Date> DateVector::getDates() const {
        return v;
    }

}
