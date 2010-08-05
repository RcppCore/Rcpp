// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// norm.h: Rcpp R/C++ interface class library -- normal distribution
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__stats__norm_h
#define Rcpp__stats__norm_h

namespace Rcpp {

namespace stats {

namespace impl {

	template <bool NA, typename T>
	class DNorm : public Rcpp::VectorBase< REALSXP, NA, DNorm<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DNorm( const VEC_TYPE& vec_, double mu_, double sigma_, bool log_ = false ) : 
			vec(vec_), mu(mu_), sigma(sigma_), log(log_) {}
		
		inline double operator[]( int i) const {
			int x = vec[i] ;
			return Rcpp::traits::is_na<REALSXP>( x ) ? NA_REAL : ::dnorm( x, mu, sigma, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double mu, sigma;
		int log;
	
};

template <typename T>
class DNorm<false,T> : public Rcpp::VectorBase< REALSXP, false, DNorm<false,T> >{
public:
	typedef typename Rcpp::VectorBase<REALSXP,false,T> VEC_TYPE;
	
	DNorm( const VEC_TYPE& vec_, double mu_, double sigma_, bool log_ = false ) : 
		vec(vec_), mu(mu_), sigma(sigma_), log(log_) {}
	
	inline double operator[]( int i) const {
		return ::dnorm( vec[i], mu, sigma, log );
	}
	
	inline int size() const { return vec.size(); }
	
private:
	const VEC_TYPE& vec;
	double mu, sigma;
	int log;
	
} ;


} // impl

template <bool NA, typename T>
inline impl::DNorm<NA,T> dnorm( const Rcpp::VectorBase<REALSXP,NA,T>& x, double mu, double sigma, bool log = false ) {
	return impl::DNorm<NA,T>( x, mu, sigma, log ); 
}
	
}
}

#endif
