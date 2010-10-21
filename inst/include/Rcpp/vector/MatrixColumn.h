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
	
	MatrixColumn( MATRIX& object, int i ) : 
	    parent(object), index(i), start(parent.begin() + i * parent.nrow() )
	{
		if( i < 0 || i >= parent.ncol() ) throw index_out_of_bounds() ;
	}
	
	MatrixColumn( const MatrixColumn& other ) : 
	    parent(other.parent), index(other.index), start(other.start){} ;
	
	template <int RT, bool NA, typename T>
	MatrixColumn& operator=( const Rcpp::VectorBase<RT,NA,T>& rhs ){
	    int n = size() ;
	    const T& ref = rhs.get_ref() ;
	    
	        int __trip_count = n >> 2 ;
            int i = 0 ;
            for ( ; __trip_count > 0 ; --__trip_count) { 
            	start[i] = ref[i] ; i++ ;            
            	start[i] = ref[i] ; i++ ;            
            	start[i] = ref[i] ; i++ ;            
            	start[i] = ref[i] ; i++ ;            
            }                                            
            switch (n - i){                          
              case 3:                                    
                  start[i] = ref[i] ; i++ ;             
              case 2:                                    
                  start[i] = ref[i] ; i++ ;             
              case 1:                                    
                  start[i] = ref[i] ; i++ ;             
              case 0:                                    
              default:                                   
                  {}                         
            }
	}

	Proxy operator[]( int i ){
		/* TODO: should we cache nrow and ncol */
		return start[i] ;
	}
	
	Proxy operator[]( int i ) const {
		/* TODO: should we cache nrow and ncol */
		return start[i] ;
	}
	
	inline iterator begin(){
		return start ;
	}
	
	inline iterator begin() const {
		return start ;
	}
	
	inline iterator end(){
		return start + parent.nrow() ;
	}
	
	inline iterator end() const {
		return start + parent.nrow() ;
	}
	
	inline int size() const {
		return parent.nrow() ;
	}
	
private:
	MATRIX& parent; 
	int index ;     
	iterator start ;

} ;

#endif
