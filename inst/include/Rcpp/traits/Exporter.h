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
	Exporter( SEXP x ) : t(x){}
	inline T get(){ return t ; }

private:
	T t ;
} ;

template <typename T> class RangeExporter {
public:
	typedef typename T::value_type r_export_type ;
	
	RangeExporter( SEXP x ) : object(x){
		// R_PreserveObject(object) ;
	}
	~RangeExporter(){
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

template <typename T, typename value_type> class IndexingExporter {
public:
	typedef value_type r_export_type ;
	
	IndexingExporter( SEXP x) : object(x){}
	~IndexingExporter(){}
	
	T get(){
		T result( ::Rf_length(object) ) ;
		::Rcpp::internal::export_indexing<T,value_type>( object, result ) ;
		return result ;
	}
	
private:
	SEXP object ;
} ;

template <typename T, typename value_type> class MatrixExporter {
public:
	typedef value_type r_export_type ;
	
	MatrixExporter( SEXP x) : object(x){}
	~MatrixExporter(){}
	
	T get() throw(::Rcpp::not_a_matrix) {
		SEXP dims = PROTECT( ::Rf_getAttrib( object, R_DimSymbol ) ) ;
		if( dims == R_NilValue || ::Rf_length(dims) != 2 ){
			throw ::Rcpp::not_a_matrix() ;
		}
		int* dims_ = INTEGER(dims) ;
		T result( dims_[0], dims_[1] ) ;
		::Rcpp::internal::export_indexing<T,value_type>( object, result ) ;
		UNPROTECT(1) ;
		return result ;
	}
	
private:
	SEXP object ;
} ;


template <typename T> class Exporter< std::vector<T> > : public RangeExporter< std::vector<T> > {
	public:
		Exporter(SEXP x) : RangeExporter< std::vector<T> >(x){}
};
template <typename T> class Exporter< std::deque<T> > : public RangeExporter< std::deque<T> > {
	public:
		Exporter(SEXP x) : RangeExporter< std::deque<T> >(x){}
};
template <typename T> class Exporter< std::list<T> > : public RangeExporter< std::list<T> > {
	public:
		Exporter(SEXP x) : RangeExporter< std::list<T> >(x){}
};

} // namespace traits
} // namespace Rcpp
#endif
