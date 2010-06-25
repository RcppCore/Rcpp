// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppFrame.cpp: Rcpp R/C++ interface class library -- data.frame support
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

#include <Rcpp.h>

ColDatum::ColDatum() : type(COLTYPE_UNKNOWN), level(0) { }

ColDatum::ColDatum(const ColDatum& datum) {
    // Need deep copy so contruction/destruction is synchronized.
    s = datum.s;
    x = datum.x;
    i = datum.i;
    type = datum.type;
    level = datum.level;
    numLevels = datum.numLevels;
    d = datum.d;
    if (type == COLTYPE_FACTOR) {
	levelNames = new std::string[numLevels];
	for (int j = 0; j < numLevels; j++)
	    levelNames[j] = datum.levelNames[j];
    }
}

ColDatum::~ColDatum() {
    if (type == COLTYPE_FACTOR) {
	// For this to work we need a deep copy when type == COLTYPE_FACTOR.
	// See the copy constructor below. It is wasteful to have
	// evey factor cell own a separate copy of levelNames, but we leave
	// the task of factoring it out (using reference counts) for
	// later.
	delete [] levelNames;
    }
}

void ColDatum::setDoubleValue(double val) { 
    x = val; 
    type = COLTYPE_DOUBLE; 
}

void ColDatum::setIntValue(int val) { 
    i = val; 
    type = COLTYPE_INT; 
}

void ColDatum::setLogicalValue(int val) { 
    if (val != 0 && val != 1)
	throw std::range_error("ColDatum::setLogicalValue: logical values must be 0/1.");
    i = val; 
    type = COLTYPE_LOGICAL; 
}

void ColDatum::setStringValue(std::string val) { 
    s = val; 
    type = COLTYPE_STRING; 
}

void ColDatum::setDateValue(RcppDate date) {
    d = date;
    type = COLTYPE_DATE;
}
 
void ColDatum::setDatetimeValue(RcppDatetime datetime) {
    x = datetime.m_d;
    type = COLTYPE_DATETIME;
}
 
void ColDatum::setFactorValue(std::string *names, int numNames, int factorLevel) {
    if (factorLevel < 1 || factorLevel > numNames)
	throw std::range_error("ColDatum::setFactorValue: factor level out of range");
    level = factorLevel;
    numLevels = numNames;
    levelNames = new std::string[numLevels];
    for (int j = 0; j < numLevels; j++)
	levelNames[j] = names[j];
    type = COLTYPE_FACTOR;
}

double ColDatum::getDoubleValue() { 
    if (type != COLTYPE_DOUBLE)
	throw std::range_error("ColDatum::getDoubleValue: wrong data type in getDoubleValue");
    return x; 
}

int ColDatum::getIntValue() { 
    if (type != COLTYPE_INT)
	throw std::range_error("ColDatum::getIntValue: wrong data type in getIntValue");
    return i; 
}

int ColDatum::getLogicalValue() { 
    if (type != COLTYPE_LOGICAL)
	throw std::range_error("ColDatum::getLogicalValue: wrong data type in getLogicalValue");
    return i; 
}

std::string ColDatum::getStringValue() { 
    if (type != COLTYPE_STRING)
	throw std::range_error("ColDatum::getStringValue: wrong data type in getStringValue");
    return s; 
}

RcppDate ColDatum::getDateValue() {
    if (type != COLTYPE_DATE)
	throw std::range_error("ColDatum::getDateValue: wrong data type in getDateValue");
    return d; 
}

double ColDatum::getDateRCode() { 
    return (double)(d.getJDN() - RcppDate::Jan1970Offset); 
}
 
RcppDatetime ColDatum::getDatetimeValue() {
    if (type != COLTYPE_DATETIME)
	throw std::range_error("ColDatum::getDatetimeValue: wrong data type in getDatetimeValue");
    return RcppDatetime(x); 
}

void ColDatum::checkFactorType() {
    if (type != COLTYPE_FACTOR)
	throw std::range_error("ColDatun::checkFactorType: wrong data type in getFactor...");
}

int ColDatum::getFactorNumLevels() { 
    checkFactorType(); 
    return numLevels; 
}

int ColDatum::getFactorLevel() { 
    checkFactorType(); 
    return level; 
}

std::string *ColDatum::getFactorLevelNames() { 
    checkFactorType(); 
    return levelNames; 
}

std::string ColDatum::getFactorLevelName() { 
    checkFactorType(); 
    return levelNames[level-1];
}

RcppFrame::RcppFrame(std::vector<std::string> colNames_) : colNames(colNames_) {
    if (colNames.size() == 0)
	throw std::range_error("RcppFrame::RcppFrame: zero length colNames");
}

RcppFrame::RcppFrame(SEXP df) {
    if (!Rf_isNewList(df))
	throw std::range_error("RcppFrame::RcppFrame: invalid data frame.");
    int ncol = Rf_length(df);
    SEXP names = Rf_getAttrib(df, R_NamesSymbol);
    colNames.resize(ncol);
    SEXP colData = VECTOR_ELT(df,0); // First column of data.
    int nrow = Rf_length(colData);
    if (nrow == 0)
	throw std::range_error("RcppFrame::RcppFrame: zero lenth column.");

    // Allocate storage for table.
    table.resize(nrow);
    for (int r = 0; r < nrow; r++)
	table[r].resize(ncol);
    
    for (int i=0; i < ncol; i++) {
	colNames[i] = std::string(CHAR(STRING_ELT(names,i)));
	SEXP colData = VECTOR_ELT(df,i);
	if (!Rf_isVector(colData) || Rf_length(colData) != nrow)
	    throw std::range_error("RcppFrame::RcppFrame: invalid column.");

	// Check for Date class. Currently R stores the date ordinal in a
	// real value. We check for Date under both Real and Integer values
	// as insurance against future changes.
	bool isDateClass = false;
	SEXP classname = Rf_getAttrib(colData, R_ClassSymbol);
	if (classname != R_NilValue)
	    isDateClass = (strcmp(CHAR(STRING_ELT(classname,0)),"Date") == 0);

	if (Rf_isReal(colData)) {
	    if (isDateClass) {
		for (int j=0; j < nrow; j++) // Column of Date's
		    table[j][i].setDateValue(RcppDate((int)REAL(colData)[j]));
	    }
	    else // Column of REAL's
		for (int j=0; j < nrow; j++)
		    table[j][i].setDoubleValue(REAL(colData)[j]);
	}
	else if (Rf_isInteger(colData)) {
	    if (isDateClass) {
		for (int j=0; j < nrow; j++) // Column of Date's
		    table[j][i].setDateValue(RcppDate(INTEGER(colData)[j]));
	    }
	    else
		for (int j=0; j < nrow; j++)
		    table[j][i].setIntValue(INTEGER(colData)[j]);
	}
	else if (Rf_isString(colData)) { // Non-factor string column
	    for (int j=0; j < nrow; j++)
		table[j][i].setStringValue(std::string(CHAR(STRING_ELT(colData,j))));
	}
	else if (Rf_isFactor(colData)) { // Factor column.
	    SEXP names = Rf_getAttrib(colData, R_LevelsSymbol);
	    int numLevels = Rf_length(names);
	    std::string *levelNames = new std::string[numLevels];
	    for (int k=0; k < numLevels; k++)
		levelNames[k] = std::string(CHAR(STRING_ELT(names,k)));
	    for (int j=0; j < nrow; j++)
		table[j][i].setFactorValue(levelNames, numLevels,
					   INTEGER(colData)[j]);
	    delete [] levelNames;
	}
	else if (Rf_isLogical(colData)) {
	    for (int j=0; j < nrow; j++) {
		table[j][i].setLogicalValue(INTEGER(colData)[j]);
	    }
	}
	else
	    throw std::range_error("RcppFrame::RcppFrame: unsupported data frame column type.");
    }
}

std::vector<std::string>& RcppFrame::getColNames() { 
    return colNames; 
}

std::vector<std::vector<ColDatum> >& RcppFrame::getTableData() { 
    return table; 
}

void RcppFrame::addRow(std::vector<ColDatum> rowData) {
    if (rowData.size() != colNames.size())
	throw std::range_error("RcppFrame::addRow: incorrect row length.");
    if (table.size() > 0) {

	// First row added determines column types. Check for consistency
	// for rows after the first...
	for (int i = 0; i < (int)colNames.size(); i++) {
	    if (rowData[i].getType() != table[0][i].getType()) {
		std::ostringstream oss;
		oss << "RcppFrame::addRow: incorrect data type at posn "
		    << i;
		throw std::range_error(oss.str());
	    }
	}
    }
    table.push_back(rowData);
}

int RcppFrame::rows() { 
    return table.size(); 
}

int RcppFrame::cols() { 
    return table[0].size(); 
}

namespace Rcpp{
namespace internal {
	inline SEXP factor_levels( std::string* names, int nlevels){
		return Rcpp::wrap( names, names + nlevels ) ;
	}
}
	template <> SEXP wrap<RcppFrame>( const RcppFrame& frame){
		
		int numProtected = 0 ;
	    std::vector<std::string> colNames = const_cast<RcppFrame&>(frame).getColNames();
	    std::vector<std::vector<ColDatum> > table = const_cast<RcppFrame&>(frame).getTableData();
	    int ncol = colNames.size();
	    int nrow = table.size();
	    int levels = 0 ;
	    SEXP value = R_NilValue ;
		
	    Rcpp::List rl( ncol ) ;
	    Rcpp::CharacterVector nm( ncol ) ;
	    
	    for (int i=0; i < ncol; i++) { 
			numProtected = 0 ;
			
			switch( table[0][i].getType() ){
			case COLTYPE_DOUBLE :
				{
				value = PROTECT(Rf_allocVector(REALSXP,nrow));
			    numProtected++;
			    double* p = REAL(value);
			    for (int j=0; j < nrow; j++,p++)
				p[j] = table[j][i].getDoubleValue();
				break ;
				}
			case COLTYPE_INT:
				{
				value = PROTECT(Rf_allocVector(INTSXP,nrow));
			    numProtected++;
			    int* p = INTEGER(value) ;
			    for (int j=0; j < nrow; j++,p++)
				INTEGER(value)[j] = table[j][i].getIntValue();
				break ;
				}
			case COLTYPE_FACTOR:
				{
				value = PROTECT(Rf_allocVector(INTSXP,nrow));
			    numProtected++;
			    levels = table[0][i].getFactorNumLevels();
			    int* p = INTEGER(value) ;
			    for (int j=0; j < nrow; j++,p++) {
				int level = table[j][i].getFactorLevel();
				p[j] = level;
			    }
			    Rf_setAttrib(value, R_LevelsSymbol, 
			    	internal::factor_levels( 
			    		table[0][i].getFactorLevelNames(), levels)
			    	);
			    Rf_setAttrib(value, R_ClassSymbol, Rf_mkString("factor") );
			    break ;
			    }
			case COLTYPE_STRING:
				{
			    value = PROTECT(Rf_allocVector(STRSXP,nrow));
			    numProtected++;
			    for (int j=0; j < nrow; j++) {
				SET_STRING_ELT(value, j, Rf_mkChar(table[j][i].getStringValue().c_str()));
			    }
			    break;
			    }
			case COLTYPE_LOGICAL:
				{
				value = PROTECT(Rf_allocVector(LGLSXP,nrow));
			    numProtected++;
			    int* p = LOGICAL(value) ;
			    for (int j=0; j < nrow; j++) {
				p[j] = table[j][i].getLogicalValue();
			    }
			    break;
			    }
			case COLTYPE_DATE:  
				{
			    value = PROTECT(Rf_allocVector(REALSXP,nrow));
			    numProtected++;
			    double* p = REAL(value) ;
			    for (int j=0; j < nrow; j++)
				p[j] = table[j][i].getDateRCode();
			    Rf_setAttrib(value, R_ClassSymbol, Rf_mkString("Date"));
			    break; 
			    }
			case COLTYPE_DATETIME:
				{
			    value = PROTECT(Rf_allocVector(REALSXP,nrow));
			    numProtected++;
			    double* p = REAL(value) ;
			    for (int j=0; j < nrow; j++) {
				// we could access the seconds as the internal double via getDouble but it's
				// more proper to use the proper accessor (and if we ever added code ...)
				p[j] = table[j][i].getDatetimeValue().getFractionalTimestamp();
			    }
			    Rf_setAttrib(value, R_ClassSymbol, Rcpp::internal::getPosixClasses() );
			    break; 
			    }
			default:
				// throw std::range_error("RcppResultSet::add invalid column type");
				break ;
				
			}
			rl[ i ] = value ;
			nm[ i ] = colNames[i] ;
			UNPROTECT( numProtected ) ;
		} 
		rl.names() = nm ;
	    return rl ;			
	}
}	

