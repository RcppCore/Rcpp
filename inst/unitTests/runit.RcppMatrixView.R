#!/usr/bin/r -t
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

test.RcppMatrixView.int <- function() {
    src <- 'RcppMatrixView<int> m(x);
            RcppResultSet rs;
            rs.add("dim1",  m.dim1());
            rs.add("dim2",  m.dim2());
            rs.add("rows",  m.rows());
            rs.add("cols",  m.cols());
            rs.add("p22",   m(1,1));
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="numeric"), src)
    checkEquals(funx(x=matrix(1:6,2,3,byrow=TRUE)),
                     list(dim1=2, dim2=3, rows=2, cols=3, p22=5),
                     msg = "RcppViewMatrix.int")
}

test.RcppMatrixView.double <- function() {
    src <- 'RcppMatrixView<double> m(x);
            RcppResultSet rs;
            rs.add("dim1",  m.dim1());
            rs.add("dim2",  m.dim2());
            rs.add("rows",  m.rows());
            rs.add("cols",  m.cols());
            rs.add("p22",   m(1,1));
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="numeric"), src)
    checkEquals(funx(x=matrix(1.0*(1:6),2,3,byrow=TRUE)),
                     list(dim1=2, dim2=3, rows=2, cols=3, p22=5),
                     msg = "RcppMatrixView.double")
}















