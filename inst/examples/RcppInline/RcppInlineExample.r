#!/usr/bin/r

suppressMessages(library(Rcpp))
suppressMessages(library(inline))

foo <- '
  SEXP  rl = R_NilValue;        // Use this when there is nothing to be returned.
  char* exceptionMesg = NULL;   // msg var in case of error

  try {
    RcppVector<int> vec(v);     // vec parameter viewed as vector of ints.
    int n = vec.size(), i = 0;
    if (n != 10000) throw std::length_error("Wrong vector size");
    for (int a = 0; a < 9; a++)
      for (int b = 0; b < 9; b++)
        for (int c = 0; c < 9; c++)
          for (int d = 0; d < 9; d++)
            vec(i++) = a*b - c*d;

    RcppResultSet rs;           // Build result set to be returned as a list to R.
    rs.add("vec", vec);         // vec as named element with name "vec"
    rl = rs.getReturnList();    // Get the list to be returned to R.
  } catch(std::exception& ex) {
    exceptionMesg = copyMessageToR(ex.what());
  } catch(...) {
    exceptionMesg = copyMessageToR("unknown reason");
  }

  if (exceptionMesg != NULL) Rf_error(exceptionMesg);

  return rl;
'

funx <- cfunction(signature(v="numeric"), foo, Rcpp=TRUE)

dd.inline.rcpp <- function() {
    x <- integer(10000)
    res <- funx(v=x)[[1]]
    tabulate(res)
}

print(mean(replicate(100,system.time(dd.inline.rcpp())["elapsed"]),trim=0.05))


