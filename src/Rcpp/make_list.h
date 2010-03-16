// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// make_list.h: Rcpp R/C++ interface class library -- list factories
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

#ifndef Rcpp__make_list_h
#define Rcpp__make_list_h

#include <Rcpp/Named.h>

namespace Rcpp{

	namespace internal{
	
	template <typename T>
	bool set_list_elt( SEXP res, SEXP names, int index, const T& o ){
		SET_VECTOR_ELT( res, index, ::Rcpp::wrap( o ) ) ;
		return false ;
	}
	
	template<> 
	bool set_list_elt< ::Rcpp::Named >( SEXP res, SEXP names, int index, const ::Rcpp::Named& o ) ;
	
	} // namespace internal
	
	inline SEXP make_list(){ return Rf_allocVector( VECSXP, 0 ); }
	
	
/* <code-bloat>

template <TYPENAMES>
SEXP make_list( ARGUMENTS ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, ___N___ ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, ___N___ ) ) ;
	
	__FOR_EACH__{{ has_names = internal::set_list_elt( res, names, ___I___, ___X___ ) | has_names ; }}                                                                                                       
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

*/
template <typename T1>
SEXP make_list( const T1& t1 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 1 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 1 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2>
SEXP make_list( const T1& t1, const T2& t2 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 2 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 2 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 3 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 3 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 4 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 4 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 5 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 5 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 6 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 6 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 7 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 7 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 8 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 8 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 9 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 9 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 10 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 10 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 11 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 11 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 10, t11 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 12 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 12 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 10, t11 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 11, t12 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 13 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 13 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 10, t11 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 11, t12 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 12, t13 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 14 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 14 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 10, t11 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 11, t12 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 12, t13 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 13, t14 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 15 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 15 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 10, t11 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 11, t12 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 12, t13 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 13, t14 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 14, t15 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 16 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 16 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 10, t11 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 11, t12 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 12, t13 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 13, t14 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 14, t15 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 15, t16 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 17 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 17 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 10, t11 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 11, t12 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 12, t13 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 13, t14 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 14, t15 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 15, t16 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 16, t17 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 18 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 18 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 10, t11 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 11, t12 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 12, t13 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 13, t14 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 14, t15 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 15, t16 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 16, t17 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 17, t18 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 19 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 19 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 10, t11 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 11, t12 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 12, t13 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 13, t14 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 14, t15 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 15, t16 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 16, t17 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 17, t18 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 18, t19 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
SEXP make_list( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19, const T20& t20 ){

	bool has_names = false ;
	SEXP res   = PROTECT( ::Rf_allocVector( VECSXP, 20 ) ) ;
	SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 20 ) ) ;
	
 has_names = internal::set_list_elt( res, names, 0, t1 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 1, t2 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 2, t3 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 3, t4 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 4, t5 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 5, t6 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 6, t7 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 7, t8 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 8, t9 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 9, t10 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 10, t11 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 11, t12 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 12, t13 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 13, t14 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 14, t15 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 15, t16 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 16, t17 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 17, t18 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 18, t19 ) | has_names ; 
 has_names = internal::set_list_elt( res, names, 19, t20 ) | has_names ; 
	
	if( has_names ){
		::Rf_setAttrib( res, ::Rf_install( "names" ), names ) ;
	}
	UNPROTECT(2) ;
	return res; 
}

/* </code-bloat> */	
}

#endif
