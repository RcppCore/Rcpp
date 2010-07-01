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

test.RcppList <- function() {
    src <- 'RcppList l;
            l.setSize(3);
            l.append("foo", 1);
            l.append("bar", 2.0);
            l.append("biz", "xyz");
            return l.getList();';
    fun <- cxxfunction(signature(), src, plugin="Rcpp")
    checkEquals(fun(), list(foo=1L, bar=2, biz="xyz"), msg="RcppList")
}
