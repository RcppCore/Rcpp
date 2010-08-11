// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Generator.h: Rcpp R/C++ interface class library -- framework for random number generation
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

#ifndef Rcpp__Generator_h
#define Rcpp__Generator_h

namespace Rcpp{

template <bool seed, typename T>
class Generator{
public:
	typedef T r_generator ;
	Generator(){ GetRNGstate(); }
	~Generator(){ PutRNGstate(); }	
} ;

template <typename T>
class Generator<false,T> {
public:
	typedef T r_generator ;
	Generator(){ }
	~Generator(){ }	
} ;

class RNGScope{
public:
	RNGScope(){ GetRNGstate(); }
	~RNGScope(){ PutRNGstate(); }	
} ;


}

#endif
