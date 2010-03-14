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

test.RObject.S4methods <- function(){
	funx <- cfunction(signature(x = "ANY" ), '
	RObject y(x) ;
	List res(5) ;
	res[0] = y.isS4() ;
	res[1] = y.hasSlot("x") ;
	res[2] = y.hasSlot("z") ;
	res[3] = y.slot("x") ;
	res[4] = y.slot("y") ;
	return res ;
	', Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;" )
	setClass("track",
           representation(x="numeric", y="numeric"))
	tr <- new( "track", x = 2, y = 2 )
	checkEquals( funx(tr),
		list( TRUE, TRUE, FALSE, 2.0, 2.0 )
	, msg = "slot management" )
	
	funx <- cfunction(signature(x = "ANY" ), '
	RObject y(x) ;
	y.slot( "x" ) = 10.0 ;
	y.slot( "y" ) = 20.0 ;
	return R_NilValue ;
	', Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;" )
	funx( tr )
	checkEquals( tr@x, 10.0 , msg = "slot('x') = 10" )
	checkEquals( tr@y, 20.0 , msg = "slot('y') = 20" )
	
	funx <- cfunction(signature(x = "ANY" ), '
	RObject y(x) ;
	y.slot( "foo" ) = 10.0 ;
	return R_NilValue ;
	', Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;" )
	checkException( funx( tr ), msg = "slot does not exist" )
	
	funx <- cfunction(signature(x = "ANY" ), '
	RObject y(x) ;
	y.slot( "foo" ) ;
	return R_NilValue ;
	', Rcpp=TRUE, verbose=FALSE, includes = "using namespace Rcpp;" )
	checkException( funx( tr ), msg = "slot does not exist" )
	
}

test.S4 <- function(){
		
	setClass("track",
           representation(x="numeric", y="numeric"))
	tr <- new( "track", x = 2, y = 3 )
	fx <- cfunction( signature( x = "ANY" ),
                        'S4 o(x); return o.slot( "x" ) ;', 
		Rcpp = TRUE, includes = "using namespace Rcpp;" )
	checkEquals( fx( tr ), 2, msg = "S4( SEXP )" )
	
	checkException( fx( list( x = 2, y = 3 ) ), msg = "not S4" )
	checkException( fx( structure( list( x = 2, y = 3 ), class = "track" ) ), msg = "S3 is not S4" )

	fx <- cfunction( signature( clazz = "character" ), 
		'
		std::string cl = as<std::string>( clazz );
		return S4( cl ); 
		', includes = "using namespace Rcpp" )
	tr <- fx( "track" )
	checkTrue( inherits( tr, "track" ) )
	checkEquals( tr@x, 0.0 )
	checkEquals( tr@y, 0.0 )
	checkException( fx( "someclassthatdoesnotexist" ) )
	
}

