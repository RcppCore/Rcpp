// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// as.h: Rcpp R/C++ interface class library -- convert SEXP to C++ objects
//
// Copyright (C) 2009 - 2010	Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__as__h
#define Rcpp__as__h

namespace Rcpp{

namespace internal{
	
	template <typename T> T as( SEXP x, ::Rcpp::traits::r_type_primitive_tag ) throw(::Rcpp::not_compatible) {
		if( ::Rf_length(x) != 1 ) throw ::Rcpp::not_compatible( "expecting a single value" ) ;
		const int RTYPE = ::Rcpp::traits::r_sexptype_traits<T>::rtype ;
		SEXP y = PROTECT( r_cast<RTYPE>(x) );
		typedef typename ::Rcpp::traits::storage_type<RTYPE>::type STORAGE;
		T res = caster<STORAGE,T>( *r_vector_start<RTYPE,STORAGE>( y ) ) ;
		UNPROTECT(1) ;
		return res ; 
	}
	
	template <typename T> T as(SEXP x, ::Rcpp::traits::r_type_string_tag ) throw(::Rcpp::not_compatible) {
		if( ! ::Rf_isString(x) ){
			throw ::Rcpp::not_compatible( "expecting a string" ) ;
		}
		if (Rf_length(x) != 1) {
    			throw ::Rcpp::not_compatible( "expecting a single value");
    		}
    		return T( CHAR( STRING_ELT( ::Rcpp::r_cast<STRSXP>(x) ,0 ) ) ) ;
	}
	
	template <typename T> T as(SEXP x, ::Rcpp::traits::r_type_generic_tag ) throw(::Rcpp::not_compatible) {
		RCPP_DEBUG( "as(SEXP = <%p>, r_type_generic_tag )", x ) ;
		::Rcpp::traits::Exporter<T> exporter(x);
		RCPP_DEBUG( "exporter type = %s", DEMANGLE(exporter) ) ;
		return exporter.get() ;
	}
	
}
	
	
/** 
 * Generic converted from SEXP to the typename. T can be any type that 
 * has a constructor taking a SEXP, which is the case for all our 
 * RObject and derived classes. 
 *
 * If it is not possible to add the SEXP constructor, e.g you don't control
 * the type, you can specialize the as template to perform the 
 * requested conversion
 *
 * This is used for example in Environment, so that for example the code
 * below will work as long as there is a way to as<> the Foo type
 *
 * Environment x = ... ; // some environment
 * Foo y = x["bla"] ;    // if as<Foo> makes sense then this works !!
 */
template <typename T> T as( SEXP m_sexp) throw(not_compatible) {
	return internal::as<T>( m_sexp, typename traits::r_type_traits<T>::r_category() ) ;
}

template<> inline SEXP as(SEXP m_sexp) throw(not_compatible) { return m_sexp ; }

} // Rcpp 

#endif
