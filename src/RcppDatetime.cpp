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

#include <RcppDatetime.h>
#include <time.h> // for strftime

RcppDatetime::RcppDatetime(void) : m_d(0), 
				   m_parsed(false), 
				   m_us(0) { 
}

RcppDatetime::RcppDatetime(const double d) : m_d(d), 
					     m_parsed(false), 
					     m_us(0) { 
}

RcppDatetime::RcppDatetime(SEXP ds) { 
    m_d = REAL(ds)[0]; 
    m_parsed = false; 
    m_us = 0;
}

void RcppDatetime::parseTime() {
    // tt is the nb of seconds, ignores fractional microsec
    time_t tt = static_cast<time_t>(floor(m_d));	
    m_tm = *localtime(&tt);			// parse time type into time structure 

    // m_us is fractional (micro)secs is diff. between (fractional) m_d and m_tm
    m_us = static_cast<int>(round( (m_d - tt) * 1.0e6));	

    m_parsed = true;				// and note that we parsed the time type
}

std::ostream& operator<<(std::ostream& os, const RcppDatetime &datetime) {
    RcppDatetime dt(datetime);
    dt.parseTime();
    char buf[32], usec[16];
    strftime(buf, 31, "%Y-%m-%d %H:%M:%S", &dt.m_tm);
    snprintf(usec, 15, ".%.06d", dt.m_us);
    os << buf << usec;
    return os;
}

RcppDatetime operator+(const RcppDatetime &date,   double offset) {
    RcppDatetime tmp(date.m_d);
    tmp.m_d += offset;
    tmp.m_parsed = false;
    return tmp;
}
