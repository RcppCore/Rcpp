// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppFrame.h: Rcpp R/C++ interface class library -- data.framee support
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

#ifndef RcppFrame_h
#define RcppFrame_h

#include <RcppCommon.h>
#include <RcppDate.h>
#include <RcppDatetime.h>

enum ColType {			// Supported data frame column types.
    COLTYPE_DOUBLE, COLTYPE_INT, COLTYPE_STRING,
    COLTYPE_FACTOR, COLTYPE_LOGICAL, 
    COLTYPE_DATE, COLTYPE_DATETIME,
    COLTYPE_UNKNOWN = -1
};
class ColDatum;			// forward declaration, see below

class RcppFrame {
    std::vector<std::string> colNames;
    std::vector<std::vector<ColDatum> >  table; // table[row][col]

public:
    RcppFrame(SEXP df); // Construct from R data frame.
    RcppFrame(std::vector<std::string> colNames);
    std::vector<std::string>& getColNames();
    std::vector<std::vector<ColDatum> >& getTableData();
    void addRow(std::vector<ColDatum> rowData);
    int rows();
    int cols();
};

class ColDatum {
public:
    ColDatum();  
    ColDatum(const ColDatum& datum); 
    ~ColDatum(); 

    ColType getType() const { return type; }
    void setDoubleValue(double val);
    void setIntValue(int val);
    void setLogicalValue(int val);
    void setStringValue(std::string val);
    void setDateValue(RcppDate date);
    void setDatetimeValue(RcppDatetime datetime);
    void setFactorValue(std::string *names, int numNames, int factorLevel);

    double getDoubleValue();
    int getIntValue();
    int getLogicalValue();
    std::string getStringValue();
    RcppDate getDateValue();
    double getDateRCode();
    RcppDatetime getDatetimeValue();
    void checkFactorType();
    int getFactorNumLevels();
    int getFactorLevel();
    std::string *getFactorLevelNames();
    std::string getFactorLevelName();
    
private:
    ColType type;
    std::string s;
    double x;			// used for double and datetime
    int i; 			// used for int and logical
    int level; 			// factor level
    int numLevels; 		// number of levels for this factor
    std::string *levelNames; 	// level name = levelNames[level-1]
    RcppDate d;
};

namespace Rcpp{
	// defined in RcppFrame__backward.h
	template <> SEXP wrap<RcppFrame>( const RcppFrame& x) ;
}

#endif
