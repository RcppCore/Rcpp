// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppResultSet.h: Rcpp R/C++ interface class library -- Results back to R
//
// Copyright (C) 2005 - 2006 Dominick Samperi
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
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

#ifndef RcppResultSet_h
#define RcppResultSet_h

#include <RcppCommon.h>

#include <classic/RcppDate.h>
#include <classic/RcppDateVector.h>
#include <classic/RcppDatetime.h>
#include <classic/RcppDatetimeVector.h>
#include <classic/RcppStringVector.h>
#include <classic/RcppFrame.h>
#include <classic/RcppList.h>
#include <classic/RcppMatrix.h>
#include <classic/RcppNumList.h>
#include <classic/RcppStringVector.h>
#include <classic/RcppVector.h>

namespace Rcpp {
    // template specialisation for wrap() on the date and datetime classes
    template <> SEXP wrap<RcppDate>(const RcppDate &date);
    template <> SEXP wrap<RcppDatetime>(const RcppDatetime &date);
    template <> SEXP wrap<RcppDateVector>(const RcppDateVector &datevec);
    template <> SEXP wrap<RcppDatetimeVector>(const RcppDatetimeVector &dtvec);
}

class RcppResultSet {
public:
	typedef std::pair<const std::string,SEXP> PAIR ;
	typedef std::list<PAIR> LIST ; 
	
    RcppResultSet();
    
    template <typename T>
    void add(const std::string& name, const T& object){
    	return add__impl( name, object ) ;
    }

    void add(const std::string&, double *, int);
    void add(const std::string&, int *, int);
    void add(const std::string&, double **, int, int);
    void add(const std::string&, int **, int, int);

    void add(const std::string& name , const std::vector<std::vector<double> >& object) ;
    void add(const std::string& name , const std::vector<std::vector<int> >& object) ;
    
    SEXP getReturnList();
    SEXP getSEXP();

protected:
    int numProtected;
    LIST values;
    
private:
	
	inline void push_back( const std::string& name, SEXP x){
		values.push_back( PAIR(name, PROTECT(x) ) ) ;
		numProtected++ ;
	}
	
	template <typename T> 
	void add__impl( const std::string&, const T& ) ;

	template <typename T> 
	void add__matrix__std( const std::string& name, const std::vector<std::vector<T> >& mat ) throw(std::range_error) ;

	template <typename T> 
	void add__matrix( const std::string& name, T**, int, int ) ;

};

#endif
