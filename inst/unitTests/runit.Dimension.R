#!/usr/bin/r -t
#
# Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

test.Dimension.const <- function(){

	# from the Rcpp-devel thread
	# http://article.gmane.org/gmane.comp.lang.r.rcpp/327
	
	cdef <- '
	class simple {
	    Rcpp::Dimension dd;
	public:
	    simple(SEXP xp) : dd(xp) {}
	    int nrow() const { return dd[0]; }
	    int ncol() const { return dd[1]; }
	};
	'
	cpp <- '
	simple ss(ia);
	return wrap(ss.nrow());
	'
	ff <- cppfunction(signature(ia = "integer"), cpp,includes = cdef)
    checkEquals( ff(2L, 2L), 2L, msg = "testing const operator[]" )
	
}
