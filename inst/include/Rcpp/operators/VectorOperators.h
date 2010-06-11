// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// VectorOperators.h: Rcpp R/C++ interface class library -- vector operators
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

#ifndef Rcpp__operators_VectorOperators_h
#define Rcpp__operators_VectorOperators_h

namespace Rcpp{

template <int RTYPE>
class LessThan {
public:
	typedef Vector<RTYPE> VEC ;
	typedef typename traits::storage_type<RTYPE>::type STORAGE ;
	
	LessThan( const VEC& lhs_, const VEC& rhs_) : 
		lhs(lhs_), rhs(rhs_){}
	
	inline int operator[]( int i ) const {
		return ( traits::is_na<RTYPE>(lhs[i]) || traits::is_na<RTYPE>(rhs[i]) ) ? 
			NA_LOGICAL : ( lhs[i] < rhs[i] ) ;
	}
	
	class iterator {
	public:
		typedef int difference_type ;
		typedef STORAGE storage_type ;
		typedef int value_type ;
		typedef const int* pointer ;
		typedef int reference ;
		typedef std::random_access_iterator_tag iterator_category ;
		
		iterator( const LessThan& comp_, int index_ = 0 ) : 
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
		const LessThan& comp ;
		int index ;
	} ;
	
	inline iterator begin() const { return iterator(*this, 0 ) ; }
	inline iterator end() const { return iterator(*this, lhs.size() ) ; }
	
private:
	const VEC& lhs ;
	const VEC& rhs ;
	
} ;

}

template <int RTYPE>
inline Rcpp::LessThan<RTYPE> operator<( const Rcpp::Vector<RTYPE>& lhs , const Rcpp::Vector<RTYPE>& rhs ){
	return Rcpp::LessThan<RTYPE>( lhs, rhs ) ;
}


#endif
