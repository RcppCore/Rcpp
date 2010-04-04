// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppDatetime.h: Rcpp R/C++ interface class library -- Datetime type support
//
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
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

#ifndef RcppDatetime_h
#define RcppDatetime_h

#include <RcppCommon.h>
#include <time.h>

class RcppDatetime {
private:
    double m_d;			// fractional seconds since epoch as eg POSIXct
    bool m_parsed;		// has m_tm been set based on m_d ?
    int m_us;			// microseconds not in POSIX time structure
    struct tm m_tm;		// time structure as eg POSIXlt
    void parseTime();		// sets m_tm and m_us based on m_d

protected:
    friend class ColDatum;

public:
    RcppDatetime(void);
    RcppDatetime(const double d);
    RcppDatetime(SEXP ds);

    double getFractionalTimestamp(void) const { return m_d; }
    int getYear(void)     { if (!m_parsed) parseTime(); return m_tm.tm_year + 1900; }
    int getMonth(void)    { if (!m_parsed) parseTime(); return m_tm.tm_mon + 1; }
    int getDay(void)      { if (!m_parsed) parseTime(); return m_tm.tm_mday; } 
    int getWeekday(void)  { if (!m_parsed) parseTime(); return m_tm.tm_wday; } 
    int getHour(void)     { if (!m_parsed) parseTime(); return m_tm.tm_hour; } 
    int getMinute(void)   { if (!m_parsed) parseTime(); return m_tm.tm_min; } 
    int getSecond(void)   { if (!m_parsed) parseTime(); return m_tm.tm_sec; } 
    int getMicroSec(void) { if (!m_parsed) parseTime(); return m_us; } 

    friend double        operator-(const RcppDatetime& dt1,  const RcppDatetime& dt2) { return dt1.m_d -  dt2.m_d; }
    friend bool          operator<(const RcppDatetime &dt1,  const RcppDatetime& dt2) { return dt1.m_d <  dt2.m_d; }
    friend bool          operator<=(const RcppDatetime &dt1, const RcppDatetime& dt2) { return dt1.m_d <= dt2.m_d; }
    friend bool          operator>(const RcppDatetime &dt1,  const RcppDatetime& dt2) { return dt1.m_d >  dt2.m_d; }
    friend bool          operator>=(const RcppDatetime &dt1, const RcppDatetime& dt2) { return dt1.m_d >= dt2.m_d; }
    friend bool          operator==(const RcppDatetime &dt1, const RcppDatetime& dt2) { return dt1.m_d == dt2.m_d; }  // remember float math...
    friend std::ostream& operator<<(std::ostream& os, const RcppDatetime &datetime); 
    friend RcppDatetime  operator+(const RcppDatetime &date,   double offset);
};

#endif
