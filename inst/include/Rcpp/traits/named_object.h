// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
/* :tabSize=4:indentSize=4:noTabs=false:folding=explicit:collapseFolds=1: */
//
// has_iterator.h: Rcpp R/C++ interface class library -- identify if a class has a nested iterator typedef
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
   
#ifndef Rcpp__traits__named_object__h
#define Rcpp__traits__named_object__h

namespace Rcpp{
namespace traits{

template <typename T> class named_object {
	public:
		named_object( const std::string& name_, const T& o_) : 
			name(name_), object(o_){} 
		const std::string& name ;
		const T& object ;
} ;
template <typename T> struct is_named : public false_type{} ;
template <typename T> struct is_named< named_object<T> >   : public true_type {} ;

} // namespace traits
} // namespace Rcpp

#endif 
