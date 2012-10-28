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
    inline double qnorm(double x, double mu, double sigma, int lt, int lg)      { return ::Rf_qnorm5(x, mu, sigma, lt, lg); }
    inline double rnorm(double mu, double sigma)                                { return ::Rf_rnorm(mu, sigma); }
    inline void	pnorm_both(double x, double *cum, double *ccum, int lt, int lg) { return ::Rf_pnorm_both(x, cum, ccum, lt, lg); }

}

#endif
