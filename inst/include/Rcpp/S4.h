// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// S4.h: Rcpp R/C++ interface class library -- S4 objects
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

#ifndef Rcpp_S4_h
#define Rcpp_S4_h                     

#include <RcppCommon.h>
#include <Rcpp/RObject.h>

namespace Rcpp{ 

/**
 * S4 object
 */
class S4 : public RObject{
public:
	S4() ;
	
	/**
	 * checks that x is an S4 object and wrap it.
	 *
	 * @param x must be an S4 object
	 */
	S4(SEXP x); 
	
	/**
	 * copy constructor
	 *
	 * @param other other S4 object
	 */
	S4(const S4& other) ;
	
	/**
	 * assignment operator. 
	 */
	S4& operator=( const S4& other);
	
	/**
	 * Creates an S4 object of the requested class. 
	 *
	 * @param klass name of the target S4 class
	 * @throw not_s4 if klass does not map to a known S4 class
	 */
	S4( const std::string& klass ) throw(S4_creation_error) ;
	
} ;

} // namespace Rcpp

#endif
