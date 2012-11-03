#!/usr/bin/r -t
# -*- mode: R; ess-indent-level: 4; tab-width: 4; indent-tabs-mode: nil; -*
#
# Copyright (C) 2012  Dirk Eddelbuettel and Romain Francois
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

.runThisTest <- Sys.getenv("RunAllRcppTests") == "yes"

if (.runThisTest) {

definitions <- function() {
    list("runit_dnorm" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dnorm(x, a, b, 0), R::dnorm(x, a, b, 1));')
         ,"runit_pnorm" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::pnorm(x, a, b, 1, 0), R::pnorm(log(x), a, b, 1, 1),
                                          R::pnorm(x, a, b, 0, 0), R::pnorm(log(x), a, b, 0, 1));')
         ,"runit_qnorm" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qnorm(x, a, b, 1, 0), R::qnorm(log(x), a, b, 1, 1),
                                          R::qnorm(x, a, b, 0, 0), R::qnorm(log(x), a, b, 0, 1));')


         ,"runit_dunif" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dunif(x, a, b, 0), R::dunif(x, a, b, 1));')
         ,"runit_punif" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::punif(x, a, b, 1, 0), R::punif(log(x), a, b, 1, 1),
                                          R::punif(x, a, b, 0, 0), R::punif(log(x), a, b, 0, 1));')
         ,"runit_qunif" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qunif(x, a, b, 1, 0), R::qunif(log(x), a, b, 1, 1),
                                          R::qunif(x, a, b, 0, 0), R::qunif(log(x), a, b, 0, 1));')


         ,"runit_dgamma" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dgamma(x, a, b, 0), R::dgamma(x, a, b, 1));')
         ,"runit_pgamma" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::pgamma(x, a, b, 1, 0), R::pgamma(log(x), a, b, 1, 1),
                                          R::pgamma(x, a, b, 0, 0), R::pgamma(log(x), a, b, 0, 1));')
         ,"runit_qgamma" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qgamma(x, a, b, 1, 0), R::qgamma(log(x), a, b, 1, 1),
                                          R::qgamma(x, a, b, 0, 0), R::qgamma(log(x), a, b, 0, 1));')


         ,"runit_dbeta" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dbeta(x, a, b, 0), R::dbeta(x, a, b, 1));')
         ,"runit_pbeta" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::pbeta(x, a, b, 1, 0), R::pbeta(log(x), a, b, 1, 1),
                                          R::pbeta(x, a, b, 0, 0), R::pbeta(log(x), a, b, 0, 1));')
         ,"runit_qbeta" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qbeta(x, a, b, 1, 0), R::qbeta(log(x), a, b, 1, 1),
                                          R::qbeta(x, a, b, 0, 0), R::qbeta(log(x), a, b, 0, 1));')


         ,"runit_dlnorm" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dlnorm(x, a, b, 0), R::dlnorm(x, a, b, 1));')
         ,"runit_plnorm" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::plnorm(x, a, b, 1, 0), R::plnorm(log(x), a, b, 1, 1),
                                          R::plnorm(x, a, b, 0, 0), R::plnorm(log(x), a, b, 0, 1));')
         ,"runit_qlnorm" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qlnorm(x, a, b, 1, 0), R::qlnorm(log(x), a, b, 1, 1),
                                          R::qlnorm(x, a, b, 0, 0), R::qlnorm(log(x), a, b, 0, 1));')


         ,"runit_dchisq" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::dchisq(x, a, 0), R::dchisq(x, a, 1));')
         ,"runit_pchisq" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::pchisq(x, a, 1, 0), R::pchisq(log(x), a, 1, 1),
                                          R::pchisq(x, a, 0, 0), R::pchisq(log(x), a, 0, 1));')
         ,"runit_qchisq" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::qchisq(x, a, 1, 0), R::qchisq(log(x), a, 1, 1),
                                          R::qchisq(x, a, 0, 0), R::qchisq(log(x), a, 0, 1));')


         ,"runit_dnchisq" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dnchisq(x, a, b, 0), R::dnchisq(x, a, b, 1));')
         ,"runit_pnchisq" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::pnchisq(x, a, b, 1, 0), R::pnchisq(log(x), a, b, 1, 1),
                                          R::pnchisq(x, a, b, 0, 0), R::pnchisq(log(x), a, b, 0, 1));')
         ,"runit_qnchisq" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qnchisq(x, a, b, 1, 0), R::qnchisq(log(x), a, b, 1, 1),
                                          R::qnchisq(x, a, b, 0, 0), R::qnchisq(log(x), a, b, 0, 1));')


         ,"runit_df" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::df(x, a, b, 0), R::df(x, a, b, 1));')
         ,"runit_pf" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::pf(x, a, b, 1, 0), R::pf(log(x), a, b, 1, 1),
                                          R::pf(x, a, b, 0, 0), R::pf(log(x), a, b, 0, 1));')
         ,"runit_qf" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qf(x, a, b, 1, 0), R::qf(log(x), a, b, 1, 1),
                                          R::qf(x, a, b, 0, 0), R::qf(log(x), a, b, 0, 1));')


         ,"runit_dt" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::dt(x, a, 0), R::dt(x, a, 1));')
         ,"runit_pt" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::pt(x, a, 1, 0), R::pt(log(x), a, 1, 1),
                                          R::pt(x, a, 0, 0), R::pt(log(x), a, 0, 1));')
         ,"runit_qt" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::qt(x, a, 1, 0), R::qt(log(x), a, 1, 1),
                                          R::qt(x, a, 0, 0), R::qt(log(x), a, 0, 1));')

         ,"runit_dbinom" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dbinom(x, a, b, 0), R::dbinom(x, a, b, 1));')
         ,"runit_pbinom" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::pbinom(x, a, b, 1, 0), R::pbinom(log(x), a, b, 1, 1),
                                          R::pbinom(x, a, b, 0, 0), R::pbinom(log(x), a, b, 0, 1));')
         ,"runit_qbinom" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qbinom(x, a, b, 1, 0), R::qbinom(log(x), a, b, 1, 1),
                                          R::qbinom(x, a, b, 0, 0), R::qbinom(log(x), a, b, 0, 1));')

         )
}

.setUp <- function() {
    if (! exists(".rcpp.rmath", globalenv())) {
        fun <- Rcpp:::compile_unit_tests(definitions())
        assign(".rcpp.rmath", fun, globalenv())
    }
}

test.rmath.norm <- function() {
    x <- 0.25
    a <- 1.25
    b <- 2.50
    f <- .rcpp.rmath$runit_dnorm
    checkEquals(f(x, a, b),
                c(dnorm(x, a, b, log=FALSE), dnorm(x, a, b, log=TRUE)),
                msg = " rmath.norm")

    f <- .rcpp.rmath$runit_pnorm
    checkEquals(f(x, a, b),
                c(pnorm(x, a, b, lower=TRUE, log=FALSE),  pnorm(log(x), a, b, lower=TRUE, log=TRUE),
                  pnorm(x, a, b, lower=FALSE, log=FALSE), pnorm(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qnorm")

    f <- .rcpp.rmath$runit_qnorm
    checkEquals(f(x, a, b),
                c(qnorm(x, a, b, lower=TRUE, log=FALSE),  qnorm(log(x), a, b, lower=TRUE,  log=TRUE),
                  qnorm(x, a, b, lower=FALSE, log=FALSE), qnorm(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qnorm")
}

test.rmath.unif <- function() {
    x <- 0.25
    a <- 1.25
    b <- 2.50
    f <- .rcpp.rmath$runit_dunif
    checkEquals(f(x, a, b),
                c(dunif(x, a, b, log=FALSE), dunif(x, a, b, log=TRUE)),
                msg = " rmath.unif")

    f <- .rcpp.rmath$runit_punif
    checkEquals(f(x, a, b),
                c(punif(x, a, b, lower=TRUE, log=FALSE),  punif(log(x), a, b, lower=TRUE, log=TRUE),
                  punif(x, a, b, lower=FALSE, log=FALSE), punif(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qunif")

    f <- .rcpp.rmath$runit_qunif
    checkEquals(f(x, a, b),
                c(qunif(x, a, b, lower=TRUE, log=FALSE),  qunif(log(x), a, b, lower=TRUE,  log=TRUE),
                  qunif(x, a, b, lower=FALSE, log=FALSE), qunif(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qunif")
}

test.rmath.gamma <- function() {
    x <- 0.25
    a <- 1.0
    b <- 1.0
    f <- .rcpp.rmath$runit_dgamma
    checkEquals(f(x, a, b),
                c(dgamma(x, a, b, log=FALSE), dgamma(x, a, b, log=TRUE)),
                msg = " rmath.gamma")

    f <- .rcpp.rmath$runit_pgamma
    checkEquals(f(x, a, b),
                c(pgamma(x, a, b, lower=TRUE, log=FALSE),  pgamma(log(x), a, b, lower=TRUE, log=TRUE),
                  pgamma(x, a, b, lower=FALSE, log=FALSE), pgamma(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qgamma")

    f <- .rcpp.rmath$runit_qgamma
    checkEquals(f(x, a, b),
                c(qgamma(x, a, b, lower=TRUE, log=FALSE),  qgamma(log(x), a, b, lower=TRUE,  log=TRUE),
                  qgamma(x, a, b, lower=FALSE, log=FALSE), qgamma(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qgamma")
}

test.rmath.beta <- function() {
    x <- 0.25
    a <- 0.8
    b <- 2.5
    f <- .rcpp.rmath$runit_dbeta
    checkEquals(f(x, a, b),
                c(dbeta(x, a, b, log=FALSE), dbeta(x, a, b, log=TRUE)),
                msg = " rmath.beta")

    f <- .rcpp.rmath$runit_pbeta
    checkEquals(f(x, a, b),
                c(pbeta(x, a, b, lower=TRUE, log=FALSE),  pbeta(log(x), a, b, lower=TRUE, log=TRUE),
                  pbeta(x, a, b, lower=FALSE, log=FALSE), pbeta(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qbeta")

    f <- .rcpp.rmath$runit_qbeta
    checkEquals(f(x, a, b),
                c(qbeta(x, a, b, lower=TRUE, log=FALSE),  qbeta(log(x), a, b, lower=TRUE,  log=TRUE),
                  qbeta(x, a, b, lower=FALSE, log=FALSE), qbeta(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qbeta")
}


test.rmath.lnorm <- function() {
    x <- 0.25
    a <- 0.8
    b <- 2.5
    f <- .rcpp.rmath$runit_dlnorm
    checkEquals(f(x, a, b),
                c(dlnorm(x, a, b, log=FALSE), dlnorm(x, a, b, log=TRUE)),
                msg = " rmath.lnorm")

    f <- .rcpp.rmath$runit_plnorm
    checkEquals(f(x, a, b),
                c(plnorm(x, a, b, lower=TRUE, log=FALSE),  plnorm(log(x), a, b, lower=TRUE, log=TRUE),
                  plnorm(x, a, b, lower=FALSE, log=FALSE), plnorm(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qlnorm")

    f <- .rcpp.rmath$runit_qlnorm
    checkEquals(f(x, a, b),
                c(qlnorm(x, a, b, lower=TRUE, log=FALSE),  qlnorm(log(x), a, b, lower=TRUE,  log=TRUE),
                  qlnorm(x, a, b, lower=FALSE, log=FALSE), qlnorm(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qlnorm")
}


test.rmath.chisq <- function() {
    x <- 0.25
    a <- 0.8
    f <- .rcpp.rmath$runit_dchisq
    checkEquals(f(x, a),
                c(dchisq(x, a, log=FALSE), dchisq(x, a, log=TRUE)),
                msg = " rmath.chisq")

    f <- .rcpp.rmath$runit_pchisq
    checkEquals(f(x, a),
                c(pchisq(x, a, lower=TRUE, log=FALSE),  pchisq(log(x), a, lower=TRUE, log=TRUE),
                  pchisq(x, a, lower=FALSE, log=FALSE), pchisq(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.qchisq")

    f <- .rcpp.rmath$runit_qchisq
    checkEquals(f(x, a),
                c(qchisq(x, a, lower=TRUE, log=FALSE),  qchisq(log(x), a, lower=TRUE,  log=TRUE),
                  qchisq(x, a, lower=FALSE, log=FALSE), qchisq(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.qchisq")
}


test.rmath.nchisq <- function() {
    x <- 0.25
    a <- 0.8
    b <- 2.5
    f <- .rcpp.rmath$runit_dnchisq
    checkEquals(f(x, a, b),
                c(dchisq(x, a, b, log=FALSE), dchisq(x, a, b, log=TRUE)),
                msg = " rmath.nchisq")

    f <- .rcpp.rmath$runit_pnchisq
    checkEquals(f(x, a, b),
                c(pchisq(x, a, b, lower=TRUE, log=FALSE),  pchisq(log(x), a, b, lower=TRUE, log=TRUE),
                  pchisq(x, a, b, lower=FALSE, log=FALSE), pchisq(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qnchisq")

    f <- .rcpp.rmath$runit_qnchisq
    checkEquals(f(x, a, b),
                c(qchisq(x, a, b, lower=TRUE, log=FALSE),  qchisq(log(x), a, b, lower=TRUE,  log=TRUE),
                  qchisq(x, a, b, lower=FALSE, log=FALSE), qchisq(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qnchisq")
}


test.rmath.f <- function() {
    x <- 0.25
    a <- 0.8
    b <- 2.5
    f <- .rcpp.rmath$runit_df
    checkEquals(f(x, a, b),
                c(df(x, a, b, log=FALSE), df(x, a, b, log=TRUE)),
                msg = " rmath.f")

    f <- .rcpp.rmath$runit_pf
    checkEquals(f(x, a, b),
                c(pf(x, a, b, lower=TRUE, log=FALSE),  pf(log(x), a, b, lower=TRUE, log=TRUE),
                  pf(x, a, b, lower=FALSE, log=FALSE), pf(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qf")

    f <- .rcpp.rmath$runit_qf
    checkEquals(f(x, a, b),
                c(qf(x, a, b, lower=TRUE, log=FALSE),  qf(log(x), a, b, lower=TRUE,  log=TRUE),
                  qf(x, a, b, lower=FALSE, log=FALSE), qf(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qf")
}


test.rmath.t <- function() {
    x <- 0.25
    a <- 0.8
    f <- .rcpp.rmath$runit_dt
    checkEquals(f(x, a),
                c(dt(x, a, log=FALSE), dt(x, a, log=TRUE)),
                msg = " rmath.t")

    f <- .rcpp.rmath$runit_pt
    checkEquals(f(x, a),
                c(pt(x, a, lower=TRUE, log=FALSE),  pt(log(x), a, lower=TRUE, log=TRUE),
                  pt(x, a, lower=FALSE, log=FALSE), pt(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.qt")

    f <- .rcpp.rmath$runit_qt
    checkEquals(f(x, a),
                c(qt(x, a, lower=TRUE, log=FALSE),  qt(log(x), a, lower=TRUE,  log=TRUE),
                  qt(x, a, lower=FALSE, log=FALSE), qt(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.qt")
}


test.rmath.binom <- function() {
    x <- 5
    a <- 10
    b <- 0.5
    f <- .rcpp.rmath$runit_dbinom
    checkEquals(f(x, a, b),
                c(dbinom(x, a, b, log=FALSE), dbinom(x, a, b, log=TRUE)),
                msg = " rmath.binom")

    f <- .rcpp.rmath$runit_pbinom
    checkEquals(f(x, a, b),
                c(pbinom(x, a, b, lower=TRUE, log=FALSE),  pbinom(log(x), a, b, lower=TRUE, log=TRUE),
                  pbinom(x, a, b, lower=FALSE, log=FALSE), pbinom(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qbinom")

    x <- x/a
    f <- .rcpp.rmath$runit_qbinom
    checkEquals(f(x, a, b),
                c(qbinom(x, a, b, lower=TRUE, log=FALSE),  qbinom(log(x), a, b, lower=TRUE,  log=TRUE),
                  qbinom(x, a, b, lower=FALSE, log=FALSE), qbinom(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qbinom")
}

}



