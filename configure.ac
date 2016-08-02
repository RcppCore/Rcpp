## -*- mode: autoconf; autoconf-indentation: 4; -*-
##
##  Rcpp configure.ac
##
##  Rcpp initial install compiler check
##
##  Copyright (C) 2016 Dirk Eddelbuettel
##
##  Licensed under GPL-2 or later

## require at least autoconf 2.61
AC_PREREQ(2.61)

## Process this file with autoconf to produce a configure script.
AC_INIT(Rcpp, m4_esyscmd_s([awk -e '/^Version:/ {print $2}' DESCRIPTION]))

## Set R_HOME, respecting an environment variable if one is set 
: ${R_HOME=$(R RHOME)}
if test -z "${R_HOME}"; then
    AC_MSG_ERROR([Could not determine R_HOME.])   
fi

## Use R to set CXX and CXXFLAGS
CXX=$(${R_HOME}/bin/R CMD config CXX)
CXXFLAGS=$("${R_HOME}/bin/R" CMD config CXXFLAGS)

## We are using C++
AC_LANG(C++)
AC_REQUIRE_CPP

## Check the C++ compiler using the CXX value set
AC_PROG_CXX

## If it is g++, we have GXX set so let's examine it
if test "${GXX}" = "yes"; then
    AC_MSG_CHECKING([whether g++ version is sufficient])
    gxx_version=$(${CXX} -v 2>&1 | awk '/^.*g.. version/ {print $3}')
    case ${gxx_version} in
        1.*|2.*|3.*|4.0.*|4.1.*|4.2.*|4.3.*|4.4.*|4.5.*)
             AC_MSG_RESULT([no])
	     AC_MSG_WARN([GCC Compiler Version <= 4.6.2 ...])
        ;;
	4.6.*|4.7.*|4.8.*|4.9.*|5.*|6.*)
	     gxx_newer_than_45="-fpermissive"
             AC_MSG_RESULT([(${gxx_version}) yes.])
	;;
    *)
	     AC_MSG_RESULT([detected compiler is g++ compatible...])
    ;;
    esac
fi
