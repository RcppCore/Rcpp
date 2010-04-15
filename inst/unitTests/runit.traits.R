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

test.has.iterator <- function(){
	
	has_iterator <- function(clazz = "std::vector<int>" ){
		code <- '
		bool ok = Rcpp::traits::has_iterator< %s >::value ;
		return wrap(ok) ;
		'
		funx <- cppfunction(signature(),sprintf( code, clazz ) )
		funx()
	}
	checkTrue( has_iterator( "std::vector<int>" ), msg = "has_iterator< std::vector<int> >" )
	checkTrue( has_iterator( "std::list<int>" ), msg = "has_iterator< std::ist<int> >" )
	checkTrue( has_iterator( "std::deque<int>" ), msg = "has_iterator< std::deque<int> >" )
	checkTrue( has_iterator( "std::set<int>" ), msg = "has_iterator< std::set<int> >" )
	checkTrue( has_iterator( "std::map<std::string,int>" ), msg = "has_iterator< std::map<string,int> >" )
	
	checkTrue( ! has_iterator( "std::pair<std::string,int>" ), msg = "has_iterator< std::pair<string,int> >" )
	checkTrue( ! has_iterator( "Rcpp::Symbol" ), msg = "Rcpp::Symbol" )
	
}

