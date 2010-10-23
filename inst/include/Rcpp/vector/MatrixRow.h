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
class MatrixRow : public VectorBase< RTYPE, true, MatrixRow<RTYPE> > {
public:
	typedef Matrix<RTYPE> MATRIX ;
	typedef typename MATRIX::Proxy Proxy ;
	typedef typename MATRIX::Proxy reference ;
	typedef typename MATRIX::value_type value_type ;
	
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
		
		inline reference operator[]( int i){
		    return row[ index + i ] ;
		}
		
		difference_type operator-(const iterator& other) {
			return index - other.index ;
		}
		
	private:
		MatrixRow& row ;
		int index ;
	} ;
	
	MatrixRow( MATRIX& object, int i ) : 
	    parent(object), 
	    start(parent.begin() + i), 
	    parent_nrow(parent.nrow()) 
	{
		if( i < 0 || i >= parent.nrow() ) throw index_out_of_bounds() ;
	}
	
	MatrixRow( const MatrixRow& other ) : 
	    parent(other.parent), 
	    start(other.start), 
	    parent_nrow(other.parent_nrow)
	{} ;
	
	template <int RT, bool NA, typename T>
	MatrixRow& operator=( const Rcpp::VectorBase<RT,NA,T>& rhs ){
	    int n = size() ;
	    const T& ref = rhs.get_ref() ;
	    
	    int __trip_count = n >> 2 ;
        int i = 0 ;
        for ( ; __trip_count > 0 ; --__trip_count) { 
        	start[get_parent_index(i)] = ref[i] ; i++ ;            
        	start[get_parent_index(i)] = ref[i] ; i++ ;            
        	start[get_parent_index(i)] = ref[i] ; i++ ;            
        	start[get_parent_index(i)] = ref[i] ; i++ ;            
        }                                            
        switch (n - i){                          
          case 3:                                    
              start[get_parent_index(i)] = ref[i] ; i++ ;             
          case 2:                                    
              start[get_parent_index(i)] = ref[i] ; i++ ;             
          case 1:                                    
              start[get_parent_index(i)] = ref[i] ; i++ ;             
          case 0:                                    
          default:                                   
              {}                         
        }
	}

	reference operator[]( int i ){
		return start[ get_parent_index(i) ] ;
	}
	
	reference operator[]( int i ) const {
		return start[ get_parent_index(i) ] ;
	}
	
	inline iterator begin(){
		return iterator( *this, 0 ) ;
	}
	
	inline iterator end(){
		return iterator( *this, size() ) ;
	}
	
	inline iterator begin() const {
		return iterator( const_cast<MatrixRow&>(*this), 0 ) ;
	}
	
	inline iterator end() const {
		return iterator( const_cast<MatrixRow&>(*this), size() ) ;
	}
	
	inline int size() const {
		return parent.ncol() ;
	}
	
private:
	MATRIX& parent; 
	typename MATRIX::iterator start ;
	int parent_nrow ;
	
	inline int get_parent_index(int i) const { return i * parent_nrow ; } 
} ;

#endif
