// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// classic.cpp: Rcpp R/C++ interface class library -- classic api bootstrap
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

#include <deprecation.h>
#ifndef RCPP_NO_CLASSIC_API

#include "deprecated/copyMessageToR.cpp"
#include "deprecated/RcppDate.cpp"
#include "deprecated/RcppDateVector.cpp"
#include "deprecated/RcppDatetime.cpp"
#include "deprecated/RcppDatetimeVector.cpp"
#include "deprecated/RcppFrame.cpp"
#include "deprecated/RcppFunction.cpp"
#include "deprecated/RcppList.cpp"
#include "deprecated/RcppNumList.cpp"
#include "deprecated/RcppParams.cpp"
#include "deprecated/RcppResultSet.cpp"
#include "deprecated/RcppStringVector.cpp"
#include "deprecated/RcppStringVectorView.cpp"

#else
// silencing the compiler
void classic_api_dummy(){}
#endif

