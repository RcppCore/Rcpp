// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// DottedPair.h: Rcpp R/C++ interface class library --  DottedPair meat
//
// Copyright (C) 2012 - 2013    Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_api_meat_DottedPair_h
#define Rcpp_api_meat_DottedPair_h

namespace Rcpp{ 

    template <typename T>
    DottedPair::Proxy& DottedPair::Proxy::operator=( const T& rhs ){
        return set( wrap( rhs) );
    }
    
    template <typename T> 
    DottedPair::Proxy::operator T() const{ return as<T>(get()); } 

    template <typename T>
	void DottedPair::push_front( const T& object){
		setSEXP( grow(object, m_sexp) ) ;
	}

	template <typename T>
	DottedPair::Proxy& DottedPair::Proxy::operator=(const traits::named_object<T>& rhs){
    	return set( rhs.object, rhs.name.c_str() ) ;
    }
	
	template <typename T>
	void DottedPair::push_back( const T& object){
		if( isNULL() ){
			setSEXP( grow( object, m_sexp ) ) ;
		} else {
			SEXP x = m_sexp ;
			/* traverse the pairlist */
			while( !Rf_isNull(CDR(x)) ){
				x = CDR(x) ;
			}
			SEXP tail = PROTECT( pairlist( object ) ); 
			SETCDR( x, tail ) ;
			UNPROTECT(1) ;
		}
	}

    template <typename T>
	void DottedPair::insert( const size_t& index, const T& object) {
		if( index == 0 ) {
			push_front( object ) ;
		} else{
		    // tautological comparison flagged by clang++
//			if( index <  0 ) throw index_out_of_bounds() ;
			if( isNULL( ) ) throw index_out_of_bounds() ;
			
			if( static_cast<R_len_t>(index) > ::Rf_length(m_sexp) ) throw index_out_of_bounds() ;
			
			size_t i=1;
			SEXP x = m_sexp ;
			while( i < index ){
				x = CDR(x) ;
				i++; 
			}
			SEXP tail = PROTECT( grow( object, CDR(x) ) ) ; 
			SETCDR( x, tail ) ;
			UNPROTECT(1) ;
		}
	}
	
	template <typename T>
	void DottedPair::replace( const int& index, const T& object ) {
 	        if( static_cast<R_len_t>(index) >= ::Rf_length(m_sexp) ) throw index_out_of_bounds() ;
		
		/* pretend we do a pairlist so that we get Named to work for us */
		SEXP x = PROTECT(pairlist( object ));
		SEXP y = m_sexp ;
		int i=0;
		while( i<index ){ y = CDR(y) ; i++; }
		
		SETCAR( y, CAR(x) );
		SET_TAG( y, TAG(x) );
		UNPROTECT(1) ;
	}

	
} // namespace Rcpp

#endif
