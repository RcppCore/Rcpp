// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// dispatch.h: Rcpp R/C++ interface class library -- macros for dispatch
//
// Copyright (C) 2012 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__macros__dispatch_h
#define Rcpp__macros__dispatch_h

#define ___RCPP_HANDLE_CASE___( ___RTYPE___ , ___FUN___ , ___OBJECT___ , ___RCPPTYPE___ )	\
	case ___RTYPE___ :																	\
		return ___FUN___( ::Rcpp::___RCPPTYPE___< ___RTYPE___ >( ___OBJECT___ ) ) ;

#define ___RCPP_RETURN___( __FUN__, __SEXP__ , __RCPPTYPE__ )						\
	SEXP __TMP__ = __SEXP__ ;															\
	switch( TYPEOF( __TMP__ ) ){										 				\
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


#endif
