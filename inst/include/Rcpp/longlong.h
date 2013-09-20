// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// longlong.h: Rcpp R/C++ interface class library -- long long support
//
// Copyright (C) 2013  Dirk Eddelbuettel and Romain Francois
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

#ifndef RCPP_LONG_LONG_H
#define RCPP_LONG_LONG_H

// This does not work as C++98, our default, has no long long support.
// So we are wrapping another layer of C++11 test around it. Feel free
// to add a boolean OR with another suitably #define'd variable which
// has to be OFF by default to restore the old behaviour.

#ifdef __GNUC__
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || (defined (__clang__) && defined(__LP64__))

// long long and unssigned long long support. 
//
// given the current restriction of what might go to CRAN
// we can only use long long if we are running a gcc compatible (e.g. clang)
// compiler and the type is actually available (hence the test for __LONG_LONG_MAX__)
// even then, we cannot use long long as is, we first have to "hide" it
// behind the __extension__ so that -pedantic stops giving warnings about 
// compliance with C++98
// 
// client code may use the facilities we provide for long long (wrap, etc ...)
// but not using long long directly, because then it is not CRAN proof. 
// So client code must use the rcpp_long_long_type and rcpp_ulong_long_type 
// types 
//
// e.g. code like this is not good: 
//
// long long x = 2 ;
//
// but code like this is CRAN proof
//
// rcpp_long_long_type x = 2 ;
//
// Note that if you don't distribute your code to CRAN and you don't use the 
// -pedantic option, then you can use long long
#if defined(__GNUC__) &&  defined(__LONG_LONG_MAX__)
    __extension__ typedef long long int rcpp_long_long_type;
    __extension__ typedef unsigned long long int rcpp_ulong_long_type;
    #define RCPP_HAS_LONG_LONG_TYPES
#endif

#if defined(RCPP_HAS_LONG_LONG_TYPES)

namespace Rcpp{
namespace traits{

    template<> struct r_sexptype_traits<rcpp_long_long_type>{ enum{ rtype = REALSXP } ; } ;
    template<> struct r_sexptype_traits<rcpp_ulong_long_type>{ enum{ rtype = REALSXP } ; } ;
    
    template<> struct r_type_traits<rcpp_long_long_type>{ typedef r_type_primitive_tag r_category ; } ;
    template<> struct r_type_traits< std::pair<const std::string,rcpp_long_long_type> >{ typedef r_type_primitive_tag r_category ; } ;
    template<> struct r_type_traits<rcpp_ulong_long_type>{ typedef r_type_primitive_tag r_category ; } ;
    template<> struct r_type_traits< std::pair<const std::string,rcpp_ulong_long_type> >{ typedef r_type_primitive_tag r_category ; } ;
    
    template <> struct wrap_type_traits<rcpp_long_long_type> { typedef wrap_type_primitive_tag wrap_category; } ;
    template <> struct wrap_type_traits<rcpp_ulong_long_type> { typedef wrap_type_primitive_tag wrap_category; } ;
}
}
#endif

#endif
#endif

#endif
