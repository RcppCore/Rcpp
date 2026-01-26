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

## Test 1.1: Invalid File Extension
## Coverage target: R/Attributes.R:58-61
tmpfile <- tempfile(fileext = ".c")
writeLines("int main() { return 0; }", tmpfile)
expect_error(sourceCpp(tmpfile), "does not have an extension of .cc or .cpp")
unlink(tmpfile)

## Test 1.2: Filename with Spaces on Windows
## Coverage target: R/Attributes.R:64-68
if (.Platform$OS.type == "windows") {
    tmpfile <- file.path(tempdir(), "test file.cpp")
    writeLines("#include <Rcpp.h>", tmpfile)
    expect_error(sourceCpp(tmpfile), "contains spaces")
    unlink(tmpfile)
}

## Test 1.3: windowsDebugDLL on Non-Windows
## Coverage target: R/Attributes.R:70-76
if (.Platform$OS.type != "windows") {
    code <- "// [[Rcpp::export]]\nint test_fn() { return 42; }"
    expect_message(sourceCpp(code = code, windowsDebugDLL = TRUE, verbose = TRUE),
                   "windowsDebugDLL.*ignored")
}
