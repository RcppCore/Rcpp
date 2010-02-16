// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppMatrixView.cpp: Rcpp R/C++ interface class library -- templated matrix view
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

#include <RcppMatrixView.h>

template <typename T>
RcppMatrixView<T>::RcppMatrixView(SEXP mat) {
    if (!Rf_isNumeric(mat) || !Rf_isMatrix(mat))
	throw std::range_error("RcppMatrixView: invalid numeric matrix in constructor");
    // Get matrix dimensions
    SEXP dimAttr = Rf_getAttrib(mat, R_DimSymbol);
    d1 = INTEGER(dimAttr)[0];
    d2 = INTEGER(dimAttr)[1];
    if (Rf_isInteger(mat)) {
	a = (T *)(INTEGER(mat));
    } else if (Rf_isReal(mat)) {
	a = (T *)(REAL(mat));
    }
}

template <typename T>
inline int RcppMatrixView<T>::dim1() const { 
    return d1; 
}

template <typename T>
inline int RcppMatrixView<T>::dim2() const { 
    return d2; 
}

template <typename T>
inline int RcppMatrixView<T>::rows() const { 
    return d1; 
}

template <typename T>
inline int RcppMatrixView<T>::cols() const { 
    return d2; 
}

template <typename T>
inline T RcppMatrixView<T>::operator()(int i, int j) const {
    if (i < 0 || i >= d1 || j < 0 || j >= d2) {
	std::ostringstream oss;
	oss << "RcppMatrixView: subscripts out of range: " << i << ", " << j;
	throw std::range_error(oss.str());
    }
    return a[i + d1 * j];
}

template class RcppMatrixView<int>;
template class RcppMatrixView<double>;


