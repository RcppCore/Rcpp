
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// nbinom_mu.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__nbinom_mu_h
#define Rcpp__stats__nbinom_mu_h

namespace Rcpp {
namespace stats {
namespace impl {

	template <bool NA, typename T>
	class DNbinom_mu : public Rcpp::VectorBase< REALSXP, NA, DNbinom_mu<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DNbinom_mu( const VEC_TYPE& vec_, int size_, double mu_ , bool log_ = false ) : 
			vec(vec_), size(size_), mu(mu_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dnbinom_mu( vec[i], size, mu , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		int size; double mu; 
		int log;
	
	};

	template <bool NA, typename T>
	class PNbinom_mu : public Rcpp::VectorBase< REALSXP, NA, PNbinom_mu<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PNbinom_mu( const VEC_TYPE& vec_, int size_, double mu_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), size(size_), mu(mu_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pnbinom_mu( vec[i], size, mu, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		int size; double mu; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QNbinom_mu : public Rcpp::VectorBase< REALSXP, NA, QNbinom_mu<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QNbinom_mu( const VEC_TYPE& vec_, int size_, double mu_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), size(size_), mu(mu_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qnbinom_mu( vec[i], size, mu, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		int size; double mu; 
		int lower, log;
	
	};
	
} // impl

template <bool NA, typename T>
inline impl::DNbinom_mu<NA,T> dnbinom_mu( const Rcpp::VectorBase<REALSXP,NA,T>& x, int size_, double mu_, bool log = false ) {
	return impl::DNbinom_mu<NA,T>( x, size_, mu_, log ); 
}

template <bool NA, typename T>
inline impl::PNbinom_mu<NA,T> pnbinom_mu( const Rcpp::VectorBase<REALSXP,NA,T>& x, int size_, double mu_, bool lower = true, bool log = false ) {
	return impl::PNbinom_mu<NA,T>( x, size_, mu_, lower, log ); 
}

template <bool NA, typename T>
inline impl::QNbinom_mu<NA,T> qnbinom_mu( const Rcpp::VectorBase<REALSXP,NA,T>& x, int size_, double mu_, bool lower = true, bool log = false ) {
	return impl::QNbinom_mu<NA,T>( x, size_, mu_, lower, log ); 
}
	
}
}

#endif

