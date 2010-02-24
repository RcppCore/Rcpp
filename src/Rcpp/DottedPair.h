// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// DottedPair.h: Rcpp R/C++ interface class library -- dotted pair list template
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

#ifndef Rcpp_DottedPair_h
#define Rcpp_DottedPair_h

#include <RcppCommon.h>
#include <Rcpp/exceptions.h>

#include <Rcpp/Symbol.h>
#include <Rcpp/grow.h>
#include <Rcpp/Named.h>

#include <Rcpp/RObject.h>

namespace Rcpp{ 

class DottedPair : public RObject{
public:

	DottedPair() ;
	
	DottedPair( const DottedPair& other) : RObject(){
		setSEXP( other.asSexp() ) ;
	}
	
	DottedPair& operator=( const DottedPair& other) ; 
	
#ifdef HAS_VARIADIC_TEMPLATES
template<typename... Args> 
	DottedPair( const Args&... args) : RObject() {
		setSEXP( pairlist(args...) ) ;
	}
#else
/* <code-bloat> */
template <typename T1>
DottedPair( const T1& t1) : RObject() {
	setSEXP( pairlist(t1) );
}
template <typename T1, typename T2>
DottedPair( const T1& t1, const T2& t2) : RObject(){
	setSEXP( pairlist(t1,t2) ); 
}
template <typename T1, typename T2, typename T3>
DottedPair( const T1& t1, const T2& t2, const T3& t3): RObject() {
	setSEXP( pairlist(t1,t2,t3) );
}
template <typename T1, typename T2, typename T3, typename T4>
DottedPair( const T1& t1, const T2& t2, const T3& t3, const T4& t4): RObject(){
	setSEXP( pairlist(t1,t2,t3,t4) );
}
template <typename T1, typename T2, typename T3, typename T4, typename T5>
DottedPair( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5) : RObject() {
	setSEXP( pairlist(t1,t2,t3,t4,t5) );
}
/* </code-bloat> */
#endif	

	/**
	 * wraps an object and add it at the end of the pairlist
	 * (this require traversing the entire pairlist)
	 *
	 * @param object anything that can be wrapped by one 
	 * of the wrap functions, or an object of class Named
	 */
	template <typename T>
	void push_back( const T& object){
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

	/**
	 * wraps an object and add it in front of the pairlist. 
	 *
	 * @param object anything that can be wrapped by one 
	 * of the wrap functions, or an object of class Named
	 */
	template <typename T>
	void push_front( const T& object){
		setSEXP( grow(object, m_sexp) ) ;
	}

	/**
	 * insert an object at the given position, pushing other objects
	 * to the tail of the list
	 *
	 * @param index index (0-based) where to insert
	 * @param object object to wrap
	 */
	template <typename T>
	void insert( const size_t& index, const T& object) throw(index_out_of_bounds) {
		if( index == 0 ) {
			push_front( object ) ;
		} else{
			if( index <  0 ) throw index_out_of_bounds() ;
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
	
	/**
	 * replaces an element of the list
	 *
	 * @param index position
	 * @param object object that can be wrapped
	 */
	template <typename T>
	void replace( const int& index, const T& object ) throw(index_out_of_bounds){
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

        inline R_len_t length() const { return ::Rf_length(m_sexp) ; }
        inline R_len_t size() const { return ::Rf_length(m_sexp) ; }
	
	/**
	 * Remove the element at the given position
	 *
	 * @param index position where the element is to be removed
	 */
	void remove( const size_t& index ) throw(index_out_of_bounds) ; 
	
	class Proxy {
	public:
		Proxy( DottedPair& v, const size_t& index_ ) throw(index_out_of_bounds) ; 
		
		/* lvalue uses */
		Proxy& operator=(const Proxy& rhs) ; 
		Proxy& operator=(SEXP rhs) ;
		
		template <typename T>
		Proxy& operator=(const T& rhs){
			SETCAR( node, wrap(rhs) ) ;
			return *this ;
		}
		Proxy& operator=(const Named& rhs) ;
		
		template <typename T> operator T() const {
			return as<T>( CAR(node) ) ;
		}
		
	private:
		RObject node ;
	} ;
	
	const Proxy operator[]( int i ) const ;
	Proxy operator[]( int i )  ;
	
	friend class Proxy; 
	
	
	
	virtual ~DottedPair() = 0 ;
	
	template <typename T>
	friend DottedPair& operator<<(DottedPair& os, const T& t){
		os.push_back( t ) ;
		return os ;
	}
	
	template <typename T>
	friend DottedPair& operator>>( const T& t, DottedPair& s){
		s.push_front(t);
		return s ;
	}
	
};

} // namespace Rcpp

#endif
