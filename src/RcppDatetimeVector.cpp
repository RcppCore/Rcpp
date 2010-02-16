// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppDatetimeVector.cpp: Rcpp R/C++ interface class library -- Datetime vector support
//
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
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

#include <RcppDatetimeVector.h>

RcppDatetimeVector::RcppDatetimeVector(SEXP vec) {
    int i;
    if (!Rf_isNumeric(vec) || Rf_isMatrix(vec) || Rf_isLogical(vec))
	throw std::range_error("RcppDatetimeVector: invalid numeric vector in constructor");
    int len = Rf_length(vec);
    if (len == 0)
	throw std::range_error("RcppDatetimeVector: null vector in constructor");
    v = new RcppDatetime[len];
    for (i = 0; i < len; i++)
	v[i] = RcppDatetime(REAL(vec)[i]);
    length = len;
}

RcppDatetimeVector::~RcppDatetimeVector() {
    delete [] v;
}

RcppDatetime & RcppDatetimeVector::operator()(int i) const {
    if (i < 0 || i >= length) {
	std::ostringstream oss;
	oss << "RcppDatetimeVector: subscript out of range: " << i;
	throw std::range_error(oss.str());
    }
    return v[i];
}

int RcppDatetimeVector::size() const { 
    return length; 
}

