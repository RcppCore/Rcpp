# Copyright (C) 2009 - 2025  Dirk Eddelbuettel and Romain Francois
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

.classes_map <- new.env()

.onLoad <- function(libname, pkgname){
    new_dummyObject(.dummyInstancePointer)   						# nocov start

    tools::vignetteEngine("asis", package = pkgname, pattern = "[.](pdf|html)[.]asis$",
                          weave = asisWeave, tangle = asisTangle)	# nocov end
}
