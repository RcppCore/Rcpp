# Copyright (C) 2010 - 2012 Dirk Eddelbuettel and Romain Francois
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

externalptr_address <- function(xp){
    .Call( as_character_externalptr, xp )
}

# just like assignInNamespace but first checks that the binding exists
forceAssignInNamespace <- function( x, value, env ){
    #if (getRversion() >= "2.15.0") {
    #    assignInMyNamespace(x, value)
    #} else {
        is_ns <- isNamespace( env )
        if( is_ns && exists( x, env ) && bindingIsLocked(x, env ) ){
            unlockBinding( x, env )
        }
        assign( x, value, env )
        if( is_ns ){
            lockBinding( x, env )
        }
    #}
}
