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


         ,"runit_dcauchy" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dcauchy(x, a, b, 0), R::dcauchy(x, a, b, 1));')
         ,"runit_pcauchy" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::pcauchy(x, a, b, 1, 0), R::pcauchy(log(x), a, b, 1, 1),
                                          R::pcauchy(x, a, b, 0, 0), R::pcauchy(log(x), a, b, 0, 1));')
         ,"runit_qcauchy" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qcauchy(x, a, b, 1, 0), R::qcauchy(log(x), a, b, 1, 1),
                                          R::qcauchy(x, a, b, 0, 0), R::qcauchy(log(x), a, b, 0, 1));')


         ,"runit_dexp" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::dexp(x, a, 0), R::dexp(x, a, 1));')
         ,"runit_pexp" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::pexp(x, a, 1, 0), R::pexp(log(x), a, 1, 1),
                                          R::pexp(x, a, 0, 0), R::pexp(log(x), a, 0, 1));')
         ,"runit_qexp" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::qexp(x, a, 1, 0), R::qexp(log(x), a, 1, 1),
                                          R::qexp(x, a, 0, 0), R::qexp(log(x), a, 0, 1));')


         ,"runit_dgeom" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::dgeom(x, a, 0), R::dgeom(x, a, 1));')
         ,"runit_pgeom" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::pgeom(x, a, 1, 0), R::pgeom(log(x), a, 1, 1),
                                          R::pgeom(x, a, 0, 0), R::pgeom(log(x), a, 0, 1));')
         ,"runit_qgeom" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::qgeom(x, a, 1, 0), R::qgeom(log(x), a, 1, 1),
                                          R::qgeom(x, a, 0, 0), R::qgeom(log(x), a, 0, 1));')


         ,"runit_dhyper" = list(signature(x_ = "double", a_ = "double", b_ = "double", c_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_), c = as<double>(c_);
	     return NumericVector::create(R::dhyper(x, a, b, c, 0), R::dhyper(x, a, b, c, 1));')
         ,"runit_phyper" = list(signature(x_ = "double", a_ = "double", b_ = "double", c_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_), c = as<double>(c_);
	     return NumericVector::create(R::phyper(x, a, b, c, 1, 0), R::phyper(log(x), a, b, c, 1, 1),
                                          R::phyper(x, a, b, c, 0, 0), R::phyper(log(x), a, b, c, 0, 1));')
         ,"runit_qhyper" = list(signature(x_ = "double", a_ = "double", b_ = "double", c_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_), c = as<double>(c_);
	     return NumericVector::create(R::qhyper(x, a, b, c, 1, 0), R::qhyper(log(x), a, b, c, 1, 1),
                                          R::qhyper(x, a, b, c, 0, 0), R::qhyper(log(x), a, b, c, 0, 1));')


         ,"runit_dnbinom" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dnbinom(x, a, b, 0), R::dnbinom(x, a, b, 1));')
         ,"runit_pnbinom" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::pnbinom(x, a, b, 1, 0), R::pnbinom(log(x), a, b, 1, 1),
                                          R::pnbinom(x, a, b, 0, 0), R::pnbinom(log(x), a, b, 0, 1));')
         ,"runit_qnbinom" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qnbinom(x, a, b, 1, 0), R::qnbinom(log(x), a, b, 1, 1),
                                          R::qnbinom(x, a, b, 0, 0), R::qnbinom(log(x), a, b, 0, 1));')


         ,"runit_dpois" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::dpois(x, a, 0), R::dpois(x, a, 1));')
         ,"runit_ppois" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::ppois(x, a, 1, 0), R::ppois(log(x), a, 1, 1),
                                          R::ppois(x, a, 0, 0), R::ppois(log(x), a, 0, 1));')
         ,"runit_qpois" = list(signature(x_ = "double", a_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_);
	     return NumericVector::create(R::qpois(x, a, 1, 0), R::qpois(log(x), a, 1, 1),
                                          R::qpois(x, a, 0, 0), R::qpois(log(x), a, 0, 1));')


         ,"runit_dweibull" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dweibull(x, a, b, 0), R::dweibull(x, a, b, 1));')
         ,"runit_pweibull" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::pweibull(x, a, b, 1, 0), R::pweibull(log(x), a, b, 1, 1),
                                          R::pweibull(x, a, b, 0, 0), R::pweibull(log(x), a, b, 0, 1));')
         ,"runit_qweibull" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qweibull(x, a, b, 1, 0), R::qweibull(log(x), a, b, 1, 1),
                                          R::qweibull(x, a, b, 0, 0), R::qweibull(log(x), a, b, 0, 1));')


         ,"runit_dlogis" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dlogis(x, a, b, 0), R::dlogis(x, a, b, 1));')
         ,"runit_plogis" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::plogis(x, a, b, 1, 0), R::plogis(log(x), a, b, 1, 1),
                                          R::plogis(x, a, b, 0, 0), R::plogis(log(x), a, b, 0, 1));')
         ,"runit_qlogis" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qlogis(x, a, b, 1, 0), R::qlogis(log(x), a, b, 1, 1),
                                          R::qlogis(x, a, b, 0, 0), R::qlogis(log(x), a, b, 0, 1));')


         ,"runit_dnbeta" = list(signature(x_ = "double", a_ = "double", b_ = "double", c_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_), c = as<double>(c_);
	     return NumericVector::create(R::dnbeta(x, a, b, c, 0), R::dnbeta(x, a, b, c, 1));')
         ,"runit_pnbeta" = list(signature(x_ = "double", a_ = "double", b_ = "double", c_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_), c = as<double>(c_);
	     return NumericVector::create(R::pnbeta(x, a, b, c, 1, 0), R::pnbeta(log(x), a, b, c, 1, 1),
                                          R::pnbeta(x, a, b, c, 0, 0), R::pnbeta(log(x), a, b, c, 0, 1));')
         ,"runit_qnbeta" = list(signature(x_ = "double", a_ = "double", b_ = "double", c_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_), c = as<double>(c_);
	     return NumericVector::create(R::qnbeta(x, a, b, c, 1, 0), R::qnbeta(log(x), a, b, c, 1, 1),
                                          R::qnbeta(x, a, b, c, 0, 0), R::qnbeta(log(x), a, b, c, 0, 1));')


         ,"runit_dnf" = list(signature(x_ = "double", a_ = "double", b_ = "double", c_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_), c = as<double>(c_);
	     return NumericVector::create(R::dnf(x, a, b, c, 0), R::dnf(x, a, b, c, 1));')
         ,"runit_pnf" = list(signature(x_ = "double", a_ = "double", b_ = "double", c_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_), c = as<double>(c_);
	     return NumericVector::create(R::pnf(x, a, b, c, 1, 0), R::pnf(log(x), a, b, c, 1, 1),
                                          R::pnf(x, a, b, c, 0, 0), R::pnf(log(x), a, b, c, 0, 1));')
         ,"runit_qnf" = list(signature(x_ = "double", a_ = "double", b_ = "double", c_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_), c = as<double>(c_);
	     return NumericVector::create(R::qnf(x, a, b, c, 1, 0), R::qnf(log(x), a, b, c, 1, 1),
                                          R::qnf(x, a, b, c, 0, 0), R::qnf(log(x), a, b, c, 0, 1));')


         ,"runit_dnt" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dnt(x, a, b, 0), R::dnt(x, a, b, 1));')
         ,"runit_pnt" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::pnt(x, a, b, 1, 0), R::pnt(log(x), a, b, 1, 1),
                                          R::pnt(x, a, b, 0, 0), R::pnt(log(x), a, b, 0, 1));')
         ,"runit_qnt" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qnt(x, a, b, 1, 0), R::qnt(log(x), a, b, 1, 1),
                                          R::qnt(x, a, b, 0, 0), R::qnt(log(x), a, b, 0, 1));')

         ,"runit_dwilcox" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::dwilcox(x, a, b, 0), R::dwilcox(x, a, b, 1));')
         ,"runit_pwilcox" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_) ;
	     return NumericVector::create(R::pwilcox(x, a, b, 1, 0), R::pwilcox(log(x), a, b, 1, 1),
                                          R::pwilcox(x, a, b, 0, 0), R::pwilcox(log(x), a, b, 0, 1));')
         ,"runit_qwilcox" = list(signature(x_ = "double", a_ = "double", b_ = "double"), '
             double x = as<double>(x_), a = as<double>(a_), b = as<double>(b_);
	     return NumericVector::create(R::qwilcox(x, a, b, 1, 0), R::qwilcox(log(x), a, b, 1, 1),
                                          R::qwilcox(x, a, b, 0, 0), R::qwilcox(log(x), a, b, 0, 1));')

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
                msg = " rmath.dnorm")

    f <- .rcpp.rmath$runit_pnorm
    checkEquals(f(x, a, b),
                c(pnorm(x, a, b, lower=TRUE, log=FALSE),  pnorm(log(x), a, b, lower=TRUE, log=TRUE),
                  pnorm(x, a, b, lower=FALSE, log=FALSE), pnorm(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pnorm")

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
                msg = " rmath.dunif")

    f <- .rcpp.rmath$runit_punif
    checkEquals(f(x, a, b),
                c(punif(x, a, b, lower=TRUE, log=FALSE),  punif(log(x), a, b, lower=TRUE, log=TRUE),
                  punif(x, a, b, lower=FALSE, log=FALSE), punif(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.punif")

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
                msg = " rmath.dgamma")

    f <- .rcpp.rmath$runit_pgamma
    checkEquals(f(x, a, b),
                c(pgamma(x, a, b, lower=TRUE, log=FALSE),  pgamma(log(x), a, b, lower=TRUE, log=TRUE),
                  pgamma(x, a, b, lower=FALSE, log=FALSE), pgamma(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pgamma")

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
                msg = " rmath.dbeta")

    f <- .rcpp.rmath$runit_pbeta
    checkEquals(f(x, a, b),
                c(pbeta(x, a, b, lower=TRUE, log=FALSE),  pbeta(log(x), a, b, lower=TRUE, log=TRUE),
                  pbeta(x, a, b, lower=FALSE, log=FALSE), pbeta(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pbeta")

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
                msg = " rmath.dlnorm")

    f <- .rcpp.rmath$runit_plnorm
    checkEquals(f(x, a, b),
                c(plnorm(x, a, b, lower=TRUE, log=FALSE),  plnorm(log(x), a, b, lower=TRUE, log=TRUE),
                  plnorm(x, a, b, lower=FALSE, log=FALSE), plnorm(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.plnorm")

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
                msg = " rmath.dchisq")

    f <- .rcpp.rmath$runit_pchisq
    checkEquals(f(x, a),
                c(pchisq(x, a, lower=TRUE, log=FALSE),  pchisq(log(x), a, lower=TRUE, log=TRUE),
                  pchisq(x, a, lower=FALSE, log=FALSE), pchisq(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.pchisq")

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
                msg = " rmath.dnchisq")

    f <- .rcpp.rmath$runit_pnchisq
    checkEquals(f(x, a, b),
                c(pchisq(x, a, b, lower=TRUE, log=FALSE),  pchisq(log(x), a, b, lower=TRUE, log=TRUE),
                  pchisq(x, a, b, lower=FALSE, log=FALSE), pchisq(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pnchisq")

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
                msg = " rmath.df")

    f <- .rcpp.rmath$runit_pf
    checkEquals(f(x, a, b),
                c(pf(x, a, b, lower=TRUE, log=FALSE),  pf(log(x), a, b, lower=TRUE, log=TRUE),
                  pf(x, a, b, lower=FALSE, log=FALSE), pf(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pf")

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
                msg = " rmath.dt")

    f <- .rcpp.rmath$runit_pt
    checkEquals(f(x, a),
                c(pt(x, a, lower=TRUE, log=FALSE),  pt(log(x), a, lower=TRUE, log=TRUE),
                  pt(x, a, lower=FALSE, log=FALSE), pt(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.pt")

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
                msg = " rmath.dbinom")

    f <- .rcpp.rmath$runit_pbinom
    checkEquals(f(x, a, b),
                c(pbinom(x, a, b, lower=TRUE, log=FALSE),  pbinom(log(x), a, b, lower=TRUE, log=TRUE),
                  pbinom(x, a, b, lower=FALSE, log=FALSE), pbinom(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pbinom")

    x <- x/a
    f <- .rcpp.rmath$runit_qbinom
    checkEquals(f(x, a, b),
                c(qbinom(x, a, b, lower=TRUE, log=FALSE),  qbinom(log(x), a, b, lower=TRUE,  log=TRUE),
                  qbinom(x, a, b, lower=FALSE, log=FALSE), qbinom(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qbinom")
}


test.rmath.cauchy <- function() {
    x <- 0.25
    a <- 0.8
    b <- 2.5
    f <- .rcpp.rmath$runit_dcauchy
    checkEquals(f(x, a, b),
                c(dcauchy(x, a, b, log=FALSE), dcauchy(x, a, b, log=TRUE)),
                msg = " rmath.dcauchy")

    f <- .rcpp.rmath$runit_pcauchy
    checkEquals(f(x, a, b),
                c(pcauchy(x, a, b, lower=TRUE, log=FALSE),  pcauchy(log(x), a, b, lower=TRUE, log=TRUE),
                  pcauchy(x, a, b, lower=FALSE, log=FALSE), pcauchy(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pcauchy")

    f <- .rcpp.rmath$runit_qcauchy
    checkEquals(f(x, a, b),
                c(qcauchy(x, a, b, lower=TRUE, log=FALSE),  qcauchy(log(x), a, b, lower=TRUE,  log=TRUE),
                  qcauchy(x, a, b, lower=FALSE, log=FALSE), qcauchy(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qcauchy")
}


test.rmath.exp <- function() {
    x <- 0.25
    a <- 1.0
    f <- .rcpp.rmath$runit_dexp
    checkEquals(f(x, a),
                c(dexp(x, a, log=FALSE), dexp(x, a, log=TRUE)),
                msg = " rmath.dexp")

    f <- .rcpp.rmath$runit_pexp
    checkEquals(f(x, a),
                c(pexp(x, a, lower=TRUE, log=FALSE),  pexp(log(x), a, lower=TRUE, log=TRUE),
                  pexp(x, a, lower=FALSE, log=FALSE), pexp(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.pexp")

    f <- .rcpp.rmath$runit_qexp
    checkEquals(f(x, a),
                c(qexp(x, a, lower=TRUE, log=FALSE),  qexp(log(x), a, lower=TRUE,  log=TRUE),
                  qexp(x, a, lower=FALSE, log=FALSE), qexp(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.qexp")
}


test.rmath.geom <- function() {
    x <- 1
    a <- 0.75
    f <- .rcpp.rmath$runit_dgeom

    checkEquals(f(x, a),
                c(dgeom(x, a, log=FALSE), dgeom(x, a, log=TRUE)),
                msg = " rmath.dgeom")

    f <- .rcpp.rmath$runit_pgeom
    checkEquals(f(x, a),
                c(pgeom(x, a, lower=TRUE, log=FALSE),  pgeom(log(x), a, lower=TRUE, log=TRUE),
                  pgeom(x, a, lower=FALSE, log=FALSE), pgeom(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.pgeom")

    f <- .rcpp.rmath$runit_qgeom
    checkEquals(f(x, a),
                c(qgeom(x, a, lower=TRUE, log=FALSE),  qgeom(log(x), a, lower=TRUE,  log=TRUE),
                  qgeom(x, a, lower=FALSE, log=FALSE), qgeom(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.qgeom")
}

test.rmath.hyper <- function() {
    x <- 5
    a <- 10
    b <- 7
    c <- 8
    f <- .rcpp.rmath$runit_dhyper
    checkEquals(f(x, a, b, c),
                c(dhyper(x, a, b, c, log=FALSE), dhyper(x, a, b, c, log=TRUE)),
                msg = " rmath.dhyper")

    f <- .rcpp.rmath$runit_phyper
    checkEquals(f(x, a, b, c),
                c(phyper(x, a, b, c, lower=TRUE, log=FALSE),  phyper(log(x), a, b, c, lower=TRUE, log=TRUE),
                  phyper(x, a, b, c, lower=FALSE, log=FALSE), phyper(log(x), a, b, c, lower=FALSE, log=TRUE)),
                msg = " rmath.phyper")

    x <- x/a
    f <- .rcpp.rmath$runit_qhyper
    checkEquals(f(x, a, b, c),
                c(qhyper(x, a, b, c, lower=TRUE, log=FALSE),  qhyper(log(x), a, b, c, lower=TRUE,  log=TRUE),
                  qhyper(x, a, b, c, lower=FALSE, log=FALSE), qhyper(log(x), a, b, c, lower=FALSE, log=TRUE)),
                msg = " rmath.qhyper")
}


test.rmath.nbinom <- function() {
    x <- 2
    a <- 8
    b <- 0.25
    f <- .rcpp.rmath$runit_dnbinom
    checkEquals(f(x, a, b),
                c(dnbinom(x, a, b, log=FALSE), dnbinom(x, a, b, log=TRUE)),
                msg = " rmath.dnbinom")

    f <- .rcpp.rmath$runit_pnbinom
    checkEquals(f(x, a, b),
                c(pnbinom(x, a, b, lower=TRUE, log=FALSE),  pnbinom(log(x), a, b, lower=TRUE, log=TRUE),
                  pnbinom(x, a, b, lower=FALSE, log=FALSE), pnbinom(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pnbinom")

    x <- x/a
    f <- .rcpp.rmath$runit_qnbinom
    checkEquals(f(x, a, b),
                c(qnbinom(x, a, b, lower=TRUE, log=FALSE),  qnbinom(log(x), a, b, lower=TRUE,  log=TRUE),
                  qnbinom(x, a, b, lower=FALSE, log=FALSE), qnbinom(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qnbinom")
}


test.rmath.pois <- function() {
    x <- 2
    a <- 1.0
    f <- .rcpp.rmath$runit_dpois
    checkEquals(f(x, a),
                c(dpois(x, a, log=FALSE), dpois(x, a, log=TRUE)),
                msg = " rmath.dpois")

    f <- .rcpp.rmath$runit_ppois
    checkEquals(f(x, a),
                c(ppois(x, a, lower=TRUE, log=FALSE),  ppois(log(x), a, lower=TRUE, log=TRUE),
                  ppois(x, a, lower=FALSE, log=FALSE), ppois(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.ppois")

    x <- 1/x
    f <- .rcpp.rmath$runit_qpois
    checkEquals(f(x, a),
                c(qpois(x, a, lower=TRUE, log=FALSE),  qpois(log(x), a, lower=TRUE,  log=TRUE),
                  qpois(x, a, lower=FALSE, log=FALSE), qpois(log(x), a, lower=FALSE, log=TRUE)),
                msg = " rmath.qpois")
}


test.rmath.weibull <- function() {
    x <- 2
    a <- 8
    b <- 0.25
    f <- .rcpp.rmath$runit_dweibull
    checkEquals(f(x, a, b),
                c(dweibull(x, a, b, log=FALSE), dweibull(x, a, b, log=TRUE)),
                msg = " rmath.dweibull")

    f <- .rcpp.rmath$runit_pweibull
    checkEquals(f(x, a, b),
                c(pweibull(x, a, b, lower=TRUE, log=FALSE),  pweibull(log(x), a, b, lower=TRUE, log=TRUE),
                  pweibull(x, a, b, lower=FALSE, log=FALSE), pweibull(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pweibull")

    x <- x/a
    f <- .rcpp.rmath$runit_qweibull
    checkEquals(f(x, a, b),
                c(qweibull(x, a, b, lower=TRUE, log=FALSE),  qweibull(log(x), a, b, lower=TRUE,  log=TRUE),
                  qweibull(x, a, b, lower=FALSE, log=FALSE), qweibull(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qweibull")
}


test.rmath.logis <- function() {
    x <- 2
    a <- 8
    b <- 0.25
    f <- .rcpp.rmath$runit_dlogis
    checkEquals(f(x, a, b),
                c(dlogis(x, a, b, log=FALSE), dlogis(x, a, b, log=TRUE)),
                msg = " rmath.dlogis")

    f <- .rcpp.rmath$runit_plogis
    checkEquals(f(x, a, b),
                c(plogis(x, a, b, lower=TRUE, log=FALSE),  plogis(log(x), a, b, lower=TRUE, log=TRUE),
                  plogis(x, a, b, lower=FALSE, log=FALSE), plogis(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.plogis")

    x <- x/a
    f <- .rcpp.rmath$runit_qlogis
    checkEquals(f(x, a, b),
                c(qlogis(x, a, b, lower=TRUE, log=FALSE),  qlogis(log(x), a, b, lower=TRUE,  log=TRUE),
                  qlogis(x, a, b, lower=FALSE, log=FALSE), qlogis(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qlogis")
}


test.rmath.nbeta <- function() {
    x <- 5
    a <- 10
    b <- 7
    c <- 8
    f <- .rcpp.rmath$runit_dnbeta
    checkEquals(f(x, a, b, c),
                c(dbeta(x, a, b, c, log=FALSE), dbeta(x, a, b, c, log=TRUE)),
                msg = " rmath.dnbeta")

    f <- .rcpp.rmath$runit_pnbeta
    checkEquals(f(x, a, b, c),
                c(pbeta(x, a, b, c, lower=TRUE, log=FALSE),  pbeta(log(x), a, b, c, lower=TRUE, log=TRUE),
                  pbeta(x, a, b, c, lower=FALSE, log=FALSE), pbeta(log(x), a, b, c, lower=FALSE, log=TRUE)),
                msg = " rmath.pnbeta")

    x <- x/a
    f <- .rcpp.rmath$runit_qnbeta
    checkEquals(f(x, a, b, c),
                c(qbeta(x, a, b, c, lower=TRUE, log=FALSE),  qbeta(log(x), a, b, c, lower=TRUE,  log=TRUE),
                  qbeta(x, a, b, c, lower=FALSE, log=FALSE), qbeta(log(x), a, b, c, lower=FALSE, log=TRUE)),
                msg = " rmath.qnbeta")
}


test.rmath.nf <- function() {
    x <- 5
    a <- 10
    b <- 7
    c <- 8
    f <- .rcpp.rmath$runit_dnf
    checkEquals(f(x, a, b, c),
                c(df(x, a, b, c, log=FALSE), df(x, a, b, c, log=TRUE)),
                msg = " rmath.dnf")

    f <- .rcpp.rmath$runit_pnf
    checkEquals(f(x, a, b, c),
                c(pf(x, a, b, c, lower=TRUE, log=FALSE),  pf(log(x), a, b, c, lower=TRUE, log=TRUE),
                  pf(x, a, b, c, lower=FALSE, log=FALSE), pf(log(x), a, b, c, lower=FALSE, log=TRUE)),
                msg = " rmath.pnf")

    x <- x/a
    f <- .rcpp.rmath$runit_qnf
    checkEquals(f(x, a, b, c),
                c(qf(x, a, b, c, lower=TRUE, log=FALSE),  qf(log(x), a, b, c, lower=TRUE,  log=TRUE),
                  qf(x, a, b, c, lower=FALSE, log=FALSE), qf(log(x), a, b, c, lower=FALSE, log=TRUE)),
                msg = " rmath.qnf")
}

test.rmath.nt <- function() {
    x <- 5
    a <- 10
    b <- 7
    f <- .rcpp.rmath$runit_dnt
    checkEquals(f(x, a, b),
                c(dt(x, a, b, log=FALSE), dt(x, a, b, log=TRUE)),
                msg = " rmath.dnt")

    f <- .rcpp.rmath$runit_pnt
    checkEquals(f(x, a, b),
                c(pt(x, a, b, lower=TRUE, log=FALSE),  pt(log(x), a, b, lower=TRUE, log=TRUE),
                  pt(x, a, b, lower=FALSE, log=FALSE), pt(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pnt")

    x <- x/a
    f <- .rcpp.rmath$runit_qnt
    checkEquals(f(x, a, b),
                c(qt(x, a, b, lower=TRUE, log=FALSE),  qt(log(x), a, b, lower=TRUE,  log=TRUE),
                  qt(x, a, b, lower=FALSE, log=FALSE), qt(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qnt")
}

test.rmath.wilcox <- function() {
    x <- 2
    a <- 4
    b <- 6
    f <- .rcpp.rmath$runit_dwilcox
    checkEquals(f(x, a, b),
                c(dwilcox(x, a, b, log=FALSE), dwilcox(x, a, b, log=TRUE)),
                msg = " rmath.dwilcox")

    f <- .rcpp.rmath$runit_pwilcox
    checkEquals(f(x, a, b),
                c(pwilcox(x, a, b, lower=TRUE, log=FALSE),  pwilcox(log(x), a, b, lower=TRUE, log=TRUE),
                  pwilcox(x, a, b, lower=FALSE, log=FALSE), pwilcox(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.pwilcox")

    x <- x/a
    f <- .rcpp.rmath$runit_qwilcox
    checkEquals(f(x, a, b),
                c(qwilcox(x, a, b, lower=TRUE, log=FALSE),  qwilcox(log(x), a, b, lower=TRUE,  log=TRUE),
                  qwilcox(x, a, b, lower=FALSE, log=FALSE), qwilcox(log(x), a, b, lower=FALSE, log=TRUE)),
                msg = " rmath.qwilcox")
}



}



