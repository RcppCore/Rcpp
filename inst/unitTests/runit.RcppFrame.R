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

test.RcppFrame <- function() {
    src <- 'std::vector<std::string> names;
            names.push_back("A");
            names.push_back("B");
            names.push_back("C");
            RcppFrame fr(names);

            std::vector<ColDatum> colDatumVector(3);
            colDatumVector[0].setDoubleValue(1.23);
            colDatumVector[1].setIntValue(42);
            colDatumVector[2].setLogicalValue(0);
            fr.addRow(colDatumVector);

            colDatumVector[0].setDoubleValue(4.56);
            colDatumVector[1].setIntValue(21);
            colDatumVector[2].setLogicalValue(1);
            fr.addRow(colDatumVector);

            RcppResultSet rs;
            rs.add("data.frame", fr);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    dframe <- data.frame(funx()[[1]]) ## needs a data.frame() call on first list elem
    checkEquals(dframe, data.frame(A=c(1.23,4.56), B=c(42,21), C=c(FALSE,TRUE)), msg = "RcppFrame")
}

