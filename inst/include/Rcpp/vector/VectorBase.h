// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// VectorBase.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__vector__VectorBase_h
#define Rcpp__vector__VectorBase_h

namespace Rcpp{
	
/** a base class for vectors, modelled after the CRTP */
template <int RTYPE, bool na, typename VECTOR>
class VectorBase {
public:
	struct r_type : traits::integral_constant<int,RTYPE>{} ;
	struct can_have_na : traits::integral_constant<bool,na>{} ;
	typedef typename traits::storage_type<RTYPE>::type stored_type ;
	
	VECTOR& get_ref(){
		return static_cast<VECTOR&>(*this) ;
	}

	inline stored_type operator[]( int i) const { return static_cast<const VECTOR*>(this)->operator[](i) ; }
	
	inline int size() const { return static_cast<const VECTOR*>(this)->size() ; }
	
	class iterator {
	public:
		typedef stored_type reference ;
		typedef stored_type* pointer ;
		typedef int difference_type ;
		typedef stored_type value_type;
		typedef std::random_access_iterator_tag iterator_category ;

		iterator( const VectorBase& object_, int index_ ) : object(object_), index(index_){} 
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
		const VectorBase& object ;
		int index; 
	} ;
	
	inline iterator begin() const { return iterator(*this, 0) ; }
	inline iterator end() const { return iterator(*this, size() ) ; }
	
} ;

} // namespace Rcpp
#endif
