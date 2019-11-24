
if (requireNamespace("tinytest", quietly=TRUE) &&
    utils::packageVersion("tinytest") >= "1.0.0") {

    ## Set a seed to make the test deterministic
    set.seed(42)

    ## R makes us to this
    Sys.setenv("R_TESTS"="")

    ## there are several more granular ways to test files in a tinytest directory,
    ## see its package vignette; tests can also run once the package is installed
    ## using the same command `test_package(pkgName)`, or by director or file
    tinytest::test_package("Rcpp", ncpu=getOption("Ncpus", 1))
}
