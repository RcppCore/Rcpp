// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// posixt.h: Rcpp R/C++ interface class library -- Date type
//
// Copyright (C) 2010	      Dirk Eddelbuettel and Romain Francois
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

#include <RcppCommon.h>

namespace Rcpp{
namespace internal{
	
SEXP getPosixClasses(){
	SEXP datetimeclass = PROTECT(Rf_allocVector(STRSXP,2));
	SET_STRING_ELT(datetimeclass, 0, Rf_mkChar("POSIXct"));
	SET_STRING_ELT(datetimeclass, 1, Rf_mkChar("POSIXt"));
	UNPROTECT(1) ;
	return datetimeclass ;
}

SEXP new_posixt_object( double d){
	SEXP x = PROTECT( Rf_ScalarReal( d ) ) ;
	Rf_setAttrib(x, R_ClassSymbol, getPosixClasses() ); 
	UNPROTECT(1); 
	return x ;	
}

SEXP new_date_object( double d){
	SEXP x = PROTECT(Rf_ScalarReal( d ) ) ;
	Rf_setAttrib(x, R_ClassSymbol, Rf_mkString("Date")); 
	UNPROTECT(1);
	return x;
}

	
}
}
