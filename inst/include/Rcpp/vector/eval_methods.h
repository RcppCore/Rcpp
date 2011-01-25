// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// eval_methods.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__vector__eval_methods_h
#define Rcpp__vector__eval_methods_h

namespace internal{
	
    template <int RTYPE> class expr_eval_methods {
    public:
	typedef Rcpp::Vector<RTYPE> VECTOR ;
		
	SEXP eval(){
	    SEXP xp = ( static_cast<VECTOR&>(*this) ).asSexp() ;
	    SEXP evalSym = Rf_install( "eval" );
	    return try_catch( Rf_lang2( evalSym, xp ) ) ;
	} ;
	SEXP eval( const ::Rcpp::Environment& env ){
	    SEXP xp = ( static_cast<VECTOR&>(*this) ).asSexp() ;
	    SEXP evalSym = Rf_install( "eval" );
	    return try_catch( Rf_lang3( evalSym, xp, env.asSexp() ) ) ;
	} ;
    } ;
	
    template<> class eval_methods<EXPRSXP> : public expr_eval_methods<EXPRSXP> {} ;
	
}
#endif
