// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// ExpressionVector.cpp: Rcpp R/C++ interface class library -- expression vectors
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

#include <Rcpp/Vector.h>
#include <Rcpp/Environment.h>

namespace Rcpp{
namespace internal{

	template <> 
	SEXP vector_from_string<EXPRSXP>( const std::string& code ){
		ParseStatus status;
		SEXP expr = PROTECT( Rf_mkString( code.c_str() ) );
		SEXP res  = PROTECT( R_ParseVector(expr, -1, &status, R_NilValue));
		switch( status ){
		case PARSE_OK:
			UNPROTECT( 2) ;
			return(res) ;
			break;
		default:
			UNPROTECT(2) ;
			throw parse_error() ;
		}
		return R_NilValue ; /* -Wall */
	}
	
	SEXP eval_methods< ::Rcpp::Vector<EXPRSXP> >::eval(){
		SEXP xp = ( static_cast< ::Rcpp::Vector<EXPRSXP>& >(*this) ).asSexp() ;
		return try_catch( ::Rf_lcons( ::Rf_install( "eval" ) , ::Rf_cons( xp, R_NilValue) ) ) ;
	} ;
	SEXP eval_methods< ::Rcpp::Vector<EXPRSXP> >::eval( const ::Rcpp::Environment& env ){
		SEXP xp = ( static_cast< ::Rcpp::Vector<EXPRSXP>& >(*this) ).asSexp() ;
		return try_catch( ::Rf_lcons( ::Rf_install( "eval" ) , ::Rf_cons( xp, ::Rf_cons(env.asSexp(), R_NilValue)) ) ) ;
	} ;
	
} // namespace internal
} // namespace Rcpp 
