// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// MatrixBase.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__vector__MatrixBase_h
#define Rcpp__vector__MatrixBase_h

namespace Rcpp{
	
/** a base class for vectors, modelled after the CRTP */
template <int RTYPE, bool na, typename MATRIX>
class MatrixBase : public traits::expands_to_logical__impl<RTYPE> {
public:
	struct r_type : traits::integral_constant<int,RTYPE>{} ;
	struct r_matrix_interface {} ;
	struct can_have_na : traits::integral_constant<bool,na>{} ;
	typedef typename traits::storage_type<RTYPE>::type stored_type ;
	
	MATRIX& get_ref(){
		return static_cast<MATRIX&>(*this) ;
	}

	inline stored_type operator[]( int i) const { 
		return static_cast<const MATRIX*>(this)->operator[](i) ;
	}
	
	inline stored_type operator()( int i, int j) throw(not_a_matrix) {
		return static_cast<const MATRIX*>(this)->operator()(i, j) ;
	}
	
	inline int size() const { return static_cast<const MATRIX&>(*this).size() ; }
	inline int nrow() const throw(not_a_matrix) { return static_cast<const MATRIX&>(*this).nrow() ; }
	inline int ncol() const throw(not_a_matrix) { return static_cast<const MATRIX&>(*this).ncol() ; }
	
	class iterator {
	public:
		typedef stored_type reference ;
		typedef stored_type* pointer ;
		typedef int difference_type ;
		typedef stored_type value_type;
		typedef std::random_access_iterator_tag iterator_category ;

		iterator( const MatrixBase& object_, int index_ ) : object(object_), index(index_){} 
		iterator( const iterator& other) : object(other.object), index(other.index){};
		
		inline iterator& operator++(){
			index++ ;
			return *this ;
		}
		inline iterator& operator++(int){
			index++;
			return *this ;
		}
		
		inline iterator& operator--(){
			index-- ;
			return *this ;
		}
		inline iterator& operator--(int){
			index--; 
			return *this ;
		}
		                    
		inline iterator operator+(difference_type n) const {
			return iterator( object, index+n ) ;
		}
		inline iterator operator-(difference_type n) const {
			return iterator( object, index-n ) ;
		}
		
		inline iterator& operator+=(difference_type n) {
			index += n ;
			return *this ;
		}
		inline iterator& operator-=(difference_type n) {
			index -= n; 
			return *this ;
		}

		inline reference operator*() {
			//  TODO: it might be better to call object( i, j )
			//        as in many cases the sugar expression 
			//        is faster with two indexes
			return object[index] ;
		}
		inline pointer operator->(){
			return &object[index] ;
		}
		
		inline bool operator==( const iterator& y) const {
			return ( index == y.index ) ;
		}
		inline bool operator!=( const iterator& y) const {
			return ( index != y.index ) ;
		}
		inline bool operator<( const iterator& other ) const {
			return index < other.index ;
		}
		inline bool operator>( const iterator& other ) const {
			return index > other.index ;
		}
		inline bool operator<=( const iterator& other ) const {
			return index <= other.index ;
		}
		inline bool operator>=( const iterator& other ) const {
			return index >= other.index ;
		}
		
		inline difference_type operator-(const iterator& other) const {
			return index - other.index ;
		}
	
			
	private:
		const MatrixBase& object ;
		int index;
		
		// int i, j ;
		// int nr, nc ;
	} ;
	
	inline iterator begin() const { return iterator(*this, 0) ; }
	inline iterator end() const { return iterator(*this, size() ) ; }
	
} ;

} // namespace Rcpp
#endif
