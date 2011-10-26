// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Rostream.h: Rcpp R/C++ interface class library -- stream buffer
//
// Copyright (C) 2011           Dirk Eddelbuettel, Romain Francois and Jelmer Ypma
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

#include <RcppCommon.h>
#include <Rcpp/iostream/Rstreambuf.h>

std::streamsize Rcpp::Rstreambuf::xsputn(const char *s, std::streamsize num ) {
    Rprintf( "%.*s", num, s );
    return num;
}

int Rcpp::Rstreambuf::overflow(int c ) {
    if (c != EOF) {
        Rprintf( "%.1s", &c );
    }
    return c;
}
