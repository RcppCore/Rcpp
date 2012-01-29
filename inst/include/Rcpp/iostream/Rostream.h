// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Rostream.h: Rcpp R/C++ interface class library -- output stream
//
// Copyright (C) 2011           Dirk Eddelbuettel, Romain Francois and Jelmer Ypma
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

#ifndef __ROSTREAM_H__
#define __ROSTREAM_H__

#include <iomanip>				// USES setw

#include <Rcpp.h>

// modified from 
// http://stackoverflow.com/questions/243696/correctly-over-loading-a-stringbuf-to-replace-cout-in-a-matlab-mex-file

namespace Rcpp {

    class Rostream : public std::ostream {
        
    protected:
        Rstreambuf buf;
	
    public:
        Rostream();
    };
    
    // declare global variable
    extern Rostream Rcout;

    // template <int RTYPE> std::ostream& operator<<(std::ostream& out, const Rcpp::Vector< RTYPE >& v) {
    //     out << "[1] " << v[0];
    //     for (int i=1;i<v.size();i++) {
    //         out << " " << v[i];
    //     }
    //     return out;  // for multiple << operators.
    // }

    // template <int RTYPE> std::ostream& operator<<(std::ostream& out, const Rcpp::Matrix< RTYPE >& m) {
    //     // width of columns showing values
    //     int val_col_width = 12;
	
    //     // width of first column, showing row index
    //     int max_row_idx = m.rows() + 1;
    //     int idx_col_width = 0;
    //     while(max_row_idx > 0) {
    //         max_row_idx /= 10;
    //         idx_col_width++;
    //     }
	
    //     // print column headers (add 1 to have R indexing)
    //     out << std::setw( val_col_width + idx_col_width + 3 ) << "[,1]";
    //     for (int jcol=1;jcol<m.ncol();jcol++) {
    //         out << std::setw( val_col_width-2 ) << "[," << jcol+1 << "]";
    //     }
    //     out << std::endl;
    //     for (int irow=0;irow<m.nrow();irow++) {
    //         // print row header (add 1 to have R indexing)
    //         out << "[" << std::setw( idx_col_width ) << irow+1 << ",]";
	
    //         // print values in current row
    //         for (int jcol=0;jcol<m.ncol();jcol++) {
    //             out << std::setw( val_col_width ) << m( irow, jcol );
    //         }
    //         out << std::endl;
    //     }
    //     return out;  // for multiple << operators.
    // }

}

#endif
