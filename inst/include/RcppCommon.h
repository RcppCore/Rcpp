// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppCommon.h: Rcpp R/C++ interface class library -- common include and defines statements
//
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
// Copyright (C) 2009 - 2012 Dirk Eddelbuettel and Romain Francois
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

#undef GOOD_COMPILER_FOR_RCPP
#ifdef __GNUC__
#define GOOD_COMPILER_FOR_RCPP
#endif
#ifdef __SUNPRO_CC
#define GOOD_COMPILER_FOR_RCPP
#endif
#ifdef __clang__
#define GOOD_COMPILER_FOR_RCPP
#endif
#ifdef __INTEL_COMPILER
#define GOOD_COMPILER_FOR_RCPP
#endif

#ifndef GOOD_COMPILER_FOR_RCPP
# error "This compiler is not supported"
#endif

#include <Rcpp/config.h>
#include <Rcpp/macros/unroll.h>

void logTxtFunction(const char* file, const int line, const char* expression ) ;

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

#include <Rcpp/module/macros.h>

#ifdef __GNUC__
    #define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
    // g++ 4.5 does not seem to like some of the fast indexing
    #if GCC_VERSION >= 40500
        #define IS_GCC_450_OR_LATER
    #endif
    // g++ 4.6 switches from exception_defines.h to bits/exception_defines.h
    #if GCC_VERSION < 40600
        #define IS_EARLIER_THAN_GCC_460
    #endif
    #if GCC_VERSION >= 40600
        #define IS_GCC_460_OR_LATER
    #endif
#endif

// Check C++0x features
#if defined(__INTEL_COMPILER)
    #if __cplusplus >= 201103L
        #define HAS_CXX0X_FLAG
        #if __INTEL_COMPILER >= 1210
            // #define HAS_VARIADIC_TEMPLATES
        #endif
        #if __INTEL_COMPILER >= 1100
            #define HAS_STATIC_ASSERT
        #endif
    #endif
#elif defined(__clang__)
    #if __cplusplus >= 201103L
        #define HAS_CXX0X_FLAG
        #if __has_feature(cxx_variadic_templates)
            // #define HAS_VARIADIC_TEMPLATES
        #endif
        #if __has_feature(cxx_static_assert)
            #define HAS_STATIC_ASSERT
        #endif
    #endif
#elif defined(__GNUC__)
    #ifdef __GXX_EXPERIMENTAL_CXX0X__
        // #define HAS_CXX0X_FLAG
        #if GCC_VERSION >= 40300
            // #define HAS_VARIADIC_TEMPLATES
            #define HAS_STATIC_ASSERT
        #endif
    #endif
#endif

// Check C++0x headers
#include <cmath>
#if defined(__INTEL_COMPILER) || (defined(__GNUC__) && !defined(__clang__))
    #if defined(__GLIBCXX__) && defined(__GXX_EXPERIMENTAL_CXX0X__)
        #if __GLIBCXX__ >= 20090421 // GCC 4.4.0
            #define HAS_CXX0X_UNORDERED_MAP
            #define HAS_CXX0X_UNORDERED_SET
            #define HAS_CXX0X_INITIALIZER_LIST
        #endif
    #endif
#elif defined(__clang__)
    #if __cplusplus >= 201103L
        #if __has_include(<unordered_map>)
            #define HAS_CXX0X_UNORDERED_MAP
        #endif
        #if __has_include(<unordered_set>)
            #define HAS_CXX0X_UNORDERED_SET
        #endif
        #if __has_include(<initializer_list>)
            #define HAS_CXX0X_INITIALIZER_LIST
        #endif
    #endif
#endif

// Check TR1 Headers
#if defined(__INTEL_COMPILER) || (defined(__GNUC__) && !defined(__clang__))
    #if defined(__GLIBCXX__)
        #if __GLIBCXX__ >= 20070719 // GCC 4.2.1
            #define HAS_TR1_UNORDERED_MAP
            #define HAS_TR1_UNORDERED_SET
        #endif
    #endif
#elif defined(__clang__)
    #if __cplusplus >= 201103L
        #if __has_include(<tr1/unordered_map>)
            #define HAS_TR1_UNORDERED_MAP
        #endif
        #if __has_include(<tr1/unordered_set>)
            #define HAS_TR1_UNORDERED_SET
        #endif
    #endif
#endif

#if defined(HAS_TR1_UNORDERED_MAP) && defined(HAS_TR1_UNORDERED_SET)
#define HAS_TR1
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
#include <limits>
#include <typeinfo>
#include <Rcpp/sprintf.h>

// Conditionally include headers
#ifdef HAS_CXX0X_INITIALIZER_LIST
#include <initializer_list>
#endif

#ifdef HAS_CXX0X_FLAG
    #if defined(HAS_CXX0X_UNORDERED_MAP)
        #include <unordered_map>
        #define RCPP_UNORDERED_MAP std::unordered_map
    #else
        #include <map>
        #define RCPP_UNORDERED_MAP std::map
    #endif
    #if defined(HAS_CXX0X_UNORDERED_SET)
        #include <unordered_set>
        #define RCPP_UNORDERED_SET std::unordered_set
    #else
        #include <set>
        #define RCPP_UNORDERED_SET std::set
    #endif
#else
    #if defined(HAS_TR1_UNORDERED_MAP)
        #include <tr1/unordered_map>
        #define RCPP_UNORDERED_MAP std::tr1::unordered_map
    #else
        #include <map>
        #define RCPP_UNORDERED_MAP std::map
    #endif
    #if defined(HAS_TR1_UNORDERED_SET)
        #include <tr1/unordered_set>
        #define RCPP_UNORDERED_SET std::tr1::unordered_set
    #else
        #include <set>
        #define RCPP_UNORDERED_SET std::set
    #endif
#endif

// include R headers, but set R_NO_REMAP and access everything via Rf_ prefixes
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
// #include <R_ext/Callbacks.h>
#include <R_ext/Complex.h>
#include <R_ext/Parse.h>
#include <R_ext/Rdynload.h>
#include <Rversion.h>
#define RCPP_GET_NAMES(x)       Rf_getAttrib(x, R_NamesSymbol)

inline SEXP Rcpp_lcons(SEXP car, SEXP cdr){
    PROTECT(car) ;
    car = Rf_lcons( car, cdr ) ; 
    UNPROTECT(1) ;
    return car ;
}
#include <Rcpp/lang.h>

#include <Rcpp/complex.h>

#include <Rcpp/barrier.h>

#define RcppExport extern "C"

#include <Rcpp/internal/posixt.h>

RcppExport void init_Rcpp_routines(DllInfo*) ;

namespace Rcpp{
    namespace internal{
        template <typename T> int rcpp_call_test(T t){
            return T::r_type::value ;
        }
        int rcpp_call_test_(SEXP) ;
    }
}

extern "C" SEXP rcpp_call_test(SEXP x) ;

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


RcppExport SEXP capabilities() ;

const char * sexp_to_name(int sexp_type); 

#include <Rcpp/exceptions.h>

namespace Rcpp{
    /* internal namespace for things not intended to be used by the user */
    namespace internal{     
        
        SEXP try_catch( SEXP expr, SEXP env );
        SEXP try_catch( SEXP expr );
        
    } // namespace internal 
    
    inline bool Rboolean_to_bool( int x){ return x == TRUE ; }
    inline bool int_to_bool(int x){ return x != 0 ; }
    inline bool double_to_bool(double x){ return x != 0.0 ; }
    inline bool Rbyte_to_bool(Rbyte x){ return x != static_cast<Rbyte>(0) ; }

} // namespace Rcpp

#include <Rcpp/macros/debug.h>

#define Rcpp_error(MESSAGE) throw Rcpp::exception( MESSAGE, __FILE__, __LINE__ ) 

namespace Rcpp {
	  inline void stop(const std::string& message) { throw Rcpp::exception(message.c_str()); }
} // namespace Rcpp

#if RCPP_DEBUG_LEVEL > 0
    #include <typeinfo>
#endif

#ifdef __GNUC__
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#ifdef LONG_LONG_MAX
    __extension__ typedef long long int rcpp_long_long_type;
    __extension__ typedef unsigned long long int rcpp_ulong_long_type;
    #define RCPP_HAS_LONG_LONG_TYPES
#endif
#endif
#endif

namespace Rcpp{
    template <typename T> class object ;
    class String ;
	namespace internal{
		template <typename Class> SEXP make_new_object( Class* ptr ) ;	
	}
}	

// DO NOT CHANGE THE ORDER OF THESE INCLUDES
#include <Rcpp/traits/integral_constant.h>
#include <Rcpp/traits/same_type.h>
#include <Rcpp/traits/named_object.h>
#include <Rcpp/Named.h>
#include <Rcpp/traits/is_convertible.h>
#include <Rcpp/traits/has_iterator.h>
#include <Rcpp/traits/expands_to_logical.h>
#include <Rcpp/traits/matrix_interface.h>
#include <Rcpp/traits/is_sugar_expression.h>
#include <Rcpp/traits/is_eigen_base.h>
#include <Rcpp/traits/has_na.h>
#include <Rcpp/traits/storage_type.h>
#include <Rcpp/traits/r_sexptype_traits.h>
#include <Rcpp/traits/storage_type.h>
#include <Rcpp/traits/comparator_type.h>
#include <Rcpp/traits/r_type_traits.h>
#include <Rcpp/traits/un_pointer.h>
#include <Rcpp/traits/is_pointer.h>
#include <Rcpp/traits/wrap_type_traits.h>
#include <Rcpp/traits/module_wrap_traits.h>
#include <Rcpp/traits/is_na.h>
#include <Rcpp/traits/if_.h>
#include <Rcpp/traits/get_na.h>
#include <Rcpp/traits/is_trivial.h>
#include <Rcpp/traits/init_type.h>

#include <Rcpp/traits/is_const.h>
#include <Rcpp/traits/is_reference.h>
#include <Rcpp/traits/remove_const.h>
#include <Rcpp/traits/remove_reference.h>
#include <Rcpp/traits/remove_const_and_reference.h>
#include <Rcpp/traits/result_of.h>

#include <Rcpp/internal/caster.h>
#include <Rcpp/internal/r_vector.h>
#include <Rcpp/r_cast.h>

#include <Rcpp/internal/wrap_forward.h>

#include <Rcpp/Date_forward.h>
#include <Rcpp/Datetime_forward.h>

#include <Rcpp/internal/export.h>
#include <Rcpp/traits/Exporter.h>
#include <Rcpp/internal/r_coerce.h>
#include <Rcpp/as.h>

#include <Rcpp/vector/VectorBase.h>
#include <Rcpp/vector/MatrixBase.h>

#include <Rcpp/internal/wrap.h>

#include <Rcpp/internal/ListInitialization.h>
#include <Rcpp/internal/Proxy_Iterator.h>
#include <Rcpp/internal/SEXP_Iterator.h>

#include <Rcpp/preprocessor.h>
#include <Rcpp/algo.h>

#include <Rcpp/sugar/sugar_forward.h>

#include <Rcpp/routines.h>
#include <Rcpp/cache.h>

// "Rcout" iostream class contributed by Jelmer Ypma
#include <Rcpp/iostream/Rstreambuf.h>
#include <Rcpp/iostream/Rostream.h>

#endif
