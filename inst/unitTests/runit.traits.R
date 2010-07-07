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
	
	classes <- c( "std::vector<int>", "std::list<int>", "std::deque<int>", 
		"std::set<int>", "std::map<std::string,int>", 
		"std::pair<std::string,int>", 
		"Rcpp::Symbol"
		)
	code <- lapply( classes, function(.){
			sprintf( '
			bool ok = Rcpp::traits::has_iterator< %s >::value ;
			return wrap(ok) ;
			', . )
		} )
	signatures <- rep( list(signature()), 7 )
	names( code ) <- names( signatures ) <- sprintf( "runit_has_iterator_%d", 1:7 )
	fx <- cxxfunction( signatures, code, plugin = "Rcpp" )
	
	checkTrue( fx$runit_has_iterator_1() , msg = "has_iterator< std::vector<int> >" )
	checkTrue( fx$runit_has_iterator_2() , msg = "has_iterator< std::ist<int> >" )
	checkTrue( fx$runit_has_iterator_3() , msg = "has_iterator< std::deque<int> >" )
	checkTrue( fx$runit_has_iterator_4() , msg = "has_iterator< std::set<int> >" )
	checkTrue( fx$runit_has_iterator_5() , msg = "has_iterator< std::map<string,int> >" )
	
	checkTrue( ! fx$runit_has_iterator_6(), msg = "has_iterator< std::pair<string,int> >" )
	checkTrue( ! fx$runit_has_iterator_7(), msg = "Rcpp::Symbol" )
	
}

