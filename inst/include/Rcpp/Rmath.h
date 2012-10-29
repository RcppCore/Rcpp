// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Rmath.h: Rcpp R/C++ interface class library -- Wrappers for R's Rmath API
//
// Copyright (C) 2010 - 2012 Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or           
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef Rcpp_Rmath_h
#define Rcpp_Rmath_h

namespace R {

    // see R's Rmath.h as well as Writing R Extension

    /* Random Number Generators */
    inline double norm_rand(void) 	{ return ::norm_rand(); }
    inline double unif_rand(void)	{ return ::unif_rand(); }
    inline double exp_rand(void)	{ return ::exp_rand(); } 

    /* Normal Distribution */
    inline double dnorm(double x, double mu, double sigma, int lg)              { return ::Rf_dnorm4(x, mu, sigma, lg); }
    inline double pnorm(double x, double mu, double sigma, int lt, int lg)      { return ::Rf_pnorm5(x, mu, sigma, lt, lg); }
    inline double qnorm(double p, double mu, double sigma, int lt, int lg)      { return ::Rf_qnorm5(p, mu, sigma, lt, lg); }
    inline double rnorm(double mu, double sigma)                                { return ::Rf_rnorm(mu, sigma); }
    inline void	pnorm_both(double x, double *cum, double *ccum, int lt, int lg) { return ::Rf_pnorm_both(x, cum, ccum, lt, lg); }

    /* Uniform Distribution */
    inline double dunif(double x, double a, double b, int lg)		{ return ::Rf_dunif(x, a, b, lg); }
    inline double punif(double x, double a, double b, int lt, int lg)   { return ::Rf_punif(x, a, b, lt, lg); }
    inline double qunif(double p, double a, double b, int lt, int lg)   { return ::Rf_qunif(p, a, b, lt, lg); }
    inline double runif(double a, double b)                             { return ::Rf_runif(a, b); }

    /* Gamma Distribution */
    inline double dgamma(double x, double shp, double scl, int lg)	   { return ::Rf_dgamma(x, shp, scl, lg); }
    inline double pgamma(double x, double alp, double scl, int lt, int lg) { return ::Rf_pgamma(x, alp, scl, lt, lg); }
    inline double qgamma(double p, double alp, double scl, int lt, int lg) { return ::Rf_pgamma(p, alp, scl, lt, lg); }
    inline double rgamma(double a, double scl)                             { return ::Rf_rgamma(a, scl); }

    inline double log1pmx(double x)                  { return ::Rf_log1pmx(x); }
    inline double log1pexp(double x)                 { return ::log1pexp(x); }  // <-- ../nmath/plogis.c
    inline double lgamma1p(double a)                 { return ::Rf_lgamma1p(a); }
    inline double logspace_add(double lx, double ly) { return ::Rf_logspace_add(lx, ly); }
    inline double logspace_sub(double lx, double ly) { return ::Rf_logspace_sub(lx, ly); }

    /* Beta Distribution */
    inline double dbeta(double x, double a, double b, int lg)         { return ::Rf_dbeta(x, a, b, lg); }
    inline double pbeta(double x, double p, double q, int lt, int lg) { return ::Rf_pbeta(x, p, q, lt, lg); }
    inline double qbeta(double a, double p, double q, int lt, int lg) { return ::Rf_qbeta(a, p, q, lt, lg); }
    inline double rbeta(double a, double b)                           { return ::Rf_rbeta(a, b); }

    /* Lognormal Distribution */
    inline double dlnorm(double x, double ml, double sl, int lg)	 { return ::Rf_dlnorm(x, ml, sl, lg); }
    inline double plnorm(double x, double ml, double sl, int lt, int lg) { return ::Rf_plnorm(x, ml, sl, lt, lg); }
    inline double qlnorm(double p, double ml, double sl, int lt, int lg) { return ::Rf_qlnorm(p, ml, sl, lt, lg); }
    inline double rlnorm(double ml, double sl)                           { return ::Rf_rlnorm(ml, sl); }

    /* Chi-squared Distribution */
    inline double dchisq(double x, double df, int lg)          { return ::Rf_dchisq(x, df, lg); }
    inline double pchisq(double x, double df, int lt, int lg)  { return ::Rf_pchisq(x, df, lt, lg); }
    inline double qchisq(double p, double df, int lt, int lg)  { return ::Rf_qchisq(p, df, lt, lg); }	
    inline double rchisq(double df)                            { return ::Rf_rchisq(df); }

    /* Non-central Chi-squared Distribution */
    inline double dnchisq(double x, double df, double ncp, int lg)          { return ::Rf_dnchisq(x, df, ncp, lg); }
    inline double pnchisq(double x, double df, double ncp, int lt, int lg)  { return ::Rf_pnchisq(x, df, ncp, lt, lg); }
    inline double qnchisq(double p, double df, double ncp, int lt, int lg)  { return ::Rf_qnchisq(p, df, ncp, lt, lg); }	
    inline double rnchisq(double df, double lb)                             { return ::Rf_rnchisq(df, lb); }

    /* F Distibution */
    inline double df(double x, double df1, double df2, int lg)		{ return ::Rf_df(x, df1, df2, lg); }
    inline double pf(double x, double df1, double df2, int lt, int lg)	{ return ::Rf_pf(x, df1, df2, lt, lg); }
    inline double qf(double p, double df1, double df2, int lt, int lg)	{ return ::Rf_qf(p, df1, df2, lt, lg); }
    inline double rf(double df1, double df2)				{ return ::Rf_rf(df1, df2); }

    /* Student t Distibution */
    inline double dt(double x, double n, int lg)			{ return ::Rf_dt(x, n, lg); }
    inline double pt(double x, double n, int lt, int lg)		{ return ::Rf_pt(x, n, lt, lg); }
    inline double qt(double p, double n, int lt, int lg)		{ return ::Rf_qt(p, n, lt, lg); }
    inline double rt(double n)						{ return ::Rf_rt(n); }

    /* Binomial Distribution */
    inline double dbinom(double x, double n, double p, int lg)	  	{ return ::Rf_dbinom(x, n, p, lg); }
    inline double pbinom(double x, double n, double p, int lt, int lg)  { return ::Rf_pbinom(x, n, p, lt, lg); }
    inline double qbinom(double p, double n, double m, int lt, int lg)  { return ::Rf_qbinom(p, n, m, lt, lg); }
    inline double rbinom(double n, double p)				{ return ::Rf_rbinom(n, p); }

}

#endif
