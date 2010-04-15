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

test.RcppVectorView.int <- function() {
    src <- 'RcppVectorView<int> m(x);
            RcppResultSet rs;
            rs.add("size",  m.size());
            rs.add("p2",    m(1));
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="numeric"), src)
    checkEquals(funx(x=c(1:6)), list(size=6, p2=2), msg="RcppVectorView.int")
}

test.RcppVectorView.double <- function() {
    src <- 'RcppVectorView<double> m(x);
            RcppResultSet rs;
            rs.add("size", m.size());
            rs.add("p2",   m(1));
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="numeric"), src)
    checkEquals(funx(x=1.0*c(1:6)), list(size=6, p2=2), msg="RcppVectorView.double")
}















