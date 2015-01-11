// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// exception.hpp: Rcpp R/C++ interface class library -- exception to stop
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

#ifndef Rcpp_exception_hpp
#define Rcpp_exception_hpp

#include <stdexcept>

void rcpp_core_set_stop(const std::exception&);

bool rcpp_core_is_stop();

void rcpp_core_get_stop();

#endif //Rcpp_exception_hpp
