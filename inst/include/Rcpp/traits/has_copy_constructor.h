// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Copyright (C) 2016 Romain Francois
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

#ifndef Rcpp__traits__has_copy_constructor__h
#define Rcpp__traits__has_copy_constructor__h

namespace Rcpp{
namespace traits{

#if defined(RCPP_USING_CXX11)
  template <typename T> struct has_copy_constructor :
    integral_constant<bool, std::is_copy_constructible<T>::value >{} ;
#else
  template<typename T> struct has_copy_constructor : true_type ;
#endif

} // traits
} // Rcpp

#endif
