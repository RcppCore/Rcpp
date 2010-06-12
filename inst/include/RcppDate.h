// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppDate.h: Rcpp R/C++ interface class library -- Date type support
//
// Copyright (C) 2005 - 2006 Dominick Samperi
// Copyright (C) 2008        Dirk Eddelbuettel
// Copyright (C) 2009 - 2010 Dirk Eddelbuettel and Romain Francois
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

#ifndef RcppDate_h
#define RcppDate_h

#include <RcppCommon.h>

class RcppDate {
private:
    void mdy2jdn(); 				// month/day/year to Julian day number.
    void jdn2mdy(); 				// Julian day number to month/day/year.
    int month, day, year;
    int jdn; 					// Julian day number

public:
    static const int Jan1970Offset;		// offset between Jan 1, 1970 and Julian Day Number
    static const int QLtoJan1970Offset;		// offset between Jan 1, 1970 and QuantLib BaseDate
    RcppDate();
    RcppDate(int Rjdn);
    RcppDate(int month_, int day_, int year_);
    RcppDate(SEXP dt);
    int getMonth() const { return month; }
    int getDay()  const  { return day; }
    int getYear() const  { return year; }
    int getJDN()  const  { return jdn; } 
    int getJulian()  const  { return jdn - Jan1970Offset; } 

    // Minimal set of date operations.
    friend RcppDate operator+(const RcppDate &date, int offset);
    friend int      operator-(const RcppDate& date1, const RcppDate& date2);
    friend bool     operator<(const RcppDate &date1, const RcppDate& date2);
    friend bool     operator>(const RcppDate &date1, const RcppDate& date2);
    friend bool     operator==(const RcppDate &date1, const RcppDate& date2);
    friend bool     operator>=(const RcppDate &date1, const RcppDate& date2);
    friend bool     operator<=(const RcppDate &date1, const RcppDate& date2);

    friend std::ostream& operator<<(std::ostream& os, const RcppDate& date);
};

#endif
