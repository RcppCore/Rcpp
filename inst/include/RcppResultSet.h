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

#include <RcppDate.h>
#include <RcppDateVector.h>
#include <RcppDatetime.h>
#include <RcppDatetimeVector.h>
#include <RcppStringVector.h>
#include <RcppFrame.h>
#include <RcppList.h>
#include <RcppMatrix.h>
#include <RcppNumList.h>
#include <RcppStringVector.h>
#include <RcppVector.h>

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
    void add(std::string, double);
    void add(std::string, int);
    void add(std::string, std::string);
    void add(std::string, double *, int);
    void add(std::string, int *, int);
    void add(std::string, double **, int, int);
    void add(std::string, int **, int, int);
    void add(std::string, RcppDate&);
    void add(std::string, RcppDateVector&);
    void add(std::string, RcppDatetime&);
    void add(std::string, RcppDatetimeVector&);
    void add(std::string, RcppStringVector&);
    void add(std::string, std::vector<double>&);
    void add(std::string, std::vector<int>&);
    void add(std::string, std::vector<std::vector<double> >&);
    void add(std::string, std::vector<std::vector<int> >&);
    void add(std::string, std::vector<std::string>&);
    void add(std::string, RcppVector<int>&);
    void add(std::string, RcppVector<double>&);
    void add(std::string, RcppMatrix<int>&);
    void add(std::string, RcppMatrix<double>&);
    void add(std::string, RcppFrame&);
    void add(std::string, RcppList&);
    void add(std::string, SEXP, bool isProtected);
    SEXP getReturnList();
    SEXP getSEXP();

protected:
    int numProtected;
    LIST values;
    
private:
	
	inline void push_back( const std::string& name, SEXP x){
		values.push_back( PAIR(name, x ) ) ;
	}
	
	// defined later because it needs wrap
	template <typename T> 
	void add__impl( const std::string& name, const T& t ) ;
	
	template <typename T> 
	void add__matrix( const std::string& name, T**, int nx, int ny ) ;
	
	template <typename T> 
	void add__matrix__std( const std::string& name, const std::vector<std::vector<T> >& mat ) throw(std::range_error) ;
};

#endif
