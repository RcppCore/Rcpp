// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// rchisq.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__random_rchisq_h
#define Rcpp__stats__random_rchisq_h

namespace Rcpp {
namespace stats {

template <bool seed>
class ChisqGenerator : public Rcpp::Generator<seed,double> {
public:
	
	ChisqGenerator( double df_ ) : df_2(df_ / 2.0) {}
	
	inline double operator()() const {
		return ::rgamma( df_2, 2.0 ) ; 
	}
	
private:
	double df_2 ;
} ;

template <bool seed>
Rcpp::NumericVector rchisq__impl( int n, double df ){
	if (!R_FINITE(df) || df < 0.0) return Rcpp::NumericVector(n, R_NaN) ;
	return Rcpp::NumericVector( n, ChisqGenerator<seed>( df ) ) ;
}
inline Rcpp::NumericVector rchisq( int n, double df ){
	return rchisq__impl<true>( n, df );
}
inline Rcpp::NumericVector rchisq_( int n, double df ){
	return rchisq__impl<false>( n, df );
}

}
}

#endif
