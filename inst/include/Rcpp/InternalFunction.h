// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// InternalFunction.h: Rcpp R/C++ interface class library -- exposing C++ functions
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

#ifndef Rcpp_InternalFunction_h
#define Rcpp_InternalFunction_h

#include <RcppCommon.h>

#include <Rcpp/grow.h>
#include <Rcpp/RObject.h>

namespace Rcpp{ 

/** 
 * functions
 */
class InternalFunction : public RObject {
public:

#include <Rcpp/generated/InternalFunction__ctors.h>	
		
private:
	
	// TODO: we can probably make this more efficient
	//       by caching the Rcpp namespace or the function
	inline void set( SEXP xp){
		Environment RCPP = Environment::Rcpp_namespace() ;
		Function intf = RCPP["internal_function"] ;
		setSEXP( intf( xp ) ) ; 
	}
	
};

} // namespace Rcpp

#endif
