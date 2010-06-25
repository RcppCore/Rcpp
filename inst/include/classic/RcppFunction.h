// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppFunction.h: Rcpp R/C++ interface class library -- function support
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

#ifndef RcppFunction_h
#define RcppFunction_h

#include <RcppCommon.h>
#include <classic/RcppDate.h>
#include <classic/RcppDatetime.h>

class RcppFunction {
public:
    RcppFunction(SEXP fn_);
    ~RcppFunction();
    SEXP listCall();
    SEXP vectorCall();
    void setRVector(std::vector<double>& v);
    void setRListSize(int size);
    void appendToRList(std::string name, double value);
    void appendToRList(std::string name, int value);
    void appendToRList(std::string name, std::string value);
    void appendToRList(std::string name, RcppDate& date);
    void appendToRList(std::string name, RcppDatetime& datetime);
    void clearProtectionStack();

private:
    SEXP fn, listArg, vectorArg;
    int listSize, currListPosn, numProtected;
    std::vector<std::string> names;
};

#endif
