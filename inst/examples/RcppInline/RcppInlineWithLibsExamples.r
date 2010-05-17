#!/usr/bin/r -t
#
# Copyright (C) 2009 - 2010	Dirk Eddelbuettel and Romain Francois
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

suppressMessages(library(Rcpp))
suppressMessages(library(inline))

firstExample <- function() {
    ## a really simple C program calling three functions from the GSL
    gslrng <- '
    gsl_rng *r;
    gsl_rng_env_setup();
    double v;

    r = gsl_rng_alloc (gsl_rng_default);

    printf("generator type: %s\\n", gsl_rng_name (r));
    printf("seed = %lu\\n", gsl_rng_default_seed);
    v = gsl_rng_get (r);
    printf("first value = %.0f\\n", v);

    gsl_rng_free(r);
    return R_NilValue;
    '

    ## turn into a function that R can call
    ## compileargs redundant on Debian/Ubuntu as gsl headers are found anyway
    funx <- cfunction(signature(), gslrng,
                      includes="#include <gsl/gsl_rng.h>",
                      Rcpp=FALSE,
                      cppargs="-I/usr/include",
                      libargs="-lgsl -lgslcblas")

    cat("Calling first example\n")
    funx()
    invisible(NULL)
}

secondExample <- function() {

    ## now use Rcpp to pass down a parameter for the seed
    gslrng <- '
    int seed = Rcpp::as<int>(par) ;

    gsl_rng *r;
    gsl_rng_env_setup();
    double v;

    r = gsl_rng_alloc (gsl_rng_default);

    gsl_rng_set (r, (unsigned long) seed);
    v = gsl_rng_get (r);

    #ifndef BeSilent
    printf("generator type: %s\\n", gsl_rng_name (r));
    printf("seed = %d\\n", seed);
    printf("first value = %.0f\\n", v);
    #endif

    gsl_rng_free(r);
    return Rcpp::wrap(v) ;
    '

    ## turn into a function that R can call
    ## compileargs redundant on Debian/Ubuntu as gsl headers are found anyway
    ## use additional define for compile to suppress output
    funx <- cfunction(signature(par="numeric"), gslrng,
                      includes="#include <gsl/gsl_rng.h>",
                      Rcpp=TRUE,
                      cppargs="-I/usr/include",
                      libargs="-lgsl -lgslcblas")
    cat("\n\nCalling second example without -DBeSilent set\n")
    print(funx(0))

    funx <- cfunction(signature(par="numeric"), gslrng,
                      includes="#include <gsl/gsl_rng.h>",
                      Rcpp=TRUE,
                      cppargs="-I/usr/include -DBeSilent",
                      libargs="-lgsl -lgslcblas")
    cat("\n\nCalling second example with -DBeSilent set\n")
    print(funx(0))

    invisible(NULL)
}

thirdExample <- function() {

    ## now use Rcpp to pass down a parameter for the seed, and a vector size
    gslrng <- '
    int seed = Rcpp::as<int>(s) ;
    int len = Rcpp::as<int>(n);

    gsl_rng *r;
    gsl_rng_env_setup();
    std::vector<double> v(len);

    r = gsl_rng_alloc (gsl_rng_default);

    gsl_rng_set (r, (unsigned long) seed);
    for (int i=0; i<len; i++) {
       v[i] = gsl_rng_get (r);
    }
    gsl_rng_free(r);

    return Rcpp::wrap(v) ;
    '

    ## turn into a function that R can call
    ## compileargs redundant on Debian/Ubuntu as gsl headers are found anyway
    ## use additional define for compile to suppress output
    funx <- cfunction(signature(s="numeric", n="numeric"),
                      gslrng,
                      includes="#include <gsl/gsl_rng.h>",
                      Rcpp=TRUE,
                      cppargs="-I/usr/include",
                      libargs="-lgsl -lgslcblas")
    cat("\n\nCalling third example with seed and length\n")
    print(funx(0, 5))

    invisible(NULL)
}

fourthExample <- function() {

    ## now use Rcpp to pass down a parameter for the seed, and a vector size
    gslrng <- '
    int seed = Rcpp::as<int>(s);
    int len = Rcpp::as<int>(n);

    gsl_rng *r;
    gsl_rng_env_setup();
    std::vector<double> v(len);

    r = gsl_rng_alloc (gsl_rng_default);

    gsl_rng_set (r, (unsigned long) seed);
    for (int i=0; i<len; i++) {
       v[i] = gsl_rng_get (r);
    }
    gsl_rng_free(r);

    return wrap(v);
    '

    ## turn into a function that R can call
    ## compileargs redundant on Debian/Ubuntu as gsl headers are found anyway
    ## use additional define for compile to suppress output
    funx <- cfunction(signature(s="numeric", n="numeric"),
                      gslrng,
                      includes=c("#include <gsl/gsl_rng.h>",
                                 "using namespace Rcpp;",
                                 "using namespace std;"),
                      Rcpp=TRUE,
                      cppargs="-I/usr/include",
                      libargs="-lgsl -lgslcblas")
    cat("\n\nCalling fourth example with seed, length and namespaces\n")
    print(funx(0, 5))

    invisible(NULL)
}

firstExample()
secondExample()
thirdExample()
fourthExample()
