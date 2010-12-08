#!/usr/bin/r

suppressMessages(library(Rcpp))
suppressMessages(library(inline))

foo <- '
    IntegerVector vec(10000);     // vec parameter viewed as vector of ints.
    int i = 0;
    for (int a = 0; a < 9; a++)
      for (int b = 0; b < 9; b++)
        for (int c = 0; c < 9; c++)
          for (int d = 0; d < 9; d++)
            vec(i++) = a*b - c*d;

    return vec;
'

funx <- cxxfunction(signature(), foo, plugin = "Rcpp" )

dd.inline.rcpp <- function() {
    res <- funx()
    tabulate(res)
}

print(mean(replicate(100,system.time(dd.inline.rcpp())["elapsed"]),trim=0.05))


