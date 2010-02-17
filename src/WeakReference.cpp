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

#include <Rcpp/WeakReference.h>
#include <Rcpp/RObject.h>

namespace Rcpp{
	
	WeakReference::WeakReference( SEXP x) throw(not_compatible) : RObject(){
		if( TYPEOF(x) == WEAKREFSXP ){
			setSEXP(x) ; 
		} else{
			throw not_compatible( "not a weak reference" ) ;
		}
	}
	
	SEXP WeakReference::key() {
		return R_WeakRefKey(m_sexp) ;
	}
	
	SEXP WeakReference::value() {
		return R_WeakRefValue(m_sexp);
	}
	
	WeakReference::WeakReference( const WeakReference& other ) : RObject( other.asSexp() ){}
	
	WeakReference& WeakReference::operator=(const WeakReference& other){
		setSEXP( other.asSexp() );
		return *this;
	}
	
}
// namesapce
