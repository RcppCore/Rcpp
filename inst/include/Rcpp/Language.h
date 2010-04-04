// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Language.h: Rcpp R/C++ interface class library -- language objects (calls)
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

#ifndef Rcpp_Language_h
#define Rcpp_Language_h

#include <RcppCommon.h>
#include <Rcpp/DottedPair.h>
#include <Rcpp/Symbol.h>
#include <Rcpp/Function.h>
#include <Rcpp/grow.h>
#include <Rcpp/r_cast.h>

namespace Rcpp{ 

/** 
 * C++ wrapper around calls (LANGSXP SEXP)
 *
 * This represents calls that can be evaluated
 */
class Language : public DottedPair {
public:

	Language() ;
	
	/**
	 * Attempts to convert the SEXP to a call
	 *
	 * @throw not_compatible if the SEXP could not be converted
	 * to a call using as.call
	 */
	Language(SEXP lang) throw(not_compatible) ;

	Language(const Language& other) ;
	Language& operator=(const Language& other) ;
	
	/**
	 * Creates a call using the given symbol as the function name
	 *
	 * @param symbol symbol name to call
	 *
	 * Language( "rnorm" ) makes a SEXP similar to this (expressed in R)
	 * > as.call( as.list( as.name( "rnorm") ) )
	 * > call( "rnorm" )
	 */
	explicit Language( const std::string& symbol ); 

	/**
	 * Creates a call using the given symbol as the function name
	 *
	 * @param symbol symbol name to call
	 *
	 * Language( Symbol("rnorm") ) makes a SEXP similar to this: 
	 * > call( "rnorm" )
	 */
	explicit Language( const Symbol& symbol ); 

	/**
	 * Creates a call to the function
	 * 
	 * @param function function to call
	 */
	explicit Language( const Function& function) ;
	
	/**
	 * Creates a call to the given symbol using variable number of 
	 * arguments
	 *
	 * @param symbol symbol
	 * @param ...Args variable length argument list. The type of each 
	 *        argument must be wrappable, meaning there need to be 
	 *        a wrap function that takes this type as its parameter
	 * 
	 * For example, Language( "rnorm", 10, 0.0 ) 
	 * will create the same call as 
	 * > call( "rnorm", 10L, 0.0 )
	 *
	 * 10 is wrapped as an integer vector using wrap( const& int )
	 * 0.0 is wrapped as a numeric vector using wrap( const& double )
	 * ...
	 */
#ifdef HAS_VARIADIC_TEMPLATES
template<typename... Args> 
Language( const std::string& symbol, const Args&... args) : DottedPair(Rf_install(symbol.c_str()), args...) {
	update() ;
}
template<typename... Args> 
Language( const Function& function, const Args&... args) : DottedPair(function, args...) {
	update() ;
}
#else
/* <code-bloat>

template <TYPENAMES> 
Language( const std::string& symbol, ARGUMENTS) : DottedPair(Rf_install(symbol.c_str()), PARAMETERS) { 
	update() ;
} 
	
template <TYPENAMES> 
Language( const Function& function, ARGUMENTS) : DottedPair(function, PARAMETERS) { 
	update() ;
} 
			
*/
template <typename T1> 
Language( const std::string& symbol, const T1& t1) : DottedPair(Rf_install(symbol.c_str()), t1) { 
	update() ;
} 
	
template <typename T1> 
Language( const Function& function, const T1& t1) : DottedPair(function, t1) { 
	update() ;
} 
			
template <typename T1, typename T2> 
Language( const std::string& symbol, const T1& t1, const T2& t2) : DottedPair(Rf_install(symbol.c_str()), t1, t2) { 
	update() ;
} 
	
template <typename T1, typename T2> 
Language( const Function& function, const T1& t1, const T2& t2) : DottedPair(function, t1, t2) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3) : DottedPair(function, t1, t2, t3) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4) : DottedPair(function, t1, t2, t3, t4) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5) : DottedPair(function, t1, t2, t3, t4, t5) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6) : DottedPair(function, t1, t2, t3, t4, t5, t6) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19) { 
	update() ;
} 
			
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20> 
Language( const std::string& symbol, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19, const T20& t20) : DottedPair(Rf_install(symbol.c_str()), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20) { 
	update() ;
} 
	
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20> 
Language( const Function& function, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19, const T20& t20) : DottedPair(function, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20) { 
	update() ;
} 
			
/* </code-bloat> */
#endif	
	
	/**
	 * sets the symbol of the call
	 */
	void setSymbol( const std::string& symbol);

	/**
	 * sets the symbol of the call
	 */
	void setSymbol( const Symbol& symbol ) ;

	/**
	 * sets the function
	 */
	void setFunction( const Function& function) ;

	/**
	 * eval this call in the global environment
	 */
	SEXP eval() ;

	/**
	 * eval this call in the requested environment
	 */
	SEXP eval(SEXP env) ;

	~Language() ;

private:
	virtual void update() ; 

};

template <typename OUT=SEXP>
class fixed_call {
public:
	typedef OUT result_type ;
	
	fixed_call( Language call_ ) : call(call_){}
	fixed_call( Function fun ) : call(fun){}
	
	OUT operator()(){
		return as<OUT>( call.eval() ) ;
	}
	
private:
	Language call ;
} ;

template <typename T, typename OUT = SEXP>
class unary_call : public std::unary_function<T,OUT> {
public:
	unary_call( Language call_ ) : call(call_), proxy(call_,1) {}
	unary_call( Language call_, int index ) : call(call_), proxy(call_,index){}
	unary_call( Function fun ) : call( fun, R_NilValue), proxy(call,1) {}
	
	OUT operator()( const T& object ){
		proxy = object ;
		return as<OUT>( call.eval() ) ;
	}
	
private:
	Language call ;
	Language::Proxy proxy ;
} ;

template <typename T1, typename T2, typename OUT = SEXP>
class binary_call : public std::binary_function<T1,T2,OUT> {
public:
	binary_call( Language call_ ) : call(call_), proxy1(call_,1), proxy2(call_,2) {}
	binary_call( Language call_, int index1, int index2 ) : call(call_), proxy1(call_,index1), proxy2(call_,index2){}
	binary_call( Function fun) : call(fun, R_NilValue, R_NilValue), proxy1(call,1), proxy2(call,2){}
	
	OUT operator()( const T1& o1, const T2& o2 ){
		proxy1 = o1 ;
		proxy2 = o2 ;
		return as<OUT>( call.eval() ) ;
	}
	
private:
	Language call ;
	Language::Proxy proxy1 ;
	Language::Proxy proxy2 ;
} ;

} // namespace Rcpp

#endif
