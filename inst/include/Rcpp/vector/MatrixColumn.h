// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// MatrixColumn.h: Rcpp R/C++ interface class library -- matrices column
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

#ifndef Rcpp__vector__MatrixColumn_h
#define Rcpp__vector__MatrixColumn_h
   
template <int RTYPE>
class MatrixColumn : public VectorBase<RTYPE,true,MatrixColumn<RTYPE> > {
public:
	typedef Matrix<RTYPE> MATRIX ;
	typedef typename MATRIX::Proxy Proxy ;
	typedef typename MATRIX::value_type value_type ;
	typedef typename MATRIX::iterator iterator ;
	
	MatrixColumn( MATRIX& object, int i ) : parent(object), index(i){
		if( i < 0 || i >= parent.ncol() ) throw index_out_of_bounds() ;
	}
	
	MatrixColumn( const MatrixColumn& other ) : parent(other.parent), index(other.index){} ;
	
	MatrixColumn& operator=( MatrixColumn& other ){
		parent = other.parent ;
		index  = other.index ;
	}

//	template <int RT, bool NA, typename T>
//	MatrixColumn& operator=( const Rcpp::VectorBase<RT,NA,T>& rhs ){
//	    std::copy( rhs.begin(), rhs.end(), begin() )  ;
//	}

	Proxy operator[]( int i ){
		/* TODO: should we cache nrow and ncol */
		return parent[ get_parent_index(i) ] ;
	}
	
	Proxy operator[]( int i ) const {
		/* TODO: should we cache nrow and ncol */
		return parent[ get_parent_index(i) ] ;
	}
	
	inline iterator begin(){
		return parent.begin() + index * parent.nrow() ;
	}
	
	inline iterator begin() const {
		return parent.begin() + index * parent.nrow() ;
	}
	
	inline iterator end(){
		return begin() + parent.nrow() ;
	}
	
	inline iterator end() const {
		return begin() + parent.nrow() ;
	}
	
	inline int size() const {
		return parent.nrow() ;
	}
	
private:
	MATRIX& parent; 
	int index ;
	
	inline int get_parent_index(int i) const { return index * parent.nrow() + i ; }
} ;

#endif
