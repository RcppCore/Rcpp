// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
/* :tabSize=4:indentSize=4:noTabs=false:folding=explicit:collapseFolds=1: */
//
// r_coerce.h: Rcpp R/C++ interface class library -- coercion
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

#ifndef Rcpp__internal__r_coerce__h
#define Rcpp__internal__r_coerce__h

namespace Rcpp{
namespace internal{

template <int FROM, int TO>
typename ::Rcpp::traits::storage_type<TO>::type 
r_coerce( typename ::Rcpp::traits::storage_type<FROM>::type from ){
	// this implementation is never actually called
	return static_cast<typename ::Rcpp::traits::storage_type<TO>::type >(from);
} ;
template <> int r_coerce<INTSXP,INTSXP>(int from) ;
template <> int r_coerce<LGLSXP,LGLSXP>(int from) ;
template <> double r_coerce<REALSXP,REALSXP>(double from);
template <> Rcomplex r_coerce<CPLXSXP,CPLXSXP>(Rcomplex from);
template <> Rbyte r_coerce<RAWSXP,RAWSXP>(Rbyte from) ;

// -> INTSXP
template <> int r_coerce<LGLSXP,INTSXP>(int from) ;
template <> int r_coerce<REALSXP,INTSXP>(double from);
template <> int r_coerce<CPLXSXP,INTSXP>(Rcomplex from);
template <> int r_coerce<RAWSXP,INTSXP>(Rbyte from) ;

// -> REALSXP
template <> double r_coerce<LGLSXP,REALSXP>(int from) ;
template <> double r_coerce<INTSXP,REALSXP>(int from);
template <> double r_coerce<CPLXSXP,REALSXP>(Rcomplex from);
template <> double r_coerce<RAWSXP,REALSXP>(Rbyte from) ;

// -> LGLSXP
template <> int r_coerce<REALSXP,LGLSXP>(double from) ;
template <> int r_coerce<INTSXP,LGLSXP>(int from);
template <> int r_coerce<CPLXSXP,LGLSXP>(Rcomplex from);
template <> int r_coerce<RAWSXP,LGLSXP>(Rbyte from) ;

// -> RAWSXP
template <> Rbyte r_coerce<REALSXP,RAWSXP>(double from) ;
template <> Rbyte r_coerce<INTSXP,RAWSXP>(int from);
template <> Rbyte r_coerce<CPLXSXP,RAWSXP>(Rcomplex from);
template <> Rbyte r_coerce<LGLSXP,RAWSXP>(int from) ;

// -> CPLXSXP
template <> Rcomplex r_coerce<REALSXP,CPLXSXP>(double from) ;
template <> Rcomplex r_coerce<INTSXP,CPLXSXP>(int from);
template <> Rcomplex r_coerce<RAWSXP,CPLXSXP>(Rbyte from);
template <> Rcomplex r_coerce<LGLSXP,CPLXSXP>(int from) ;


} // internal
} // Rcpp

#endif
