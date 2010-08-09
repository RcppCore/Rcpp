
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// lnorm.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__lnorm_h
#define Rcpp__stats__lnorm_h

namespace Rcpp {
namespace stats {
namespace impl {

	template <bool NA, typename T>
	class DLnorm : public Rcpp::VectorBase< REALSXP, NA, DLnorm<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DLnorm( const VEC_TYPE& vec_, double meanlog_ = 0.0, double sdlog_ = 1.0 , bool log_ = false ) : 
			vec(vec_), meanlog(meanlog_), sdlog(sdlog_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dlnorm( vec[i], meanlog, sdlog , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double meanlog; double sdlog; 
		int log;
	
	};

	template <bool NA, typename T>
	class PLnorm : public Rcpp::VectorBase< REALSXP, NA, PLnorm<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PLnorm( const VEC_TYPE& vec_, double meanlog_ = 0.0, double sdlog_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), meanlog(meanlog_), sdlog(sdlog_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::plnorm( vec[i], meanlog, sdlog, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double meanlog; double sdlog; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QLnorm : public Rcpp::VectorBase< REALSXP, NA, QLnorm<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QLnorm( const VEC_TYPE& vec_, double meanlog_ = 0.0, double sdlog_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), meanlog(meanlog_), sdlog(sdlog_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qlnorm( vec[i], meanlog, sdlog, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double meanlog; double sdlog; 
		int lower, log;
	
	};
	
} // impl

template <bool NA, typename T>
inline impl::DLnorm<NA,T> dlnorm( const Rcpp::VectorBase<REALSXP,NA,T>& x, double meanlog_ = 0.0, double sdlog_ = 1.0, bool log = false ) {
	return impl::DLnorm<NA,T>( x, meanlog_, sdlog_, log ); 
}

template <bool NA, typename T>
inline impl::PLnorm<NA,T> plnorm( const Rcpp::VectorBase<REALSXP,NA,T>& x, double meanlog_ = 0.0, double sdlog_ = 1.0, bool lower = true, bool log = false ) {
	return impl::PLnorm<NA,T>( x, meanlog_, sdlog_, lower, log ); 
}

template <bool NA, typename T>
inline impl::QLnorm<NA,T> qlnorm( const Rcpp::VectorBase<REALSXP,NA,T>& x, double meanlog_ = 0.0, double sdlog_ = 1.0, bool lower = true, bool log = false ) {
	return impl::QLnorm<NA,T>( x, meanlog_, sdlog_, lower, log ); 
}
	
}
}

#endif

