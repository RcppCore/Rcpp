// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// MatrixColumn.h: Rcpp R/C++ interface class library -- columns of matrices
//
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

#ifndef Rcpp__MatrixColumn_h
#define Rcpp__MatrixColumn_h

#include <RcppCommon.h>
#include <Rcpp/VectorBase.h>

namespace Rcpp{

template <typename VECTOR>
class MatrixColumn {
public:

	typedef typename VECTOR::reference reference ;
	typedef typename VECTOR::value_type value_type ;
	typedef typename VECTOR::iterator iterator ;
	
	MatrixColumn( VECTOR& object, int i ) : parent(object), index(i){
		if( ! ::Rf_isMatrix(parent) ) throw VectorBase::not_a_matrix() ;
		if( i < 0 || i >= parent.ncol() ) throw RObject::index_out_of_bounds() ;
	}
	
	MatrixColumn( const MatrixColumn& other ) : parent(other.parent), index(other.index){} ;
	
	MatrixColumn& operator=( MatrixColumn& other ){
		if( other.size() != size() ) throw std::range_error( "not compatible" ) ;
		std::copy( other.begin(), other.end(), begin() ) ;
		return *this ;
	}
	
	reference operator[]( const int& i ){
		/* TODO: should we cache nrow and ncol */
		return parent[ index * parent.ncol() + i ] ;
	}
	
	iterator begin(){
		return parent.begin() + index * parent.ncol() ;
	}
	
	iterator end(){
		return parent.begin() + index * parent.ncol() + parent.nrow() ;
	}
	
	inline int size() const {
		return parent.nrow() ;
	}
	
private:
	VECTOR& parent; 
	int index ;
} ;
	
	
} // namespace Rcpp
#endif
