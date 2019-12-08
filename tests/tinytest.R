
if (requireNamespace("tinytest", quietly=TRUE) &&
    utils::packageVersion("tinytest") >= "1.0.0") {

    ## Set a seed to make the test deterministic
    set.seed(42)

    ## R makes us to this
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
    if ((Sys.getenv("CI") == "true")     ||
        (Sys.getenv("TRAVIS") == "true") ||
        (Sys.getenv("CONTINUOUS_INTEGRATION") == "true")) {
        if (Sys.getenv("RunAllRcppTests") != "no") { 			# if env.var not yet set
            message("Always enabling \"RunAllRcppTests\"=\"yes\" on Travis\n")
            Sys.setenv("RunAllRcppTests"="yes")
        }
        if (Sys.getenv("RunVerboseRcppTests") != "no") { 		# if env.var not yet set
            message("Always enabling \"RunVerboseRcppTests\"=\"yes\" on Travis\n")
            Sys.setenv("RunVerboseRcppTests"="yes")
        }
    }

    ## there are several more granular ways to test files in a tinytest directory,
    ## see its package vignette; tests can also run once the package is installed
    ## using the same command `test_package(pkgName)`, or by director or file
    tinytest::test_package("Rcpp", ncpu=getOption("Ncpus", 1))
}
