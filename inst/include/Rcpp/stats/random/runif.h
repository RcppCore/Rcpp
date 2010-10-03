// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// runif.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__random_runif_h
#define Rcpp__stats__random_runif_h

namespace Rcpp {
	namespace stats {

		class UnifGenerator : public ::Rcpp::Generator<false,double> {
		public:
	
			UnifGenerator( double min_ = 0.0, double max_ = 1.0) : 
				min(min_), max(max_), diff(max_ - min_) {}
	
			inline double operator()() const {
				double u;
				do {u = unif_rand();} while (u <= 0 || u >= 1);
				return min + diff * u;
			}
	
		private:
			double min; 
			double max ;
			double diff ;
		} ;

	} // stats

	// Please make sure you to read Section 6.3 of "Writing R Extensions"
	// about the need to call GetRNGstate() and PutRNGstate() when using 
	// the random number generators provided by R.
	inline NumericVector runif( int n, double min, double max ){
		if (!R_FINITE(min) || !R_FINITE(max) || max < min) return NumericVector( n, R_NaN ) ;
		if( min == max ) return NumericVector( n, min ) ;
		return NumericVector( n, stats::UnifGenerator( min, max ) ) ;
	}

	// Please make sure you to read Section 6.3 of "Writing R Extensions"
	// about the need to call GetRNGstate() and PutRNGstate() when using 
	// the random number generators provided by R.
	inline NumericVector runif( int n, double min /*, double max = 1.0 */ ){
		if (!R_FINITE(min) || 1.0 < min) return NumericVector( n, R_NaN ) ;
		if( min == 1.0 ) return NumericVector( n, 1.0 ) ;
		return NumericVector( n, stats::UnifGenerator( min, 1.0 ) ) ;
	}

	// Please make sure you to read Section 6.3 of "Writing R Extensions"
	// about the need to call GetRNGstate() and PutRNGstate() when using 
	// the random number generators provided by R.
	inline NumericVector runif( int n /*, double min = 0.0, double max = 1.0 */ ){
		return NumericVector( n, unif_rand ) ;
	}

} // Rcpp

#endif
