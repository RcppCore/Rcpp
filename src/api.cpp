// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// api.cpp: Rcpp R/C++ interface class library -- Rcpp api
//
// Copyright (C) 2012 - 2020  Dirk Eddelbuettel and Romain Francois
// Copyright (C) 2021         Dirk Eddelbuettel, Romain Francois and Iñaki Ucar
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

#define COMPILING_RCPP
#define RCPP_USE_GLOBAL_ROSTREAM

#include <Rcpp.h>

using namespace Rcpp;

#include "internal.h"
#include <R_ext/PrtUtil.h>

#ifdef RCPP_HAS_DEMANGLING
#include <cxxabi.h>
#endif

namespace Rcpp {
    // [[Rcpp::register]]
    Rostream<true>&  Rcpp_cout_get() {
      static Rostream<true>  Rcpp_cout;
      return Rcpp_cout;
    }
    // [[Rcpp::register]]
    Rostream<false>& Rcpp_cerr_get() {
      static Rostream<false> Rcpp_cerr;
      return Rcpp_cerr;
    }
    Rostream<true>&  Rcout = Rcpp_cout_get();
    Rostream<false>& Rcerr = Rcpp_cerr_get();

    namespace internal {

        int rngSynchronizationSuspended = 0;

        // [[Rcpp::register]]
        unsigned long enterRNGScope() {
            if (rngSynchronizationSuspended == 0)
                GetRNGstate();
            return 0;
        }

        // [[Rcpp::register]]
        unsigned long exitRNGScope() {
            if (rngSynchronizationSuspended == 0)
                PutRNGstate();
            return 0;
        }

        // [[Rcpp::register]]
        unsigned long beginSuspendRNGSynchronization() {        // #nocov start
            ++rngSynchronizationSuspended;
            return rngSynchronizationSuspended;
        }

        // [[Rcpp::register]]
        unsigned long endSuspendRNGSynchronization() {
            --rngSynchronizationSuspended;
            return rngSynchronizationSuspended;
        }                                                       // #nocov end

        // [[Rcpp::register]]
        char* get_string_buffer() {
            static char buffer[MAXELTSIZE];
            return buffer;
        }

    }

    // [[Rcpp::register]]
    const char * type2name(SEXP x) {                            // #nocov start
        switch (TYPEOF(x)) {
        case NILSXP:    return "NILSXP";
        case SYMSXP:    return "SYMSXP";
        case RAWSXP:    return "RAWSXP";
        case LISTSXP:   return "LISTSXP";
        case CLOSXP:    return "CLOSXP";
        case ENVSXP:    return "ENVSXP";
        case PROMSXP:   return "PROMSXP";
        case LANGSXP:   return "LANGSXP";
        case SPECIALSXP:    return "SPECIALSXP";
        case BUILTINSXP:    return "BUILTINSXP";
        case CHARSXP:   return "CHARSXP";
        case LGLSXP:    return "LGLSXP";
        case INTSXP:    return "INTSXP";
        case REALSXP:   return "REALSXP";
        case CPLXSXP:   return "CPLXSXP";
        case STRSXP:    return "STRSXP";
        case DOTSXP:    return "DOTSXP";
        case ANYSXP:    return "ANYSXP";
        case VECSXP:    return "VECSXP";
        case EXPRSXP:   return "EXPRSXP";
        case BCODESXP:  return "BCODESXP";
        case EXTPTRSXP: return "EXTPTRSXP";
        case WEAKREFSXP:    return "WEAKREFSXP";
        case S4SXP:     return "S4SXP";
        default:
        return "<unknown>";
        }
    }                                                           // #nocov end


} // namespace Rcpp

// [[Rcpp::register]]
std::string demangle(const std::string& name) {
    #ifdef RCPP_HAS_DEMANGLING
        std::string real_class;
        int status =-1;
        char *dem = 0;
        dem = abi::__cxa_demangle(name.c_str(), 0, 0, &status);
        if (status == 0) {
            real_class = dem;
            free(dem);
        } else {
            real_class = name;
        }
        return real_class;
    #else
        return name;
    #endif
}

// NOTE: remains registered but this routine is now effectively unused by Rcpp;
// we retain it for backwards compatibility with any existing packages which
// (explicitly or implicitly) rely on its existence. See also:
// https://github.com/RcppCore/Rcpp/issues/1066

// [[Rcpp::register]]
const char* short_file_name(const char* file) {                 // #nocov start
    static std::string f;
    f = file;
    size_t index = f.find("/include/");
    if (index != std::string::npos) {
        f = f.substr(index + 9);
    }
    return f.c_str();
}

// [[Rcpp::internal]]
SEXP as_character_externalptr(SEXP xp) {
    char buffer[20];
    snprintf(buffer, 20, "%p", (void*)R_ExternalPtrAddr(xp));
    return Rcpp::wrap((const char*)buffer);
}                                                               // #nocov end

// [[Rcpp::internal]]
SEXP rcpp_capabilities() {
    Shield<SEXP> cap(Rf_allocVector(LGLSXP, 13));
    Shield<SEXP> names(Rf_allocVector(STRSXP, 13));
    #ifdef HAS_VARIADIC_TEMPLATES
        LOGICAL(cap)[0] = TRUE;
    #else
        LOGICAL(cap)[0] = FALSE;
    #endif
    #ifdef HAS_CXX0X_INITIALIZER_LIST
        LOGICAL(cap)[1] = TRUE;
    #else
        LOGICAL(cap)[1] = FALSE;
    #endif
    /* exceptions are always supported */
    LOGICAL(cap)[2] = TRUE;

    #ifdef HAS_TR1_UNORDERED_MAP
        LOGICAL(cap)[3] = TRUE;
    #else
       LOGICAL(cap)[3] = FALSE;
    #endif

    #ifdef HAS_TR1_UNORDERED_SET
        LOGICAL(cap)[4] = TRUE;
    #else
        LOGICAL(cap)[4] = FALSE;
    #endif

    LOGICAL(cap)[5] = TRUE;

    #ifdef RCPP_HAS_DEMANGLING
        LOGICAL(cap)[6] = TRUE;
    #else
       LOGICAL(cap)[6] = FALSE;
    #endif

       LOGICAL(cap)[7] = FALSE;

    #ifdef RCPP_HAS_LONG_LONG_TYPES
        LOGICAL(cap)[8] = TRUE;
    #else
        LOGICAL(cap)[8] = FALSE;
    #endif

    #ifdef HAS_CXX0X_UNORDERED_MAP
      LOGICAL(cap)[9] = TRUE;
    #else
      LOGICAL(cap)[9] = FALSE;
    #endif

    #ifdef HAS_CXX0X_UNORDERED_SET
      LOGICAL(cap)[10] = TRUE;
    #else
      LOGICAL(cap)[10] = FALSE;
    #endif

    #ifdef RCPP_USING_CXX11
      LOGICAL(cap)[11] = TRUE;
    #else
      LOGICAL(cap)[11] = FALSE;
    #endif

    #ifdef RCPP_NEW_DATE_DATETIME_VECTORS
      LOGICAL(cap)[12] = TRUE;
    #else
      LOGICAL(cap)[12] = FALSE;
    #endif


    SET_STRING_ELT(names, 0, Rf_mkChar("variadic templates"));
    SET_STRING_ELT(names, 1, Rf_mkChar("initializer lists"));
    SET_STRING_ELT(names, 2, Rf_mkChar("exception handling"));
    SET_STRING_ELT(names, 3, Rf_mkChar("tr1 unordered maps"));
    SET_STRING_ELT(names, 4, Rf_mkChar("tr1 unordered sets"));
    SET_STRING_ELT(names, 5, Rf_mkChar("Rcpp modules"));
    SET_STRING_ELT(names, 6, Rf_mkChar("demangling"));
    SET_STRING_ELT(names, 7, Rf_mkChar("classic api"));
    SET_STRING_ELT(names, 8, Rf_mkChar("long long"));
    SET_STRING_ELT(names, 9, Rf_mkChar("C++0x unordered maps"));
    SET_STRING_ELT(names, 10, Rf_mkChar("C++0x unordered sets"));
    SET_STRING_ELT(names, 11, Rf_mkChar("Full C++11 support"));
    SET_STRING_ELT(names, 12, Rf_mkChar("new date(time) vectors"));
    Rf_setAttrib(cap, R_NamesSymbol, names);
    return cap;
}


// [[Rcpp::internal]]
SEXP rcpp_can_use_cxx0x() {                                     // #nocov start
    #if defined(HAS_VARIADIC_TEMPLATES) || defined(RCPP_USING_CXX11)
        return Rf_ScalarLogical(TRUE);
    #else
        return Rf_ScalarLogical(FALSE);
    #endif
}


// [[Rcpp::internal]]
SEXP rcpp_can_use_cxx11() {
    #if defined(RCPP_USING_CXX11)
        return Rf_ScalarLogical(TRUE);
    #else
        return Rf_ScalarLogical(FALSE);
    #endif
}


// [[Rcpp::register]]
SEXP stack_trace(const char* file, int line) {
    return R_NilValue;
}                                                               // #nocov end


// // [ [ Rcpp::register ] ]
// void print(SEXP s) {
//     Rf_PrintValue(s);           // defined in Rinternals.h
// }

// }}}


// [[Rcpp::internal]]
SEXP getRcppVersionStrings() {
    Shield<SEXP> versionstring(Rf_allocVector(STRSXP,2));
    SET_STRING_ELT(versionstring, 0, Rf_mkChar(RCPP_VERSION_STRING));
    SET_STRING_ELT(versionstring, 1, Rf_mkChar(RCPP_DEV_VERSION_STRING));
    return versionstring;
}
