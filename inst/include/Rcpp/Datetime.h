// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// Datetime.h: Rcpp R/C++ interface class library -- Datetime (POSIXct)
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

#ifndef Rcpp__Datetime_h
#define Rcpp__Datetime_h

#include <RcppCommon.h>

namespace Rcpp {

    class Datetime {
    public:	
		Datetime();
		Datetime(SEXP s); 
		Datetime(const double &dt);	// from double, just like POSIXct
		Datetime(const std::string &s, const std::string &fmt="%Y-%m-%d %H:%M:%0S");
		Datetime(const Datetime &copy);
		~Datetime() {};
		
		double getFractionalTimestamp(void) const { return m_dt; } 

		int getMicroSeconds() const { return m_us; }
		int getSeconds()      const { return m_tm.tm_sec; }
		int getMinutes()      const { return m_tm.tm_min; }
		int getHours()        const { return m_tm.tm_hour; }
		int getDay()          const { return m_tm.tm_mday; }
		int getMonth()        const { return m_tm.tm_mon + 1; } 	 // makes it 1 .. 12
		int getYear()         const { return m_tm.tm_year + 1900; }
		int getWeekday()      const { return m_tm.tm_wday + 1; } 	 // makes it 1 .. 7
		int getYearday()      const { return m_tm.tm_yday + 1; }     // makes it 1 .. 366

		Datetime & operator=(const Datetime &newdt); 		// copy assignment operator 

		// Minimal set of date operations.
		friend Datetime  operator+(const Datetime &dt, double offset);
		friend double    operator-(const Datetime& dt1, const Datetime& dt2);
		friend bool      operator<(const Datetime &dt1, const Datetime& dt2);
		friend bool      operator>(const Datetime &dt1, const Datetime& dt2);
		friend bool      operator==(const Datetime &dt1, const Datetime& dt2);
		friend bool      operator>=(const Datetime &dt1, const Datetime& dt2);
		friend bool      operator<=(const Datetime &dt1, const Datetime& dt2);
		friend bool      operator!=(const Datetime &dt1, const Datetime& dt2);

    private:
        double m_dt;				// fractional seconds since epoch
        struct tm m_tm;				// standard time representation
		unsigned int m_us;			// microsecond (to complement m_tm)

		void update_tm();			// update m_tm based on m_dt

    };


    // template specialisation for wrap() on datetime
    template <> SEXP wrap<Rcpp::Datetime>(const Rcpp::Datetime &dt);

    // needed to wrap containers of Date such as vector<Date> or map<string,Date>
    namespace internal {
		template<> inline double caster<Rcpp::Datetime,double>( Rcpp::Datetime from){
			return static_cast<double>( from.getFractionalTimestamp() ) ;
		}
		template<> inline Rcpp::Datetime caster<double,Rcpp::Datetime>( double from){
			return Rcpp::Datetime( static_cast<double>( from ) ) ;
		}
    }
    
    template<> inline SEXP wrap_extra_steps<Rcpp::Datetime>( SEXP x ){
		SEXP datetimeclass = PROTECT(Rf_allocVector(STRSXP,2));
		SET_STRING_ELT(datetimeclass, 0, Rf_mkChar("POSIXt"));
		SET_STRING_ELT(datetimeclass, 1, Rf_mkChar("POSIXct"));
		Rf_setAttrib(x, R_ClassSymbol, datetimeclass); 
		UNPROTECT(1);
    	return x ;
    }
	
}

#endif
