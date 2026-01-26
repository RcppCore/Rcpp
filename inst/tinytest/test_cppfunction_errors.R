##  Copyright (C) 2026  Dirk Eddelbuettel
##
##  This file is part of Rcpp.
##
##  Rcpp is free software: you can redistribute it and/or modify it
##  under the terms of the GNU General Public License as published by
##  the Free Software Foundation, either version 2 of the License, or
##  (at your option) any later version.
##
##  Rcpp is distributed in the hope that it will be useful, but
##  WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU General Public License for more details.
##
##  You should have received a copy of the GNU General Public License
##  along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

if (Sys.getenv("RunAllRcppTests") != "yes") exit_file("Set 'RunAllRcppTests' to 'yes' to run.")

## Test 2.1: No Function Definition
## Coverage target: R/Attributes.R:326
code <- "int x = 5;" # No function, just a variable
expect_error(cppFunction(code), "No function definition found")

## Test 2.2: Multiple Function Definitions
## Coverage target: R/Attributes.R:328
code <- "
// [[Rcpp::export]]
int foo() { return 1; }

// [[Rcpp::export]]
int bar() { return 2; }
"
## compilation dies sooner so we never actually see the messages
expect_error(cppFunction(code)) #, "More than one function definition")
