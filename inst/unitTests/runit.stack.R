#!/usr/bin/env r
#
# Copyright (C) 2010 - 2017  Dirk Eddelbuettel and Romain Francois
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

.runThisTest <- Sys.getenv("RunAllRcppTests") == "yes"


if (.runThisTest) {

    .setUp <- Rcpp:::unitTestSetup("stack.cpp")

    test.stackUnwinds <- function() {
        # On old versions of R, Rcpp_fast_eval() falls back to Rcpp_eval() and
        # leaks on longjumps
        hasUnwind <- getRversion() >= "3.5.0"
        checkUnwound <- if (hasUnwind) checkTrue else function(x) checkTrue(!x)
        testEvalUnwind <- function(expr, indicator) {
            testFastEval(expr, parent.frame(), indicator)
        }

        # On errors - Always unwound
        unwound <- FALSE
        out <- tryCatch(testEvalUnwind(quote(stop("err")), unwound), error = identity)
        checkTrue(unwound)
        msg <- if (hasUnwind) "err" else "Evaluation error: err."
        checkIdentical(out$message, msg)

        # On interrupts - Always unwound
        unwound <- FALSE
        expr <- quote({
            repeat testSendInterrupt()
            "returned"
        })
        out <- tryCatch(testEvalUnwind(expr, unwound), interrupt = function(c) "onintr")
        checkTrue(unwound)
        checkIdentical(out, "onintr")

        # On caught conditions
        unwound <- FALSE
        expr <- quote(signalCondition(simpleCondition("cnd")))
        cnd <- tryCatch(testEvalUnwind(expr, unwound), condition = identity)
        checkTrue(inherits(cnd, "simpleCondition"))
        checkUnwound(unwound)

        # On restart jumps
        unwound <- FALSE
        expr <- quote(invokeRestart("rst"))
        out <- withRestarts(testEvalUnwind(expr, unwound), rst = function(...) "restarted")
        checkIdentical(out, "restarted")
        checkUnwound(unwound)

        # On returns
        unwound <- FALSE
        expr <- quote(signalCondition(simpleCondition(NULL)))
        out <- callCC(function(k) {
            withCallingHandlers(testEvalUnwind(expr, unwound),
                simpleCondition = function(e) k("jumped")
            )
        })
        checkIdentical(out, "jumped")
        checkUnwound(unwound)

        # On returned condition
        unwound <- FALSE
        cnd <- simpleError("foo")
        out <- tryCatch(testEvalUnwind(quote(cnd), unwound),
            error = function(c) "abort"
        )
        checkTrue(unwound)
        if (hasUnwind) {
            checkIdentical(out, cnd)
        } else {
            checkIdentical(out, "abort")
        }
    }
}
