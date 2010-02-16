#!/usr/bin/r -t
#
# Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
#
# This file is part of Rcpp.
#
# Rcpp is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Rcpp is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

.setUp <- function(){
	suppressMessages( require( inline ) )
}

test.Symbol <- function(){
	funx <- cfunction(signature(), '
	SEXP res = PROTECT( Rf_allocVector( LGLSXP, 4) ) ;
	/* SYMSXP */
	LOGICAL(res)[0] = Symbol( Rf_install("foobar") ).asSexp() == Rf_install("foobar") ? TRUE : FALSE ;
	
	/* CHARSXP */
	LOGICAL(res)[1] = Symbol( Rf_mkChar("foobar") ).asSexp() == Rf_install("foobar") ? TRUE : FALSE ;
	
	/* STRSXP */
	LOGICAL(res)[2] = Symbol( Rf_mkString("foobar") ).asSexp() == Rf_install("foobar") ? TRUE : FALSE ;
	
	/* std::string */
	LOGICAL(res)[3] = Symbol( "foobar" ).asSexp() == Rf_install("foobar") ? TRUE : FALSE ;
	
	UNPROTECT(1) ; /* res */
	return res ;
	', Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;" )
	res <- funx()
	checkTrue( res[1L], msg = "Symbol creation - SYMSXP " )
	checkTrue( res[2L], msg = "Symbol creation - CHARSXP " )
	checkTrue( res[3L], msg = "Symbol creation - STRSXP " )
	checkTrue( res[4L], msg = "Symbol creation - std::string " )
}

test.Symbol.notcompatible <- function(){
	funx <- cfunction(signature(x="ANY"), 'return Symbol(x);', 
		Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;" )
	checkException( funx(funx), msg = "Symbol not compatible with function" )
	checkException( funx(asNamespace("Rcpp")), msg = "Symbol not compatible with environment" )
	checkException( funx(1:10), msg = "Symbol not compatible with integer" )
	checkException( funx(TRUE), msg = "Symbol not compatible with logical" )
	checkException( funx(1.3), msg = "Symbol not compatible with numeric" )
	checkException( funx(as.raw(1) ), msg = "Symbol not compatible with raw" )
}
