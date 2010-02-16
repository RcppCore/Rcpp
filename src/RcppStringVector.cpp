// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppStringVector.cpp: Rcpp R/C++ interface class library -- string vector support
//
// Copyright (C) 2005 - 2006 Dominick Samperi
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

#include <RcppStringVector.h>

RcppStringVector::RcppStringVector(SEXP vec) {
    int i;
    if (Rf_isMatrix(vec) || Rf_isLogical(vec))
	throw std::range_error("RcppStringVector: invalid numeric vector in constructor");
    if (!Rf_isString(vec))
	throw std::range_error("RcppStringVector: invalid string");
    int len = Rf_length(vec);
    if (len == 0)
	throw std::range_error("RcppStringVector: null vector in constructor");
    v = new std::string[len];
    for (i = 0; i < len; i++)
	v[i] = std::string(CHAR(STRING_ELT(vec,i)));
    length = len;
}

RcppStringVector::~RcppStringVector() {
    delete [] v;
}

std::string& RcppStringVector::operator()(int i) const {
    if (i < 0 || i >= length) {
	std::ostringstream oss;
	oss << "RcppStringVector: subscript out of range: " << i;
	throw std::range_error(oss.str());
    }
    return v[i];
}

int RcppStringVector::size() const { 
    return length; 
}

std::vector<std::string> RcppStringVector::stlVector() const {
    std::vector<std::string> tmp(length);
    for (int i = 0; i < length; i++)
	tmp[i] = v[i];
    return tmp;
}
