// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// DateVector.h: Rcpp R/C++ interface class library -- Date vector support
//
// Copyright (C) 2010	     Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__DateVector_h
#define Rcpp__DateVector_h

#include <RcppCommon.h>

namespace Rcpp {

	class DateVector {
	public:
		typedef std::vector<Date>::iterator iterator;
		typedef std::vector<Date>::const_iterator const_iterator;
		
		// TODO: use a custom exception class instead of std::range_error
		DateVector(SEXP vec) throw(std::range_error);
		DateVector(int n);
		~DateVector() {};

		const Date& operator()(unsigned int i) const throw(std::range_error);
		Date& operator()(unsigned int i) throw(std::range_error);

		const Date& operator[](unsigned int i) const;
		Date& operator[](unsigned int i);

		int size() const;

		std::vector<Date> getDates() const;
		
		inline iterator begin(){ return v.begin(); }
		inline iterator end(){ return v.end(); }
		
		inline const_iterator begin() const { return v.begin(); }
		inline const_iterator end() const { return v.end(); }
		
		inline operator SEXP() const { return wrap( v ) ; } 
		
	private:
		std::vector<Date> v;
	};
}

#endif
