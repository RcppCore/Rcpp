// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Function.h: Rcpp R/C++ interface class library -- functions (also primitives and builtins)
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

#ifndef Rcpp_Function_h
#define Rcpp_Function_h

#include <RcppCommon.h>

#include <Rcpp/grow.h>
#include <Rcpp/RObject.h>

namespace Rcpp{ 

/** 
 * functions
 */
class Function : public RObject{
public:

	/**
	 * Attempts to convert the SEXP to a pair list
	 *
	 * @throw not_compatible if the SEXP could not be converted
	 * to a pair list using as.pairlist
	 */
	Function(SEXP lang) throw(not_compatible) ;
	
	/**
	 * Finds a function, searching from the global environment
	 *
	 * @param name name of the function
	 */
	Function(const std::string& name) throw(no_such_function) ;
	
	Function(const Function& other) ;
	Function& operator=(const Function& other );
	
	// /**
	//  * Finds a function, searching from a specific environment
	//  *
	//  * @param name name of the function
	//  * @param env environment where to find it
	//  */
	// Function(const std::string& name, SEXP env ) ;
	
	/**
	 * calls the function with the specified arguments
	 *
	 * @param ...Args variable length argument list. The type of each 
	 *        argument must be wrappable, meaning there need to be 
	 *        a wrap function that takes this type as its parameter
	 *
	 */
#ifdef HAS_VARIADIC_TEMPLATES
template<typename... Args> 
	SEXP operator()( const Args&... args) /* throw(Evaluator::eval_error) */ {
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(args...) ) ) ;
	}
#else
	SEXP operator()(){
		return internal::try_catch( Rf_lcons( m_sexp, R_NilValue ) ) ;	
	}
/* <code-bloat>

	template <TYPENAMES>
	SEXP operator()(ARGUMENTS){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(PARAMETERS) ) ) ;
	}
	
*/
	template <typename T1>
	SEXP operator()(const T1& t1){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1) ) ) ;
	}
	
	template <typename T1, typename T2>
	SEXP operator()(const T1& t1, const T2& t2){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19) ) ) ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
	SEXP operator()(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19, const T20& t20){
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20) ) ) ;
	}
	
/* </code-bloat> */
#endif
	
	/**
	 * Returns the environment of this function
	 */
	SEXP environment() const throw(not_a_closure) ;
	
	/**
	 * Returns the body of the function
	 */
	SEXP body() const ;
	 
	~Function() ;
};

} // namespace Rcpp

#endif
