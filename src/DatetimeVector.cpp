// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// DatetimeVector.cpp: Rcpp R/C++ interface class library -- Datetime vector
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

#include <Rcpp/DatetimeVector.h>
#include <Rcpp/Datetime.h>

namespace Rcpp {

	DatetimeVector::DatetimeVector(SEXP vec) throw(std::range_error) : v()  {
		int i;
		if (!Rf_isNumeric(vec) || Rf_isMatrix(vec) || Rf_isLogical(vec))
			throw std::range_error("DatetimeVector: invalid numeric vector in constructor");
		int len = Rf_length(vec);
		if (len == 0)
			throw std::range_error("DatetimeVector: null vector in constructor");
		v.resize(len);
		for (i = 0; i < len; i++)
			v[i] = Datetime( static_cast<double>(REAL(vec)[i]));
	}


	DatetimeVector::DatetimeVector(int n) : v(n) {}

	const Datetime & DatetimeVector::operator()(unsigned int i) const throw(std::range_error) {
		if (i >= v.size()) {
			std::ostringstream oss;
			oss << "DatetimeVector: subscript out of range: " << i;
			throw std::range_error(oss.str());
		}
		return v[i];
	}

	Datetime & DatetimeVector::operator()(unsigned int i) throw(std::range_error) {
		if (i >= v.size()) {
			std::ostringstream oss;
			oss << "DatetimeVector: subscript out of range: " << i;
			throw std::range_error(oss.str());
		}
		return v[i];
	}

	const Datetime & DatetimeVector::operator[](unsigned int i) const {
		return v[i];
	}

	Datetime & DatetimeVector::operator[](unsigned int i) {
		return v[i];
	}

	int DatetimeVector::size() const { 
		return v.size(); 
	}

	std::vector<Datetime> DatetimeVector::getDatetimes() const {
		return v;
	}

}
