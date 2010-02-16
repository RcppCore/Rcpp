#!/bin/bash

# build the shared library for the C variant
R CMD SHLIB convolve2_c.c
R CMD SHLIB convolve7_c.c

# build the shared library for the C++ variant
# we have to let R know where the Rcpp header and library are
export PKG_CPPFLAGS=`r -e "Rcpp:::CxxFlags()"`
export PKG_LIBS=`r -e "Rcpp:::LdFlags()"`
R CMD SHLIB convolve2_cpp.cpp
R CMD SHLIB convolve3_cpp.cpp
R CMD SHLIB convolve4_cpp.cpp

# call R so that we get an interactive session
Rscript exampleRCode.r 
