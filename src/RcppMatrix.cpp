// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppMatrix.h: Rcpp R/C++ interface class library -- templated matrix support
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

#include <RcppMatrix.h>

template <typename T>
RcppMatrix<T>::RcppMatrix(SEXP mat) {

    if (!Rf_isNumeric(mat) || !Rf_isMatrix(mat))
	throw std::range_error("RcppMatrix: invalid numeric matrix in constructor");

    // Get matrix dimensions
    SEXP dimAttr = Rf_getAttrib(mat, R_DimSymbol);
    dim1 = INTEGER(dimAttr)[0];
    dim2 = INTEGER(dimAttr)[1];

    // We guard against  the possibility that R might pass an integer matrix.
    // Can be prevented using R code: temp <- as.double(a), dim(temp) <- dim(a)
    int i,j;
    int isInt = Rf_isInteger(mat);
    T *m = (T *)R_alloc(dim1*dim2, sizeof(T));
    a = (T **)R_alloc(dim1, sizeof(T *));
    for (i = 0; i < dim1; i++)
	a[i] = m + i*dim2;
    if (isInt) {
	for (i=0; i < dim1; i++)
	    for (j=0; j < dim2; j++)
		a[i][j] = (T)(INTEGER(mat)[i+dim1*j]);
    }	
    else {
	for (i=0; i < dim1; i++)
	    for (j=0; j < dim2; j++)
		a[i][j] = (T)(REAL(mat)[i+dim1*j]);
    }	
}

template <typename T>
RcppMatrix<T>::RcppMatrix(int _dim1, int _dim2) {
    dim1 = _dim1;
    dim2 = _dim2;
    int i,j;
    T *m = (T *)R_alloc(dim1*dim2, sizeof(T));
    a = (T **)R_alloc(dim1, sizeof(T *));
    for (i = 0; i < dim1; i++)
	a[i] = m + i*dim2;
    for (i=0; i < dim1; i++)
	for (j=0; j < dim2; j++)
	    a[i][j] = 0;
}

template <typename T> int RcppMatrix<T>::getDim1() const { 
    return dim1; 
}

template <typename T> int RcppMatrix<T>::getDim2() const { 
    return dim2; 
}

template <typename T> int RcppMatrix<T>::rows() const { 
    return dim1; 
}

template <typename T> int RcppMatrix<T>::cols() const { 
    return dim2; 
}

template <typename T>
T& RcppMatrix<T>::operator()(int i, int j) const {
    if (i < 0 || i >= dim1 || j < 0 || j >= dim2) {
	std::ostringstream oss;
	oss << "RcppMatrix: subscripts out of range: " << i << ", " << j;
	throw std::range_error(oss.str());
    }
    return a[i][j];
}

template <typename T>
T **RcppMatrix<T>::cMatrix() {
    int i,j;
    T *m = (T *)R_alloc(dim1*dim2, sizeof(T));
    T **tmp = (T **)R_alloc(dim1, sizeof(T *));
    for (i = 0; i < dim1; i++)
	tmp[i] = m + i*dim2;
    for (i=0; i < dim1; i++)
	for (j=0; j < dim2; j++)
	    tmp[i][j] = a[i][j];
    return tmp;
}

template <typename T>
std::vector<std::vector<T> > RcppMatrix<T>::stlMatrix() {
    int i,j;
    std::vector<std::vector<T> > temp;
    for (i = 0; i < dim1; i++) {
	temp.push_back(std::vector<T>(dim2));
    }
    for (i = 0; i < dim1; i++)
	for (j = 0; j < dim2; j++)
	    temp[i][j] = a[i][j];
    return temp;
}

// Explicit instantiation (required for external linkage)
template class RcppMatrix<int>;
template class RcppMatrix<double>;

