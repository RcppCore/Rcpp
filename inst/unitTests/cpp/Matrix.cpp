// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Matrix.cpp: Rcpp R/C++ interface class library -- Matrix unit tests
//
// Copyright (C) 2013 - 2014    Dirk Eddelbuettel, Romain Francois and Kevin Ushey
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

#include <Rcpp.h>
using namespace Rcpp ;

// [[Rcpp::export]]
double matrix_numeric( NumericMatrix m){
    double trace = 0.0 ;
    for( size_t i=0 ; i<4; i++){
        	trace += m(i,i) ;
    }
    return trace ;
}

// [[Rcpp::export]]
std::string matrix_character( CharacterMatrix m){
    std::string trace ;
    for( size_t i=0 ; i<4; i++){
        	trace += m(i,i) ;
    }
    return trace;
}

// [[Rcpp::export]]
List matrix_generic( GenericMatrix m){
    List output( m.ncol() ) ;
    for( size_t i=0 ; i<4; i++){
        	output[i] = m(i,i) ;
    }
    return output ;
}

// [[Rcpp::export]]
NumericMatrix matrix_opequals(SEXP x) {
  NumericMatrix xx;
  xx = NumericMatrix(x);
  return xx;
}

// [[Rcpp::export]]
IntegerMatrix matrix_integer_diag(){
    return IntegerMatrix::diag( 5, 1 ) ;
}

// [[Rcpp::export]]
CharacterMatrix matrix_character_diag(){
    return CharacterMatrix::diag( 5, "foo" ) ;
}

// [[Rcpp::export]]
NumericMatrix matrix_numeric_ctor1(){
    return NumericMatrix(3);
}

// [[Rcpp::export]]
NumericMatrix matrix_numeric_ctor2(){
    return NumericMatrix(3,3);
}

// [[Rcpp::export]]
int integer_matrix_indexing( IntegerMatrix m){
    int trace = 0.0 ;
    for( size_t i=0 ; i<4; i++){
        trace += m(i,i) ;
    }
    return trace ;
}

// [[Rcpp::export]]
IntegerVector integer_matrix_indexing_lhs( IntegerVector m ){
    for( size_t i=0 ; i<4; i++){
        m(i,i) = 2 * i ;
    }
    return m ;
}

// [[Rcpp::export]]
double runit_NumericMatrix_row( NumericMatrix m){
    NumericMatrix::Row first_row = m.row(0) ;
    return std::accumulate( first_row.begin(), first_row.end(), 0.0 ) ;
}

// [[Rcpp::export]]
std::string runit_CharacterMatrix_row( CharacterMatrix m ){
    CharacterMatrix::Row first_row = m.row(0) ;
    std::string res(
    	std::accumulate(
    		first_row.begin(), first_row.end(), std::string() ) ) ;
    return res ;
}

// [[Rcpp::export]]
IntegerVector runit_GenericMatrix_row( GenericMatrix m ){
    GenericMatrix::Row first_row = m.row(0) ;
    IntegerVector out( first_row.size() ) ;
    std::transform(
    	first_row.begin(), first_row.end(),
    	out.begin(),
    	unary_call<SEXP,int>( Function("length" ) ) ) ;
    return out ;
}

// [[Rcpp::export]]
double runit_NumericMatrix_column( NumericMatrix m ){
    NumericMatrix::Column col = m.column(0) ;
    return std::accumulate( col.begin(), col.end(), 0.0 ) ;
}

// [[Rcpp::export]]
NumericMatrix runit_NumericMatrix_cumsum( NumericMatrix input ){
    int nr = input.nrow(), nc = input.ncol() ;
    NumericMatrix output(nr, nc) ;
    NumericVector tmp( nr );
    for( int i=0; i<nc; i++){
        tmp = tmp + input.column(i) ;
        NumericMatrix::Column target( output, i ) ;
        std::copy( tmp.begin(), tmp.end(), target.begin() ) ;
    }
    return output ;
}

// [[Rcpp::export]]
std::string runit_CharacterMatrix_column( CharacterMatrix m){
    CharacterMatrix::Column col = m.column(0) ;
    std::string res(
        std::accumulate( col.begin(), col.end(), std::string() )
    ) ;
    return res ;
}

// [[Rcpp::export]]
IntegerVector runit_GenericMatrix_column( GenericMatrix m ){
    GenericMatrix::Column col = m.column(0) ;
    IntegerVector out( col.size() ) ;
    std::transform(
    	   col.begin(), col.end(),
    	   out.begin(),
    	   unary_call<SEXP,int>( Function("length" ) )
    ) ;
    return wrap(out) ;
}

// [[Rcpp::export]]
List runit_Row_Column_sugar( NumericMatrix x){
    NumericVector r0 = x.row(0) ;
    NumericVector c0 = x.column(0) ;
    return List::create(
        r0,
        c0,
        x.row(1),
        x.column(1),
        x.row(1) + x.column(1)
        ) ;
}

// [[Rcpp::export]]
NumericMatrix runit_NumericMatrix_colsum( NumericMatrix input ){
    int nc = input.ncol() ;
    NumericMatrix output = clone<NumericMatrix>( input ) ;
    for( int i=1; i<nc; i++){
       output(_,i) = output(_,i-1) + input(_,i) ;
    }
    return output ;
}

// [[Rcpp::export]]
NumericMatrix runit_NumericMatrix_rowsum( NumericMatrix input ){
    int nr = input.nrow();
    NumericMatrix output = clone<NumericMatrix>( input ) ;
    for( int i=1; i<nr; i++){
       output(i,_) = output(i-1,_) + input(i,_) ;
    }
    return output ;
}

// [[Rcpp::export]]
NumericMatrix runit_SubMatrix( ){
    NumericMatrix xx(4, 5);
    xx(0,0) = 3;
    xx(0,1) = 4;
    xx(0,2) = 5;
    xx(1,_) = xx(0,_);
    xx(_,3) = xx(_,2);
    SubMatrix<REALSXP> yy = xx( Range(0,2), Range(0,3) ) ;
    NumericMatrix res = yy ;
    return res;
}

