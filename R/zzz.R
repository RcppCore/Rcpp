# Copyright (C) 2009 - 2011 Dirk Eddelbuettel and Romain Francois
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

.dummyInstancePointer <- new.env() # just something permanent

.onLoad <- function(libname, pkgname){
    ## Call to init_Rcpp_cache is not needed here as it is called in
    ## R_init_Rcpp.  Calling it twice is potentially destructive
#    .Call("init_Rcpp_cache", PACKAGE = "Rcpp" )
    minimum_svn_rev <- packageDescription( pkgname )[["MinimumSvnRev"]]
    # if( as.integer(R.version[["svn rev"]]) < as.integer(minimum_svn_rev)){
    #     packageStartupMessage(gettextf(paste("R version (%s) older than minimum required (%s)",
    #                                          "for full use of reference methods"),
    #                                    R.version[["svn rev"]], minimum_svn_rev))
    # }
    new_dummyObject(.dummyInstancePointer);
}

