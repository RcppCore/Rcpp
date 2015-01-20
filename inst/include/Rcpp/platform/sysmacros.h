// sysmacros.h: Rcpp R/C++ interface class library -- avoid sysmacros pollution
//
// Copyright (C) 2015  Dirk Eddelbuettel, Romain Francois, and Kevin Ushey
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
// along with Rcpp.  If not, see <http://www.gnu.org/Licenses/>.

#ifndef RCPP__PLATFORM__SYSMACROS_H
#define RCPP__PLATFORM__SYSMACROS_H

// include <sys/sysmacros.h>, and then remove stupid
// 'major', 'minor' and 'makedev' defines. this works
// around Rinternals.h eventually including this header
// and letting the macros leak through
#if defined(__GNUC__) && !defined(__APPLE__) && !defined(WIN32)

# ifdef major
#  define RCPP_HAS_MAJOR_MACRO
#  pragma push_macro("major")
# endif

# ifdef minor
#  define RCPP_HAS_MINOR_MACRO
#  pragma push_macro("minor")
# endif

# ifdef makedev
#  define RCPP_HAS_MAKEDEV_MACRO
#  pragma push_macro("makedev")
# endif

# include <sys/sysmacros.h>

# undef major
# undef minor
# undef makedev

# ifdef RCPP_HAS_MAJOR_MACRO
#  pragma pop_macro("major")
# endif

# ifdef RCPP_HAS_MINOR_MACRO
#  pragma pop_macro("minor")
# endif

# ifdef RCPP_HAS_MAKEDEV_MACRO
#  pragma pop_macro("makedev")
# endif

#endif

#endif /* RCPP__PLATFORM__SYSMACROS_H */
