// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// traits.h: Rcpp R/C++ interface class library -- support traits for vector
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

#ifndef Rcpp__vector__traits_h
#define Rcpp__vector__traits_h
 
namespace traits{

	template <int RTYPE>
	class r_vector_cache{
	public:
		typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
		typedef typename r_vector_iterator<RTYPE>::type iterator ;
		typedef typename r_vector_proxy<RTYPE>::type proxy ;
		typedef typename storage_type<RTYPE>::type storage_type ;
		
		r_vector_cache() : start(0){} ;
		void update( const VECTOR& v ) {
			start = ::Rcpp::internal::r_vector_start<RTYPE,storage_type>(v.asSexp()) ;
			RCPP_DEBUG_3( " cache<%d>::update( <%p> ), start = <%p>", RTYPE, reinterpret_cast<void*>(v.asSexp()),  reinterpret_cast<void*>(start) ) ;
		}
		inline iterator get() const { return start; }
		inline iterator get(int i) const { return start + i ; }
		
		inline proxy ref() { return *start ;}
		inline proxy ref(int i) { return start[i] ; }
		
		inline proxy ref() const { return *start ;}
		inline proxy ref(int i) const { return start[i] ; }
		
		private:
			iterator start ;
	} ;
	template <int RTYPE> class proxy_cache{
	public:
		typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
		typedef typename r_vector_iterator<RTYPE>::type iterator ;
		typedef typename r_vector_proxy<RTYPE>::type proxy ;
		
		proxy_cache(): p(0){}
		~proxy_cache(){}
		void update( const VECTOR& v ){
			p = const_cast<VECTOR*>(&v) ;
			RCPP_DEBUG_3( " cache<%d>::update( <%p> ), p = <%p>", RTYPE, reinterpret_cast<void*>(v.asSexp()),  reinterpret_cast<void*>(p) ) ;
		}
		inline iterator get() const { return iterator( proxy(*p, 0 ) ) ;}
		inline iterator get(int i) const { return iterator( proxy(*p, i ) ) ;}
		inline proxy ref() const { return proxy(*p,0) ; }
		inline proxy ref(int i) const { return proxy(*p,i);}
		
		private:
			VECTOR* p ;
	} ;
	template<> class r_vector_cache<VECSXP> : public proxy_cache<VECSXP>{
	public:
		r_vector_cache() : proxy_cache<VECSXP>(){} ;
	};
	template<> class r_vector_cache<EXPRSXP> : public proxy_cache<EXPRSXP>{
	public:
		r_vector_cache() : proxy_cache<EXPRSXP>(){} ;
	};
	template<> class r_vector_cache<STRSXP> : public proxy_cache<STRSXP>{
	public:
		r_vector_cache() : proxy_cache<STRSXP>(){} ;
	} ;
		
} // traits 

#endif
