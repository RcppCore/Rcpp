// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// grow.h: Rcpp R/C++ interface class library -- grow a pairlist
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

#ifndef Rcpp_grow_h
#define Rcpp_grow_h

#include <RcppCommon.h>
#include <Rcpp/Named.h>

namespace Rcpp{

inline SEXP pairlist() { return R_NilValue ; }

#ifdef HAS_VARIADIC_TEMPLATES

/* end of the recursion, wrap first to make the CAR and use 
   R_NilValue as the CDR of the list */
template<typename T>
SEXP pairlist( const T& first){
	return grow(first, R_NilValue ) ; 
}

template<typename T, typename... Args>
SEXP pairlist( const T& first, const Args&... args ){
	return grow(first, pairlist(args...) ) ;
}
#else

#include <Rcpp/generated/grow__pairlist.h>

#endif
	
namespace internal{

template <typename T>
SEXP grow__dispatch( ::Rcpp::traits::false_type, const T& head, SEXP tail ){
	return Rf_cons( wrap(head), tail ) ;	
}

template <typename T>
SEXP grow__dispatch( ::Rcpp::traits::true_type, const T& head, SEXP tail ){
	SEXP x;
	x = PROTECT( Rf_cons( wrap( head.object) , tail) ) ;
	SET_TAG( x, Rf_install( head.name.c_str() ) ); 
	UNPROTECT(1); 
	return x; 	
}

} // namespace internal


/**
 * grows a pairlist. First wrap the head into a SEXP, then 
 * grow the tail pairlist
 */
template <typename T>
SEXP grow(const T& head, SEXP tail){
	return internal::grow__dispatch( typename traits::is_named<T>::type(), head, tail ) ;
}


} // namespace Rcpp

#endif
