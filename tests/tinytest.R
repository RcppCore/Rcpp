
if (requireNamespace("tinytest", quietly=TRUE)) {

    ## Set a seed to make the test deterministic
    set.seed(42)

    ## R makes us do this (but tinytest now sets it too)
    Sys.setenv("R_TESTS"="")

    ## Force tests to be executed if in dev release which we define as
    ## having a sub-release, eg 0.9.15.5 is one whereas 0.9.16 is not
    if (length(strsplit(packageDescription("Rcpp")$Version, "\\.")[[1]]) > 3) {	# dev rel, and
        if (Sys.getenv("RunAllRcppTests") != "no") { 			# if env.var not yet set
            message("Setting \"RunAllRcppTests\"=\"yes\" for development release\n")
            Sys.setenv("RunAllRcppTests"="yes")
        }
        if (Sys.getenv("RunVerboseRcppTests") != "no") { 		# if env.var not yet set
            message("Setting \"RunVerboseRcppTests\"=\"yes\" for development release\n")
            Sys.setenv("RunVerboseRcppTests"="yes")
        }
    }

    ## On Travis also always set tests; see
    ## https://docs.travis-ci.com/user/environment-variables/#default-environment-variables
    ## GitHub Action also set CI variable; see
    ## https://docs.github.com/en/actions/reference/environment-variables
    ## And we set it in 'docker run' call
    ## Ensure Codecov runs full tests too
    if ((Sys.getenv("CI") == "true")                     ||
        (Sys.getenv("TRAVIS") == "true")                 ||
        (Sys.getenv("CONTINUOUS_INTEGRATION") == "true") ||
        (Sys.getenv("CODECOV_TOKEN") != "")) {
        if (Sys.getenv("RunAllRcppTests") != "no") { 			# if env.var not yet set
            message("Always enabling \"RunAllRcppTests\"=\"yes\" in CI\n")
            Sys.setenv("RunAllRcppTests"="yes")
        }
        if (Sys.getenv("RunVerboseRcppTests") != "no") { 		# if env.var not yet set
            message("Always enabling \"RunVerboseRcppTests\"=\"yes\" in CI\n")
            Sys.setenv("RunVerboseRcppTests"="yes")
        }
    }

    ## there are several more granular ways to test files in a tinytest directory,
    ## see its package vignette; tests can also run once the package is installed
    ## using the same command `test_package(pkgName)`, or by director or file
    tinytest::test_package("Rcpp", ncpu=getOption("Ncpus", 1))
}
