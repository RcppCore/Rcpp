// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// eval_methods.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__vector__forward_eval_methods_h
#define Rcpp__vector__forward_eval_methods_h

namespace internal{
	template <int RTYPE>
	SEXP vector_from_string( const std::string& st ) throw(parse_error,not_compatible) {
		return r_cast<RTYPE>( Rf_mkString( st.c_str() ) ) ;
	}
	
	template <int RTYPE>
	SEXP vector_from_string_expr( const std::string& code) throw(parse_error,not_compatible) {
		ParseStatus status;
		SEXP expr = PROTECT( ::Rf_mkString( code.c_str() ) );
		SEXP res  = PROTECT( ::R_ParseVector(expr, -1, &status, R_NilValue));
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
	
	template <>
	inline SEXP vector_from_string<EXPRSXP>( const std::string& st ) throw(parse_error,not_compatible) {
		return vector_from_string_expr<EXPRSXP>( st ) ;
	}
	
	template <int RTYPE> class eval_methods {} ;
	template <> class eval_methods<EXPRSXP> ;
	
}
#endif
