
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// f.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__f_h
#define Rcpp__stats__f_h

namespace Rcpp {
namespace stats {
namespace impl {

	template <bool NA, typename T>
	class DF : public Rcpp::VectorBase< REALSXP, NA, DF<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DF( const VEC_TYPE& vec_, double df1_, double df2_ , bool log_ = false ) : 
			vec(vec_), df1(df1_), df2(df2_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::df( vec[i], df1, df2 , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df1; double df2; 
		int log;
	
	};

	template <bool NA, typename T>
	class PF : public Rcpp::VectorBase< REALSXP, NA, PF<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PF( const VEC_TYPE& vec_, double df1_, double df2_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), df1(df1_), df2(df2_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pf( vec[i], df1, df2, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df1; double df2; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QF : public Rcpp::VectorBase< REALSXP, NA, QF<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QF( const VEC_TYPE& vec_, double df1_, double df2_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), df1(df1_), df2(df2_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qf( vec[i], df1, df2, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df1; double df2; 
		int lower, log;
	
	};
	
} // impl

template <bool NA, typename T>
inline impl::DF<NA,T> df( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df1_, double df2_, bool log = false ) {
	return impl::DF<NA,T>( x, df1_, df2_, log ); 
}

template <bool NA, typename T>
inline impl::PF<NA,T> pf( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df1_, double df2_, bool lower = true, bool log = false ) {
	return impl::PF<NA,T>( x, df1_, df2_, lower, log ); 
}

template <bool NA, typename T>
inline impl::QF<NA,T> qf( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df1_, double df2_, bool lower = true, bool log = false ) {
	return impl::QF<NA,T>( x, df1_, df2_, lower, log ); 
}
	
}
}

#endif

