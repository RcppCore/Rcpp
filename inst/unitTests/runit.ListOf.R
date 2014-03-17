# Copyright (C) 2014  Dirk Eddelbuettel, Romain Francois and Kevin Ushey
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
    
    .setUp <- Rcpp:::unitTestSetup("ListOf.cpp")
    
    x <- list( c(1, 5), c(2, 6), c(3, 7) )
    
    test.identity <- function() {
        checkIdentical(
            test_identity(setNames(x, c('a', 'b', 'c'))),
            setNames(x, c('a', 'b', 'c'))
        )
    }
    
    test.lapply.sum <- function() {
        checkIdentical( test_lapply_sum(x), lapply(x, sum) )
    }
    
    test.sapply.sum <- function() {
        checkIdentical( test_sapply_sum(x), sapply(x, sum) )
    }
    
    test.assign <- function() {
        test_assign(x, 100, "apple")
        checkIdentical( x[[2]], 100 )
    }
    
    test.assign.names <- function() {
        x <- setNames(list(1, 2, 3), c('a', 'b', 'c'))
        test_assign_names(x)
        checkIdentical( x[["a"]], x[["b"]] )
    }
    
    test.arith <- function() {
        checkIdentical(test_add(list(1, 2, 3)), 6)
        checkIdentical(test_add2(list(1, 2, 3)), list(3, 2, 3))
        checkIdentical(test_add_subtract(list(1, 2, 3)), 0)
        checkIdentical(test_mult( list(1, 2, 3) ), 6)
        checkIdentical(test_char( list("banana") ), list("apple"))
    }
    
    test.assign.names <- function() {
        checkException(test_assign_names(list(alpha=1, beta=2, gamma=3)))
    }
    
}
