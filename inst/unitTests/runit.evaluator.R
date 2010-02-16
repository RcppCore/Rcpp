#!/usr/bin/r -t
#
# Copyright (C) 2009 - 2010	Romain Francois
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

test.evaluator.error <- function(){
	funx <- cfunction(signature(),  '
	return Rcpp::Evaluator::run( Rf_lang2( Rf_install("stop"), Rf_mkString( "boom" ) ) ) ;
	', Rcpp=TRUE, verbose=FALSE)
	
	checkException( funx(), msg = "Evaluator::run( stop() )" )
}

test.evaluator.ok <- function(){
	funx <- cfunction(signature(x="integer"),  '
	return Rcpp::Evaluator::run( Rf_lang2( Rf_install("sample"), x ) ) ;
	', Rcpp=TRUE, verbose=FALSE)
	
	checkEquals( sort(funx(1:10)), 1:10, msg = "Evaluator running fine" )
}
             
