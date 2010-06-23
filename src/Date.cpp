// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Date.h: Rcpp R/C++ interface class library -- Date type
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

#include <Rcpp/Date.h>

namespace Rcpp {

    Date::Date() {
	d = 0; 
    };

    Date::Date(const int &dt) {
	d = dt;
    }

    Date::Date(const std::string &s, const std::string &fmt) {
	// we cheat and call strptime() from R
	Rcpp::Function strptime("strptime");
	d = Rcpp::as<int>(strptime(s, fmt));
    }

    Date::Date(const unsigned int &mon, const unsigned int &day, const unsigned int &year) {

	struct tm tm;;
	tm.tm_sec = tm.tm_min = tm.tm_hour = tm.tm_isdst = 0;

	// allow for special case (yyyy, mm, dd) which we prefer over (mm, dd, year)
	if (mon >= 1900 && day <= 12 && year <= 31) {
	    tm.tm_year = mon - 1900;
	    tm.tm_mon  = day - 1;       // range 0 to 11
	    tm.tm_mday = year;
	} else {
	    tm.tm_mday  = day;
	    tm.tm_mon   = mon - 1;	// range 0 to 11
	    tm.tm_year  = year - 1900;
	}
	double tmp = mktime(&tm);
	d = tmp/(24*60*60);
    }

    Date::~Date() {
	// nothing to do
    }

    int Date::getDate(void) const { 
	return d; 
    };


    template <> SEXP wrap(const Date &date) {
	SEXP value = PROTECT(Rf_allocVector(REALSXP, 1));
	REAL(value)[0] = date.getDate();
	SEXP dateclass = PROTECT(Rf_allocVector(STRSXP,1));
	SET_STRING_ELT(dateclass, 0, Rf_mkChar("Date"));
	Rf_setAttrib(value, R_ClassSymbol, dateclass); 
	UNPROTECT(2);
	return value;
    }

}
