// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// rnorm.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__random_norm_h
#define Rcpp__stats__random_norm_h

namespace Rcpp {
namespace stats {

template <bool seed>
class NormGenerator : public Rcpp::Generator<seed,double> {
public:
	
	NormGenerator( double mean = 0.0 , double sd = 1.0 ) : 
		mean(mean), sd(sd) {}
	
	inline double operator()() const {
		return mean + sd * ::norm_rand() ;
	}
	
private:
	double mean ;
	double sd ;
} ;

template <bool seed>
Rcpp::NumericVector rnorm__impl( int n, double mean, double sd ){
	if (ISNAN(mean) || !R_FINITE(sd) || sd < 0.){
		// TODO: R also throws a warning in that case, should we ?
		return Rcpp::NumericVector( n, R_NaN ) ;
	}  else if (sd == 0. || !R_FINITE(mean)){
		return Rcpp::NumericVector( n, mean ) ;
	} else {
		return Rcpp::NumericVector( n, NormGenerator<seed>( mean, sd ) ); 
	}
}
inline Rcpp::NumericVector rnorm( int n, double mean = 0.0, double sd = 1.0 ){
	return rnorm__impl<true>( n, mean, sd );
}
inline Rcpp::NumericVector rnorm_( int n, double mean = 0.0, double sd = 1.0 ){
	return rnorm__impl<false>( n, mean, sd );
}

}
}

#endif
