// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Timer.h: Rcpp R/C++ interface class library -- Rcpp benchmark utility
//
// Copyright (C) 2012 JJ Allaire, Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef RCPP_BENCHMARH_TIMER_H
#define RCPP_BENCHMARH_TIMER_H

#include <stdint.h>
#include <vector>
#include <string>

#define R_NO_REMAP
#include <Rinternals.h>

namespace Rcpp{

    typedef uint64_t nanotime_t;
    nanotime_t get_nanotime(void); 
    
    class Timer {
    public:
        Timer() ;
        
        void step( const std::string& ) ;
        
        operator SEXP() const ;
        
        private:
            typedef std::pair<std::string,nanotime_t> Step;
            typedef std::vector<Step> Steps;
            
            Steps data ;
            nanotime_t start_time ;
            
    } ;
    
}

#endif

