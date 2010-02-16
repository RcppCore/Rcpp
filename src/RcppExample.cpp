// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; -*-
//
// RcppExample.cpp: R/C++ interface class library example
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

/*
 * The following class definitions employ advanced features of the Rcpp
 * library and R, permitting the C++ programmer to call user-defined functions
 * on the R side. They should be skipped on first reading.
 */

/*
 * Define a class that can be used to call an R function that expects a
 * real vector argument and returns a scalar. The R function is defined in
 * the example section of the documentation page for RcppExample (see
 * RcppExample.Rd).
 */
class MyRVectorFunc : public RcppFunction {
public:
    MyRVectorFunc(SEXP fn) : RcppFunction(fn) {}

    // This trivial function will use an R function to compute the
    // sum of the elements of v!
    double getSum(std::vector<double>& v) {

	// Turn vector into a SEXP that can be passed to R as an argument.
	setRVector(v);

	// Call the R function that was passed in as the paramter fn, with
	// the SEXP vector that was just set as its argument.
	SEXP result = vectorCall();

	// Assuming that the R function simply returns a real number we
	// pass it back to the C++ user as follows. If the R function returns
	// something more complicated transform result into a C++ object to
	// be returned, and  clear the part of the protection stack due to
	// this object before returning (to prevent protection stack overflow).
	// Note that it is unsafe to do this if the returned result depends
	// on PROTECT-ed SEXP's. For example, result should not be 
	// wrapped in a class like RcppParams where objects hold onto the
	// the PROTECT-ed SEXP that was used to construct them.

	double value = REAL(result)[0];

	// Safe now to clear the contribution of this function to the
	// protection stack.
	clearProtectionStack();

	return value;
    }
};

/*
 * Define a class that can be used to call an R function that expects a
 * heterogeneous list argument, and returns a vector of the same length
 * with 1 added to each component (no names). The R function is defined in
 * the example section of the documentation page for RcppExample (see
 * RcppExample.Rd).
 */
class MyRListFunc : public RcppFunction {
public:
    MyRListFunc(SEXP fn) : RcppFunction(fn) {}
    std::vector<double> addOne(double alpha, double beta, double gamma) {

	// Build argument list.
	setRListSize(3);
	appendToRList("alpha", alpha);
	appendToRList("beta",  beta);
	appendToRList("gamma", gamma);

	// Call the R function passed in as fn with the list argument just
	// constructed.
	SEXP result = listCall();

	// Turn returned R vector into a C++ vector, clear protection stack,
	// and return.
	std::vector<double> vec(Rf_length(result));
	for(int i=0; i < Rf_length(result); i++)
	    vec[i] = REAL(result)[i];

	// See comments in previous class definition on the purpose of this.
	clearProtectionStack();

	return vec;
    }
};

/*
 * Sample function illustrates how to use the Rcpp R/C++ interface library.
 */
RcppExport SEXP Rcpp_Example(SEXP params, SEXP nlist, 
			     SEXP numvec, SEXP nummat,
			     SEXP df, SEXP datevec, SEXP stringvec,
			     SEXP fnvec, SEXP fnlist) {

    SEXP rl=R_NilValue; // Use this when there is nothing to be returned.
    char *exceptionMesg=NULL;

    try {

	int i=0, j=0;

	// Get parameters in params.
	RcppParams rparam(params);
	std::string method = rparam.getStringValue("method");
	double tolerance = rparam.getDoubleValue("tolerance");
	int    maxIter = rparam.getIntValue("maxIter");
	RcppDate startDate = rparam.getDateValue("startDate");

	// The output of commands like this may not appear under Windows.
	Rprintf("Parsing start date argument: %d/%d/%d\n", 
		startDate.getMonth(),
		startDate.getDay(),
		startDate.getYear());

	// QuantLib note: an RcppDate is automatically converted to QuantLib
	// Date when the context calls for this, provided 
	// USING_QUANTLIB is set.

	RcppDateVector dateVec(datevec);
	//dateVec(0) = RcppDate(12, 15, 1989); // update one element.

	RcppStringVector stringVec(stringvec);
	//stringVec(1) = string("New York"); // update one element.

	// and nl.getValue(i) to fetch data.
	RcppNumList nl(nlist);

	// numvec parameter viewed as vector of ints (with truncation).
	//RcppVector<int> vecI(numvec);

	// mat parameter viewed as matrix of ints (with truncation).
	//RcppMatrix<int> matI(nummat);

	// vec parameter viewed as vector of doubles.
	RcppVector<double> vecD(numvec);

	// mat parameter viewed as matrix of doubles.
	RcppMatrix<double> matD(nummat);

	// Do some computations with the matrices.
	int nrows = matD.getDim1();
	int ncols = matD.getDim2();
	for(i = 0; i < nrows; i++)
	    for(j = 0; j < ncols; j++)
		matD(i,j) = 2 * matD(i,j);

	int len = vecD.size();
	for(i = 0; i < len; i++)
	    vecD(i) = 3 * vecD(i);

	// Get copy of matrix/vector in standard (unchecked) C/C++ format.
	// May be useful when these vectors need to be passed to
	// C/C++ code that does not know about Rcpp classes...
	double **a = matD.cMatrix();
	double  *v = vecD.cVector();

	// ...or we might want to use an STL container...
	std::vector<double> stlvec(vecD.stlVector());
	nrows = (int)stlvec.size();
	for(i = 0; i < nrows; i++)
	    stlvec[i] += 1;

	// ...or perhaps a container of containers.
	std::vector<std::vector<double> > stlmat(matD.stlMatrix());
	nrows = (int)stlmat.size();
	ncols = (int)stlmat[0].size();
	for(i = 0; i < nrows; i++)
	    for(j = 0; j < ncols; j++)
		stlmat[i][j] += 2;

	// Get a zero matrix the same size as matD.
	//RcppMatrix<double> matZ(nrows, ncols);

	// Make a vector of strings
	std::vector<std::string> svec(2);
        svec[0] = "hello";
	svec[1] = "world";

	// Process the input data frame and show factors and dates.
	RcppFrame inframe(df);

	/*
	Rprintf("\nFactors and Dates in frame...");
	vector<vector<ColDatum> > table = inframe.getTableData();
	int nrow = table.size();
	int ncol = table[0].size();
	for(int row=0; row < nrow; row++) {
	    for(int col=0; col < ncol; col++) {
		RcppDate d;
		string name;
		int level;
		switch(table[row][col].getType()) {
		case COLTYPE_FACTOR:
		    level = table[row][col].getFactorLevel();
		    name  = table[row][col].getFactorLevelName();
		    Rprintf("Level, name: %d, %s\n",
		            level, name.c_str());
		    break;
		case COLTYPE_DATE:
		    d = table[row][col].getDateValue();
		    Rprintf("Start Date: %d/%d/%d\n", 
		            d.getMonth(),
			    d.getDay(),
			    d.getYear());
		    break;
		default:
		    ; // Ignore other types.
		}
	    }
	}
	*/

	// Make a pre-data frame, that is, a list object that when passed
	// the the R function data.frame() will return a data frame with
	// the specified column names and data types. The first row added
	// determines the types for all columns.
	int numCol=4;
	std::vector<std::string> colNames(numCol);
	colNames[0] = "alpha"; // column of strings
	colNames[1] = "beta";  // column of reals
	colNames[2] = "gamma"; // factor column
	colNames[3] = "delta"; // column of Dates
	RcppFrame frame(colNames);

	// Third column will be a factor. In the current implementation the
	// level names are copied to every factor value (and factors
	// in the same column must have the same level names). The level names
	// for a particular column will be factored out (pardon the pun) in
	// a future release.
	int numLevels = 2;
	std::string *levelNames = new std::string[2];
	levelNames[0] = std::string("pass"); // level 1
	levelNames[1] = std::string("fail"); // level 2

	// First row (this one determines column types).
	std::vector<ColDatum> row1(numCol);
	row1[0].setStringValue("a");
	row1[1].setDoubleValue(3.14);
	row1[2].setFactorValue(levelNames, numLevels, 1);
	row1[3].setDateValue(RcppDate(7,4,2006));
	frame.addRow(row1);

	// Second row.
	std::vector<ColDatum> row2(numCol);
	row2[0].setStringValue("b");
	row2[1].setDoubleValue(6.28);
	row2[2].setFactorValue(levelNames, numLevels, 1);
	row2[3].setDateValue(RcppDate(12,25,2006));
	frame.addRow(row2);

	// Done with levelNames.
	delete [] levelNames;

	// Test MyRVectorFunction defined above...
	MyRVectorFunc vfunc(fnvec);
	int n = 10;
	std::vector<double> vecInput(n);
	for(int i=0; i < n; i++)
	    vecInput[i] = i;
	double vecSum = vfunc.getSum(vecInput);
	Rprintf("Testing vector function argument: vecSum = %lf\n", vecSum);
	
	// Test MyRListFunction defined above...
	MyRListFunc lfunc(fnlist);
	double alpha=1, beta=2, gamma=3;
	std::vector<double> vecOut = lfunc.addOne(alpha, beta, gamma);
	Rprintf("Testing list function argument: %lf, %lf, %lf\n", vecOut[0], vecOut[1], vecOut[2]);

	RcppDate aDate(12, 25, 1999);

	// Build result set to be returned as a list to R.
	RcppResultSet rs;

	rs.add("date", aDate);
	rs.add("dateVec", dateVec);
	rs.add("method", method);
	rs.add("tolerance", tolerance);
	rs.add("maxIter", maxIter);
	rs.add("nlFirstName", nl.getName(0));
	rs.add("nlFirstValue", nl.getValue(0));
	rs.add("matD", matD);
	rs.add("stlvec", stlvec);
	rs.add("stlmat", stlmat);
	rs.add("a", a, nrows, ncols);
	rs.add("v", v, len);
	rs.add("stringVec", stringVec);
	rs.add("strings", svec);
	rs.add("InputDF", inframe);
	rs.add("PreDF", frame);


	// Instead of returning selected input parameters as we did in
	// the last three statements, the entire input parameter list
	// can be returned like this:
	rs.add("params", params, false);


	// Get the list to be returned to R.
	rl = rs.getReturnList();
	
    } catch(std::exception& ex) {
	exceptionMesg = copyMessageToR(ex.what());
    } catch(...) {
	exceptionMesg = copyMessageToR("unknown reason");
    }
    
    if(exceptionMesg != NULL)
	Rf_error(exceptionMesg);

    return rl;
}


RcppExport SEXP RcppParamsExample(SEXP params) {

    SEXP rl=R_NilValue; // Use this when there is nothing to be returned.
    char *exceptionMesg=NULL;

    try {

	// Get parameters in params.
	RcppParams rparam(params);
	std::string method      = rparam.getStringValue("method");
	double tolerance   = rparam.getDoubleValue("tolerance");
	int    maxIter     = rparam.getIntValue("maxIter");
	RcppDate startDate = rparam.getDateValue("startDate");
	
	Rprintf("\nIn C++, seeing the following value\n");
	Rprintf("Method argument    : %s\n", method.c_str());
	Rprintf("Tolerance argument : %f\n", tolerance);
	Rprintf("MaxIter argument   : %d\n", maxIter);
	Rprintf("Start date argument: %04d-%02d-%02d\n", 
		startDate.getYear(), startDate.getMonth(), startDate.getDay());

	// Build result set to be returned as a list to R.
	RcppResultSet rs;

	rs.add("method",    method);
	rs.add("tolerance", tolerance);
	rs.add("maxIter",   maxIter);
	rs.add("startDate", startDate);

	// Instead of returning selected input parameters as we did in
	// the last statements, the entire input parameter list can be
	// returned like this:
	rs.add("params", params, false);  // 'false' to not PROTECT params

	// Get the list to be returned to R.
	rl = rs.getReturnList();
	
    } catch(std::exception& ex) {
	exceptionMesg = copyMessageToR(ex.what());
    } catch(...) {
	exceptionMesg = copyMessageToR("unknown reason");
    }
    
    if(exceptionMesg != NULL)
	Rf_error(exceptionMesg);

    return rl;
}

RcppExport SEXP RcppDateExample(SEXP dvsexp, SEXP dtvsexp) {

    SEXP rl=R_NilValue; // Use this when there is nothing to be returned.
    char *exceptionMesg=NULL;

    try {

	RcppDateVector dv(dvsexp);
	RcppDatetimeVector dtv(dtvsexp);
	
	Rprintf("\nIn C++, seeing the following date value\n");
	for (int i=0; i<dv.size(); i++) {
	    std::cout << dv(i) << std::endl;
	    dv(i) = dv(i) + 7;		// shift a week
	}
	Rprintf("\nIn C++, seeing the following datetime value\n");
	for (int i=0; i<dtv.size(); i++) {
	    std::cout << dtv(i) << std::endl;
	    dtv(i) = dtv(i) + 0.250;    // shift 250 millisec
	}

	// Build result set to be returned as a list to R.
	RcppResultSet rs;
	rs.add("date",   dv);
	rs.add("datetime", dtv);

	// Get the list to be returned to R.
	rl = rs.getReturnList();
	
    } catch(std::exception& ex) {
	exceptionMesg = copyMessageToR(ex.what());
    } catch(...) {
	exceptionMesg = copyMessageToR("unknown reason");
    }
    
    if(exceptionMesg != NULL)
	Rf_error(exceptionMesg);

    return rl;
}

RcppExport SEXP RcppVectorExample(SEXP vector) {

    SEXP rl=R_NilValue; // Use this when there is nothing to be returned.
    char *exceptionMesg=NULL;

    try {

	// Get parameters in params.
	RcppVector<int> vec(vector);
	int n = vec.size();

	Rprintf("\nIn C++, seeing a vector of length %d\n", n);

	// create a C++ STL vector, and reserve appropriate size
	std::vector<double> res(n);
	
	for (int i=0; i<n; i++) {
	    res[i] = sqrt(static_cast<double>(vec(i)));
	}

	// Build result set to be returned as a list to R.
	RcppResultSet rs;

	rs.add("result",  res);
	rs.add("original", vec);

	// Get the list to be returned to R.
	rl = rs.getReturnList();
	
    } catch(std::exception& ex) {
	exceptionMesg = copyMessageToR(ex.what());
    } catch(...) {
	exceptionMesg = copyMessageToR("unknown reason");
    }
    
    if(exceptionMesg != NULL)
	Rf_error(exceptionMesg);

    return rl;
}

RcppExport SEXP RcppXPtrExample_create_external_pointer(){
	std::vector<int> *v = new std::vector<int> ;
	v->push_back( 1 ) ;
	v->push_back( 2 ) ;
	Rcpp::XPtr< std::vector<int> > p(v) ;
	return p ;
}

RcppExport SEXP RcppXPtrExample_get_external_pointer(SEXP x){
	Rcpp::XPtr< std::vector<int> > p(x) ;
	return Rf_ScalarInteger( p->back( ) ) ;
}


