// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Rcpp.h: R/C++ interface class library
//
// Copyright (C) 2009 - 2010 Dirk Eddelbuettel and Romain Francois
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

#include "Rcpp.h"

// This file shows how to use an R function in a callback from C++. It
// is implemented using the 'classic Rcpp' API. A simpler alternative
// using the 'new Rcpp' API is provided in the file 'newApiExample.r'/

// Define a (file-local) class that can be used to call an R function
// that expects a real vector argument and returns a vector.
// 
// We define this class by inhereting from Rcpp's RcppFunction class
// and adding a single function 'transformVector'
//
// The R function being used is defined in the R script calling this
//
class RVectorFuncCall : public RcppFunction {
public:
    RVectorFuncCall(SEXP fn) : RcppFunction(fn) {}

    // This function uses an R function to operate on all elements of vector v
    std::vector<double> transformVector(std::vector<double>& v) {
	setRVector(v);		// Turn vector into a SEXP to be passed  to R

	// Call the R function passed in as the paramter fn, 
	// with SEXP vector that was just set as its argument.
	SEXP result = vectorCall();

	// Turn returned R vector into a C++ vector, clear protection stack, and return.
	std::vector<double> vec( RcppVector<double>(result).stlVector() );

	// Safe now to clear the contribution of this function to the protection stack.
	clearProtectionStack();
		
	return vec;
    }
};


// Standard wrapper C++ function using Rcpp interface, this function will be called from R
RcppExport SEXP RCppFunctionCallWrapper(SEXP params, SEXP numvec, SEXP fnvec) {

    SEXP  rl = R_NilValue;		// Use this when there is nothing to be returned.
    char* exceptionMesg = NULL;

    try {
	RcppParams rparam(params);	// Get parameters in params.
	int N = rparam.getIntValue("N");

	std::vector<double> vec( RcppVector<double>(numvec).stlVector());

	for (int i=0; i<N; i++) { 

	    // Test RVectorFuncCall defined above, init'ed with the supplied function
	    RVectorFuncCall vfunc(fnvec);

	    // transform vec with the R function given to vfunc
	    vec = vfunc.transformVector(vec);
			
	}
	// Build result set to be returned as a list to R.
	RcppResultSet rs;
	rs.add("vec", vec);
	
	rl = rs.getReturnList();		// Get the list to be returned to R.

    } catch(std::exception& ex) {
	exceptionMesg = copyMessageToR(ex.what());
    } catch(...) {
	exceptionMesg = copyMessageToR("unknown reason");
    }
    
    if(exceptionMesg != NULL)
	Rf_error(exceptionMesg);
  
    return rl;
}
