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
			)
			, "runit_dpois" = list(
				signature( x = "integer" ),
				'
					IntegerVector xx(x) ;
					return List::create(
						_["false"] = stats::dpois( xx, .5 ),
						_["true"]  = stats::dpois( xx, .5 , true )
						) ;
				'
			)
			, "runit_dnorm" = list(
				signature( x = "numeric" ),
				'
					NumericVector xx(x) ;
					return List::create(
						_["false"] = stats::dnorm( xx, 0.0, 1.0 ),
						_["true"]  = stats::dnorm( xx, 0.0, 1.0, true )
						) ;
				'
			)
			, "runit_dt" = list(
				signature( x = "numeric" ),
				'
					NumericVector xx(x) ;
					return List::create(
						_["false"] = stats::dt( xx, 5),
						_["true"]  = stats::dt( xx, 5, true )
						) ;
				'
			)
			, "runit_pt" = list(
				signature( x = "numeric" ),
				'
					NumericVector xx(x) ;
					return List::create(
						_["false"] = stats::pt( xx, 5, true),
						_["true"]  = stats::pt( xx, 5, true, true  )
						) ;
				'
			)
            , "runit_pnorm" = list(
				signature( x = "numeric" ),
				'
					NumericVector xx(x) ;
 					return List::create(
 						_["lowerNoLog"] = stats::pnorm( xx, 0.0, 1.0 ),
 						_["lowerLog"]  = stats::pnorm( xx, 0.0, 1.0, true, true ),
 						_["upperNoLog"] = stats::pnorm( xx, 0.0, 1.0, false ),
 						_["upperLog"]  = stats::pnorm( xx, 0.0, 1.0, false, true )
 						) ;
                 '
              )
              , "runit_qnorm_prob" = list(
				signature( x = "numeric" ),
				'
					NumericVector xx(x) ;
 					return List::create(
 						_["lower"] = stats::qnorm( xx, 0.0, 1.0 ),
 						_["upper"] = stats::qnorm( xx, 0.0, 1.0, false)
 						) ;
                 '
              )

              ## need a separate test for log prob because different allowable range of x
              , "runit_qnorm_log" = list(
				   signature( x = "numeric" ),
				   '
					NumericVector xx(x) ;
 					return List::create(
 						_["lower"] = stats::qnorm( xx, 0.0, 1.0, true, true),
 						_["upper"] = stats::qnorm( xx, 0.0, 1.0, false, true)
 						) ;
                   '
              )
              , "runit_qt" = list(
				signature( x = "numeric", p = "list" ),
				'
					NumericVector xx(x);
                    List pp(p);
                    int df  = as<int>(pp["df"]);
                    bool lt = as<bool>(pp["lower"]);
                    bool lg = as<bool>(pp["log"]);
					return wrap(stats::qt( xx, df, lt, lg));
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

test.stats.pnorm <- function( ) {
    fx <- .rcpp.stats$runit_pnorm
    v <- qnorm(seq(0.0, 1.0, by=0.1))
    checkEquals(fx(v),
                list(lowerNoLog = pnorm(v),
                     lowerLog   = pnorm(v, log=TRUE ),
                     upperNoLog = pnorm(v, lower=FALSE),
                     upperLog   = pnorm(v, lower=FALSE, log=TRUE)
                     ),
                msg = "stats.pnorm" )
    ## Borrowed from R's d-p-q-r-tests.R
    z <- c(-Inf,Inf,NA,NaN, rt(1000, df=2))
    z.ok <- z > -37.5 | !is.finite(z)
    pz <- fx(z)
    checkEqualsNumeric(pz$lowerNoLog, 1 - pz$upperNoLog, msg = "stats.pnorm")
    checkEqualsNumeric(pz$lowerNoLog, fx(-z)$upperNoLog, msg = "stats.pnorm")
    checkEqualsNumeric(log(pz$lowerNoLog[z.ok]), pz$lowerLog[z.ok], msg = "stats.pnorm")
    ## FIXME: Add tests that use non-default mu and sigma
}

test.stats.qnorm <- function( ) {
    fx <- .rcpp.stats$runit_qnorm_prob
    checkEquals(fx(c(0, 1, 1.1, -.1)),
                list(lower = c(-Inf, Inf, NaN, NaN),
                     upper = c(Inf, -Inf, NaN, NaN)
                     ),
                msg = "stats.qnorm" )
    ## Borrowed from R's d-p-q-r-tests.R and Wichura (1988)
    checkEqualsNumeric(fx(c( 0.25,  .001,	 1e-20))$lower,
                       c(-0.6744897501960817, -3.090232306167814, -9.262340089798408),
                       msg = "stats.qnorm",
                       tol = 1e-15)

    fx <- .rcpp.stats$runit_qnorm_log
    checkEquals(fx(c(-Inf, 0, 0.1)),
                list(lower = c(-Inf, Inf, NaN),
                     upper = c(Inf, -Inf, NaN)
                     ),
                msg = "stats.qnorm" )
    checkEqualsNumeric(fx(-1e5)$lower, -447.1974945)
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

test.stats.qt <- function( ) {
	fx <- .rcpp.stats$runit_qt
    v <- seq(0.05, 0.95, by=0.05)
    checkEquals(fx(v, list(df=5, lower=FALSE, log=FALSE)),
                qt(v, df=5, lower=FALSE, log=FALSE), msg="stats.qt.f.f")
    checkEquals(fx(v, list(df=5, lower=TRUE,  log=FALSE)),
                qt(v, df=5, lower=TRUE,  log=FALSE), msg="stats.qt.t.f")
    checkEquals(fx(-v, list(df=5, lower=FALSE,  log=TRUE)),
                qt(-v, df=5, lower=FALSE,  log=TRUE), msg="stats.qt.f.t")
    checkEquals(fx(-v, list(df=5, lower=TRUE,  log=TRUE)),
                qt(-v, df=5, lower=TRUE,  log=TRUE), msg="stats.qt.t.t")
}


