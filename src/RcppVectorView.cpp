// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppVectorView.cpp: Rcpp R/C++ interface class library -- templated vector view
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

#include <RcppVectorView.h>

template <typename T>
RcppVectorView<T>::RcppVectorView(SEXP vec) {
    if (!Rf_isNumeric(vec) || Rf_isMatrix(vec) || Rf_isLogical(vec))
	throw std::range_error("RcppVectorView: invalid numeric vector in constructor");
    len = Rf_length(vec);
    if (Rf_isInteger(vec)) {
	v = (T *)(INTEGER(vec));
    } else if (Rf_isReal(vec)) {
	v = (T *)(REAL(vec));
    }
}

template <typename T>
inline int RcppVectorView<T>::size() const { 
    return len; 
}

template <typename T>
inline T RcppVectorView<T>::operator()(int i) const {
    if (i < 0 || i >= len) {
	std::ostringstream oss;
	oss << "RcppVectorView: subscript out of range: " << i;
	throw std::range_error(oss.str());
    }
    return v[i];
}

template class RcppVectorView<int>;
template class RcppVectorView<double>;

