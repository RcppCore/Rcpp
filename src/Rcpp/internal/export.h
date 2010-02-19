// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
/* :tabSize=4:indentSize=4:noTabs=false:folding=explicit:collapseFolds=1: */
//
// export.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__internal__export__h
#define Rcpp__internal__export__h

namespace Rcpp{
namespace internal{

	
	template <typename InputIterator, typename value_type>
	void export_range__impl( SEXP x, InputIterator first, ::Rcpp::traits::false_type ){
		const int RTYPE = ::Rcpp::traits::r_sexptype_traits<value_type>::rtype ;
		typedef typename ::Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
		SEXP y = PROTECT( ::Rcpp::r_cast<RTYPE>(x) ) ;
		STORAGE* start = ::Rcpp::internal::r_vector_start<RTYPE,STORAGE>(y) ;
		std::copy( start, start + ::Rf_length(y), first ) ;
		UNPROTECT(1) ;
	}
	
	template <typename InputIterator, typename value_type>
	void export_range__impl( SEXP x, InputIterator first, ::Rcpp::traits::true_type ){
		const int RTYPE = ::Rcpp::traits::r_sexptype_traits<value_type>::rtype ;
		typedef typename ::Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
		SEXP y = PROTECT( ::Rcpp::r_cast<RTYPE>(x) ) ;
		STORAGE* start = ::Rcpp::internal::r_vector_start<RTYPE,STORAGE>(y) ;
		std::transform( start, start + ::Rf_length(y) , first, caster<STORAGE,value_type> ) ;
		UNPROTECT(1) ;
	}
	
	
	template <typename T, typename value_type>
	void export_indexing__impl( SEXP x, T& res, ::Rcpp::traits::false_type ){
		const int RTYPE = ::Rcpp::traits::r_sexptype_traits<value_type>::rtype ;
		typedef typename ::Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
		SEXP y = PROTECT( ::Rcpp::r_cast<RTYPE>(x) ) ;
		STORAGE* start = ::Rcpp::internal::r_vector_start<RTYPE,STORAGE>(y) ;
		R_len_t size = ::Rf_length(y)  ;
		for( R_len_t i=0; i<size; i++){
			res[i] =  start[i] ;
		}
		UNPROTECT(1) ;
	}
	
	template <typename T, typename value_type>
	void export_indexing__impl( SEXP x, T& res, ::Rcpp::traits::true_type ){
		const int RTYPE = ::Rcpp::traits::r_sexptype_traits<value_type>::rtype ;
		typedef typename ::Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
		SEXP y = PROTECT( ::Rcpp::r_cast<RTYPE>(x) ) ;
		STORAGE* start = ::Rcpp::internal::r_vector_start<RTYPE,STORAGE>(y) ;
		R_len_t size = ::Rf_length(y)  ;
		for( R_len_t i=0; i<size; i++){
			res[i] =  caster<STORAGE,value_type>(start[i]) ;
		}
		UNPROTECT(1) ;
	}

	
	template <typename InputIterator>
	void export_range( SEXP x, InputIterator first){
		export_range__impl<InputIterator,typename std::iterator_traits<InputIterator>::value_type>(
			x, 
			first,
			typename ::Rcpp::traits::r_sexptype_needscast< typename std::iterator_traits<InputIterator>::value_type >() );
	}
	
	template <typename T, typename value_type>
	void export_indexing( SEXP x, T& res ){
		export_indexing__impl<T,value_type>( 
			x, 
			res, 
			typename ::Rcpp::traits::r_sexptype_needscast<value_type>() ) ;
	}
	
}
}

#endif
