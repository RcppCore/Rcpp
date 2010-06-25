// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppMatrix_backward.h: Rcpp R/C++ interface class library -- templated matrix support
//
// Copyright (C) 2010	     Dirk Eddelbuettel and Romain Francois
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

#ifndef RcppMatrix__backward_h
#define RcppMatrix__backward_h

#include <RcppCommon.h>

namespace Rcpp{
namespace internal{

	template <typename T>
	SEXP wrap__old__rcppmatrix( const ::RcppMatrix<T>& x ){
		int nx = x.rows() ;
		int ny = x.cols() ;
		Rcpp::Matrix< Rcpp::traits::r_sexptype_traits<T>::rtype > mat( nx, ny ) ;
		for (int i = 0; i < nx; i++)
		for (int j = 0; j < ny; j++)
	    	mat[i + nx*j] = x(i,j);
        return mat ;
	}
}    

template <>
inline SEXP wrap( const RcppMatrix<int>& x){
	return internal::wrap__old__rcppmatrix( x ); 
}
template <>
inline SEXP wrap( const RcppMatrix<double>& x){
	return internal::wrap__old__rcppmatrix( x ); 
}


}

#endif
