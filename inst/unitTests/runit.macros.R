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

test.macro.switch <- function(){
	rcpp_typeof <- function(x){
		.Call( "rcpp_call_test", x, PACKAGE = "Rcpp" )
	}
	sexp_types <- c( integer = 13L, double = 14L, raw = 24L, 
		complex = 15L, logical = 10L, list = 19L, 
		"expression" = 20L, character = 16 )
	checkEquals( rcpp_typeof(1L ), sexp_types[[ "integer" ]], msg = "RCPP_RETURN_VECTOR <INTSXP> " )
	checkEquals( rcpp_typeof(1.0), sexp_types[["double"]], msg = "RCPP_RETURN_VECTOR <REALSXP> " )
	checkEquals( rcpp_typeof(as.raw(0)), sexp_types[["raw"]] , msg = "RCPP_RETURN_VECTOR <RAWSXP> " )
	checkEquals( rcpp_typeof(1i), sexp_types[["complex"]], msg = "RCPP_RETURN_VECTOR <CPLXSXP> " )
	checkEquals( rcpp_typeof(TRUE), sexp_types[["logical"]], msg = "RCPP_RETURN_VECTOR <LGLSXP> " )
	checkEquals( rcpp_typeof(list(1)), sexp_types[["list"]] , msg = "RCPP_RETURN_VECTOR <VECSXP> " )
	checkEquals( rcpp_typeof(expression(x)), sexp_types[["expression"]], msg = "RCPP_RETURN_VECTOR <EXPRSXP> " )
	checkEquals( rcpp_typeof(""), sexp_types[["character"]], msg = "RCPP_RETURN_VECTOR <STRSXP> " )
}

