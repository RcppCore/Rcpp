// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppResultSet.h: Rcpp R/C++ interface class library -- Results back to R
//
// Copyright (C) 2005 - 2006 Dominick Samperi
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

class RcppResultSet {
public:
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
    std::list<std::pair<std::string,SEXP> > values;
};

#endif
