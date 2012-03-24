# Copyright (C) 2009 - 2012 Dirk Eddelbuettel and Romain Francois
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

.rcpp_cache <- NULL
cpp_exception <- function( message = "C++ exception", class = NULL, cppstack = rcpp_get_current_stack_trace() ){
    callstack <- sys.calls()
    ncalls <- length(callstack)
    call <- if( ncalls > 1L) callstack[[ ncalls - 1L ]] else match.call()
    classes <- c( class, "C++Error", "error", "condition" )
    condition <- structure(list( message = message, call = call, cppstack = cppstack ),
                           class = classes )
    setStackTrace( NULL )
    stop( condition )
}

## Dummy versions
rcpp_get_current_stack_trace <- function() "DUMMY STACK TRACE"
rcpp_set_current_stack_trace <- function(s) NULL


# used by Rcpp::Evaluator
setCurrentError <- function( condition = NULL) .Call( rcpp_set_current_error, condition )
getCurrentError <- function() .Call( rcpp_get_current_error )

setErrorOccured <- function(error_occured = TRUE) .Call( rcpp_set_error_occured, error_occured )
getErrorOccured <- function() .Call( rcpp_get_error_occured )

setStackTrace <- function(trace = TRUE) .Call( rcpp_set_stack_trace, trace )
getStackTrace <- function() .Call( rcpp_get_stack_trace)

# all below are called from Evaluator::run
# on the C++ side, don't change them unless you also change
# Evaluator::run

getCurrentErrorMessage <- function() conditionMessage( getCurrentError() )
.rcpp_error_recorder <- function(e){  
    invisible( .Call( rcpp_error_recorder, e ) )
}

# for backwards compatibility, but not used anywhere
rcpp_tryCatch <- function(expr){ 
    tryCatch(expr, error = .rcpp_error_recorder )
}

