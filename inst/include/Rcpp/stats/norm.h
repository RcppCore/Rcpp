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



	template <bool NA, typename T>
	class DNorm : public Rcpp::VectorBase< REALSXP, NA, DNorm<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DNorm( const VEC_TYPE& vec_, double mu_, double sigma_, bool log_ = false ) : 
			vec(vec_), mu(mu_), sigma(sigma_), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dnorm4( vec[i], mu, sigma, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double mu, sigma;
		int log;
	
	};

	template <bool NA, typename T>
	class PNorm : public Rcpp::VectorBase< REALSXP, NA, PNorm<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PNorm( const VEC_TYPE& vec_, double mu_, double sigma_,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), mu(mu_), sigma(sigma_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pnorm5( vec[i], mu, sigma, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double mu, sigma;
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QNorm : public Rcpp::VectorBase< REALSXP, NA, QNorm<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QNorm( const VEC_TYPE& vec_, double mu_, double sigma_,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), mu(mu_), sigma(sigma_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qnorm5( vec[i], mu, sigma, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double mu, sigma;
		int lower, log;
	
	};
	
} // stats

template <bool NA, typename T>
inline stats::DNorm<NA,T> dnorm( const Rcpp::VectorBase<REALSXP,NA,T>& x, double mu, double sigma, bool log = false ) {
	return stats::DNorm<NA,T>( x, mu, sigma, log ); 
}

template <bool NA, typename T>
inline stats::PNorm<NA,T> pnorm( const Rcpp::VectorBase<REALSXP,NA,T>& x, double mu, double sigma, bool lower = true, bool log = false ) {
	return stats::PNorm<NA,T>( x, mu, sigma, lower, log ); 
}

template <bool NA, typename T>
inline stats::QNorm<NA,T> qnorm( const Rcpp::VectorBase<REALSXP,NA,T>& x, double mu, double sigma, bool lower = true, bool log = false ) {
	return stats::QNorm<NA,T>( x, mu, sigma, lower, log ); 
}
	
}

#endif
