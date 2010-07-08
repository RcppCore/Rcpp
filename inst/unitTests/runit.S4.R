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

.setUp <- function() {
    tests <- ".rcpp.S4"
    if( ! exists( tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list(
        	"S4_methods" = list( 
        		signature(x = "ANY" ), '
					RObject y(x) ;
					List res(5) ;
					res[0] = y.isS4() ;
					res[1] = y.hasSlot("x") ;
					res[2] = y.hasSlot("z") ;
					res[3] = y.slot("x") ;
					res[4] = y.slot("y") ;
					return res ;
				'
        	), 
        	"S4_getslots" = list( 
        		signature(x = "ANY" ), '
					RObject y(x) ;
					y.slot( "x" ) = 10.0 ;
					y.slot( "y" ) = 20.0 ;
					return R_NilValue ;
				'
        	), 
        	"S4_setslots" = list( 
        		signature(x = "ANY" ), '
				RObject y(x) ;
				y.slot( "foo" ) = 10.0 ;
				return R_NilValue ;
				'
        	), 
        	"S4_setslots_2" = list( 
        		signature(x = "ANY" ), '
					RObject y(x) ;
					y.slot( "foo" ) ;
					return R_NilValue ;
				'
        	), 
        	"S4_ctor" = list( 
        		signature( clazz = "character" ), 
				'
					std::string cl = as<std::string>( clazz );
					return S4( cl ); 
				' 
        	), 
        	"S4_is" = list( 
        		signature(tr="ANY"), '
					S4 o(tr) ;
					return wrap( o.is( "track" ) ) ;
				'
        	), 
        	"S4_is_2" = list( 
        		signature(tr="ANY"), '
					S4 o(tr) ;
					return wrap( o.is( "trackCurve" ) ) ;
				'
        	), 
        	"S4_slotproxy" = list(
        	    signature(tr="ANY"), 
        	    ' S4 o(tr); return NumericVector(o.slot("x")); '
        	), 
        	"S4_attrproxy" = list( 
        		signature(tr="ANY"), 
        		' IntegerVector o(tr); return CharacterVector(o.attr("foo")); '
        	)
        )
        
        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction(signatures, bodies,
                           plugin = "Rcpp",
                           cxxargs = ifelse(Rcpp:::capabilities()[["initializer lists"]],"-std=c++0x",""))
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}

test.RObject.S4methods <- function(){
	fx <- .rcpp.S4$S4_methods
	setClass("track",
           representation(x="numeric", y="numeric"))
	tr <- new( "track", x = 2, y = 2 )
	checkEquals( fx(tr),
		list( TRUE, TRUE, FALSE, 2.0, 2.0 )
	, msg = "slot management" )
	
	fx <- .rcpp.S4$S4_getslots
	fx( tr )
	checkEquals( tr@x, 10.0 , msg = "slot('x') = 10" )
	checkEquals( tr@y, 20.0 , msg = "slot('y') = 20" )
	
	fx <- .rcpp.S4$S4_setslots
	checkException( fx( tr ), msg = "slot does not exist" )
	
	fx <- .rcpp.S4$S4_setslots_2
	checkException( fx( tr ), msg = "slot does not exist" )
	
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

	fx <- .rcpp.S4$S4_ctor
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
	
	fx <- .rcpp.S4$S4_is
	checkTrue( fx( tr1 ), msg = 'track is track' )
	checkTrue( fx( tr2 ), msg = 'trackCurve is track' )
	
	fx <- .rcpp.S4$S4_is_2
	checkTrue( !fx( tr1 ), msg = 'track is not trackCurve' )
	checkTrue( fx( tr2 ), msg = 'trackCurve is trackCurve' )
	
}

test.Vector.SlotProxy.ambiguity <- function(){
	setClass("track", representation(x="numeric", y="numeric"))
	setClass("trackCurve", representation(smooth = "numeric"), contains = "track")
	
	tr1 <- new( "track", x = 2, y = 3 )
	fx <- .rcpp.S4$S4_slotproxy
	checkEquals( fx(tr1), 2, "Vector( SlotProxy ) ambiguity" )
	
}

test.Vector.AttributeProxy.ambiguity <- function(){
	x <- 1:10
	attr( x, "foo" ) <- "bar"
	
	fx <- .rcpp.S4$S4_attrproxy
	checkEquals( fx(x), "bar", "Vector( AttributeProxy ) ambiguity" )
	
}

