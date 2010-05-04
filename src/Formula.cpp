// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Formula.cpp: Rcpp R/C++ interface class library -- Formulae
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

#include <Rcpp/Formula.h>

namespace Rcpp{
	
	Formula::Formula() : Language(){}
	
	Formula::Formula(SEXP x) throw(not_compatible) : Language(){
		switch( TYPEOF( x ) ){
		case LANGSXP:
			if( ::Rf_inherits( x, "formula") ){
				setSEXP( x );
			} else{
				SEXP y = internal::convert_using_rfunction( x, "as.formula") ;
				setSEXP( y ) ;
			}
			break;
		case EXPRSXP:
		case VECSXP:
			/* lists or expression, try the first one */
			if( ::Rf_length(x) > 0 ){
				SEXP y = VECTOR_ELT( x, 0 ) ;
				if( ::Rf_inherits( y, "formula" ) ){
					setSEXP( y ) ;	
				} else{
					SEXP z = internal::convert_using_rfunction( y, "as.formula") ;
					setSEXP( z ) ;
				}
			} else{
				throw not_compatible( "cannot create formula from empty list or expression" ) ;	
			}
			break;
		default:
			SEXP y = internal::convert_using_rfunction( x, "as.formula") ;
			setSEXP( y ) ;
		}
	}
	
	Formula::Formula( const std::string& code) throw(not_compatible) : Language() {
		setSEXP( internal::convert_using_rfunction( ::Rf_mkString(code.c_str()), "as.formula") );	
	}
	
	Formula::Formula( const Formula& other ) : Language( other.asSexp() ){}
	
	Formula& Formula::operator=( const Formula& other ){
		setSEXP( other.asSexp() );
		return *this ;
	}
	
} // namespace Rcpp
