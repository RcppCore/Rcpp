// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// SEXP_Vector.h: Rcpp R/C++ interface class library -- template for expression vector and generic vector
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

#ifndef Rcpp_SEXP_Vector_h
#define Rcpp_SEXP_Vector_h

#include <RcppCommon.h>
#include <Rcpp/exceptions.h>
#include <Rcpp/VectorBase.h>
#include <Rcpp/MatrixRow.h>
#include <Rcpp/MatrixColumn.h>
#include <Rcpp/Environment.h>
#include <Rcpp/Dimension.h>

namespace Rcpp{

template <int RTYPE>
class SEXP_Vector : public VectorBase< SEXP_Vector<RTYPE> > {
public:
	const static int r_type = RTYPE ;
	class NameProxy ;
	class Proxy ;
	typedef VectorBase< SEXP_Vector<RTYPE> > Base ;
	
	class Proxy {
	public:
		Proxy( SEXP_Vector& v, size_t i ) : parent(v), index(i){} ;
		
		Proxy& operator=(SEXP rhs) { 
			set(rhs) ;
			return *this ;
		}
		
		Proxy& operator=(const Proxy& rhs) {
			set(rhs.get());
			return *this ;	
		}
               
		template <typename T>
		Proxy& operator=( const T& rhs){
			set( wrap(rhs) ) ;
			return *this; 
		}
		
		inline operator SEXP() const { return get() ; }
		template <typename U> operator U(){
			return as<U>( get() ) ;
		}
		
		void swap(Proxy& other){
			SEXP tmp = PROTECT( get() ) ;
			set( other.get() ) ;
			other.set( tmp ) ;
			UNPROTECT(1) ;
		}
		
	private:
		SEXP_Vector& parent; 
	public:
		size_t index ;
		inline void move(int n) { index += n ; }
	private:
		inline void set(SEXP x) { SET_VECTOR_ELT( parent, index, x ) ;} 
		inline SEXP get() const { return VECTOR_ELT(parent, index ); } 
	} ;
	
	typedef internal::Proxy_Iterator<SEXP_Vector<RTYPE>,Proxy> iterator ;
	
	class NameProxy {
	public:
		NameProxy( SEXP_Vector& v, const std::string& name_ ) : parent(v), name(name_){} ;
		
		NameProxy& operator=(SEXP rhs) { 
			set( rhs) ; 
			return *this ;
		}
		
		NameProxy& operator=(const NameProxy& rhs){
			set( rhs.get() ) ;
			return *this;
		}
		
		template <typename T>
		NameProxy& operator=( const T& rhs){
			set( wrap(rhs) ) ;
			return *this; 
		}
		
		inline operator SEXP() const { 
			return get() ;
		}
		template <typename U> operator U(){
			return as<U>( get() ) ;
		}
		
	private:
		SEXP_Vector & parent; 
		std::string name ;
		void set(SEXP x) {
			int index = 0 ;
			try{
				index = parent.offset(name) ;
				// parent[ index ] = x ;
			} catch( const index_out_of_bounds& ex ){
				parent.push_back( Named(name, x ) ); 
			}
		}
		
		SEXP get() const {
			return (SEXP) parent[ parent.offset(name) ] ;
		}
	} ;
	
	friend class Proxy;
	friend class NameProxy ;
	
	typedef MatrixRow<SEXP_Vector> Row ;
	typedef MatrixColumn<SEXP_Vector> Column ;
	typedef Proxy reference ;
	typedef Proxy value_type ;
	
	SEXP_Vector() : Base(){} ; 
	
	SEXP_Vector(const SEXP_Vector& other) : Base(){
		Base::setSEXP( other.asSexp() ) ;
	} ;
	
	SEXP_Vector& operator=(const SEXP_Vector& other){
		Base::setSEXP( other.asSexp() ) ;
		return *this ;
	}
	
	SEXP_Vector(SEXP x) : Base() {
		SEXP y = r_cast<RTYPE>(x) ;
		Base::setSEXP( y );
	}
	
	SEXP_Vector(const size_t& size) : Base(size){}
	
	SEXP_Vector(const Dimension& dims) : Base(dims){}

	template <typename InputIterator>
	SEXP_Vector(InputIterator first, InputIterator last) : Base() {
		assign( first, last ) ;
	}
	
#ifdef HAS_INIT_LISTS
	SEXP_Vector( std::initializer_list<SEXP> list) : Base(){
		assign( list.begin(), list.end() ) ;
	} ;
#endif
	
	const NameProxy operator[]( const std::string& name) const {
		return NameProxy( *this, name ) ;
	}
	NameProxy operator[](const std::string& name) {
		return NameProxy( const_cast<SEXP_Vector&>(*this), name ) ;
	}
    	
	inline const Proxy operator[]( int i ) const throw(index_out_of_bounds){
		return Proxy(const_cast<SEXP_Vector&>(*this), Base::offset(i)) ;
	}
	inline Proxy operator[]( int i ) throw(index_out_of_bounds){
		return Proxy(*this, Base::offset(i) ) ; 
	}
	
	inline iterator begin() { return iterator(*this, 0) ; }
	inline iterator end() { return iterator(*this, Base::size() ) ; }
	
	Proxy operator()( const size_t& i) throw(index_out_of_bounds) {
		return Proxy(*this, Base::offset(i) ) ;
	}
	Proxy operator()( const size_t& i, const size_t& j) throw(index_out_of_bounds,not_a_matrix){
		return Proxy(*this, Base::offset(i,j) ) ;
	}
	
	template <typename InputIterator>
	void assign( InputIterator first, InputIterator last){
		/* FIXME: we might not need the wrap if the object already 
		          has the appropriate length */
		Base::setSEXP( r_cast<RTYPE>( wrap( first, last) ) ) ;
	}
	
	template <typename WRAPPABLE>
	void push_back( const WRAPPABLE& t){
		push_back_sexp( wrap(t), false, "" ) ;
	}
	void push_back( const Named& t){
		push_back_sexp( t.getSEXP() , true, t.getTag() ) ;
	}

	template <typename WRAPPABLE>
	void push_front( const WRAPPABLE& t){
		push_front_sexp( wrap(t), false, "" ) ;
	}
	void push_front( const Named& t){
		push_front_sexp( t.getSEXP() , true, t.getTag() ) ;
	}

	template <typename WRAPPABLE>
	iterator insert( iterator position, const WRAPPABLE& object ){
		return insert_sexp( position, wrap(object), false, "" ) ;
	}
	
	template <typename WRAPPABLE>
	iterator insert( int index, const WRAPPABLE& object){
		return insert_sexp( iterator(*this,index), wrap(object), false, "" ) ;
	}
	
	iterator insert( iterator position, const Named& object ){
		return insert_sexp( position, object.getSEXP() , true, object.getTag() ) ;
	}
	
	iterator insert( int index, const Named& object){
		return insert_sexp( iterator(*this,index), object.getSEXP() , true, object.getTag() ) ;
	}
	
	iterator erase( iterator position ){
		erase_single( position.index() ) ;
		return position ;
	}
	iterator erase( int index ){
		erase_single(index) ;
		return iterator(*this,index) ;
	}
	
	iterator erase( iterator first, iterator last){
		erase_range(first.index(), last.index() ) ;
		return first ;
	}
	
	iterator erase( int first, int last){
		erase_range(first, last ) ;
		return iterator( *this, first ) ;
	}
	
	inline Row row( int i){ return Row(*this, i ) ; }
	inline Column column( int i){ return Column(*this, i ) ; }
	
private:
	
	/* 
	   FIXME: this currently loses the attributes of the
	   current object, but then append in R also does. 
	   
	   It is probably not safe to just copy the attributes as is, 
	   as they could for example relate to dimensions or dimnames, etc ...
	   
	   not sure what to do
	   */
	void push_back_sexp( SEXP t, bool named, const std::string& name ){
		if( Base::isNULL() ){ 
			set_single( t, named, name );
		} else {
			push_middle_sexp( Base::size(), t, named, name ) ;
		}
	}
	
	void push_front_sexp( SEXP t, bool named, const std::string& name ){
		if( Base::isNULL() ){ 
			set_single( t, named, name );
		} else {
			push_middle_sexp( 0, t, named, name ) ;
		}
	}
	
	void erase_single( int index ){
		if( index >= Base::size() || index < 0 ) throw index_out_of_bounds() ;
		
		R_len_t n = Base::size() ;
		SEXP x = PROTECT( Rf_allocVector( RTYPE, n-1 ) ) ;
		R_len_t i=0 ;
		for( ; i<index; i++){
			SET_VECTOR_ELT( x, i, VECTOR_ELT(Base::m_sexp, i ) ) ;
		}
		i++; /* skip the one we don't want */
		for( ; i<n; i++){
			SET_VECTOR_ELT( x, i-1, VECTOR_ELT(Base::m_sexp, i ) ) ;
		}
		SEXP names = RCPP_GET_NAMES( Base::m_sexp ) ;
		if( names != R_NilValue ){
			SEXP x_names = PROTECT( Rf_allocVector( STRSXP, n-1) );
			for( i=0; i<index; i++){
				SET_STRING_ELT( x_names, i, STRING_ELT(names, i ) ) ;
			}
			i++ ; /* skip */
			for( ; i<n; i++){
				SET_STRING_ELT( x_names, i-1, STRING_ELT(names, i ) ) ;
			}
			Rf_setAttrib( x, Rf_install("names"), x_names );
			UNPROTECT(1) ; /* x_names */
		} 
		Base::setSEXP( x ); 
		UNPROTECT(1) ; /* x */
	}
	
	void erase_range( int first, int last ){
		if( first > last ) throw std::range_error("invalid range") ;
		if( last >= Base::size() || first < 0 ) throw index_out_of_bounds() ;
		
		int range_size = last - first + 1 ;
		R_len_t n = Base::size() ;
		SEXP x = PROTECT( Rf_allocVector( RTYPE, n - range_size ) ) ;
		R_len_t i=0 ;
		for( ; i<first; i++){
			SET_VECTOR_ELT( x, i, VECTOR_ELT(Base::m_sexp, i ) ) ;
		}
		for( i=last+1; i<n; i++){
			SET_VECTOR_ELT( x, i-range_size, VECTOR_ELT(Base::m_sexp, i ) ) ;
		}
		SEXP names = RCPP_GET_NAMES( Base::m_sexp ) ;
		if( names != R_NilValue ){
			SEXP x_names = PROTECT( Rf_allocVector( STRSXP, n-range_size) );
			for( i=0; i<first; i++){
				SET_STRING_ELT( x_names, i, STRING_ELT(names, i ) ) ;
			}
			for( i=last+1; i<n; i++){
				SET_STRING_ELT( x_names, i-range_size, STRING_ELT(names, i ) ) ;
			}
			Rf_setAttrib( x, Rf_install("names"), x_names );
			UNPROTECT(1) ; /* x_names */
		} 
		Base::setSEXP( x ); 
		UNPROTECT(1) ; /* x */
	}

	
	void push_middle_sexp( int index, SEXP t, bool named, const std::string& name ){
		if( index > Base::size() || index < 0 ) throw index_out_of_bounds() ;
		PROTECT(t) ; /* just in case */
		
		R_len_t n = Base::size() ;
		SEXP x = PROTECT( Rf_allocVector( RTYPE, n+1 ) ) ;
		R_len_t i=0 ;
		for( ; i<index; i++){
			SET_VECTOR_ELT( x, i, VECTOR_ELT(Base::m_sexp, i ) ) ;
		}
		SET_VECTOR_ELT( x, i, t ) ;
		for( ; i<n; i++){
			SET_VECTOR_ELT( x, i+1, VECTOR_ELT(Base::m_sexp, i ) ) ;
		}
		SEXP names = RCPP_GET_NAMES( Base::m_sexp ) ;
		if( names != R_NilValue ){
			SEXP x_names = PROTECT( Rf_allocVector( STRSXP, n+1) );
			for( i=0; i<index; i++){
				SET_STRING_ELT( x_names, i, STRING_ELT(names, i ) ) ;
			}
			SET_STRING_ELT( x_names, i, Rf_mkChar(name.c_str()) ) ;
			for( ; i<n; i++){
				SET_STRING_ELT( x_names, i+1, STRING_ELT(names, i ) ) ;
			}
			Rf_setAttrib( x, Rf_install("names"), x_names );
			UNPROTECT(1) ; /* x_names */
		} else if(named){
			SEXP x_names = PROTECT( Rf_allocVector( STRSXP, n+1) );
			SET_STRING_ELT(x_names, index, Rf_mkChar(name.c_str()) ) ;
			Rf_setAttrib( x, Rf_install("names"), x_names );
			UNPROTECT(1) ; /* x_names */
		}
		Base::setSEXP( x ); 
		UNPROTECT(2) ; /* t, x */
	}

	
	void set_single( SEXP t, bool named, const std::string& name ){
		SEXP x = PROTECT( Rf_allocVector( RTYPE, 1) );
		SET_VECTOR_ELT( x, 0, t ) ;
		if( named ){
			SEXP names = PROTECT( Rf_mkString( name.c_str() ) ) ;
			Rf_setAttrib( x, Rf_install("names"), names) ;
			UNPROTECT(1) ; /* names */
		}
		Base::setSEXP( x ) ;
		UNPROTECT(1) ;
	}
	
	iterator insert_sexp( iterator position, SEXP x, bool named, const std::string& name){
		push_middle_sexp(position.index(), x, named, name ) ;
		/* iterators are lazy, so they stay valid */
		return position ;
	}
	
}   ;

typedef SEXP_Vector<VECSXP> GenericVector ;
typedef GenericVector List ;

} //namespace Rcpp

namespace std {
	template<> inline void swap(Rcpp::SEXP_Vector<VECSXP>::Proxy& a, Rcpp::SEXP_Vector<VECSXP>::Proxy& b) { a.swap(b) ; }
	template<> inline void swap(Rcpp::SEXP_Vector<EXPRSXP>::Proxy& a, Rcpp::SEXP_Vector<EXPRSXP>::Proxy& b) { a.swap(b) ; }
}

#endif
