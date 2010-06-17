// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// traits.h: Rcpp R/C++ interface class library -- support traits for vector
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

#ifndef Rcpp__vector__traits_h
#define Rcpp__vector__traits_h
 
namespace traits{

	template <int RTYPE> struct r_vector_element_converter{
		typedef typename ::Rcpp::internal::element_converter<RTYPE> type ;
	} ;
	template<> struct r_vector_element_converter<STRSXP>{
		typedef ::Rcpp::internal::string_element_converter<STRSXP> type ;
	} ;
	template<> struct r_vector_element_converter<VECSXP>{
		typedef ::Rcpp::internal::generic_element_converter<VECSXP> type ;
	} ;
	template<> struct r_vector_element_converter<EXPRSXP>{
		typedef ::Rcpp::internal::generic_element_converter<EXPRSXP> type ;
	} ;
	
	template <int RTYPE> 
	struct r_vector_name_proxy{
		typedef typename ::Rcpp::internal::simple_name_proxy<RTYPE> type ;
	} ;
	template<> struct r_vector_name_proxy<STRSXP>{
		typedef ::Rcpp::internal::string_name_proxy<STRSXP> type ;
	} ;
	template<> struct r_vector_name_proxy<VECSXP>{
		typedef ::Rcpp::internal::generic_name_proxy<VECSXP> type ;
	} ;
	template<> struct r_vector_name_proxy<EXPRSXP>{
		typedef ::Rcpp::internal::generic_name_proxy<EXPRSXP> type ;
	} ;
	
	template <int RTYPE>
	struct r_vector_proxy{
		typedef typename storage_type<RTYPE>::type& type ;
	} ;
	template<> struct r_vector_proxy<STRSXP> {
		typedef ::Rcpp::internal::string_proxy<STRSXP> type ;
	} ;
	template<> struct r_vector_proxy<EXPRSXP> {
		typedef ::Rcpp::internal::generic_proxy<EXPRSXP> type ;
	} ;
	template<> struct r_vector_proxy<VECSXP> {
		typedef ::Rcpp::internal::generic_proxy<VECSXP> type ;
	} ;
	
	template <int RTYPE>
	struct r_vector_iterator {
		typedef typename storage_type<RTYPE>::type* type ;
	};
	template <int RTYPE> struct proxy_based_iterator{
		typedef ::Rcpp::internal::Proxy_Iterator< typename r_vector_proxy<RTYPE>::type > type ;
	} ;
	template<> struct r_vector_iterator<VECSXP> : proxy_based_iterator<VECSXP>{} ;
	template<> struct r_vector_iterator<EXPRSXP> : proxy_based_iterator<EXPRSXP>{} ;
	template<> struct r_vector_iterator<STRSXP> : proxy_based_iterator<STRSXP>{} ;
	
	template <int RTYPE>
	class r_vector_cache{
	public:
		typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
		typedef typename r_vector_iterator<RTYPE>::type iterator ;
		typedef typename r_vector_proxy<RTYPE>::type proxy ;
		typedef typename storage_type<RTYPE>::type storage_type ;
		
		r_vector_cache() : start(0){} ;
		void update( const VECTOR& v ) {
			start = ::Rcpp::internal::r_vector_start<RTYPE,storage_type>(v.asSexp()) ;
		}
		inline iterator get() const { return start; }
		inline iterator get(int i) const { return start + i ; }
		inline proxy ref() const { return *start ;}
		inline proxy ref(int i) const { return *(start+i) ; }
		
		private:
			iterator start ;
	} ;
	template <int RTYPE> class proxy_cache{
	public:
		typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
		typedef typename r_vector_iterator<RTYPE>::type iterator ;
		typedef typename r_vector_proxy<RTYPE>::type proxy ;
		
		proxy_cache(): p(0){}
		~proxy_cache(){}
		void update( const VECTOR& v ){
			p = const_cast<VECTOR*>(&v) ;
		}
		inline iterator get() const { return iterator( proxy(*p, 0 ) ) ;}
		inline iterator get(int i) const { return iterator( proxy(*p, i ) ) ;}
		inline proxy ref() const { return proxy(*p,0) ; }
		inline proxy ref(int i) const { return proxy(*p,i);}
		
		private:
			VECTOR* p ;
	} ;
	template<> class r_vector_cache<VECSXP> : public proxy_cache<VECSXP>{
	public:
		r_vector_cache() : proxy_cache<VECSXP>(){} ;
	};
	template<> class r_vector_cache<EXPRSXP> : public proxy_cache<EXPRSXP>{
	public:
		r_vector_cache() : proxy_cache<EXPRSXP>(){} ;
	};
	template<> class r_vector_cache<STRSXP> : public proxy_cache<STRSXP>{
	public:
		r_vector_cache() : proxy_cache<STRSXP>(){} ;
	} ;
	
	template<int RTYPE> struct init_type {
		typedef typename storage_type<RTYPE>::type type ;
	} ;
	template<> struct init_type<STRSXP>{
		typedef const char* type ;
	} ;
	template<> struct init_type<LGLSXP>{
		typedef bool type ;
	} ;
	
} // traits 

#endif
