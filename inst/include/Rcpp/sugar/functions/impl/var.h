// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// var.h: Rcpp R/C++ interface class library -- var
//
// Copyright (C) 2011 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__sugar__impl_var_h
#define Rcpp__sugar__impl_var_h

namespace Rcpp{
namespace sugar{

    template <int RTYPE, bool NA, typename T>
    typename Rcpp::traits::storage_type<RTYPE>::type Var<RTYPE,NA,T>::get() const {
		STORAGE m = mean(object).get() ;
		Minus_Vector_Primitive<RTYPE,NA,T> mm( object, m) ;
		STORAGE ssq  = sum( pow(mm,2.0) ).get() ;
	    return ssq / (object.size() - 1 ) ;
	}         
	
}
}

#endif
