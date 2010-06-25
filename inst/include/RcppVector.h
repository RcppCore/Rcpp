// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppVector.h: Rcpp R/C++ interface class library -- templated vector support
//
// Copyright (C) 2005 - 2006 Dominick Samperi
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
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

#ifndef RcppVector_h
#define RcppVector_h

#include <RcppCommon.h>

template <typename T>
class RcppVector {
public:
	typedef T* iterator ;
	typedef const T* const_iterator ;
	
    RcppVector(SEXP vec);
    RcppVector(int len);
    int size() const;
    T& operator()(int i) const; 
    T *cVector() const;
    std::vector<T> stlVector() const;
    
    inline const_iterator begin() const { return v ; }
    inline const_iterator end() const { return v + len ; }
    
    inline iterator begin(){ return v ; }
    inline iterator end(){ return v + len ; }
    
private:
    int len;
    T *v;
};

template <typename T> 
RcppVector<T>::RcppVector(SEXP vec) {
    int i;

    // The function Rf_isVector returns TRUE for vectors AND
    // matrices, so it does not distinguish. We could
    // check the dim attribute here to be sure that it
    // is not present (i.e., dimAttr == R_NilValue, not 0!).
    // But it is easier to simply check if it is set via
    // Rf_isMatrix (in which case we don't have a vector).
    if (!Rf_isNumeric(vec) || Rf_isMatrix(vec) || Rf_isLogical(vec))
	throw std::range_error("RcppVector: invalid numeric vector in constructor");
    len = Rf_length(vec);
    v = (T *) R_alloc(len, sizeof(T));
    if (Rf_isInteger(vec)) {
	for (i = 0; i < len; i++)
	    v[i] = (T)(INTEGER(vec)[i]);
    }	
    else if (Rf_isReal(vec)) {
    for (i = 0; i < len; i++)
	    v[i] = (T)(REAL(vec)[i]);
    }
}

template <typename T>
RcppVector<T>::RcppVector(int _len) {
    len = _len;
    v = (T *) R_alloc(len, sizeof(T));
    std::fill( v, v + len, 0 ) ;
}

template <typename T>
int RcppVector<T>::size() const { 
    return len; 
}

template <typename T>
inline T& RcppVector<T>::operator()(int i) const {
    if (i < 0 || i >= len) {
	std::ostringstream oss;
	oss << "RcppVector: subscript out of range: " << i;
	throw std::range_error(oss.str());
    }
    return v[i];
}

template <typename T>
T *RcppVector<T>::cVector() const {
    T* tmp = (T *)R_alloc(len, sizeof(T));
    std::copy( v, v+len, tmp ) ;
    return tmp;
}

template <typename T>
std::vector<T> RcppVector<T>::stlVector() const {
    return std::vector<T> tmp( v, v + len );
}

#endif
