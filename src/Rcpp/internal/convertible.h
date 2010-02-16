// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
/* :tabSize=4:indentSize=4:noTabs=false:folding=explicit:collapseFolds=1: */
//
// convertible.h: Rcpp R/C++ interface class library -- dispatch the 
// implementation of is_convertible traits depending on whether we have
// access to tr1 or c++0x
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

#ifndef Rcpp_internal_is_convertible_h
#define Rcpp_internal_is_convertible_h

// this is a private header, do not include it directly

#ifdef HAS_CXX0X
// use the c++0x implementation
#include <type_traits>
namespace Rcpp{
namespace internal{
template <typename FROM, typename TO> struct is_convertible : 
	public ::Rcpp::traits::integral_constant<bool,std::is_convertible<FROM,TO>::value>{} ;
} // internal
} // Rcpp
#else
#ifdef HAS_TR1
#include <tr1/type_traits>
// use the tr1 implementation
namespace Rcpp{
namespace internal{
template <typename FROM, typename TO> struct is_convertible : 
	public ::Rcpp::traits::integral_constant<bool,std::tr1::is_convertible<FROM,TO>::value>{} ;
} // internal
} // Rcpp
#else
// hope for the best
namespace Rcpp{
namespace internal{
template <typename FROM, typename TO> struct is_convertible : 
	public ::Rcpp::traits::true_type{} ;
} // internal
} // Rcpp
#endif
#endif



#endif
