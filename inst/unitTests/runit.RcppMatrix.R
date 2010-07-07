#!/usr/bin/r -t
# -*- mode: R; tab-width: 4 -*-
#
# Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
#
# This file is part of Rcpp.
#
# Rcpp is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Rcpp is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

.setUp <- function() {

    tests <- ".Rcpp.RcppMatrix"
    if ( ! exists(tests, globalenv() )) {

        ## definition of all the functions at once
        f <- list("RcppMatrix_int"=list(
                  signature(x="numeric"),
                  'RcppMatrix<int> m(x);
		           RcppResultSet rs;
	 	           rs.add("dim1",  m.getDim1());
     		       rs.add("dim2",  m.getDim2());
        		   rs.add("rows",  m.rows());
            	   rs.add("cols",  m.cols());
            	   rs.add("p22",   m(1,1));
            	   std::vector<std::vector<int> > mm = m.stlMatrix();
            	   rs.add("m",     mm);
	    		   return rs.getReturnList();')

                  ,"RcppMatrix_double"=list(
                   signature(x="numeric"),
                   'RcppMatrix<double> m(x);
		            RcppResultSet rs;
		            rs.add("dim1",  m.getDim1());
		            rs.add("dim2",  m.getDim2());
		            rs.add("rows",  m.rows());
		            rs.add("cols",  m.cols());
		            rs.add("p22",   m(1,1));
		            std::vector<std::vector<double> > mm = m.stlMatrix();
		            rs.add("m",     mm);
					return rs.getReturnList();')

                  ,"RcppMatrix_double_na_nan"=list(
                   signature(x="numeric"),
                   'RcppMatrix<double> m(x);
		            RcppResultSet rs;
		            rs.add("na_21",  R_IsNA(m(1,0)));
		            rs.add("na_22",  R_IsNA(m(1,1)));
		            rs.add("nan_31", R_IsNaN(m(2,0)));
		            rs.add("nan_32", R_IsNaN(m(2,1)));
	    			return rs.getReturnList();')

                  ,"RcppMatrixView_int"=list(
                   signature(x="numeric"),
                   'RcppMatrixView<int> m(x);
		            RcppResultSet rs;
		            rs.add("dim1",  m.dim1());
		            rs.add("dim2",  m.dim2());
		            rs.add("rows",  m.rows());
		            rs.add("cols",  m.cols());
		            rs.add("p22",   m(1,1));
				    return rs.getReturnList();')

                  ,"RcppMatrixView_double"=list(
                   signature(x="numeric"),
                   'RcppMatrixView<double> m(x);
		            RcppResultSet rs;
		            rs.add("dim1",  m.dim1());
		            rs.add("dim2",  m.dim2());
		            rs.add("rows",  m.rows());
		            rs.add("cols",  m.cols());
		            rs.add("p22",   m(1,1));
				    return rs.getReturnList();')

                  ,"RcppVector_int"=list(
                   signature(x="numeric"),
                   'RcppVector<int> m(x);
		            RcppResultSet rs;
		            rs.add("size",  m.size());
		            rs.add("p2",    m(1));
		            std::vector<int> v = m.stlVector();
		            rs.add("v",     v);
			        return rs.getReturnList();')

                  ,"RcppVector_double"=list(
                   signature(x="numeric"),
                   'RcppVector<double> m(x);
		            RcppResultSet rs;
		            rs.add("size", m.size());
		            rs.add("p2",   m(1));
		            std::vector<double> v = m.stlVector();
		            rs.add("v",     v);
				    return rs.getReturnList();')

                  ,"RcppVector_double_na_nan"=list(
                   signature(x="numeric"),
                   'RcppVector<double> m(x);
		            RcppResultSet rs;
		            rs.add("na_2",  R_IsNA(m(1)));
		            rs.add("na_3",  R_IsNA(m(2)));
		            rs.add("nan_4", R_IsNaN(m(3)));
		            rs.add("nan_5", R_IsNaN(m(4)));
	    			return rs.getReturnList();')

                  ,"RcppVectorView_int"=list(
                   signature(x="numeric"),
                   'RcppVectorView<int> m(x);
		            RcppResultSet rs;
		            rs.add("size",  m.size());
		            rs.add("p2",    m(1));
				    return rs.getReturnList();')

                  ,"RcppVectorView_double"=list(
                   signature(x="numeric"),
                   'RcppVectorView<double> m(x);
		            RcppResultSet rs;
		            rs.add("size", m.size());
		            rs.add("p2",   m(1));
	    			return rs.getReturnList();')

                  ,"RcppStringVector_classic"=list(
                   signature(x="character"),
                   'RcppStringVector s = RcppStringVector(x);
		            RcppResultSet rs;
		            rs.add("string", s);
			        return rs.getReturnList();')

                  ,"RcppStringVector_wrap"=list(
                   signature(x="character"),
                   'RcppStringVector s = RcppStringVector(x);
			        return wrap(s);')

                  ,"RcppStringVector_begin"=list(
                   signature(x="character"),
				   'RcppStringVector s = RcppStringVector(x);
		            return wrap(*s.begin());')

                  ,"RcppStringVector_end"=list(
                   signature(x="character"),
                   'RcppStringVector s = RcppStringVector(x);
		            return wrap(s(s.size()-1));')
                   )

        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction( signatures, bodies, plugin = "Rcpp")
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}

test.RcppMatrix.int <- function() {
    funx <- .Rcpp.RcppMatrix$RcppMatrix_int
    M <- matrix(1:6, 2, 3, byrow=TRUE)
    checkEquals(funx(x=M), list(dim1=2, dim2=3, rows=2, cols=3, p22=5, m=M),
                     msg = "RcppMatrix.int")
}

test.RcppMatrix.double <- function() {
    funx <- .Rcpp.RcppMatrix$RcppMatrix_double
    M <- matrix(1:6,2,3,byrow=TRUE)
    checkEquals(funx(x=M), list(dim1=2, dim2=3, rows=2, cols=3, p22=5, m=M),
                     msg = "RcppMatrix.double")
}

test.RcppMatrix.double.na.nan <- function() {
    funx <- .Rcpp.RcppMatrix$RcppMatrix_double_na_nan
    M <- matrix(1:6,3,2,byrow=TRUE)
    M[2,1] <- NA
    M[3,1] <- NaN
    checkEquals(funx(x=M),
                list(na_21=1, na_22=0, nan_31=1, nan_32=0),
                msg = "RcppMatrix.double.na.nan")
}



test.RcppMatrixView.int <- function() {
    funx <- .Rcpp.RcppMatrix$RcppMatrixView_int
    checkEquals(funx(x=matrix(1:6,2,3,byrow=TRUE)),
                     list(dim1=2, dim2=3, rows=2, cols=3, p22=5),
                     msg = "RcppViewMatrix.int")
}

test.RcppMatrixView.double <- function() {
    funx <- .Rcpp.RcppMatrix$RcppMatrixView_double
    checkEquals(funx(x=matrix(1.0*(1:6),2,3,byrow=TRUE)),
                     list(dim1=2, dim2=3, rows=2, cols=3, p22=5),
                     msg = "RcppMatrixView.double")
}




test.RcppVector.int <- function() {
    funx <- .Rcpp.RcppMatrix$RcppVector_int
    checkEquals(funx(x=c(1:6)), list(size=6, p2=2, v=c(1:6)), msg="RcppVector.int")
}

test.RcppVector.double <- function() {
    funx <- .Rcpp.RcppMatrix$RcppVector_double
    checkEquals(funx(x=c(1:6)), list(size=6, p2=2, v=c(1:6)), msg="RcppVector.double")
}

test.RcppVector.double.na.nan <- function() {
    funx <- .Rcpp.RcppMatrix$RcppVector_double_na_nan
    x <- 1:6
    x[2] <- NA
    x[4] <- NaN
    checkEquals(funx(x=x),
                list(na_2=1, na_3=0, nan_4=1, nan_5=0),
                msg = "RcppMatrix.double.na.nan")
}



test.RcppVectorView.int <- function() {
    funx <- .Rcpp.RcppMatrix$RcppVectorView_int
    checkEquals(funx(x=c(1:6)), list(size=6, p2=2), msg="RcppVectorView.int")
}

test.RcppVectorView.double <- function() {
    funx <- .Rcpp.RcppMatrix$RcppVectorView_double
    checkEquals(funx(x=1.0*c(1:6)), list(size=6, p2=2), msg="RcppVectorView.double")
}



test.RcppStringVector.classic <- function() {
    fun <- .Rcpp.RcppMatrix$RcppStringVector_classic
    sv <- c("tic", "tac", "toe")
    checkEquals(fun(sv), list(string=sv), msg = "RcppStringVector.classic")
}

test.RcppStringVector.wrap <- function() {
    fun <- .Rcpp.RcppMatrix$RcppStringVector_wrap
    sv <- c("tic", "tac", "toe")
    checkEquals(fun(sv), sv, msg = "RcppStringVector.wrap")
}

test.RcppStringVector.begin <- function() {
    fun <- .Rcpp.RcppMatrix$RcppStringVector_begin
    sv <- c("tic", "tac", "toe")
    checkEquals(fun(sv), sv[1], msg = "RcppStringVector.begin")
}

test.RcppStringVector.end <- function() {
    fun <- .Rcpp.RcppMatrix$RcppStringVector_end
    sv <- c("tic", "tac", "toe")
    checkEquals(fun(sv), sv[3], msg = "RcppStringVector.begin")
}




