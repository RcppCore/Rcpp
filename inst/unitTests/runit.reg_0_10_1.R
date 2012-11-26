#!/usr/bin/r -t
#
# Copyright (C) 2012  Dirk Eddelbuettel and Romain Francois
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

.setUp <- function(){
    sourceCpp( system.file( "unitTests/cpp/reg_tests_0_10_1.cpp", package = "Rcpp" ) )   
}

test.DataFrame.nrows <- function(){
    checkEquals( DataFrame_nrows( iris ), nrow(iris) )  
}

test.RangeIndexer <- function(){
    x <- rnorm(10)
    checkEquals( RangeIndexer_sugar(x), max(x[1:5]) )    
}

test.self_match <- function(){
    x <- sample( letters, 1000, replace = TRUE )
    checkEquals( test_self_match(x), match(x,unique(x)) )    
}

test.table <- function(){
    x <- sample( letters, 1000, replace = TRUE )
    checkTrue( all( test_table(x) == table(x) ) )
    checkTrue( all( names(test_table(x)) == names(table(x)) ) )
}

test.duplicated <- function(){
    x <- sample( letters, 1000, replace = TRUE )
    checkEquals( test_duplicated(x), duplicated(x) )
}

test.setdiff <- function(){
    checkEquals( test_setdiff( 1:10, 1:5 ), setdiff( 1:10, 1:5 ) )
}
test.union <- function(){
    checkEquals( test_union( 1:10, 1:5 ), union( 1:10, 1:5 ) )
}
test.intersect <- function(){
    checkEquals( test_intersect( 1:10, 1:5 ), intersect( 1:10, 1:5 ) )
}

test.AreMacrosDefined <- function(){
    checkTrue( Rcpp:::areMacrosDefined( "__cplusplus" ) )    
}




