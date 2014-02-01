#!/usr/bin/r -t
# -*- mode: R; tab-width: 4; -*-
#
# Copyright (C) 2012 - 2014  Dirk Eddelbuettel and Romain Francois
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

    .setUp <- Rcpp:::unitTestSetup("String.cpp")

    test.replace_all <- function(){
        checkEquals( String_replace_all("foobar", "o", "*"), "f**bar")
    }
    test.replace_first <- function(){
        checkEquals( String_replace_first("foobar", "o", "*"), "f*obar")
    }
    test.replace_last <- function(){
        checkEquals( String_replace_last("foobar", "o", "*"), "fo*bar")
    }

    test.String.sapply <- function(){
        res <- test_sapply_string( "foobar", c("o", "a" ), c("*", "!" ) )
        checkEquals( res, "f**b!r" )    
    }

    test.compare.Strings <- function(){
        res <- test_compare_Strings( "aaa", "aab" )
        target <- list( 
            "a  < b" = TRUE, 
            "a  > b" = FALSE,  
            "a == b" = FALSE,
            "a == a" = TRUE
            )
        checkEquals( res, target )
    }
    
}
