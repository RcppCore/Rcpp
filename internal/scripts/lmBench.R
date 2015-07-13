#!/usr/bin/r

suppressMessages({
    library(utils)
    library(methods)
    library(RcppEigen)
    library(RcppArmadillo)
    library(RcppGSL)
    library(rbenchmark)
})

set.seed(1)
N <- 100
p <- 9
mm <- cbind(1, matrix(rnorm(N * p), nc = p))
y <- rnorm(N)
res <- benchmark(RRchol = .Call("fastLmChol2", mm, y, PACKAGE="RcppEigen"),
                 NRchol = .Call("fastLmChol1", mm, y, PACKAGE="RcppEigen"),
                 NReigen = .Call("fastLmBench", mm, y, PACKAGE="RcppEigen"),
                 RReigen = .Call("fastLm", mm, y, PACKAGE="RcppEigen"),
                 NRarma = .Call("fastLm", mm, y, PACKAGE="RcppArmadillo"),
                 lmFit = lm.fit(mm, y),
                 NRGSL = .Call("fastLm", mm, y, PACKAGE="RcppGSL"),
                 columns=c("test", "elapsed", "relative", "user.self", "sys.self"),
                 order="elapsed",
                 replications=1000)
print(res)
