# Copyright (C) 2010 - 2019  Dirk Eddelbuettel and Romain Francois
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

externalptr_address <- function(xp) {
    .Call(as_character_externalptr, xp)			# #nocov
}

# just like assignInNamespace but first checks that the binding exists
forceAssignInNamespace <- function(x, value, env) {
    is_ns <- isNamespace(env)
    unlocker <- get("unlockBinding", baseenv())
    if (is_ns && exists(x, env) && bindingIsLocked(x, env)) {
        unlocker(x, env)				# #nocov
    }
    assign(x, value, env)
    if (is_ns) {
        lockBinding(x, env)				# #nocov
    }
}

# Transform a path for passing to the build system on the command line.
# Leave paths alone for posix. For Windows, mirror the behavior of the
# R package build system by starting with the fully resolved absolute path,
# transforming it to a short path name if it contains spaces, and then
# converting backslashes to forward slashes
asBuildPath <- function(path) {

    if (.Platform$OS.type == "windows") {
        path <- normalizePath(path)			# #nocov start
        if (grepl(' ', path, fixed=TRUE))
            path <- utils::shortPathName(path)
        path <- gsub("\\\\", "/", path)			# #nocov end
    }

    return(path)
}


##' Helper function to report the package version of the R installation.
##'
##' While \code{packageVersion(Rcpp)} exports the version registers in
##' \code{DESCRIPTION}, this version does get incremented more easily
##' during development and can therefore be higher than the released
##' version.  The actual \code{#define} long used at the C++ level
##' corresponds more to an \sQuote{API Version} which is now provided
##' by this function, and use for example in the package skeleton
##' generator.
##'
##' @title Export the Rcpp (API) Package Version
##' @param devel An logical value indicating if the development or
##' release version number should be returned, default is release.
##' @return A \code{package_version} object with either the release
##' or development version.
##' @author Dirk Eddelbuettel
##' @seealso \code{\link{packageVersion}},
##' \code{\link{Rcpp.package.skeleton}}
##' @examples getRcppVersion()
getRcppVersion <- function(devel = FALSE) {
    rcpp <- .Call("getRcppVersionStrings", PACKAGE="Rcpp")
    package_version(rcpp[if(devel) 2 else 1])
}
