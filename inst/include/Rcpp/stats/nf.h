
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// nf.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__nf_h
#define Rcpp__stats__nf_h

namespace Rcpp {
namespace stats {
namespace impl {

	template <bool NA, typename T>
	class DNf : public Rcpp::VectorBase< REALSXP, NA, DNf<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DNf( const VEC_TYPE& vec_, double df1_, double df2_, double ncp_ , bool log_ = false ) : 
			vec(vec_), df1(df1_), df2(df2_), ncp(ncp_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dnf( vec[i], df1, df2, ncp , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df1; double df2; double ncp; 
		int log;
	
	};

	template <bool NA, typename T>
	class PNf : public Rcpp::VectorBase< REALSXP, NA, PNf<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PNf( const VEC_TYPE& vec_, double df1_, double df2_, double ncp_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), df1(df1_), df2(df2_), ncp(ncp_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pnf( vec[i], df1, df2, ncp, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df1; double df2; double ncp; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QNf : public Rcpp::VectorBase< REALSXP, NA, QNf<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QNf( const VEC_TYPE& vec_, double df1_, double df2_, double ncp_ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), df1(df1_), df2(df2_), ncp(ncp_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qnf( vec[i], df1, df2, ncp, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double df1; double df2; double ncp; 
		int lower, log;
	
	};
	
} // impl

template <bool NA, typename T>
inline impl::DNf<NA,T> dnf( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df1_, double df2_, double ncp_, bool log = false ) {
	return impl::DNf<NA,T>( x, df1_, df2_, ncp_, log ); 
}

template <bool NA, typename T>
inline impl::PNf<NA,T> pnf( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df1_, double df2_, double ncp_, bool lower = true, bool log = false ) {
	return impl::PNf<NA,T>( x, df1_, df2_, ncp_, lower, log ); 
}

template <bool NA, typename T>
inline impl::QNf<NA,T> qnf( const Rcpp::VectorBase<REALSXP,NA,T>& x, double df1_, double df2_, double ncp_, bool lower = true, bool log = false ) {
	return impl::QNf<NA,T>( x, df1_, df2_, ncp_, lower, log ); 
}
	
}
}

#endif

