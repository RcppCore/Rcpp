// sets.h: Rcpp R/C++ interface class library --
//
// Copyright (C) 2012 - 2025  Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__sugar__sets_h
#define Rcpp__sugar__sets_h

namespace std {
    template<>
    struct hash<Rcpp::String> {
        std::size_t operator()(const Rcpp::String& key) const {
            return pointer_hasher( key.get_sexp() ) ;
        }
        hash<SEXP> pointer_hasher ;
    };
}

#endif
