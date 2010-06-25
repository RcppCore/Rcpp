// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// DatetimeVector.h: Rcpp R/C++ interface class library -- Datetime vector
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

#ifndef Rcpp__DatetimeVector_h
#define Rcpp__DatetimeVector_h

#include <RcppCommon.h>

namespace Rcpp {

	class DatetimeVector {
	public:
		typedef std::vector<Datetime>::iterator iterator;
		typedef std::vector<Datetime>::const_iterator const_iterator;
		
		// TODO: use a custom exception class instead of std::range_error
		DatetimeVector(SEXP vec) throw(std::range_error);
		DatetimeVector(int n);
		~DatetimeVector() {};

		const Datetime& operator()(unsigned int i) const throw(std::range_error);
		Datetime& operator()(unsigned int i) throw(std::range_error);

		const Datetime& operator[](unsigned int i) const;
		Datetime& operator[](unsigned int i);

		int size() const;

		std::vector<Datetime> getDatetimes() const;
		
		inline iterator begin(){ return v.begin(); }
		inline iterator end(){ return v.end(); }
		
		inline const_iterator begin() const { return v.begin(); }
		inline const_iterator end() const { return v.end(); }
		
		inline operator SEXP() const { return wrap( v ) ; } 
		
	private:
		std::vector<Datetime> v;
	};
}

#endif
