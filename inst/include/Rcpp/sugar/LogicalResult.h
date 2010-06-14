// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// LogicalResult.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__sugar__LogicalResult_h
#define Rcpp__sugar__LogicalResult_h

namespace Rcpp{
namespace sugar{  

template <typename T>
class LogicalResult {
public:
	
	LogicalResult() {} ;
		
	inline int operator[]( int i){
		return static_cast<T*>(this)->operator[]( i ) ;
	}
	
	inline int size(){
		return static_cast<T&>(*this).size() ;
	}
	
public:
	
	class iterator {
	public:
		typedef int difference_type ;
		typedef int value_type ;
		typedef const int* pointer ;
		typedef int reference ;
		typedef std::random_access_iterator_tag iterator_category ;
		
		iterator( const LogicalResult& comp_, int index_ = 0 ) : 
			comp(comp_), index(index_) {}
		                                                     
		inline difference_type operator-( const iterator& other ){
			return index - other.index ;
		}
		inline bool operator==( const iterator& other ){
			return index == other.index ;
		}
		inline bool operator<( const iterator& other ){
			return index < other.index ;
		}
		inline bool operator>( const iterator& other ){
			return index > other.index ;
		}
		inline bool operator<=( const iterator& other ){
			return index <= other.index ;
		}
		inline bool operator>=( const iterator& other ){
			return index >= other.index ;
		}
		inline bool operator!=( const iterator& other ){
			return index != other.index ;
		}
		
		inline reference operator*(){
			return comp[index] ;
		}
		inline pointer operator->(){
			return &comp[index] ;
		}

		inline iterator& operator++(){
			index++; 
			return *this ;
		}
		inline iterator& operator++(int){
			index++ ;
			return *this ;
		}
		inline iterator& operator--(){
			index-- ;
			return *this ;
		}
		inline iterator& operator--(int){
			index-- ;
			return *this ;
		}
		inline iterator& operator+=(difference_type n) {
			index += n ;
			return *this ;
		}
		inline iterator& operator-=(difference_type n) {
			index -= n ;
			return *this ;
		}
		
		inline iterator operator+(difference_type n) const {
			return iterator( comp, index + n ) ;
		}
		inline iterator operator-(difference_type n) const {
			return iterator( comp, index - n ) ;
		}

	private:
		const LogicalResult& comp ;
		int index ;
	} ;
	
	inline iterator begin() const { return iterator(*this, 0 ) ; }
	inline iterator end() const { return iterator(*this, size() ) ; }

	
} ;

}
}

#endif
