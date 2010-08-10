
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// weibull.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__weibull_h
#define Rcpp__stats__weibull_h

namespace Rcpp {
namespace stats {


	template <bool NA, typename T>
	class DWeibull : public Rcpp::VectorBase< REALSXP, NA, DWeibull<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DWeibull( const VEC_TYPE& vec_, double shape_, double scale_ = 1.0 , bool log_ = false ) : 
			vec(vec_), shape(shape_), scale(scale_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dweibull( vec[i], shape, scale , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double shape; double scale; 
		int log;
	
	};

	template <bool NA, typename T>
	class PWeibull : public Rcpp::VectorBase< REALSXP, NA, PWeibull<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PWeibull( const VEC_TYPE& vec_, double shape_, double scale_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), shape(shape_), scale(scale_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pweibull( vec[i], shape, scale, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double shape; double scale; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QWeibull : public Rcpp::VectorBase< REALSXP, NA, QWeibull<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QWeibull( const VEC_TYPE& vec_, double shape_, double scale_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), shape(shape_), scale(scale_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qweibull( vec[i], shape, scale, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double shape; double scale; 
		int lower, log;
	
	};
	
} // stats

template <bool NA, typename T>
inline stats::DWeibull<NA,T> dweibull( const Rcpp::VectorBase<REALSXP,NA,T>& x, double shape_, double scale_ = 1.0, bool log = false ) {
	return stats::DWeibull<NA,T>( x, shape_, scale_, log ); 
}

template <bool NA, typename T>
inline stats::PWeibull<NA,T> pweibull( const Rcpp::VectorBase<REALSXP,NA,T>& x, double shape_, double scale_ = 1.0, bool lower = true, bool log = false ) {
	return stats::PWeibull<NA,T>( x, shape_, scale_, lower, log ); 
}

template <bool NA, typename T>
inline stats::QWeibull<NA,T> qweibull( const Rcpp::VectorBase<REALSXP,NA,T>& x, double shape_, double scale_ = 1.0, bool lower = true, bool log = false ) {
	return stats::QWeibull<NA,T>( x, shape_, scale_, lower, log ); 
}
	
}

#endif

