#!/usr/bin/r -t
# -*- mode: R; tab-width: 4 -*-
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
				  "runit_dbeta" = list(
				  signature(x = "numeric",
							a = "numeric", b = "numeric"),
				  '
				  double aa = as<double>(a), bb = as<double>(b) ;
				  NumericVector xx(x) ;
				  return List::create(_["NoLog"] = stats::dbeta( xx, aa, bb),
									  _["Log"]	 = stats::dbeta( xx, aa, bb, true ));
				  ')

				  ,
				  "runit_dbinom" = list(
				  signature( x = "integer" ),
				  '
				  IntegerVector xx(x) ;
				  return List::create(_["false"] = stats::dbinom( xx, 10, .5),
									  _["true"]	 = stats::dbinom( xx, 10, .5, true ));
				  ')

				  ,
				  "runit_dunif" = list(
				  signature( x = "integer" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["NoLog"] = stats::dunif( xx, 0, 1),
									  _["Log"]	= stats::dunif( xx, 0, 1, true ));
				  ')

				  ,
				  "runit_dgamma" = list( signature( x = "integer" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["NoLog"] = stats::dgamma( xx, 1.0, 1.0),
									  _["Log"]	 = stats::dgamma( xx, 1.0, 1.0, true ));
				  ')

				  ,
				  "runit_dpois" = list(
				  signature( x = "integer" ),
				  '
				  IntegerVector xx(x) ;
				  return List::create(_["false"] = stats::dpois( xx, .5 ),
									  _["true"]	 = stats::dpois( xx, .5 , true));
				  ')

				  ,
				  "runit_dnorm" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["false"] = stats::dnorm( xx, 0.0, 1.0 ),
									  _["true"]	 = stats::dnorm( xx, 0.0, 1.0, true ));
				  ')

				  ,
				  "runit_dt" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["false"] = stats::dt( xx, 5),
									  _["true"]	 = stats::dt( xx, 5, true ));
				  ')

				  ,
				  "runit_pbeta" = list(
				  signature(x = "numeric",
							a = "numeric", b = "numeric"),
				  '
				  double aa = as<double>(a), bb = as<double>(b) ;
				  NumericVector xx(x) ;
				  return List::create(_["lowerNoLog"] = stats::pbeta( xx, aa, bb),
									  _["lowerLog"]	  = stats::pbeta( xx, aa, bb, true, true),
									  _["upperNoLog"] = stats::pbeta( xx, aa, bb, false),
									  _["upperLog"]	  = stats::pbeta( xx, aa, bb, false, true));
				  ')

				  ,
				  "runit_pbinom" = list(
				  signature( x = "numeric", size = "integer", prob = "numeric" ),
				  '
				  int n = as<int>(size);
				  double p = as<double>(prob);
				  NumericVector xx(x) ;
				  return List::create(_["lowerNoLog"] = stats::pbinom(xx, n, p ),
									  _["lowerLog"]	  = stats::pbinom(xx, n, p, true, true ),
									  _["upperNoLog"] = stats::pbinom(xx, n, p, false ),
									  _["upperLog"]	  = stats::pbinom(xx, n, p, false, true ));
				  ')

				  ,
				  ## Using fixed values of n and p
				  "runit_pbinom_fixed" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["lowerNoLog"] = stats::pbinom(xx, 20, 0.5 ),
									  _["lowerLog"]	  = stats::pbinom(xx, 20, 0.5, true, true ),
									  _["upperNoLog"] = stats::pbinom(xx, 20, 0.5, false ),
									  _["upperLog"]	  = stats::pbinom(xx, 20, 0.5, false, true ));
				  ')

				  ,
				  "runit_punif" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["lowerNoLog"] = stats::punif( xx, 0.0, 1.0 ),
									  _["lowerLog"]	  = stats::punif( xx, 0.0, 1.0, true, true ),
									  _["upperNoLog"] = stats::punif( xx, 0.0, 1.0, false ),
									  _["upperLog"]	  = stats::punif( xx, 0.0, 1.0, false, true ));
				  ')

				  ,
				  "runit_pgamma" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["lowerNoLog"] = stats::pgamma( xx, 2.0, 1.0 ),
									  _["lowerLog"]	  = stats::pgamma( xx, 2.0, 1.0, true, true ),
									  _["upperNoLog"] = stats::pgamma( xx, 2.0, 1.0, false ),
									  _["upperLog"]	  = stats::pgamma( xx, 2.0, 1.0, false, true ));
				  ')

				  ,
				  "runit_pnorm" = list(signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["lowerNoLog"] = stats::pnorm( xx, 0.0, 1.0 ),
									  _["lowerLog"]	  = stats::pnorm( xx, 0.0, 1.0, true, true ),
									  _["upperNoLog"] = stats::pnorm( xx, 0.0, 1.0, false ),
									  _["upperLog"]	  = stats::pnorm( xx, 0.0, 1.0, false, true ));
				  ')

				  ,
				  "runit_ppois" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["lowerNoLog"] = stats::ppois( xx, 0.5 ),
									  _["lowerLog"]	  = stats::ppois( xx, 0.5, true, true ),
									  _["upperNoLog"] = stats::ppois( xx, 0.5, false ),
									  _["upperLog"]	  = stats::ppois( xx, 0.5, false, true ));
				  ')

				  ,
				  "runit_pt" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["false"] = stats::pt( xx, 5, true),
									  _["true"]	 = stats::pt( xx, 5, true, true	 ));
				  '
				  )

				  ,
				  "runit_qbinom_prob" = list(
				  signature( x = "numeric", size = "integer", prob = "numeric" ),
				  '
				  int n = as<int>(size);
				  double p = as<double>(prob);
				  NumericVector xx(x) ;
				  return List::create(_["lower"] = stats::qbinom( xx, n, p ),
									  _["upper"] = stats::qbinom( xx, n, p, false));
				  ')

				  ,
				  ## Using fixed values of n and p
				  "runit_qbinom_prob_fixed" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["lower"] = stats::qbinom( xx, 20, 0.5 ),
									  _["upper"] = stats::qbinom( xx, 20, 0.5, false));
				  '
				  )

				  ,
				  "runit_qunif_prob" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["lower"] = stats::qunif( xx, 0.0, 1.0 ),
									  _["upper"] = stats::qunif( xx, 0.0, 1.0, false));
				  '
				  )

				  ,
				  "runit_qnorm_prob" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["lower"] = stats::qnorm( xx, 0.0, 1.0 ),
									  _["upper"] = stats::qnorm( xx, 0.0, 1.0, false));
				  ')

				  ## need a separate test for log prob because different allowable range of x
				  ,
				  "runit_qnorm_log" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["lower"] = stats::qnorm( xx, 0.0, 1.0, true, true),
									  _["upper"] = stats::qnorm( xx, 0.0, 1.0, false, true));
				  ')

				  ,
				  "runit_qpois_prob" = list(
				  signature( x = "numeric" ),
				  '
				  NumericVector xx(x) ;
				  return List::create(_["lower"] = stats::qpois( xx, 0.5 ),
									  _["upper"] = stats::qpois( xx, 0.5, false));
				  ')


                  ,
                  "runit_qt" = list(
                  signature( x = "numeric", df = "integer", lower = "logical", log = "logical" ),
                  '
				  NumericVector xx(x);
                  int d = as<int>(df);
                  bool lt = as<bool>(lower);
                  bool lg = as<bool>(log);
			      return wrap(stats::qt( xx, d, lt, lg));
				  ')

                  ) ## end of list of test function sources

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

test.stats.dgamma <- function( ) {
    fx <- .rcpp.stats$runit_dgamma
    v <- 1:4
    checkEquals(fx(v),
                list( NoLog = dgamma(v, 1.0, 1.0), Log = dgamma(v, 1.0, 1.0, log = TRUE ) ),
                msg = "stats.dgamma" )
}

test.stats.pgamma <- function( ) {
    fx <- .rcpp.stats$runit_pgamma
    v <- (1:9)/10
    checkEquals(fx(v),
                list(lowerNoLog = pgamma(v, shape = 2.0),
                     lowerLog   = pgamma(v, shape = 2.0, log=TRUE ),
                     upperNoLog = pgamma(v, shape = 2.0, lower=FALSE),
                     upperLog   = pgamma(v, shape = 2.0, lower=FALSE, log=TRUE)
                     ),
                msg = "stats.pgamma" )
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

test.stats.punif <- function( ) {
    fx <- .rcpp.stats$runit_punif
    v <- qunif(seq(0.0, 1.0, by=0.1))
    checkEquals(fx(v),
                list(lowerNoLog = punif(v),
                     lowerLog   = punif(v, log=TRUE ),
                     upperNoLog = punif(v, lower=FALSE),
                     upperLog   = punif(v, lower=FALSE, log=TRUE)
                     ),
                msg = "stats.punif" )
    # TODO: also borrow from R's d-p-q-r-tests.R
}

test.stats.qunif <- function( ) {
    fx <- .rcpp.stats$runit_qunif_prob
    checkEquals(fx(c(0, 1, 1.1, -.1)),
                list(lower = c(0, 1, NaN, NaN),
                     upper = c(1, 0, NaN, NaN)
                     ),
                msg = "stats.qunif" )
    # TODO: also borrow from R's d-p-q-r-tests.R
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

test.stats.pbinom <- function( ) {
    fx <- .rcpp.stats$runit_pbinom
    n <- 20
    p <- 0.5
    vv <- 0:n
    checkEquals(fx(vv, n, p),
                list(lowerNoLog = pbinom(vv, n, p),
                     lowerLog   = pbinom(vv, n, p, log=TRUE),
                     upperNoLog = pbinom(vv, n, p, lower=FALSE),
                     upperLog   = pbinom(vv, n, p, lower=FALSE, log=TRUE)
                     ),
                msg = " stats.pbinom")
}

test.stats.qbinom <- function( ) {
    fx <- .rcpp.stats$runit_qbinom_prob
    n <- 20
    p <- 0.5
    vv <- seq(0, 1, by = 0.1)
    checkEquals(fx(vv, n, p),
                list(lower = qbinom(vv, n, p),
                     upper = qbinom(vv, n, p, lower=FALSE)
                     ),
                msg = " stats.qbinom")
}

test.stats.pbinom.fixed <- function( ) {
    fx <- .rcpp.stats$runit_pbinom_fixed
    vv <- 0:20
    checkEquals(fx(vv),
                list(lowerNoLog = pbinom(vv, 20, 0.5),
                     lowerLog   = pbinom(vv, 20, 0.5, log=TRUE),
                     upperNoLog = pbinom(vv, 20, 0.5, lower=FALSE),
                     upperLog   = pbinom(vv, 20, 0.5, lower=FALSE, log=TRUE)
                     ),
                msg = " stats.pbinom.fixed")
}

test.stats.qbinom.fixed <- function( ) {
    fx <- .rcpp.stats$runit_qbinom_prob_fixed
    vv <- seq(0, 1, by = 0.1)
    checkEquals(fx(vv),
                list(lower = qbinom(vv, 20, 0.5),
                     upper = qbinom(vv, 20, 0.5, lower=FALSE)
                     ),
                msg = " stats.qbinom.fixed")
}

test.stats.ppois <- function( ) {
    fx <- .rcpp.stats$runit_ppois
    vv <- 0:20
    checkEquals(fx(vv),
                list(lowerNoLog = ppois(vv, 0.5),
                     lowerLog   = ppois(vv, 0.5,              log=TRUE),
                     upperNoLog = ppois(vv, 0.5, lower=FALSE),
                     upperLog   = ppois(vv, 0.5, lower=FALSE, log=TRUE)
                     ),
                msg = " stats.ppois")
}

test.stats.qpois.prob <- function( ) {
    fx <- .rcpp.stats$runit_qpois_prob
    vv <- seq(0, 1, by = 0.1)
    checkEquals(fx(vv),
                list(lower = qpois(vv, 0.5),
                     upper = qpois(vv, 0.5, lower=FALSE)
                     ),
                msg = " stats.qpois.prob")
}

test.stats.dbeta <- function() {
    fx <- .rcpp.stats$runit_dbeta
    vv <- seq(0, 1, by = 0.1)
    a <- 0.5; b <- 2.5
    checkEquals(fx(vv, a, b),
                list(NoLog = dbeta(vv, a, b),
                     Log   = dbeta(vv, a, b, log=TRUE)
                     ),
                msg = " stats.qbeta")
}


test.stats.pbeta <- function( ) {
    fx <- .rcpp.stats$runit_pbeta
    a <- 0.5; b <- 2.5
    v <- qbeta(seq(0.0, 1.0, by=0.1), a, b)
    checkEquals(fx(v, a, b),
                list(lowerNoLog = pbeta(v, a, b),
                     lowerLog   = pbeta(v, a, b,              log=TRUE),
                     upperNoLog = pbeta(v, a, b, lower=FALSE),
                     upperLog   = pbeta(v, a, b, lower=FALSE, log=TRUE)
                     ),
                msg = " stats.pbeta" )
    ## Borrowed from R's d-p-q-r-tests.R
    x <- c(.01, .10, .25, .40, .55, .71, .98)
    pbval <- c(-0.04605755624088, -0.3182809860569, -0.7503593555585,
               -1.241555830932, -1.851527837938, -2.76044482378, -8.149862739881)
    checkEqualsNumeric(fx(x, 0.8, 2)$upperLog, pbval, msg = " stats.pbeta")
    checkEqualsNumeric(fx(1-x, 2, 0.8)$lowerLog, pbval, msg = " stats.pbeta")
}


test.stats.dunif <- function() {
    fx <- .rcpp.stats$runit_dunif
    vv <- seq(0, 1, by = 0.1)
    checkEquals(fx(vv),
                list(NoLog = dunif(vv),
                     Log   = dunif(vv, log=TRUE)
                     ),
                msg = " stats.dunif")
}

test.stats.qt <- function( ) {
	fx <- .rcpp.stats$runit_qt
    v <- seq(0.05, 0.95, by=0.05)
    checkEquals(fx(v, df=5, lower=FALSE, log=FALSE),
                qt(v, df=5, lower=FALSE, log=FALSE), msg="stats.qt.f.f")
    checkEquals(fx(v, df=5, lower=TRUE,  log=FALSE),
                qt(v, df=5, lower=TRUE,  log=FALSE), msg="stats.qt.t.f")
    checkEquals(fx(-v, df=5, lower=FALSE, log=TRUE),
                qt(-v, df=5, lower=FALSE, log=TRUE), msg="stats.qt.f.t")
    checkEquals(fx(-v, df=5, lower=TRUE,  log=TRUE),
                qt(-v, df=5, lower=TRUE,  log=TRUE), msg="stats.qt.t.t")
}

# TODO: test.stats.qgamma
# TODO: test.stats.(dpq)chisq

