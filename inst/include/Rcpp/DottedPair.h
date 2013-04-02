// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// DottedPair.h: Rcpp R/C++ interface class library -- dotted pair list template
//
// Copyright (C) 2010 - 2013 Dirk Eddelbuettel and Romain Francois
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
#include <Rcpp/Named.h>
#include <Rcpp/RObject.h>

namespace Rcpp{ 

class DottedPair : public RObject{
public:

	DottedPair() ;
	
	DottedPair(SEXP x) : RObject(x){} 
	
	DottedPair( const DottedPair& other) : RObject(other.asSexp()){}
	
	DottedPair& operator=( const DottedPair& other) ; 
	
#ifdef HAS_VARIADIC_TEMPLATES
template<typename... Args> 
	DottedPair( const Args&... args) : RObject() {
		setSEXP( pairlist(args...) ) ;
	}
#else

#include <Rcpp/generated/DottedPair__ctors.h> 

#endif	

	/**
	 * wraps an object and add it at the end of the pairlist
	 * (this require traversing the entire pairlist)
	 *
	 * @param object anything that can be wrapped by one 
	 * of the wrap functions, named objects (instances of traits::named_object<> 
	 * are treated specially
	 */
	template <typename T>
	void push_back( const T& object) ;

	/**
	 * wraps an object and add it in front of the pairlist. 
	 *
	 * @param object anything that can be wrapped by one 
	 * of the wrap functions, or an object of class Named
	 */
	template <typename T>
	void push_front( const T& object) ;

	/**
	 * insert an object at the given position, pushing other objects
	 * to the tail of the list
	 *
	 * @param index index (0-based) where to insert
	 * @param object object to wrap
	 */
	template <typename T>
	void insert( const size_t& index, const T& object) ;
	
	/**
	 * replaces an element of the list
	 *
	 * @param index position
	 * @param object object that can be wrapped
	 */
	template <typename T>
	void replace( const int& index, const T& object ) ;

    inline R_len_t length() const { return ::Rf_length(m_sexp) ; }
    inline R_len_t size() const { return ::Rf_length(m_sexp) ; }
	
	/**
	 * Remove the element at the given position
	 *
	 * @param index position where the element is to be removed
	 */
	void remove( const size_t& index ); 
	
	class Proxy {
	public:
		Proxy( DottedPair& v, const size_t& index_ ); 
		
		/* lvalue uses */
		Proxy& operator=(const Proxy& rhs) ; 
		Proxy& operator=(SEXP rhs) ;
		
		template <typename T>
		Proxy& operator=(const T& rhs) ;
		
		template <typename T>
		Proxy& operator=(const traits::named_object<T>& rhs) ;
		
		template <typename T> operator T() const ;
		
		inline SEXP get() const { return CAR(node); }
		inline operator SEXP() const { return get() ; }
		inline Proxy& set(SEXP x){ SETCAR( node, x ) ; return *this ;} 
		inline Proxy& set(SEXP x, const char* name){
            SETCAR( node, x ) ;
            SEXP rhsNameSym = ::Rf_install( name ); // cannot be gc()ed once in symbol table
            SET_TAG( node, rhsNameSym ) ;
            return *this ;
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
