// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-

// This is a rewrite of the 'Writing R Extensions' section 5.10.1 example

#include <Rcpp.h>

RcppExport SEXP convolve2cpp(SEXP a, SEXP b)
{
    RcppVector<double> xa(a);
    RcppVector<double> xb(b);

    int nab = xa.size() + xb.size() - 1;

    RcppVector<double> xab(nab);
    for (int i = 0; i < nab; i++) xab(i) = 0.0;

    for (int i = 0; i < xa.size(); i++)
	for (int j = 0; j < xb.size(); j++) 
	    xab(i + j) += xa(i) * xb(j);

    RcppResultSet rs;
    rs.add("ab", xab);
    return rs.getReturnList();
}

#include "loopmacro.h"
LOOPMACRO_CPP(convolve2cpp)

