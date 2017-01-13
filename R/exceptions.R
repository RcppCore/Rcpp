# Copyright (C) 2009 - 2017  Dirk Eddelbuettel and Romain Francois
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

.rcpp_error_recorder <- function(e) {
    invisible(.Call(rcpp_error_recorder, e))		# #nocov
}

.warningsEnv <- new.env()
.warningsEnv$warnings <- character()

.rcpp_warning_recorder <- function(w){
    .warningsEnv$warnings <- append(.warningsEnv$warnings, w$message) 	# #nocov
    invokeRestart("muffleWarning")					# #nocov
}

.rcpp_collect_warnings <- function() {
    warnings <- .warningsEnv$warnings			# #nocov start
    .warningsEnv$warnings <- character()
    warnings						# #nocov end
}

print.Rcpp_stack_trace <- function(x, ...) {
  cat(format(x, ...))					# #nocov
}

str.Rcpp_stack_trace <- function(object, ...) {
  cat(format(object, ...))				# #nocov
}

format.Rcpp_stack_trace <- function(x, ...) {
  paste0(						# #nocov start
    if (nzchar(x$file)) paste0(x$file, ":", x$line),
    "\n  ", paste(collapse = "\n   ", seq_along(x$stack), ":", x$stack), "\n")
}							# #nocov end
