// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// WeakReference.h: Rcpp R/C++ interface class library -- weak references
//
// Copyright (C) 2009 - 2010	Romain Francois and Dirk Eddelbuettel
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

#ifndef Rcpp_WeakReference_h
#define Rcpp_WeakReference_h

#include <RcppCommon.h>
#include <Rcpp/RObject.h>

namespace Rcpp{

class WeakReference : public RObject {
public:
	WeakReference() : RObject(){} ;

	/**
	 * wraps a weak reference
	 *
	 * @param x presumably a SEXP of SEXTYPE WEAKREFSXP
	 *
	 * @throw not_compatible if x is not a weak reference
	 */
	WeakReference( SEXP x) throw(not_compatible) ; 

	WeakReference( const WeakReference& other) ;
	WeakReference& operator=(const WeakReference& other) ;
	
	/* TODO: constructor that makes a new weak reference based
		on key, value, finalizer (C and R) */
	
	/** 
	 * Retrieve the key
	 */
	SEXP key() ; 

	/**
	 * Retrieve the value
	 */
	SEXP value() ;

} ;


}

#endif
