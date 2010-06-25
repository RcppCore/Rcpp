// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Rcpp.h: R/C++ interface class library
//
// Copyright (C) 2005 - 2006 Dominick Samperi
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
// Copyright (C) 2009 - 2010 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_hpp
#define Rcpp_hpp

/* it is important that this comes first */
#include <RcppCommon.h>

/* classic api */
#include <RcppDate.h>
#include <RcppDateVector.h>
#include <RcppDatetime.h>
#include <RcppDatetimeVector.h>
#include <RcppFrame.h>
#include <RcppFunction.h>
#include <RcppList.h>
#include <RcppMatrix.h>
#include <RcppMatrixView.h>
#include <RcppNumList.h>
#include <RcppParams.h>
#include <RcppResultSet.h>
#include <RcppStringVector.h>
#include <RcppStringVectorView.h>
#include <RcppVector.h>
#include <RcppVectorView.h>

/* new api */
#include <Rcpp/exceptions.h>

#include <Rcpp/RObject.h>
#include <Rcpp/Named.h>

#include <Rcpp/S4.h>
#include <Rcpp/clone.h>
#include <Rcpp/grow.h>
#include <Rcpp/Dimension.h>
#include <Rcpp/Environment.h>
#include <Rcpp/Evaluator.h>
#include <Rcpp/Vector.h>
#include <Rcpp/XPtr.h>
#include <Rcpp/Symbol.h>
#include <Rcpp/Language.h>
#include <Rcpp/DottedPair.h>
#include <Rcpp/Pairlist.h>
#include <Rcpp/Function.h>
#include <Rcpp/WeakReference.h>
#include <Rcpp/StringTransformer.h>
#include <Rcpp/Formula.h>
#include <Rcpp/DataFrame.h>
#include <Rcpp/Date.h>
#include <Rcpp/DateVector.h>
#include <Rcpp/Datetime.h>
#include <Rcpp/DatetimeVector.h>

#ifdef RCPP_ENABLE_MODULES
#include <Rcpp/Module.h>
#endif

#include <Rcpp/InternalFunction.h>
#include <Rcpp/sugar/sugar.h>

#include <RcppResultSet__backward.h>

#endif
