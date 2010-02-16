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

test.as.int <- function(){
	funx <- cfunction(signature(x="numeric"), '
	int y = as<int>(x) ;
	return wrap(y) ;
	', Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;")
	checkEquals( funx(10), 10L, msg = "as<int>( REALSXP ) " )
	checkEquals( funx(10L), 10L, msg = "as<int>( INTSXP ) " )
	checkEquals( funx(as.raw(10L)), 10L, msg = "as<int>( RAWSXP ) " )
	checkEquals( funx(TRUE), 1L, msg = "as<int>( LGLSXP ) " )
}

test.as.double <- function(){
	funx <- cfunction(signature(x="numeric"), '
	double y = as<double>(x) ;
	return wrap(y) ;
	', Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;")
	checkEquals( funx(10), 10.0, msg = "as<double>( REALSXP ) " )
	checkEquals( funx(10L), 10.0, msg = "as<double>( INTSXP ) " )
	checkEquals( funx(as.raw(10L)), 10.0, msg = "as<double>( RAWSXP ) " )
	checkEquals( funx(TRUE), 1.0, msg = "as<double>( LGLSXP ) " )
}

test.as.raw <- function(){
	funx <- cfunction(signature(x="numeric"), '
	Rbyte y = as<Rbyte>(x) ;
	return wrap(y) ;
	', Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;")
	checkEquals( funx(10), as.raw(10), msg = "as<Rbyte>( REALSXP ) " )
	checkEquals( funx(10L), as.raw(10), msg = "as<Rbyte>( INTSXP ) " )
	checkEquals( funx(as.raw(10L)), as.raw(10), msg = "as<Rbyte>( RAWSXP ) " )
	checkEquals( funx(TRUE), as.raw(1), msg = "as<Rbyte>( LGLSXP ) " )
}

test.as.bool <- function(){
	funx <- cfunction(signature(x="numeric"), '
	bool y = as<bool>(x) ;
	return wrap(y) ;
	', Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;")
	checkEquals( funx(10), as.logical(10), msg = "as<bool>( REALSXP ) " )
	checkEquals( funx(10L), as.logical(10), msg = "as<bool>( INTSXP ) " )
	checkEquals( funx(as.raw(10L)), as.logical(10), msg = "as<bool>( RAWSXP ) " )
	checkEquals( funx(TRUE), as.logical(1), msg = "as<bool>( LGLSXP ) " )
}

test.as.string <- function(){
	funx <- cfunction(signature(x="character"), '
	string y = as<string>(x) ;
	return wrap(y) ;
	', Rcpp=TRUE, verbose=FALSE, 
	includes =c( "using namespace Rcpp;", "using namespace std;" ) )
	checkEquals( funx("foo"), "foo", msg = "as<string>( STRSXP ) " )
}

test.as.vector.int <- function(){
	funx <- cfunction(signature(x="numeric"), '
	vector<int> y = as< vector<int> >(x) ;
	return wrap(y) ;
	', Rcpp=TRUE, verbose=FALSE, 
	includes =c( "using namespace Rcpp;", "using namespace std;" ) )
	checkEquals( funx(1:10), 1:10 , msg = "as<vector<int>>( INTSXP ) " )
	checkEquals( funx(as.numeric(1:10)), 1:10 , msg = "as<vector<int>>( REALSXP ) " )
	checkEquals( funx(as.raw(1:10)), 1:10 , msg = "as<vector<int>>( RAWSXP ) " )
	checkEquals( funx(c(TRUE,FALSE)), 1:0 , msg = "as<vector<int>>( LGLSXP ) " )
}

test.as.vector.double <- function(){
	funx <- cfunction(signature(x="numeric"), '
	vector<double> y = as< vector<double> >(x) ;
	return wrap(y) ;
	', Rcpp=TRUE, verbose=FALSE, 
	includes =c( "using namespace Rcpp;", "using namespace std;" ) )
	checkEquals( funx(1:10), as.numeric(1:10) , msg = "as<vector<double>>( INTSXP ) " )
	checkEquals( funx(as.numeric(1:10)), as.numeric(1:10) , msg = "as<vector<double>>( REALSXP ) " )
	checkEquals( funx(as.raw(1:10)), as.numeric(1:10), msg = "as<vector<double>>( RAWSXP ) " )
	checkEquals( funx(c(TRUE,FALSE)), c(1.0, 0.0) , msg = "as<vector<double>>( LGLSXP ) " )
}

test.as.vector.raw <- function(){
	funx <- cfunction(signature(x="numeric"), '
	vector<Rbyte> y = as< vector<Rbyte> >(x) ;
	return wrap(y) ;
	', Rcpp=TRUE, verbose=FALSE, 
	includes =c( "using namespace Rcpp;", "using namespace std;" ) )
	checkEquals( funx(1:10), as.raw(1:10) , msg = "as<vector<Rbyte>>( INTSXP ) " )
	checkEquals( funx(as.numeric(1:10)), as.raw(1:10) , msg = "as<vector<Rbyte>>( REALSXP ) " )
	checkEquals( funx(as.raw(1:10)), as.raw(1:10) , msg = "as<vector<Rbyte>>( RAWSXP ) " )
	checkEquals( funx(c(TRUE,FALSE)), as.raw(1:0) , msg = "as<vector<Rbyte>>( LGLSXP ) " )
}

test.as.vector.bool <- function(){
	funx <- cfunction(signature(x="numeric"), '
	vector<bool> y = as< vector<bool> >(x) ;
	return wrap(y) ;
	', Rcpp=TRUE, verbose=FALSE, 
	includes =c( "using namespace Rcpp;", "using namespace std;" ) )
	checkEquals( funx(0:10), as.logical(0:10) , msg = "as<vector<bool>>( INTSXP ) " )
	checkEquals( funx(as.numeric(0:10)), as.logical(0:10) , msg = "as<vector<bool>>( REALSXP ) " )
	checkEquals( funx(as.raw(0:10)), as.logical(0:10) , msg = "as<vector<bool>>( RAWSXP ) " )
	checkEquals( funx(c(TRUE,FALSE)), as.logical(1:0) , msg = "as<vector<bool>>( LGLSXP ) " )
}


test.as.vector.bool <- function(){
	funx <- cfunction(signature(x="character"), '
	vector<string> y = as< vector<string> >(x) ;
	return wrap(y) ;
	', Rcpp=TRUE, verbose=FALSE, 
	includes =c( "using namespace Rcpp;", "using namespace std;" ) )
	checkEquals( funx(letters), letters , msg = "as<vector<string>>( STRSXP ) " )
	
}

