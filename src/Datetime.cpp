// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// Datetime.h: Rcpp R/C++ interface class library -- Datetime (POSIXct)
//
// Copyright (C) 2010	      Dirk Eddelbuettel and Romain Francois
//
// The mktime00() function is
// Copyright (C) 2000 - 2010  The R Development Core Team.
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

#include <Rcpp/Datetime.h>
#include <Rcpp/Function.h>
#include <Rmath.h> 		// for Rf_fround
#include <time.h>		// for gmtime

namespace Rcpp {

    Datetime::Datetime() {
		m_dt = 0; 
		update_tm();
    }

    Datetime::Datetime(SEXP d) {
		m_dt = Rcpp::as<double>(d); 
		update_tm();
    }

    Datetime::Datetime(const double &dt) {
		m_dt = dt;
		update_tm();
    }

    Datetime::Datetime(const std::string &s, const std::string &fmt) {
		Rcpp::Function strptime("strptime");	// we cheat and call strptime() from R
		m_dt = Rcpp::as<double>(strptime(s, fmt));
		update_tm();
    }

    Datetime::Datetime(const Datetime &copy) {
		m_dt = copy.m_dt;
		m_us = copy.m_us;
		m_tm = copy.m_tm;
    }

    Datetime & Datetime::operator=(const Datetime & newdt) {
		if (this != &newdt) {
			m_dt = newdt.m_dt;
			m_us = newdt.m_us;
			m_tm = newdt.m_tm;
		}
		return *this;
    }

    void Datetime::update_tm() {
		time_t t = static_cast<time_t>(floor(m_dt));	
		m_tm = *gmtime(&t);		// this may need a Windows fix, re-check R's datetime.c
		// m_us is fractional (micro)secs as diff. between (fractional) m_dt and m_tm
		m_us = static_cast<int>(::Rf_fround( (m_dt - t) * 1.0e6, 0.0));	
    }

    Datetime operator+(const Datetime &datetime, double offset) {
		Datetime newdt(datetime.m_dt);
		newdt.m_dt += offset;
		time_t t = static_cast<time_t>(floor(newdt.m_dt));	
		newdt.m_tm = *gmtime(&t);		// this may need a Windows fix, re-check R's dat		
		newdt.m_us = static_cast<int>(::Rf_fround( (newdt.m_dt - t) * 1.0e6, 0.0));	
		return newdt;
    }

    double  operator-(const Datetime& d1, const Datetime& d2) { return d2.m_dt - d1.m_dt; }
    bool    operator<(const Datetime &d1, const Datetime& d2) { return d1.m_dt < d2.m_dt; }
    bool    operator>(const Datetime &d1, const Datetime& d2) { return d1.m_dt > d2.m_dt; }
    bool    operator==(const Datetime &d1, const Datetime& d2) { return d1.m_dt == d2.m_dt; }
    bool    operator>=(const Datetime &d1, const Datetime& d2) { return d1.m_dt >= d2.m_dt; }
    bool    operator<=(const Datetime &d1, const Datetime& d2) { return d1.m_dt <= d2.m_dt; }
    bool    operator!=(const Datetime &d1, const Datetime& d2) { return d1.m_dt != d2.m_dt; }

    template <> SEXP wrap(const Datetime &date) {
		return internal::new_posixt_object( date.getFractionalTimestamp() ) ;
    }

}
