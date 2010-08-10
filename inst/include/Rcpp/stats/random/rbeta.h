// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// rbeta.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__random_rbeta_h
#define Rcpp__stats__random_rbeta_h

namespace Rcpp {
namespace stats {

template <bool seed>
class BetaGenerator : public ::Rcpp::Generator<seed,double> {
public:
	BetaGenerator( double a_, double b_ ) : a(a_), b(b_) {}
	inline double operator()() const { 
		return ::rbeta( a, b );
	}
private:
	double a, b ;
} ;

} // stats

template <bool seed>
NumericVector rbeta__impl( int n, double a, double b ){
	return NumericVector( n, stats::BetaGenerator<seed>( a, b ) ) ;
}
inline NumericVector rbeta( int n, double a, double b ){
	return rbeta__impl<true>( n, a, b );
}
inline NumericVector rbeta_( int n, double a, double b ){
	return rbeta__impl<false>( n, a, b );
}

} // Rcpp

#endif
