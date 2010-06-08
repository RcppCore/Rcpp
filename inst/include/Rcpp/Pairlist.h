// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Pairlist.h: Rcpp R/C++ interface class library -- pair lists objects (LISTSXP)
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

#ifndef Rcpp_Pairlist_h
#define Rcpp_Pairlist_h

#include <RcppCommon.h>
#include <Rcpp/DottedPair.h>
#include <Rcpp/r_cast.h>

namespace Rcpp{

class Pairlist : public DottedPair {
public:		
	Pairlist();
	Pairlist(SEXP x) throw(not_compatible) ;
	Pairlist(const Pairlist& other) ;
	Pairlist& operator=(const Pairlist& other) ;
		
#ifdef HAS_VARIADIC_TEMPLATES
template<typename... Args> 
	Pairlist( const Args&... args) : DottedPair(args...) {}
#else

#include <Rcpp/generated/Pairlist__ctors.h>

#endif

	~Pairlist() ;
		
} ;
	
}
#endif
