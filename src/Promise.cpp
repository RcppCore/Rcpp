// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Promise.h: Rcpp R/C++ interface class library -- promises (PROMSXP)
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

#include <Rcpp/Promise.h>

namespace Rcpp {

	Promise::Promise(SEXP x) throw(not_compatible) : RObject(){
		if( TYPEOF(x) == PROMSXP ){
			setSEXP( x ) ;
		} else{
			throw not_compatible("not a promise") ;
		}
	}

	Promise::Promise(const Promise& other) : RObject() {
		setSEXP( other.asSexp() );
	}
	
	Promise& Promise::operator=(const Promise& other){
		setSEXP( other.asSexp() );
		return *this ;
	}
	
	int Promise::seen() const {
		return PRSEEN(m_sexp);
	}

	SEXP Promise::value() const throw(unevaluated_promise) {
		SEXP val = PRVALUE(m_sexp) ; 
		if( val == R_UnboundValue ) throw unevaluated_promise() ;
		return val ;
	}
	
	bool Promise::was_evaluated() const {
		return PRVALUE(m_sexp) != R_UnboundValue ;
	}

	Environment Promise::environment() const {
		return Environment(PRENV(m_sexp)) ;
	}

	ExpressionVector Promise::expression() const {
		return ExpressionVector(PRCODE(m_sexp)) ;
	}
	
} // namespace

