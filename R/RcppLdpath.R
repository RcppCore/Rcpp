# Copyright (C) 2010 - 2021  Dirk Eddelbuettel and Romain Francois
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

## make sure system.file returns an absolute path
Rcpp.system.file <- function(...){
    tools::file_path_as_absolute( base::system.file( ..., package = "Rcpp" ) )
}

## quote path if non-standard characters are used
Rcpp.quoteNonStandard <- function(path) {
    ## On unix, check if path has only characters that do not need quoting
    noquote <- .Platform$OS.type == "unix" && grepl("^[[:alnum:]/._~+@%-]*$", path)
    ## If no quoting needed return unchanged else quote input
    if (noquote) path else shQuote(path)
}

## Use R's internal knowledge of path settings to find the lib/ directory
## plus optinally an arch-specific directory on system building multi-arch
RcppLdPath <- function() {
    #.Deprecated(msg=paste("This function is now deprecated as it has not",
    #                      "been needed since 2013."))
    ""
}

## Provide linker flags -- i.e. -L/path/to/libRcpp -- as well as an
## optional rpath call needed to tell the Linux dynamic linker about the
## location.  This is not needed on OS X where we encode this as library
## built time (see src/Makevars) or Windows where we use a static library
## Updated Jan 2010:  We now default to static linking but allow the use
##                    of rpath on Linux if static==FALSE has been chosen
##                    Note that this is probably being called from LdFlags()
## Updated Nov 2013:  We no longer build a library. This should be deprecated.
RcppLdFlags <- function() {
    #.Deprecated(msg=paste("This function is now deprecated as it has not",
    #                      "been needed since 2013."))
    ""
}

# indicates if Rcpp was compiled with GCC >= 4.3
canUseCXX0X <- function() { TRUE }  # .Call( "canUseCXX0X", PACKAGE = "Rcpp" )

## Provide compiler flags -- i.e. -I/path/to/Rcpp.h
RcppCxxFlags <- function(cxx0x=FALSE) {
    path <- Rcpp.system.file( "include" )
    if (.Platform$OS.type=="windows") {
        path <- asBuildPath(path)				# #nocov
    }
    paste0('-I', Rcpp.quoteNonStandard(path))
}

## Shorter names, and call cat() directly
## CxxFlags defaults to no using c++0x extensions are these are considered non-portable
CxxFlags <- function(cxx0x=FALSE) {
    #.Deprecated(msg=paste("This function is now deprecated as R uses minimally",
    #                      "viable compilers om all platforme."))
    cat(RcppCxxFlags(cxx0x=cxx0x))				# #nocov
}

## LdFlags defaults to static linking on the non-Linux platforms Windows and OS X
LdFlags <- function() {
    cat(RcppLdFlags())
}

# capabilities
RcppCapabilities <- capabilities <- function() .Call( rcpp_capabilities )

# compile, load and call the cxx0x.c script to identify whether
# the compiler is GCC >= 4.3
RcppCxx0xFlags <- function() {
    #.Deprecated(msg=paste("This function is now deprecated as R uses minimally",
    #                      "viable compilers om all platforme."))
    script <- Rcpp.system.file( "discovery", "cxx0x.R" )	# #nocov start
    flag <- capture.output( source( script ) )
    flag
}

Cxx0xFlags <- function() {
    cat(RcppCxx0xFlags())									# #nocov end
}
