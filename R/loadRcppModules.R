# Copyright (C) 2010 - 2012 John Chambers, Dirk Eddelbuettel and Romain Francois
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

loadRcppModules <- function(direct=TRUE){
    ## hunt for the namespace of the package that calls this
    calls <- sys.calls()
    w <- which( sapply( calls, function(call){
        identical( call[[1L]], as.name( "runHook" ) )
    } ) )
    if( !length(w) )
        stop( "loadRcppModules can only be used within a .onLoad function" )
    w <- w[ length(w) ]
    call <- calls[[w]]
    if( !identical( call[[2L]], ".onLoad" ) )
        stop( "loadRcppModules can only be used within a .onLoad function" )
    f <- sys.frame( w )
    ns <- get("env", f )
    if( !isNamespace( ns ) )
        stop( "loadRcppModules not called from a namespace" )
    pkg <- get( "pkgname", f )
    lib <- get( "libname", f )

    ## look for declared modules in the DESCRIPTION fields
    description <- packageDescription(pkg, lib.loc=lib)
    modules <- description[["RcppModules"]]
    if( !is.null( modules ) ){
        modules <- strsplit( modules, "[[:space:]]*,[[:space:]]*")[[1L]]
        for( m in modules ){
            tryCatch( {
                mod <- Module( m, pkg, mustStart = TRUE)
                if(isTRUE(direct)){
                    populate( mod, ns )
                } else {
                    forceAssignInNamespace( m, mod, ns )
                }
                assign(.moduleMetaName(m), mod, envir = ns)
            }, error = function(e){
                stop( sprintf( "failed to load module %s from package %s\n%s", m, pkg, conditionMessage(e) ) )
            })
        }
   }
}
