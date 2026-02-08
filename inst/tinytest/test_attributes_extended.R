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

Rcpp::sourceCpp("cpp/attributes_extended.cpp")

## Test named exports
expect_equal(custom_exported_name(), 123)
expect_equal(another.custom.name(), "dotted name")

## Test unnamed export parameter
expect_equal(my_custom_name(), 456)

## Test RNG parameters
expect_equal(test_rng_lowercase_true(), 789)
expect_equal(test_rng_uppercase_true(), 101)
expect_equal(test_rng_lowercase_false(), 202)

## Test invisible parameters (should return invisibly)
result1 <- withVisible(test_invisible_lowercase_true())
expect_false(result1$visible)

result2 <- withVisible(test_invisible_uppercase_true())
expect_false(result2$visible)

## Test C++ name conversion (dots to underscores)
expect_equal(test.with.dots(), 999)
