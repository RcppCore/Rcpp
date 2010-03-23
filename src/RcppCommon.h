// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppCommon.h: Rcpp R/C++ interface class library -- common include and defines statements
//
// Copyright (C) 2005 - 2006 Dominick Samperi
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
// Copyright (C)        2009 Romain Francois
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

#ifndef RcppCommon_h
#define RcppCommon_h

void logTxtFunction(const char* file, const int line, const char* expression ) ;

#define ___RCPP_HANDLE_CASE___( ___RTYPE___ , ___FUN___ , ___OBJECT___ , ___RCPPTYPE___ )	\
	case ___RTYPE___ :																	\
		return ___FUN___( ::Rcpp::___RCPPTYPE___< ___RTYPE___ >( ___OBJECT___ ) ) ;	
		         
#define ___RCPP_RETURN___( __FUN__, __SEXP__ , __RCPPTYPE__ )						\
	SEXP __TMP__ = __SEXP__ ;															\
	switch( TYPEOF( __TMP__ ) ){														\
		___RCPP_HANDLE_CASE___( INTSXP  , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( REALSXP , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( RAWSXP  , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( LGLSXP  , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( CPLXSXP , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( STRSXP  , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( VECSXP  , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
		___RCPP_HANDLE_CASE___( EXPRSXP , __FUN__ , __TMP__ , __RCPPTYPE__ )			\
	default:																			\
		throw std::range_error( "not a vector" ) ;									\
	}

#define RCPP_RETURN_VECTOR( _FUN_, _SEXP_ )  ___RCPP_RETURN___( _FUN_, _SEXP_ , Vector ) 
#define RCPP_RETURN_MATRIX( _FUN_, _SEXP_ )  ___RCPP_RETURN___( _FUN_, _SEXP_ , Matrix )

/**
 * \brief Rcpp API
 */
namespace Rcpp{
/**
 * \brief traits used to dispatch wrap
 */
namespace traits{
} // traits
/**
 * \brief internal implementation details
 */
namespace internal{	
} // internal 
} // Rcpp

#ifdef __GNUC__
	#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
	#ifdef __GXX_EXPERIMENTAL_CXX0X__
		#define HAS_CXX0X
		#if GCC_VERSION >= 40300
			#define HAS_VARIADIC_TEMPLATES
		#endif
		#if GCC_VERSION >= 40400
			#define HAS_INIT_LISTS
		#endif
	#endif
	// FIXME: [romain] I did not actually check, tr1::unordered_map was 
	// probably introduced before GCC 4.3
	#if GCC_VERSION >= 40300
		#define HAS_TR1
		#define HAS_TR1_UNORDERED_MAP
		#define HAS_TR1_UNORDERED_SET
	#endif
#endif

#include <iterator>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>
#include <deque>
#include <functional>
#include <numeric>
#include <algorithm>
#include <complex>

#ifdef HAS_INIT_LISTS
#include <initializer_list>
#endif

#ifdef HAS_TR1_UNORDERED_MAP
#include <tr1/unordered_map>
#endif

#ifdef HAS_TR1_UNORDERED_SET
#include <tr1/unordered_set>
#endif

std::string demangle( const char* name) ;
#define DEMANGLE(__TYPE__) demangle( typeid(__TYPE__).name() ).c_str() 

// include R headers, but set R_NO_REMAP and access everything via Rf_ prefixes
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <R_ext/Callbacks.h>
#include <R_ext/Complex.h>
#include <R_ext/Parse.h>
#include <Rversion.h>
#define RCPP_GET_NAMES(x)	Rf_getAttrib(x, R_NamesSymbol)

// #ifdef BUILDING_DLL
// #define RcppExport extern "C" __declspec(dllexport)
// #else
#define RcppExport extern "C"
// #endif


namespace Rcpp{
namespace internal{
template <typename T> int rcpp_call_test(T t){
	return T::r_type::value ;
}
int rcpp_call_test_(SEXP) ;
}
}

extern "C" SEXP rcpp_call_test(SEXP x) ;

char *copyMessageToR(const char* const mesg);

/* in exceptions.cpp */
void forward_uncaught_exceptions_to_r() ;
RcppExport SEXP initUncaughtExceptionHandler() ; 

/* just testing variadic templates */
#ifdef HAS_VARIADIC_TEMPLATES
template<typename... Args>
int variadic_length( const Args&... args) { return sizeof...(Args) ; }
#endif

#ifdef HAS_VARIADIC_TEMPLATES
RcppExport inline SEXP canUseCXX0X(){ return Rf_ScalarLogical( TRUE ); }
#else
RcppExport inline SEXP canUseCXX0X(){ return Rf_ScalarLogical( FALSE ); }
#endif

RcppExport SEXP test_named() ;
RcppExport SEXP capabilities() ;

const char * sexp_to_name(int sexp_type); 

RcppExport SEXP initRcpp() ;

namespace Rcpp{
/* internal namespace for things not intended to be used by the 
   user */
namespace internal{	
	
	/* defined in Evaluator.cpp */
	SEXP convert_using_rfunction(SEXP x, const char* const fun) ;
	
	SEXP try_catch( SEXP expr, SEXP env ) ;
	SEXP try_catch( SEXP expr ) ;
	
} // namespace internal 

inline bool Rboolean_to_bool( int x){ return x == TRUE ; }
inline bool int_to_bool(int x){ return x != 0 ; }
inline bool double_to_bool(double x){ return x != 0.0 ; }
inline bool Rbyte_to_bool(Rbyte x){ return x != static_cast<Rbyte>(0) ; }

} // namespace Rcpp

// simple logging help
#define RCPP_DEBUG_LEVEL 0

#ifndef logTxt
	#if RCPP_DEBUG_LEVEL > 0
		#define logTxt(x) ::logTxtFunction(__FILE__, __LINE__, x);
		#define RCPP_DEBUG( fmt , ... ) Rprintf( "%s:%d " fmt "\n" , __FILE__, __LINE__,##__VA_ARGS__ ) ;
	#else
		#define logTxt(x)
		#define RCPP_DEBUG( fmt , ... )
	#endif
#endif

// DO NOT CHANGE THE ORDER OF THESE INCLUDES
#include <Rcpp/traits/integral_constant.h>
#include <Rcpp/traits/same_type.h>
#include <Rcpp/traits/named_object.h>
#include <Rcpp/traits/is_convertible.h>
#include <Rcpp/traits/has_iterator.h>
#include <Rcpp/traits/has_na.h>
#include <Rcpp/traits/storage_type.h>
#include <Rcpp/traits/r_sexptype_traits.h>
#include <Rcpp/traits/storage_type.h>
#include <Rcpp/traits/r_type_traits.h>
#include <Rcpp/traits/wrap_type_traits.h>

#include <Rcpp/internal/caster.h>
#include <Rcpp/internal/r_vector.h>
#include <Rcpp/r_cast.h>

#include <Rcpp/internal/export.h>
#include <Rcpp/traits/Exporter.h>
#include <Rcpp/internal/r_coerce.h>
#include <Rcpp/as.h>
#include <Rcpp/internal/wrap.h>

#include <Rcpp/internal/ListInitialization.h>
#include <Rcpp/internal/Proxy_Iterator.h>

RcppExport SEXP RcppXPtrExample_create_external_pointer() ;
RcppExport SEXP RcppXPtrExample_get_external_pointer(SEXP ); 

#endif
