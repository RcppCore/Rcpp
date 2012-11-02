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

}
