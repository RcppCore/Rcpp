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

test.RcppVector.int <- function() {
    src <- 'RcppVector<int> m(x);
            RcppResultSet rs;
            rs.add("size",  m.size());
            rs.add("p2",    m(1));
            std::vector<int> v = m.stlVector();
            rs.add("v",     v);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="numeric"), src)
    checkEquals(funx(x=c(1:6)), list(size=6, p2=2, v=c(1:6)), msg="RcppVector.int")
}

test.RcppVector.double <- function() {
    src <- 'RcppVector<double> m(x);
            RcppResultSet rs;
            rs.add("size", m.size());
            rs.add("p2",   m(1));
            std::vector<double> v = m.stlVector();
            rs.add("v",     v);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="numeric"), src)
    checkEquals(funx(x=c(1:6)), list(size=6, p2=2, v=c(1:6)), msg="RcppVector.double")
}

test.RcppVector.double.na.nan <- function() {
    src <- 'RcppVector<double> m(x);
            RcppResultSet rs;
            rs.add("na_2",  R_IsNA(m(1)));
            rs.add("na_3",  R_IsNA(m(2)));
            rs.add("nan_4", R_IsNaN(m(3)));
            rs.add("nan_5", R_IsNaN(m(4)));
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="numeric"), src)
    x <- 1:6
    x[2] <- NA
    x[4] <- NaN
    checkEquals(funx(x=x),
                list(na_2=1, na_3=0, nan_4=1, nan_5=0),
                msg = "RcppMatrix.double.na.nan")
}















