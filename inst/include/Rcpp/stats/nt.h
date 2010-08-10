
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// nt.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__nt_h
#define Rcpp__stats__nt_h

namespace Rcpp {
namespace stats {


	template <bool NA, typename T>
	class DNt : public Rcpp::VectorBase< REALSXP, NA, DNt<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DNt( const VEC_TYPE& vec_, double df_, double ncp_ , bool log_ = false ) : 
			vec(vec_), df(df_), ncp(ncp_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dnt( vec[i], df, ncp , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df; double ncp; 
		int log;
	
	};

	template <bool NA, typename T>
	class PNt : public Rcpp::VectorBase< REALSXP, NA, PNt<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PNt( const VEC_TYPE& vec_, double df_, double ncp_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), df(df_), ncp(ncp_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pnt( vec[i], df, ncp, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df; double ncp; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QNt : public Rcpp::VectorBase< REALSXP, NA, QNt<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QNt( const VEC_TYPE& vec_, double df_, double ncp_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), df(df_), ncp(ncp_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qnt( vec[i], df, ncp, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df; double ncp; 
		int lower, log;
	
	};
	
} // stats

template <bool NA, typename T>
inline stats::DNt<NA,T> dnt( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df_, double ncp_, bool log = false ) {
	return stats::DNt<NA,T>( x, df_, ncp_, log ); 
}

template <bool NA, typename T>
inline stats::PNt<NA,T> pnt( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df_, double ncp_, bool lower = true, bool log = false ) {
	return stats::PNt<NA,T>( x, df_, ncp_, lower, log ); 
}

template <bool NA, typename T>
inline stats::QNt<NA,T> qnt( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df_, double ncp_, bool lower = true, bool log = false ) {
	return stats::QNt<NA,T>( x, df_, ncp_, lower, log ); 
}
	
}

#endif

