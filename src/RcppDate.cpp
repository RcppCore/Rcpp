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

#include <RcppDate.h>

const int RcppDate::Jan1970Offset = 2440588;    // Offset from R date representation to Julian day number.
const int RcppDate::QLtoJan1970Offset = 25569;  // Offset between R / Unix epoch date and the QL base date

RcppDate::RcppDate() : month(1), 
		       day(1), 
		       year(1970) { 
    mdy2jdn(); 
}

RcppDate::RcppDate(int Rjdn) { 
    jdn = Rjdn+Jan1970Offset; 
    jdn2mdy(); 
}

RcppDate::RcppDate(int month_, int day_, int year_) : month(month_), 
						      day(day_), 
						      year(year_) { 
    if (month < 1 || month > 12 || day < 1 || day > 31)
	throw std::range_error("RcppDate: invalid date");
    mdy2jdn();
}

RcppDate::RcppDate(SEXP dt) {
    jdn = Rcpp::as<int>(dt) + Jan1970Offset;
    jdn2mdy();
}

// Print an RcppDate.
std::ostream& operator<<(std::ostream& os, const RcppDate& date) {
    os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
    return os;
}

// A few basic date operations.
RcppDate operator+(const RcppDate& date, int offset) {
    RcppDate temp(date.month, date.day, date.year);
    temp.jdn += offset;
    temp.jdn2mdy();
    return temp;
}

int operator-(const RcppDate& date2, const RcppDate& date1) {
    return date2.jdn - date1.jdn;
}

bool  operator<(const RcppDate &date1, const RcppDate& date2) {
    return date1.jdn < date2.jdn;
}

bool  operator>(const RcppDate &date1, const RcppDate& date2) {
    return date1.jdn > date2.jdn;
}

bool  operator>=(const RcppDate &date1, const RcppDate& date2) {
    return date1.jdn >= date2.jdn;
}

bool  operator<=(const RcppDate &date1, const RcppDate& date2) {
    return date1.jdn <= date2.jdn;
}

bool  operator==(const RcppDate &date1, const RcppDate& date2) {
    return date1.jdn == date2.jdn;
}

// The Julian day number (jdn) is the number of days since Monday,
// Jan 1, 4713BC (year = -4712). Here 1BC is year 0, 2BC is year -1, etc.
// On the other hand, R measures days since Jan 1, 1970, and these dates are
// converted to jdn's by adding Jan1970Offset.
//
// mdy2jdn and jdn2mdy are inverse functions for dates back to 
// year = -4799 (4800BC).
//
// See the Wikipedia entry on Julian day number for more information 
// on these algorithms.
//

// Transform month/day/year to Julian day number.
void RcppDate::mdy2jdn() {
    int m = month, d = day, y = year;
    int a = (14 - m)/12;
    y += 4800 - a;
    m += 12*a - 3;
    jdn = (d + (153*m + 2)/5 + 365*y
	   + y/4 - y/100 + y/400 - 32045);
}

// Transform from Julian day number to month/day/year.
void RcppDate::jdn2mdy() {
    int jul = jdn + 32044;
    int g = jul/146097;
    int dg = jul % 146097;
    int c = (dg/36524 + 1)*3/4;
    int dc = dg - c*36524;
    int b = dc/1461;
    int db = dc % 1461;
    int a = (db/365 + 1)*3/4;
    int da = db - a*365;
    int y = g*400 + c*100 + b*4 + a;
    int m = (da*5 + 308)/153 - 2;
    int d = da - (m + 4)*153 /5 + 122;
    y = y - 4800 + (m + 2)/12;
    m = (m + 2) % 12 + 1;
    d = d + 1;
    month = m;
    day   = d;
    year  = y;
}

