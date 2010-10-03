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

		class NormGenerator : public Generator<false,double> {
		public:
	
			NormGenerator( double mean_ = 0.0 , double sd_ = 1.0 ) : 
				mean(mean_), sd(sd_) {}
	
			inline double operator()() const {
				return mean + sd * ::norm_rand() ;
			}
	
		private:
			double mean ;
			double sd ;
		} ;


		class NormGenerator__sd1 : public Generator<false,double> {
		public:
	
			NormGenerator__sd1( double mean_ = 0.0 ) : mean(mean_) {}
	
			inline double operator()() const {
				return mean + ::norm_rand() ;
			}
	
		private:
			double mean ;
		} ;


		class NormGenerator__mean0 : public Generator<false,double> {
		public:
	
			NormGenerator__mean0( double sd_ = 1.0 ) : sd(sd_) {}
	
			inline double operator()() const {
				return sd * ::norm_rand() ;
			}
	
		private:
			double sd ;
		} ;


	} // stats

	// Please make sure you to read Section 6.3 of "Writing R Extensions"
	// about the need to call GetRNGstate() and PutRNGstate() when using 
	// the random number generators provided by R.
	inline NumericVector rnorm( int n, double mean, double sd){
		if (ISNAN(mean) || !R_FINITE(sd) || sd < 0.){
			// TODO: R also throws a warning in that case, should we ?
			return NumericVector( n, R_NaN ) ;
		}  else if (sd == 0. || !R_FINITE(mean)){
			return NumericVector( n, mean ) ;
		} else {
			bool sd1 = sd == 1.0 ; 
			bool mean0 = mean == 0.0 ;
			if( sd1 && mean0 ){
				return NumericVector( n, norm_rand ) ;
			} else if( sd1 ){
				return NumericVector( n, stats::NormGenerator__sd1( mean ) );
			} else if( mean0 ){
				return NumericVector( n, stats::NormGenerator__mean0( sd ) );
			} else {
				// general case
				return NumericVector( n, stats::NormGenerator( mean, sd ) );
			}
		}
	}

	// Please make sure you to read Section 6.3 of "Writing R Extensions"
	// about the need to call GetRNGstate() and PutRNGstate() when using 
	// the random number generators provided by R.
	inline NumericVector rnorm( int n, double mean /*, double sd [=1.0] */ ){
		if (ISNAN(mean) ){
			// TODO: R also throws a warning in that case, should we ?
			return NumericVector( n, R_NaN ) ;
		}  else if ( !R_FINITE(mean)){
			return NumericVector( n, mean ) ;
		} else {
			bool mean0 = mean == 0.0 ;
			if( mean0 ){
				return NumericVector( n, norm_rand ) ;
			} else {
				return NumericVector( n, stats::NormGenerator__sd1( mean ) );
			}
		}
	}

	// Please make sure you to read Section 6.3 of "Writing R Extensions"
	// about the need to call GetRNGstate() and PutRNGstate() when using 
	// the random number generators provided by R.
	inline NumericVector rnorm( int n /*, double mean [=0.0], double sd [=1.0] */ ){
		return NumericVector( n, norm_rand ) ;
	}

} // Rcpp

#endif
