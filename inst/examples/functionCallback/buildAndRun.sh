#!/bin/bash

# we have to let R know where the Rcpp header and library are
export PKG_CPPFLAGS=`Rscript -e "Rcpp:::CxxFlags()"`
export PKG_LIBS=`Rscript -e "Rcpp:::LdFlags()"`

# build the shared library
R CMD SHLIB RcppFunctionCallExample.cpp 

# call R so that we get an interactive session
cat ExampleRCode.r | R --slave --vanilla
