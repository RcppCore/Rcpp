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
	if( ! exists( ".rcpp.stats", globalenv() ) ){
		# definition of all the functions at once

		f <- list(
			"runit_dbinom" = list(
				signature( x = "integer" ),
				'
					IntegerVector xx(x) ;
					return List::create(
						_["false"] = stats::dbinom( xx, 10, .5),
						_["true"]  = stats::dbinom( xx, 10, .5, true )
						) ;
				'
			),
			"runit_dpois" = list(
				signature( x = "integer" ),
				'
					IntegerVector xx(x) ;
					return List::create(
						_["false"] = stats::dpois( xx, .5 ),
						_["true"]  = stats::dpois( xx, .5 , true )
						) ;
				'
			),
			"runit_dnorm" = list(
				signature( x = "numeric" ),
				'
					NumericVector xx(x) ;
					return List::create(
						_["false"] = stats::dnorm( xx, 0.0, 1.0 ),
						_["true"]  = stats::dnorm( xx, 0.0, 1.0, true )
						) ;
				'
			),
			"runit_dt" = list(
				signature( x = "numeric" ),
				'
					NumericVector xx(x) ;
					return List::create(
						_["false"] = stats::dt( xx, 5),
						_["true"]  = stats::dt( xx, 5, true )
						) ;
				'
			),
			"runit_pt" = list(
				signature( x = "numeric" ),
				'
					NumericVector xx(x) ;
					return List::create(
						_["false"] = stats::pt( xx, 5, true),
						_["true"]  = stats::pt( xx, 5, true, true  )
						) ;
				'
			)


		)

		signatures <- lapply( f, "[[", 1L )
		bodies <- lapply( f, "[[", 2L )
		fx <- cxxfunction( signatures, bodies, plugin = "Rcpp")
		getDynLib( fx ) # just forcing loading the dll now
		assign( ".rcpp.stats", fx, globalenv() )
	}
}

test.stats.dbinom <- function( ){
	fx <- .rcpp.stats$runit_dbinom
	checkEquals(fx(1:10) ,
                list( false = dbinom(1:10, 10, .5), true = dbinom(1:10, 10, .5, TRUE ) ),
                msg = "stats.dbinom" )
}

test.stats.dpois <- function( ){
	fx <- .rcpp.stats$runit_dpois
	checkEquals(fx(0:5) ,
                list( false = dpois(0:5, .5), true = dpois(0:5, .5, TRUE ) ),
                msg = "stats.dpois" )
}

test.stats.dnorm <- function( ) {
	fx <- .rcpp.stats$runit_dnorm
    v <- seq(0.0, 1.0, by=0.1)
    checkEquals(fx(v),
                list( false = dnorm(v, 0.0, 1.0), true = dnorm(v, 0.0, 1.0, TRUE ) ),
                msg = "stats.dnorm" )
}

test.stats.dt <- function( ) {
	fx <- .rcpp.stats$runit_dt
    v <- seq(0.0, 1.0, by=0.1)
    checkEquals(fx(v),
                list( false = dt(v, 5), true = dt(v, 5, log=TRUE ) ), # NB: need log=TRUE here
                msg = "stats.dt" )
}

test.stats.pt <- function( ) {
	fx <- .rcpp.stats$runit_pt
    v <- seq(0.0, 1.0, by=0.1)
    checkEquals(fx(v),
                list( false = pt(v, 5), true = pt(v, 5, log=TRUE ) ), # NB: need log=TRUE here
                msg = "stats.pt" )
}

