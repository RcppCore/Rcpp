
library(Rcpp)

Rcpp::sourceCpp("cpp/rcppversion.cpp")

## we take packageVersion, make it a character variable, split it by dots and turn it to ints
## note that v could now be a three or four element vector depending on what the package version is
pv <- packageVersion("Rcpp")
pvstr <- as.character(pv)
v <- as.integer(unlist(strsplit(pvstr, "\\.")))

## construct a release string from the first three elements, ie "1.0.3" from 1.0.3.1
relstr <- as.character(as.package_version(paste(v[1:3], collapse=".")))


## call C++ function returning list of six values, three each for 'release' and 'dev' version
res <- checkVersion(v)


## basic check: is the #defined version equal to the computed version (issue #1014)
expect_equal(res$cur_ver, res$def_ver, info="current computed version equal defined version")

## basic check: is the #defined string version equal to the computed string version (adjusting for rel)
expect_equal(relstr, res$def_str, info="current computed version equal defined dev string")

## additional checks if we are a dev version
if (length(v) == 4) {
    expect_equal(res$cur_dev_ver, res$def_dev_ver, info="current computed dev version greater equal defined dev version")

    ## basic check: is #defined string version equal to computed string
    expect_equal(pvstr, res$def_dev_str, info="current computed version equal defined dev string")
}
