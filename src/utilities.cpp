// utilities.cpp: Rcpp R/C++ interface class library -- attribute utilities
//
// Copyright (C) 2025 - current  Dirk Eddelbuettel
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

#define COMPILING_RCPP

#include <cmath>
#include <string>
#include <vector>
#include <Rcpp/Lighter>

// See WRE Section 6.22.6 'Working with attributes' under R 4.6.0 or later
// This function collects the names from 'tag' in a vector passed via *data
// It is used by AttributeProxyPolicy::attributeNames() in a call to R_mapAttrib
// [[Rcpp::register]]
SEXP get_attr_names(SEXP tag, SEXP attr, void* data) {
    std::vector<std::string>* vecptr = static_cast<std::vector<std::string>*>(data);
    std::string s{CHAR(Rf_asChar(tag))};
    vecptr->push_back(s);
    return NULL;
}
