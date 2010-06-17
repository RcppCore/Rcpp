// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// proxy.h: Rcpp R/C++ interface class library -- proxies
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

#ifndef Rcpp__vector__proxy_h
#define Rcpp__vector__proxy_h

namespace internal{
	template <int RTYPE> class string_proxy ;
	template <int RTYPE> class generic_proxy ;
	
	template <int RTYPE> class simple_name_proxy {
	public:
		typedef ::Rcpp::Vector<RTYPE> VECTOR ;
		typedef typename ::Rcpp::traits::storage_type<RTYPE>::type CTYPE ;
		simple_name_proxy( VECTOR& v, const std::string& name_) :
			parent(v), name(name_){} ;
		simple_name_proxy( const simple_name_proxy& other ) : 
			parent(other.parent), name(other.name){} ;
		~simple_name_proxy() {} ;
		
		simple_name_proxy& operator=( CTYPE rhs ){
			set( rhs ) ;
			return *this ;
		}
		simple_name_proxy& operator=( const simple_name_proxy& other){
			set( other.get() ) ;
			return *this ;
		}
		
		template <typename T>
		simple_name_proxy& operator=( const T& rhs ){
			set( caster<T,CTYPE>(rhs) ) ;
			return *this ;
		}
		
		// TODO: other operators +=, -=, ...
		
		operator CTYPE() const {
			 return get() ;
		}
		
		// this helps wrap, for example : wrap( x["foo"] )
		operator SEXP() const {
			return ::Rcpp::wrap(get()) ;
		}
		
	private:
		VECTOR& parent ;
		std::string name;
		void set( CTYPE rhs ){
			int index = 0 ;
			try{
				index = parent.offset(name) ;
				parent[ index ] = rhs ;
			} catch( const index_out_of_bounds& ex ){
				parent.push_back( rhs, name ); 
			}
		}
		CTYPE get() const {
			return parent[ parent.offset(name) ];
		}
	} ;
	
	template <int RTYPE>
	class string_name_proxy{
	public:
		typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
		typedef const char* iterator ;
		typedef const char& reference ;
		
		string_name_proxy( VECTOR& v, const std::string& name_) :
			parent(v), name(name_){} ;
		string_name_proxy( const string_name_proxy& other ) : 
			parent(other.parent), name(other.name){} ;
		~string_name_proxy(){} ;
		
		string_name_proxy& operator=( const std::string& rhs ){
			set( rhs ) ;
			return *this ;
		}
		string_name_proxy& operator=( const string_name_proxy& other){
			set( other.get() ) ;
			return *this ;
		}
		
		operator char* (){
			 return get() ;
		}
		
		operator SEXP(){
			return ::Rf_mkString(get()) ;
		}
		
		inline iterator begin() { return get() ; }
		inline iterator end(){ return begin() + size() ; }
		inline reference operator[]( int i ){ return *( get() + i ) ; }
		inline int size(){ return strlen( get() ) ; }
		
	private:
		VECTOR& parent ;
		std::string name;
		void set( const std::string& rhs ){
			int index = 0 ;
			try{
				index = parent.offset(name) ;
				parent[ index ] = rhs ;
			} catch( const index_out_of_bounds& ex ){
				parent.push_back( rhs, name ); 
			}
		}
		char* get(){
			return parent[ parent.offset(name) ];
		}
		
	} ;
	
	template <int RTYPE> class generic_name_proxy {
	public:
		typedef ::Rcpp::Vector<RTYPE> VECTOR ;
		generic_name_proxy( VECTOR& v, const std::string& name_) :
			parent(v), name(name_){
				RCPP_DEBUG( "generic_name_proxy( VECTOR& = %p, const string& = %s)", v.asSexp(), name_.c_str() );
		} ;
		generic_name_proxy( const generic_name_proxy& other ) : 
			parent(other.parent), name(other.name){} ;
		~generic_name_proxy(){} ;
		
		generic_name_proxy& operator=( SEXP rhs ){
			set( rhs ) ;
			return *this ;
		}
		generic_name_proxy& operator=( const generic_name_proxy& other){
			set( other.get() ) ;
			return *this ;
		}
		
		template <typename T>
		generic_name_proxy& operator=( const T& rhs ){
			set( ::Rcpp::wrap(rhs) ) ;
			return *this ;
		}
		
		// TODO: other operators +=, -=, ...
		
		operator SEXP(){
			 return get() ;
		}
		
		template <typename T>
		operator T(){
			#if RCPP_DEBUG_LEVEL > 0
			SEXP res = get() ;
			RCPP_DEBUG( "generic_name_proxy::get() = <%p> ", res ) ;
			return ::Rcpp::as<T>( res ) ;
			#else
			return ::Rcpp::as<T>( get() ) ;
			#endif
		}
		
	private:
		VECTOR& parent ;
		std::string name;
		void set( SEXP rhs ){
			int index = 0 ;
			try{
				index = parent.offset(name) ;
				parent[ index ] = rhs ;
			} catch( const index_out_of_bounds& ex ){
				parent.push_back( rhs, name ); 
			}
		}
		SEXP get(){
			return parent[ parent.offset(name) ];
		}
	} ;
}

#endif
