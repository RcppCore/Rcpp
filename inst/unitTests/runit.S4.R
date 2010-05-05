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

test.RObject.S4methods <- function(){
	funx <- cppfunction(signature(x = "ANY" ), '
	RObject y(x) ;
	List res(5) ;
	res[0] = y.isS4() ;
	res[1] = y.hasSlot("x") ;
	res[2] = y.hasSlot("z") ;
	res[3] = y.slot("x") ;
	res[4] = y.slot("y") ;
	return res ;
	' )
	setClass("track",
           representation(x="numeric", y="numeric"))
	tr <- new( "track", x = 2, y = 2 )
	checkEquals( funx(tr),
		list( TRUE, TRUE, FALSE, 2.0, 2.0 )
	, msg = "slot management" )
	
	funx <- cppfunction(signature(x = "ANY" ), '
	RObject y(x) ;
	y.slot( "x" ) = 10.0 ;
	y.slot( "y" ) = 20.0 ;
	return R_NilValue ;
	' )
	funx( tr )
	checkEquals( tr@x, 10.0 , msg = "slot('x') = 10" )
	checkEquals( tr@y, 20.0 , msg = "slot('y') = 20" )
	
	funx <- cppfunction(signature(x = "ANY" ), '
	RObject y(x) ;
	y.slot( "foo" ) = 10.0 ;
	return R_NilValue ;
	' )
	checkException( funx( tr ), msg = "slot does not exist" )
	
	funx <- cppfunction(signature(x = "ANY" ), '
	RObject y(x) ;
	y.slot( "foo" ) ;
	return R_NilValue ;
	' )
	checkException( funx( tr ), msg = "slot does not exist" )
	
}

test.S4 <- function(){
		
	setClass("track",
           representation(x="numeric", y="numeric"))
	tr <- new( "track", x = 2, y = 3 )
	fx <- cppfunction( signature( x = "ANY" ),
                        'S4 o(x); return o.slot( "x" ) ;')
	checkEquals( fx( tr ), 2, msg = "S4( SEXP )" )
	
	checkException( fx( list( x = 2, y = 3 ) ), msg = "not S4" )
	checkException( fx( structure( list( x = 2, y = 3 ), class = "track" ) ), msg = "S3 is not S4" )

	fx <- cppfunction( signature( clazz = "character" ), 
		'
		std::string cl = as<std::string>( clazz );
		return S4( cl ); 
		' )
	tr <- fx( "track" )
	checkTrue( inherits( tr, "track" ) )
	checkEquals( tr@x, numeric(0) )
	checkEquals( tr@y, numeric(0) )
	checkException( fx( "someclassthatdoesnotexist" ) )
	
}


test.S4.is <- function(){
	setClass("track", representation(x="numeric", y="numeric"))
	setClass("trackCurve", representation(smooth = "numeric"), contains = "track")
	
	tr1 <- new( "track", x = 2, y = 3 )
	tr2 <- new( "trackCurve", x = 2, y = 3, smooth = 5 )
	
	fx <- cppfunction( signature(tr="ANY"), '
		S4 o(tr) ;
		return wrap( o.is( "track" ) ) ;
		' )
	checkTrue( fx( tr1 ), msg = 'track is track' )
	checkTrue( fx( tr2 ), msg = 'trackCurve is track' )
	
	fx <- cppfunction( signature(tr="ANY"), '
		S4 o(tr) ;
		return wrap( o.is( "trackCurve" ) ) ;
		' )
	checkTrue( !fx( tr1 ), msg = 'track is not trackCurve' )
	checkTrue( fx( tr2 ), msg = 'trackCurve is trackCurve' )
	
}

test.Vector.SlotProxy.ambiguity <- function(){
	setClass("track", representation(x="numeric", y="numeric"))
	setClass("trackCurve", representation(smooth = "numeric"), contains = "track")
	
	tr1 <- new( "track", x = 2, y = 3 )
	fx <- cppfunction( signature(tr="ANY"), 
		' S4 o(tr); return NumericVector(o.slot("x")); '
	)
	checkEquals( fx(tr1), 2, "Vector( SlotProxy ) ambiguity" )
	
}

test.Vector.AttributeProxy.ambiguity <- function(){
	x <- 1:10
	attr( x, "foo" ) <- "bar"
	
	fx <- cppfunction( signature(tr="ANY"), 
		' S4 o(tr); return CharacterVector(o.slot("foo")); '
	)
	checkEquals( fx(tr1), "bar", "Vector( AttributeProxy ) ambiguity" )
	
}

