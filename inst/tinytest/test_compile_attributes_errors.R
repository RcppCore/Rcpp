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

## Test 3.1: Missing DESCRIPTION File
## Coverage target: R/Attributes.R:420
tmpdir <- tempfile()
dir.create(tmpdir)
expect_error(compileAttributes(tmpdir), "must refer to the directory containing an R package")
unlink(tmpdir, recursive = TRUE)

## Test 3.2: Missing NAMESPACE File
## Coverage target: R/Attributes.R:432
tmpdir <- tempfile()
dir.create(tmpdir)
writeLines("Package: TestPkg", file.path(tmpdir, "DESCRIPTION"))
expect_error(compileAttributes(tmpdir), "must refer to the directory containing an R package")
unlink(tmpdir, recursive = TRUE)
