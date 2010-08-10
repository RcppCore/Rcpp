// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// beta.h: Rcpp R/C++ interface class library -- beta distribution
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__stats__beta_h
#define Rcpp__stats__beta_h

namespace Rcpp {

namespace stats {



	template <bool NA, typename T>
	class DBeta : public Rcpp::VectorBase< REALSXP, NA, DBeta<NA,T> > {
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;

		DBeta( const VEC_TYPE& vec_, double a_, double b_, bool log_ = false ) : 
			vec(vec_), a(a_), b(b_), log(log_) {}
		
		inline double operator[]( int i) const { return ::dbeta( vec[i], a, b, log ); }
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double a, b;
		int log;
	
	};

	template <bool NA, typename T>
	class PBeta : public Rcpp::VectorBase< REALSXP, NA, PBeta<NA,T> > {
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;

		PBeta( const VEC_TYPE& vec_, double a_, double b_, bool lowertail_ = true, bool log_ = false ) : 
			vec(vec_), a(a_), b(b_), lowertail(lowertail_), log(log_) {}
		
		inline double operator[]( int i) const { return ::pbeta( vec[i], a, b, lowertail, log ); }
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double a, b;
		int lowertail, log;
	
	};

	template <bool NA, typename T>
	class QBeta : public Rcpp::VectorBase< REALSXP, NA, QBeta<NA,T> > {
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;

		QBeta( const VEC_TYPE& vec_, double a_, double b_, bool lowertail_ = true, bool log_ = false ) : 
			vec(vec_), a(a_), b(b_), lowertail(lowertail_), log(log_) {}
		
		inline double operator[]( int i) const { return ::qbeta( vec[i], a, b, lowertail, log ); }
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		double a, b;
		int lowertail, log;
	
	};
	
} // stats

template <bool NA, typename T>
inline stats::DBeta<NA,T> dbeta( const Rcpp::VectorBase<REALSXP,NA,T>& x, double a, double b, bool log = false ) {
	return stats::DBeta<NA,T>( x, a, b, log ); 
}

template <bool NA, typename T>
inline stats::PBeta<NA,T> pbeta( const Rcpp::VectorBase<REALSXP,NA,T>& x,
								double a, double b,
								bool lowertail = true, bool log = false ) {
	return stats::PBeta<NA,T>( x, a, b, lowertail, log ); 
}

template <bool NA, typename T>
inline stats::QBeta<NA,T> qbeta( const Rcpp::VectorBase<REALSXP,NA,T>& x,
								double a, double b,
								bool lowertail = true, bool log = false ) {
	return stats::QBeta<NA,T>( x, a, b, lowertail, log ); 
}
	
}

#endif
