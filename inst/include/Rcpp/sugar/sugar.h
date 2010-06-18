// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// sugar.h: Rcpp R/C++ interface class library -- main file for Rcpp::sugar
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
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

#ifndef RCPP_SUGAR_H
#define RCPP_SUGAR_H

// functions
#include <Rcpp/sugar/any.h>
#include <Rcpp/sugar/all.h>
#include <Rcpp/sugar/is_na.h>
#include <Rcpp/sugar/seq_along.h>

// binary operators
#include <Rcpp/sugar/Comparator.h>
#include <Rcpp/sugar/Comparator_With_One_Value.h>
#include <Rcpp/sugar/logical_operators.h>
#include <Rcpp/sugar/plus.h>
#include <Rcpp/sugar/minus.h>
#include <Rcpp/sugar/times.h>
#include <Rcpp/sugar/divides.h>

// unary operators
#include <Rcpp/sugar/not.h>

#endif
