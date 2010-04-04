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

#ifndef Rcpp_Promise_h
#define Rcpp_Promise_h

#include <RcppCommon.h>
#include <Rcpp/Vector.h>
#include <Rcpp/Environment.h>
#include <Rcpp/RObject.h>

namespace Rcpp{ 

class Promise : public RObject {     
public:

	class unevaluated_promise : public std::exception{
	public:
		unevaluated_promise() throw(){}; 
		virtual ~unevaluated_promise() throw(){} ;
		virtual const char* what() const throw() ;
	} ;

	Promise( SEXP x) throw(not_compatible) ;
	
	Promise( const Promise& other) ;
	Promise& operator=(const Promise& other ) ;
	
	/** 
	 * Return the result of the PRSEEN macro
	 */
	int seen() const ;
	
	/**
	 * Return the result of the PRVALUE macro on the promise
	 */
	SEXP value() const throw(unevaluated_promise) ;

	bool was_evaluated() const ;
	
	/**
	 * The promise expression: PRCODE
	 */
	ExpressionVector expression() const ;

	/**
	 * The promise environment : PRENV
	 */
	Environment environment() const ;
	
} ;

} // namespace

#endif
