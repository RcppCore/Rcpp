// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// diag.h: Rcpp R/C++ interface class library -- diag
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__sugar__diag_h
#define Rcpp__sugar__diag_h

namespace Rcpp{
namespace sugar{
	
template <int RTYPE, bool NA, typename T>
class Matrix_Diag : public Rcpp::VectorBase< RTYPE ,NA, Matrix_Diag<RTYPE,NA,T> > {
public:
	typedef typename Rcpp::MatrixBase<RTYPE,NA,T> MAT_TYPE ;
	typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
	
	Matrix_Diag( const MAT_TYPE& object_ ) : object(object_), n(0) {
		int nr = object.nrow() ;
		int nc = object.ncol() ;
		n = (nc < nr ) ? nc : nr ;
	}
	
	inline STORAGE operator[]( int i ) const {
		return object( i, i ) ;
	}
	inline int size() const { return n; }
	         
private:
	const MAT_TYPE& object ;
	int n ;
} ;
	
} // sugar

template <int RTYPE,bool NA, typename T>
inline sugar::Matrix_Diag<RTYPE,NA,T> diag( 
	const MatrixBase<RTYPE,NA,T>& t 
	){
	return sugar::Matrix_Diag<RTYPE,NA,T>( t ) ;
}

} // Rcpp
#endif

