# Copyright (C)        2009 - 2010 Dirk Eddelbuettel and Romain Francois
#
# This file is part of Rcpp.
#
# Rcpp is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Rcpp is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

Rcpp.package.skeleton <- function(
	name = "anRpackage", list = character(), environment = .GlobalEnv,
	path = ".", force = FALSE, namespace = TRUE, 
	code_files = character(), 
	example_code = TRUE, 
	module = FALSE ){
	
	env <- parent.frame(1)
	
	if( !length(list) ){
		fake <- TRUE
		assign( "Rcpp.fake.fun", function(){}, envir = env )
		if( example_code ){
			assign( "rcpp_hello_world", function(){}, envir = env )
		}
		remove_hello_world <- TRUE
	} else {
		if( ! "rcpp_hello_world" %in% list ){
			call[["list"]] <- c( "rcpp_hello_world", call[["list"]] )
			remove_hello_world <- TRUE
		} else{
			remove_hello_world <- FALSE
		}
		fake <- FALSE
	}
	
	# first let the traditional version do its business
	call <- match.call()
	call[[1]] <- as.name("package.skeleton")
	call[["namespace"]] <- namespace
	# remove Rcpp specific arguments
	if( "example_code" %in% names( call ) ){
		call[["example_code"]] <- NULL
	}
	if( "module" %in% names( call ) ){
		call[["module"]] <- NULL
	}
	
	if( fake ){
		call[["list"]] <- c( if( isTRUE(example_code)) "rcpp_hello_world" , "Rcpp.fake.fun" )
	}
	
	tryCatch( eval( call, envir = env ), error = function(e){
		stop( "error while calling `package.skeleton`" )
	} )
	
	message( "\nAdding Rcpp settings" )
	
	# now pick things up 
	root <- file.path( path, name )
	
	# Add Rcpp to the DESCRIPTION
	DESCRIPTION <- file.path( root, "DESCRIPTION" )
	if( file.exists( DESCRIPTION ) ){
		depends <- c( 
			if( isTRUE(module) ) "methods", 
			sprintf( "Rcpp (>= %s)", packageDescription("Rcpp")[["Version"]] )
		) 
		x <- cbind( read.dcf( DESCRIPTION ), 
			"Depends" = paste( depends, collapse = ", ") , 
			"LinkingTo" = "Rcpp", 
			"SystemRequirements" = "GNU make" )
		write.dcf( x, file = DESCRIPTION )
		message( " >> added Depends: Rcpp" )
		message( " >> added LinkingTo: Rcpp" )
		message( " >> added SystemRequirements: GNU make" )
	}
	
	# if there is a NAMESPACE, add a useDynLib
	NAMESPACE <- file.path( root, "NAMESPACE")
	if( file.exists( NAMESPACE ) ){
		lines <- readLines( NAMESPACE )
		ns <- file( NAMESPACE, open = "w" )
		if( ! grepl( "useDynLib", lines ) ){
			lines <- c( sprintf( "useDynLib(%s)", name), lines)
			writeLines( lines, con = ns )
			message( " >> added useDynLib directive to NAMESPACE" )
		}
		
		if(isTRUE(module)){
			writeLines( 'importClassesFrom( Rcpp, "C++Object", "C++Class", "Module" )', ns )
		}
		close( ns )
	}
	
	# lay things out in the src directory
	src <- file.path( root, "src")
	if( !file.exists( src )){
		dir.create( src )
	}
	skeleton <- system.file( "skeleton", package = "Rcpp" )
	Makevars <- file.path( src, "Makevars" )
	if( !file.exists( Makevars ) ){
		file.copy( file.path( skeleton, "Makevars" ), Makevars )
		message( " >> added Makevars file with Rcpp settings" )
	}
	
	Makevars.win <- file.path( src, "Makevars.win" )
	if( !file.exists( Makevars.win ) ){
		file.copy( file.path( skeleton, "Makevars.win" ), Makevars.win )
		message( " >> added Makevars.win file with Rcpp settings" )
	}
		
	if( example_code ){
		header <- readLines( file.path( skeleton, "rcpp_hello_world.h" ) )
		header <- gsub( "@PKG@", name, header, fixed = TRUE )
		writeLines( header , file.path( src, "rcpp_hello_world.h" ) )
		message( " >> added example header file using Rcpp classes")
		
		file.copy( file.path( skeleton, "rcpp_hello_world.cpp" ), src )
		message( " >> added example src file using Rcpp classes")
		
		rcode <- readLines( file.path( skeleton, "rcpp_hello_world.R" ) )
		rcode <- gsub( "@PKG@", name, rcode, fixed = TRUE )
		writeLines( rcode , file.path( root, "R", "rcpp_hello_world.R" ) )
		message( " >> added example R file calling the C++ example")
		
		hello.Rd <- file.path( root, "man", "rcpp_hello_world.Rd")
		unlink( hello.Rd )
		file.copy( 
			system.file("skeleton", "rcpp_hello_world.Rd", package = "Rcpp" ), 
			hello.Rd
			)
		message( " >> added Rd file for rcpp_hello_world")
		
	}
	
	if( isTRUE( module ) ){
		file.copy( 
			system.file( "skeleton", "rcpp_module.cpp", package = "Rcpp" ), 
			file.path( root, "src" )
		)
		file.copy( 
			system.file( "skeleton", "zzz.R", package = "Rcpp" ), 
			file.path( root, "R" )
		)
		file.copy( 
			system.file( "skeleton", "yada.Rd", package = "Rcpp" ), 
			file.path( root, "man" )
		)
		message( " >> copied the example module " )
		
	}
	
	lines <- readLines( package.doc <- file.path( root, "man", sprintf( "%s-package.Rd", name ) ) )
	lines <- sub( "~~ simple examples", "%% ~~ simple examples", lines )
	writeLines( lines, package.doc )
	
	if( fake ){
		rm( "Rcpp.fake.fun", envir = env )
		unlink( file.path( root, "R"  , "Rcpp.fake.fun.R" ) )
		unlink( file.path( root, "man", "Rcpp.fake.fun.Rd" ) )
	}
	
	if( isTRUE(remove_hello_world) ){
		rm( "rcpp_hello_world", envir = env )
	}
	
	invisible( NULL )
}

