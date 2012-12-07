// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// random.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2010 - 2012 Douglas Bates, Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__stats__random_random_h
#define Rcpp__stats__random_random_h

namespace Rcpp{ 
    
NumericVector rbeta( int n, double a, double b ) ;
NumericVector rbinom( int n, double nin, double pp ) ;
NumericVector rcauchy( int n, double location, double scale ) ;
NumericVector rcauchy( int n, double location /* , double scale [=1.0] */ ) ;
NumericVector rcauchy( int n /*, double location [=0.0] , double scale [=1.0] */ ) ;
NumericVector rchisq( int n, double df ) ;
NumericVector rexp( int n, double rate ) ;
NumericVector rexp( int n /* , rate = 1 */ ) ;
NumericVector rf( int n, double n1, double n2 ) ;
NumericVector rgamma( int n, double a, double scale ) ;
NumericVector rgamma( int n, double a /* scale = 1.0 */ ) ;
NumericVector rgeom( int n, double p ) ;
NumericVector rhyper( int n, double nn1, double nn2, double kk ) ;
NumericVector rlnorm( int n, double meanlog, double sdlog ) ;
NumericVector rlnorm( int n, double meanlog /*, double sdlog = 1.0 */) ;
NumericVector rlnorm( int n /*, double meanlog [=0.], double sdlog = 1.0 */) ;
NumericVector rlogis( int n, double location, double scale ) ;
NumericVector rlogis( int n, double location /*, double scale =1.0 */ ) ;
NumericVector rlogis( int n /*, double location [=0.0], double scale =1.0 */ ) ;
NumericVector rnbinom( int n, double siz, double prob ) ;
NumericVector rnbinom_mu( int n, double siz, double mu ) ;
NumericVector rnchisq( int n, double df, double lambda ) ;
NumericVector rnchisq( int n, double df /*, double lambda = 0.0 */ ) ;
NumericVector rnorm( int n, double mean, double sd) ;
NumericVector rnorm( int n, double mean /*, double sd [=1.0] */ ) ;
NumericVector rnorm( int n /*, double mean [=0.0], double sd [=1.0] */ ) ;
NumericVector rpois( int n, double mu ) ;
NumericVector rsignrank( int n, double nn ) ;
NumericVector rt( int n, double df ) ;
NumericVector runif( int n, double min, double max ) ;
NumericVector runif( int n, double min /*, double max = 1.0 */ ) ;
NumericVector runif( int n /*, double min = 0.0, double max = 1.0 */ ) ;
NumericVector rweibull( int n, double shape, double scale ) ;
NumericVector rweibull( int n, double shape /* scale = 1 */ ) ;
NumericVector rwilcox( int n, double mm, double nn ) ;

namespace internal {
    void enterRNGScope();
    void exitRNGScope();
}

class RNGScope{
public:
	RNGScope(){ internal::enterRNGScope(); }
	~RNGScope(){ internal::exitRNGScope(); }	
} ;

template <typename T>
class Generator : public RNGScope {
public:
	typedef T r_generator ;
} ;

}
#endif
