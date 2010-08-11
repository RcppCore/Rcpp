// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// rweibull.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2010 Douglas Bates, Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__stats__random_rweibull_h
#define Rcpp__stats__random_rweibull_h

namespace Rcpp {
namespace stats {

class WeibullGenerator : public ::Rcpp::Generator<false,double> {
public:
	
	WeibullGenerator( double shape_, double scale_ ) : 
		shape_inv( 1/shape_), scale(scale_) {}
	
	inline double operator()() const {
		return scale * ::R_pow(-::log(unif_rand()), shape_inv );
	}
	
private:
	double shape_inv ;
	double scale ;
} ;
} // stats

inline NumericVector rweibull( int n, double shape, double scale ){
	if (!R_FINITE(shape) || !R_FINITE(scale) || shape <= 0. || scale <= 0.) {
		if(scale == 0.) return NumericVector(n, 0.);
		/* else */
		return NumericVector(n, R_NaN);
    }
	return NumericVector( n, stats::WeibullGenerator( shape, scale ) ) ;
}

} // Rcpp

#endif
