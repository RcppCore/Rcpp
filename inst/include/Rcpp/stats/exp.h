
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// exp.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__exp_h
#define Rcpp__stats__exp_h

namespace Rcpp {
namespace stats {
namespace impl {

	template <bool NA, typename T>
	class DExp : public Rcpp::VectorBase< REALSXP, NA, DExp<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DExp( const VEC_TYPE& vec_, double rate_ = 1.0 , bool log_ = false ) : 
			vec(vec_), rate(rate_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dexp( vec[i], rate , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double rate; 
		int log;
	
	};

	template <bool NA, typename T>
	class PExp : public Rcpp::VectorBase< REALSXP, NA, PExp<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PExp( const VEC_TYPE& vec_, double rate_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), rate(rate_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pexp( vec[i], rate, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double rate; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QExp : public Rcpp::VectorBase< REALSXP, NA, QExp<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QExp( const VEC_TYPE& vec_, double rate_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), rate(rate_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qexp( vec[i], rate, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double rate; 
		int lower, log;
	
	};
	
} // impl

template <bool NA, typename T>
inline impl::DExp<NA,T> dexp( const Rcpp::VectorBase<REALSXP,NA,T>& x, double shape = 1.0, bool log = false ) {
	return impl::DExp<NA,T>( x, 1.0/shape, log ); 
}

template <bool NA, typename T>
inline impl::PExp<NA,T> pexp( const Rcpp::VectorBase<REALSXP,NA,T>& x, double shape = 1.0, bool lower = true, bool log = false ) {
	return impl::PExp<NA,T>( x, 1.0/shape, lower, log ); 
}

template <bool NA, typename T>
inline impl::QExp<NA,T> qexp( const Rcpp::VectorBase<REALSXP,NA,T>& x, double shape = 1.0, bool lower = true, bool log = false ) {
	return impl::QExp<NA,T>( x, 1.0/shape, lower, log ); 
}
	
}
}

#endif

