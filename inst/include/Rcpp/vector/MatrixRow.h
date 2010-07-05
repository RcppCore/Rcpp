// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// MatrixRow.h: Rcpp R/C++ interface class library -- matrices row
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

#ifndef Rcpp__vector__MatrixRow_h
#define Rcpp__vector__MatrixRow_h
   
template <int RTYPE>
class MatrixRow {
public:
	typedef Matrix<RTYPE> MATRIX ;
	typedef typename MATRIX::Proxy Proxy ;
	typedef typename MATRIX::Proxy reference ;
	
	class iterator {
	public:
		typedef typename traits::r_vector_iterator<RTYPE>::type vector_iterator ;
		
		typedef int difference_type ;
		typedef typename traits::r_vector_proxy<RTYPE>::type value_type ;
		typedef typename traits::r_vector_proxy<RTYPE>::type reference ;
		typedef typename std::iterator_traits<vector_iterator>::pointer pointer ;
	
		typedef std::random_access_iterator_tag iterator_category ;
		
		iterator( MatrixRow& row_, int index_ ) : row(row_), index(index_){}
		
		iterator& operator++(){ 
			index++;
			return *this ;
		}
		iterator& operator++(int) { 
			index++;
			return *this ;
		}
	
		iterator& operator--(){ 
			index-- ;
			return *this ;
		} 
		iterator& operator--(int){ 
			index-- ;
			return *this ;
		}
		                    
		iterator operator+(difference_type n) const { return iterator( row, index + n ) ; }
		iterator operator-(difference_type n) const { return iterator( row, index - n ) ; }
		
		iterator& operator+=(difference_type n) { index += n ; return *this ;} 
		iterator& operator-=(difference_type n) { index -= n ; return *this ;} 
        	
		reference operator*() {
			return row[index] ;
		}
		pointer operator->(){
			return &row[index] ;
		}
		
		bool operator==( const iterator& other) { return index == other.index ; } 
		bool operator!=( const iterator& other) { return index != other.index ; }
		bool operator<( const iterator& other ) { return index < other.index ;}
		bool operator>( const iterator& other ) { return index > other.index ;}
		bool operator<=( const iterator& other ) { return index <= other.index ; }
		bool operator>=( const iterator& other ) { return index >= other.index ; }
		
		difference_type operator-(const iterator& other) {
			return index - other.index ;
		}
		
	private:
		MatrixRow& row ;
		int index ;
	} ;
	
	MatrixRow( MATRIX& object, int i ) : parent(object), index(i){
		if( i < 0 || i >= parent.nrow() ) throw index_out_of_bounds() ;
	}
	
	MatrixRow( const MatrixRow& other ) : parent(other.parent), index(other.index){} ;
	                          
	MatrixRow& operator=( MatrixRow& other ){
		parent = other.parent ;
		index = other.index ;
		return *this ;
	}
	
	reference operator[]( const int& i ){
		/* TODO: should we cache nrow and ncol */
		return parent[ index + i * parent.nrow() ] ;
	}
	
	inline iterator begin(){
		return iterator( *this, 0 ) ;
	}
	
	inline iterator end(){
		return iterator( *this, size() ) ;
	}
	
	inline int size() const {
		return parent.ncol() ;
	}
	
private:
	MATRIX& parent; 
	int index ;
} ;

#endif
