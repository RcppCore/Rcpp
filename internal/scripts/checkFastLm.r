#!/usr/bin/r
library(datasets)

data(trees)

firstTest <- function() {
    f1 <- lm(log(Girth) ~ log(Volume), data=trees)
    print(f1)
    print(summary(f1))

    suppressMessages(library(RcppGSL))
    f2 <- fastLm(log(Girth) ~ log(Volume), data=trees)
    print(f2)
    print(summary(f2))

    suppressMessages(library(RcppArmadillo))
    f3 <- fastLm(log(Girth) ~ log(Volume), data=trees)
    print(f3)
    print(summary(f3))
}

secondTest <- function() {
    y <- log(trees$Girth)
    X <- cbind(1, log(trees$Volume))
    colnames(X) <- c("iota", "logVol")

    f1 <- lm.fit(X, y)
    print(f1)
    #print(summary(f1))

    suppressMessages(library(RcppGSL))
    f2 <- fastLm(X, y)
    print(f2)
    print(summary(f2))

    suppressMessages(library(RcppArmadillo))
    f3 <- fastLm(X, y)
    print(f3)
    print(summary(f3))
}

firstTest()
secondTest()
