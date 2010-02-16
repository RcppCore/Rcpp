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

SEXP pairlist() ;

/* end of the recursion, wrap first to make the CAR and use 
   R_NilValue as the CDR of the list */
template<typename T>
SEXP pairlist( const T& first){
	return grow(first, R_NilValue ) ; 
}

#ifdef HAS_VARIADIC_TEMPLATES
template<typename T, typename... Args>
SEXP pairlist( const T& first, const Args&... args ){
	return grow(first, pairlist(args...) ) ;
}
#else
/* <code-bloat> */
template <typename T1, typename T2>
SEXP pairlist( const T1& t1, const T2& t2){
	return grow(t1, grow(t2, R_NilValue) );
}
template <typename T1, typename T2, typename T3>
SEXP pairlist( const T1& t1, const T2& t2, const T3& t3){
	return grow(t1, grow(t2, grow(t3,R_NilValue)));
}
template <typename T1, typename T2, typename T3, typename T4>
SEXP pairlist( const T1& t1, const T2& t2, const T3& t3, const T4& t4){
	return grow(t1, grow(t2, grow(t3,grow(t4,R_NilValue))));
}
template <typename T1, typename T2, typename T3, typename T4, typename T5>
SEXP pairlist( const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5){
	return grow(t1, grow(t2, grow(t3,grow(t4, grow(t5,R_NilValue)))));
}
/* </code-bloat> */
#endif
	
	
/**
 * grows a pairlist. First wrap the head into a SEXP, then 
 * grow the tail pairlist
 */
template<typename T>
SEXP grow(const T& head, SEXP tail){
	return Rf_cons( wrap(head), tail ) ;
}
template<> SEXP grow<Named>(const Named& head, SEXP tail) ;


} // namespace Rcpp

#endif
