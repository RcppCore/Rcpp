

cook <- function( 
	dist = "norm", 
	params = list( 
		mu = list( type = "double", default = "0.0" ),
		sigma = list( type = "double", default = "1.0" ) 
	), 
	input = c("double", "integer"), 
	output = sprintf("Rcpp/inst/include/Rcpp/stats/%s.h", dist)
	){

	input <- match.arg( input )	
	
	udist <- dist
	substring( udist, 1, 1 ) <- toupper( substring( udist, 1, 1 ) )
	
	param_def  <- paste( sapply(params, "[[", "type"), " ", names(params), "; ", sep = "" )
	param_def  <- paste( param_def, collapse = "" )

	param_decl <- paste( sapply(params, "[[", "type"), " ", names(params), "_" , sep = "" )
	for( i in seq_along(params) ){
		if( "default" %in% names(params[[i]]) ){
			param_decl[i] <- paste( param_decl[i], " = ", params[[i]][["default"]], sep = "" )
		}
	}
	param_decl <- paste( param_decl, collapse = ", " )
	
	param_init <- paste( names(params), "(", names(params), "_)", sep = "" )
	param_init <- paste( param_init, collapse = ", ")
	
	param_list  <- paste( names(params), collapse = ", " )
	param_ulist <- paste( paste( names(params), "_", sep = "" ),  collapse = ", " )
	
	
code <- '
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// auto generated file (from script/stats.R) 
//
// __DIST__.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2010 Douglas Bates, Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__stats____DIST___h
#define Rcpp__stats____DIST___h

namespace Rcpp {
namespace stats {

	template <bool NA, typename T>
	class D__UDIST__ : public Rcpp::VectorBase< REALSXP, NA, D__UDIST__<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		D__UDIST__( const VEC_TYPE& vec_, __PARAM_DECL__ , bool log_ = false ) : 
			vec(vec_), __PARAM_INIT__ , log(log_) {}
		
		inline double operator[]( int i) const {
			return ::d__DIST__( vec[i], __PARAM_LIST__ , log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		__PARAM_DEF__
		int log;
	
	};

	template <bool NA, typename T>
	class P__UDIST__ : public Rcpp::VectorBase< REALSXP, NA, P__UDIST__<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		P__UDIST__( const VEC_TYPE& vec_, __PARAM_DECL__ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), __PARAM_INIT__ , lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::p__DIST__( vec[i], __PARAM_LIST__, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		__PARAM_DEF__
		int lower, log;
	
	};

	template <bool NA, typename T>
	class Q__UDIST__ : public Rcpp::VectorBase< REALSXP, NA, Q__UDIST__<NA,T> >{
	public:
		typedef typename Rcpp::VectorBase<REALSXP,NA,T> VEC_TYPE;
	
		Q__UDIST__( const VEC_TYPE& vec_, __PARAM_DECL__ ,
			   bool lower_tail = true, bool log_ = false ) : 
			vec(vec_), __PARAM_INIT__, lower(lower_tail), log(log_) {}
		
		inline double operator[]( int i) const {
			return ::q__DIST__( vec[i], __PARAM_LIST__, lower, log );
		}
		
		inline int size() const { return vec.size(); }
		
	private:
		const VEC_TYPE& vec;
		__PARAM_DEF__
		int lower, log;
	
	};
	
} // stats

template <bool NA, typename T>
inline stats::D__UDIST__<NA,T> d__DIST__( const VectorBase<REALSXP,NA,T>& x, __PARAM_DECL__, bool log = false ) {
	return stats::D__UDIST__<NA,T>( x, __PARAM_ULIST__, log ); 
}

template <bool NA, typename T>
inline stats::P__UDIST__<NA,T> p__DIST__( const VectorBase<REALSXP,NA,T>& x, __PARAM_DECL__, bool lower = true, bool log = false ) {
	return stats::P__UDIST__<NA,T>( x, __PARAM_ULIST__, lower, log ); 
}

template <bool NA, typename T>
inline stats::Q__UDIST__<NA,T> q__DIST__( const VectorBase<REALSXP,NA,T>& x, __PARAM_DECL__, bool lower = true, bool log = false ) {
	return stats::Q__UDIST__<NA,T>( x, __PARAM_ULIST__, lower, log ); 
}
	
} // Rcpp

#endif
'
code <- gsub( "__DIST__" , dist, code, fixed = TRUE )
code <- gsub( "__UDIST__", udist, code, fixed = TRUE )
code <- gsub( "__PARAM_INIT__", param_init, code, fixed = TRUE )
code <- gsub( "__PARAM_LIST__", param_list, code, fixed = TRUE )
code <- gsub( "__PARAM_ULIST__", param_ulist, code, fixed = TRUE )
code <- gsub( "__PARAM_DECL__", param_decl, code, fixed = TRUE )
code <- gsub( "__PARAM_DEF__", param_def, code, fixed = TRUE )

writeLines( code, output )

}

# cook( "unif", params = list( 
# 	"min" = list( type = "double", default = "0.0" ), 
# 	"max" = list( type = "double", default = "1.0" )
# 	) )
#                                   
# cook( "gamma", params = list( 
# 	"shape" = list( type = "double" ), 
# 	"scale" = list( type = "double", default = "1.0" )
# 	) )
# 
# cook( "chisq", params = list( 
# 	"df" = list( type = "double" ) 
# 	) )
#
# cook( "lnorm", params = list( 
#	"meanlog" = list( type = "double", default = "0.0" ), 
#	"sdlog" = list( type = "double", default = "1.0" )
#	) )
# 
# cook( "weibull", params = list(
# 		"shape" = list( type = "double" ), 
# 		"scale" = list( type = "double", default = "1.0" )
#  	)  )
# 
# cook( "logis", params = list(
# 		"location" = list( type = "double", default = "0.0" ), 
# 		"scale" = list( type = "double", default = "1.0" )
#  	)  )
# 
# cook( "f", params = list(
# 	"df1" = list( type = "double" ), 
# 	"df2" = list( type = "double" )
#  	)  )
#

# # manual editing needed so that the dexp, qexp, etc ...
# # are parameterized by shape instead of rate
# cook( "exp", params = list( 
# 	"rate" = list( type = "double", default = "1.0" )
# ) )
# 

# cook( "cauchy", params = list( 
# 	"location" = list( type = "double", default = "0.0" ), 
# 	"scale" = list( type = "double", default = "1.0" )
# ) )

# cook( "geom", params = list( 
# 	prob = list( type = "double" ) 
# 	) )

# cook( "hyper", params = list( 
# 	mm = list( type = "double" ), 
# 	nn = list( type = "double" ),
# 	kk = list( type = "double" )
# 	) )

# cook( "nt", params = list(
# 	"df" = list( type = "double" ), 
# 	"ncp" = list( type = "double" )
# ) )

# cook( "nchisq", params = list(
# 	"df" = list( type = "double" ), 
# 	"ncp" = list( type = "double" )                  
# ) )
 
# cook( "nbeta", params = list( 
# 	"shape1" = list( type = "double" ), 
# 	"shape2" = list( type = "double" ), 
# 	"ncp" = list( type = "double" ) 
# ) )

# cook( "nf", params = list(
# 	"df1" = list( type = "double" ), 
# 	"df2" = list( type = "double" ), 
# 	"ncp" = list( type = "double" )
#  	)  )

# cook( "nbinom", params = list(
# 	"size" = list( type = "int" ),
# 	"prob" = list( type = "double" )
#  	)  )
# 
# cook( "nbinom_mu", params = list(
# 	"size" = list( type = "int" ),
# 	"mu"   = list( type = "double" )
#  	)  )

