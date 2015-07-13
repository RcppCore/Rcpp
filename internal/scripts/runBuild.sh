#!/bin/sh
#
# Rebuilds all vignettes
# Builds tarball
# Runs checks based on tarball
# Copies tarball in place for Debian package builds from SVN dir
# Copies tarball to web directory too

set -e 
set -u 

progname=`basename $0`
options='lnh?'
 
usage_and_exit()
{
    echo ""
    echo "Usage: $progname [-n] [-?|-h]"
    echo "  Run build and tests for Rcpp package"
    echo ""
    echo "Options:"
    echo "  -n,-l    no copy, only local build tests"
    echo "  -h       show this help"
    echo ""
    exit 0
}

copy=1
while getopts "$options" i 
do 
    case "$i" in
	n)
	    copy=0
	    shift
	    ;;
	l)
	    copy=0
	    shift
	    ;;
	h|?)
	    usage_and_exit
	    ;;
    esac
done

if [ ! -d Rcpp ]; then
    echo "Not above Rcpp/"
    exit -1
fi

version=$(r -e'cat(as.character(read.dcf("Rcpp/DESCRIPTION")[,"Version"]))')
encodedversion=$(grep RCPP_VERSION Rcpp/inst/include/Rcpp/config.h | awk '{print $3}')
echo "Working on:  $encodedversion -- $version"

#export RCPP_CXX0X="yes"
export RCPP_CXX0X="no"

export RunAllRcppTests="yes"

## remove old pdf vignettes and make fresh ones -- no longer needed with vignette scheme
## cd Rcpp/inst/doc && make pdfclean && make pdfall && cd - 

R CMD build --force Rcpp

R CMD check --as-cran Rcpp_${version}.tar.gz

if [ ${copy} -eq 1 ]; then
    test -d tarballs   && cp -vax Rcpp_${version}.tar.gz tarballs/rcpp_${version}.orig.tar.gz
    test -d build-area && cp -vax Rcpp_${version}.tar.gz build-area/rcpp_${version}.orig.tar.gz
    test -d ~/www/code/rcpp && cp -vax Rcpp_${version}.tar.gz ~/www/code/rcpp
fi

echo "Done with $encodedversion -- $version"
