
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// cauchy.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__stats__cauchy_h
#define Rcpp__stats__cauchy_h

namespace Rcpp {
namespace stats {


	template <bool NA, typename T>
	class DCauchy : public Rcpp::VectorBase< REALSXP, NA, DCauchy<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		DCauchy( const VEC_TYPE& vec_, double location_ = 0.0, double scale_ = 1.0 , bool log_ = false ) : 
			vec(vec_), location(location_), scale(scale_) , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::dcauchy( vec[i], location, scale , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double location; double scale; 
		int log;
	
	};

	template <bool NA, typename T>
	class PCauchy : public Rcpp::VectorBase< REALSXP, NA, PCauchy<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		PCauchy( const VEC_TYPE& vec_, double location_ = 0.0, double scale_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), location(location_), scale(scale_) , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::pcauchy( vec[i], location, scale, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double location; double scale; 
		int lower, log;
	
	};

	template <bool NA, typename T>
	class QCauchy : public Rcpp::VectorBase< REALSXP, NA, QCauchy<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		QCauchy( const VEC_TYPE& vec_, double location_ = 0.0, double scale_ = 1.0 ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), location(location_), scale(scale_), lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::qcauchy( vec[i], location, scale, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double location; double scale; 
		int lower, log;
	
	};
	
} // stats

template <bool NA, typename T>
inline stats::DCauchy<NA,T> dcauchy( const Rcpp::VectorBase<REALSXP,NA,T>& x, double location_ = 0.0, double scale_ = 1.0, bool log = false ) {
	return stats::DCauchy<NA,T>( x, location_, scale_, log ); 
}

template <bool NA, typename T>
inline stats::PCauchy<NA,T> pcauchy( const Rcpp::VectorBase<REALSXP,NA,T>& x, double location_ = 0.0, double scale_ = 1.0, bool lower = true, bool log = false ) {
	return stats::PCauchy<NA,T>( x, location_, scale_, lower, log ); 
}

template <bool NA, typename T>
inline stats::QCauchy<NA,T> qcauchy( const Rcpp::VectorBase<REALSXP,NA,T>& x, double location_ = 0.0, double scale_ = 1.0, bool lower = true, bool log = false ) {
	return stats::QCauchy<NA,T>( x, location_, scale_, lower, log ); 
}
	
}

#endif

