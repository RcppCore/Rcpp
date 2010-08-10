
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// nbinom.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__nbinom_h
#define Rcpp__stats__nbinom_h

namespace Rcpp {
namespace stats {
namespace impl {

	template <bool NA, typename T>
	class DNbinom : public Rcpp::VectorBase< REALSXP, NA, DNbinom<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DNbinom( const VEC_TYPE& vec_, int size_, double prob_ , bool log_ = false ) : 
			vec(vec_), siz(size_), prob(prob_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dnbinom( vec[i], siz, prob , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		int siz; double prob; 
		int log;
	
	};

	template <bool NA, typename T>
	class PNbinom : public Rcpp::VectorBase< REALSXP, NA, PNbinom<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PNbinom( const VEC_TYPE& vec_, int size_, double prob_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), siz(size_), prob(prob_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pnbinom( vec[i], siz, prob, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		int siz; double prob; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QNbinom : public Rcpp::VectorBase< REALSXP, NA, QNbinom<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QNbinom( const VEC_TYPE& vec_, int size_, double prob_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), siz(size_), prob(prob_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qnbinom( vec[i], siz, prob, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		int siz; double prob; 
		int lower, log;
	
	};
	
} // impl

template <bool NA, typename T>
inline impl::DNbinom<NA,T> dnbinom( const Rcpp::VectorBase<REALSXP,NA,T>& x, int size_, double prob_, bool log = false ) {
	return impl::DNbinom<NA,T>( x, size_, prob_, log ); 
}

template <bool NA, typename T>
inline impl::PNbinom<NA,T> pnbinom( const Rcpp::VectorBase<REALSXP,NA,T>& x, int size_, double prob_, bool lower = true, bool log = false ) {
	return impl::PNbinom<NA,T>( x, size_, prob_, lower, log ); 
}

template <bool NA, typename T>
inline impl::QNbinom<NA,T> qnbinom( const Rcpp::VectorBase<REALSXP,NA,T>& x, int size_, double prob_, bool lower = true, bool log = false ) {
	return impl::QNbinom<NA,T>( x, size_, prob_, lower, log ); 
}
	
}
}

#endif

