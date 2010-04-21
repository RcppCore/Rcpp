// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// rcast.h: Rcpp R/C++ interface class library -- cast from one SEXP type to another
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

#ifndef Rcpp_rcast_h
#define Rcpp_rcast_h

#include <Rcpp/exceptions.h>

namespace Rcpp{
namespace internal {
	
// /* r_true_cast is only meant to be used when the target SEXP type
//   is different from the SEXP type of x */
template <int TARGET>
SEXP r_true_cast( SEXP x) throw(::Rcpp::not_compatible) {
	throw not_compatible( "not compatible" ) ;
}

template<> SEXP r_true_cast<INTSXP>(SEXP x)   throw(::Rcpp::not_compatible) ;
template<> SEXP r_true_cast<REALSXP>(SEXP x)  throw(::Rcpp::not_compatible) ;
template<> SEXP r_true_cast<RAWSXP>(SEXP x)   throw(::Rcpp::not_compatible) ;
template<> SEXP r_true_cast<CPLXSXP>(SEXP x)  throw(::Rcpp::not_compatible) ;
template<> SEXP r_true_cast<LGLSXP>(SEXP x)   throw(::Rcpp::not_compatible) ;
template<> SEXP r_true_cast<STRSXP>(SEXP x)   throw(::Rcpp::not_compatible) ;
template<> SEXP r_true_cast<VECSXP>(SEXP x)   throw(::Rcpp::not_compatible) ;
template<> SEXP r_true_cast<EXPRSXP>(SEXP x)  throw(::Rcpp::not_compatible) ;
template<> SEXP r_true_cast<LISTSXP>(SEXP x)  throw(::Rcpp::not_compatible) ;
template<> SEXP r_true_cast<LANGSXP>(SEXP x)  throw(::Rcpp::not_compatible) ;

} // namespace internal 

template <int TARGET> SEXP r_cast( SEXP x) throw(not_compatible) { 
	return (TYPEOF(x)== TARGET) ? x : internal::r_true_cast<TARGET>(x) ; 
}

} // namespace Rcpp

#endif
