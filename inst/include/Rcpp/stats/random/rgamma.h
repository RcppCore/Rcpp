// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// rgamma.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__random_rgamma_h
#define Rcpp__stats__random_rgamma_h

namespace Rcpp {
    namespace stats {
        template <bool seed>
        class GammaGenerator : public Generator<seed,double>{
        public:
            GammaGenerator(double a_, double scale_) : 
                a(a_), scale(scale_) {}
            inline double operator()() const { return ::Rf_rgamma(a, scale ) ;}    
        private:
            double a, scale ;
        } ;
    }    // stats
    
    
	// Please make sure you to read Section 6.3 of "Writing R Extensions"
	// about the need to call GetRNGstate() and PutRNGstate() when using 
	// the random number generators provided by R.
	inline NumericVector rgamma( int n, double a, double scale ){
		if (!R_FINITE(a) || !R_FINITE(scale) || a < 0.0 || scale <= 0.0) {
			if(scale == 0.) return NumericVector( n, 0.) ;
			return NumericVector( n, R_NaN ) ;
		}
		if( a == 0. ) return NumericVector(n, 0. ) ;
		return NumericVector( n, stats::GammaGenerator<false>(a, scale) ) ;
	} 
	inline NumericVector rgamma( int n, double a /* scale = 1.0 */ ){
		if (!R_FINITE(a) || a < 0.0 ) {
			return NumericVector( n, R_NaN ) ;
		}
		if( a == 0. ) return NumericVector(n, 0. ) ;
		/* TODO: check if we can take advantage of the scale = 1 special case */
		return NumericVector( n, stats::GammaGenerator<false>(a, 1.0) ) ;
	} 
	

} // Rcpp

#endif
