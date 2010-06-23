// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// Date.h: Rcpp R/C++ interface class library -- dates
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

#ifndef Rcpp__Date_h
#define Rcpp__Date_h

#include <RcppCommon.h>

namespace Rcpp {

    class Date {
    public:	
		Date();
		Date(const int &dt);	// from integer, just like R (with negative dates before Jan 1, 1970)
		Date(const std::string &s, const std::string &fmt="%Y-%m-%d");
		Date(const unsigned int &m, const unsigned int &d, const unsigned int &y); 
		~Date();
		
		int getDate(void) const; 

		static const int QLtoJan1970Offset;  // Offset between R / Unix epoch date and the QL base date

#if 0		
		// rest to follow
		// assignment
		// copy
		// ...
		
		// Minimal set of date operations.
		friend Date   operator+(const Date &date, int offset);
		friend int    operator-(const Date& date1, const Date& date2);
		friend bool   operator<(const Date &date1, const Date& date2);
		friend bool   operator>(const Date &date1, const Date& date2);
		friend bool   operator==(const Date &date1, const Date& date2);
		friend bool   operator>=(const Date &date1, const Date& date2);
		friend bool   operator<=(const Date &date1, const Date& date2);
#endif

    private:
        int d;					// day number, relative to epoch of Jan 1, 1970

		double mktime00(struct tm &tm) const; // from R's src/main/datetime.c

    };


    // template specialisation for wrap() on the date 
    template <> SEXP wrap<Rcpp::Date>(const Rcpp::Date &date);

    // needed to wrap containers of Date such as vector<Date> or map<string,Date>
    namespace internal {
		template<> inline double caster<Rcpp::Date,double>( Rcpp::Date from){
			return static_cast<double>( from.getDate() ) ;
		}
		template<> inline Rcpp::Date caster<double,Rcpp::Date>( double from){
			return Rcpp::Date( static_cast<int>( from ) ) ;
		}
    }
    
    template<> inline SEXP wrap_extra_steps<Rcpp::Date>( SEXP x ){
    	Rf_setAttrib( x, Rf_install("class"), Rf_mkString( "Date" ) ) ;
    	return x ;
    }
	
}

#endif
