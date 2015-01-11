#!/usr/bin/r -t
# -*- mode: R; tab-width: 4; -*-
#
# Copyright (C) 2015   Wush Wu
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
    
.setUp <- Rcpp:::unitTestSetup("memory.cpp")

test.memory <- function() {
  checkEquals(capture.output(testMemory1()), "deleting DeleteNotifier(1)") 
  checkEquals(capture.output(testMemory2()), "deleting DeleteNotifier(2)") 
  checkEquals(capture.output(testMemory3()), "deleting DeleteNotifier(3)") 
  checkEquals(capture.output(testMemory4()), "deleting DeleteNotifier(4)") 
  checkEquals(capture.output(testMemory5()), "deleting DeleteNotifier(5)") 
}

}
