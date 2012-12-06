// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Environment.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2012    Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_api_meat_Environment_h
#define Rcpp_api_meat_Environment_h

namespace Rcpp{ 

template <typename WRAPPABLE>
bool Environment::assign( const std::string& name, const WRAPPABLE& x) const {
    return assign( name, wrap( x ) ) ;
}

template <typename T> 
Environment::Binding::operator T() const{
    SEXP x = env.get(name) ;
    return as<T>(x) ;
}  
    
template <typename WRAPPABLE>
Environment::Binding& Environment::Binding::operator=(const WRAPPABLE& rhs){
    env.assign( name, rhs ) ;
    return *this ;
}
    
} // namespace Rcpp

#endif
