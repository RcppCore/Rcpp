
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// chisq.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__chisq_h
#define Rcpp__stats__chisq_h

namespace Rcpp {
namespace stats {


	template <bool NA, typename T>
	class DChisq : public Rcpp::VectorBase< REALSXP, NA, DChisq<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DChisq( const VEC_TYPE& vec_, double df_ , bool log_ = false ) : 
			vec(vec_), df(df_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dchisq( vec[i], df , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df; 
		int log;
	
	};

	template <bool NA, typename T>
	class PChisq : public Rcpp::VectorBase< REALSXP, NA, PChisq<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PChisq( const VEC_TYPE& vec_, double df_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), df(df_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pchisq( vec[i], df, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QChisq : public Rcpp::VectorBase< REALSXP, NA, QChisq<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QChisq( const VEC_TYPE& vec_, double df_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), df(df_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qchisq( vec[i], df, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df; 
		int lower, log;
	
	};
	
} // stats

template <bool NA, typename T>
inline stats::DChisq<NA,T> dchisq( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df_, bool log = false ) {
	return stats::DChisq<NA,T>( x, df_, log ); 
}

template <bool NA, typename T>
inline stats::PChisq<NA,T> pchisq( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df_, bool lower = true, bool log = false ) {
	return stats::PChisq<NA,T>( x, df_, lower, log ); 
}

template <bool NA, typename T>
inline stats::QChisq<NA,T> qchisq( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df_, bool lower = true, bool log = false ) {
	return stats::QChisq<NA,T>( x, df_, lower, log ); 
}
	
}

#endif

