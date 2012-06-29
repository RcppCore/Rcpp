#!/usr/bin/r -t
#
# Copyright (C) 2011 - 2012  Dirk Eddelbuettel, Romain Francois and Jelmer Ypma
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

.runThisTest <- Sys.getenv("RunAllRcppTests") == "yes"

if (.runThisTest) {

    test.rcout <- function() {

        src <- '
        std::string tfile = as<std::string>(tmpfile);

	// define and open testfile
        std::ofstream testfile(tfile.c_str());

        // save output buffer of the Rcout stream
        std::streambuf* Rcout_buffer = Rcout.rdbuf();

        // redirect ouput into testfile
        Rcout.rdbuf( testfile.rdbuf() );

	// write a test string to the file
        Rcout << as<std::string>( teststring ) << std::endl;

        // restore old output buffer
        Rcout.rdbuf(Rcout_buffer);

	// close testfile
	testfile.close();

        return Rcpp::wrap<int>( 0 );
'

        fun <- cxxfunction(signature(tmpfile="character",
                                     teststring = "character" ),
                           includes = "#include <iostream>\n#include <fstream>",
                           body = src, plugin="Rcpp")

        ## define test string that is written to two files
        teststr <- "First line.\nSecond line."

        rcppfile <- tempfile()
        rfile <- tempfile()

        ## write to test_rcpp.txt from Rcpp
        fun(rcppfile,  teststr )

        ## write to test_r.txt from R
        cat( teststr, file=rfile, sep='\n' )

        ## compare whether the two files have the same data
        checkEquals( readLines(rcppfile), readLines(rfile), msg="Rcout output")

    }
}
