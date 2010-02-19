// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
/* :tabSize=4:indentSize=4:noTabs=false:folding=explicit:collapseFolds=1: */
//
// exporter.h: Rcpp R/C++ interface class library -- identify if a class has a nested iterator typedef
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
   
#ifndef Rcpp__traits__exporter__h
#define Rcpp__traits__exporter__h

namespace Rcpp{
namespace traits{

template <typename T> class Exporter{
public:
	Exporter( SEXP x ) : T(x){}
	inline T get(){ return t ; }

private:
	T t ;
} ;

template <typename T> class StdVectorExporter {
public:
	typedef typename T::value_type r_export_type ;
	
	StdVectorExporter( SEXP x ) : object(x){
		// R_PreserveObject(object) ;
	}
	~StdVectorExporter(){
		// R_ReleaseObject(object) ;
	}
	
	T get(){ 
		T vec( ::Rf_length(object) );
		::Rcpp::internal::export_range( object, vec.begin() ) ;
		return vec ;
	}
	
private:
	SEXP object ;
} ;

template <typename T> class Exporter< std::vector<T> > : public StdVectorExporter< std::vector<T> > {
	public:
		Exporter(SEXP x) : StdVectorExporter< std::vector<T> >(x){}
}; 


} // namespace traits
} // namespace Rcpp
#endif
