// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// ModuleInitRetry.cpp: Rcpp R/C++ interface class library -- module whose
//                      initialization fails the first time only
//
// Copyright (C) 2026  Kevin Ushey
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

class ModuleInitRetry {
public:
    ModuleInitRetry() {}
    int value() { return 42; }
};

int retry_add_one(int x) {
    return x + 1;
}

static int boot_count = 0;

// registers a class and a function, then throws on the first boot only, so
// the second boot must not find what the first one registered
RCPP_MODULE(moduleInitRetry) {
    class_<ModuleInitRetry>("ModuleInitRetry")
        .constructor()
        .method("value", &ModuleInitRetry::value)
        ;
    function("retry_add_one", &retry_add_one);

    if (++boot_count == 1)
        throw std::runtime_error("first boot fails");
}
