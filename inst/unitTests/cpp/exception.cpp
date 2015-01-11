// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// exception.cpp: Rcpp R/C++ interface class library -- exception to stop unit tests
//
// Copyright (C) 2015 Wush Wu
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#include <Rcpp.h>
using namespace Rcpp;

class DeleteNotifier : public std::exception {
  int _id;
public:
  DeleteNotifier(int id) : std::exception(), _id(id) { }
  virtual ~DeleteNotifier() throw () {
    Rprintf("deleting DeleteNotifier(%d)\n", _id);
  }
  virtual const char* what() const throw () {
    return "test notifier";
  }
};

//[[Rcpp::export]]
void testMemory1() {
  DeleteNotifier dn(1);
}

//[[Rcpp::export]]
void testMemory2() {
  try {
    DeleteNotifier dn(2);
    throw std::logic_error("test dn2");
  }
  catch(std::exception& e) {
  }
}

//[[Rcpp::export(".testMemory3")]]
void testMemory3() {
  DeleteNotifier dn(3);
  throw std::logic_error("test dn3");
}

//[[Rcpp::export(".testMemory4")]]
void testMemory4() {
  try {
    throw DeleteNotifier(4);
  }
  catch(std::exception& e) {
  }
}

//[[Rcpp::export(".testMemory5")]]
void testMemory5() {
  throw DeleteNotifier(5);
}

/*** R
testMemory3 <- function() {
  tryCatch(.testMemory3(), error = function(e) {})
  invisible(NULL)
}

testMemory4 <- function() {
  tryCatch(.testMemory4(), error = function(e) {})
  invisible(NULL)
}

testMemory5 <- function() {
  tryCatch(.testMemory5(), error = function(e) {})
  invisible(NULL)
}

*/
