library(testRcppModule)
vClass <- stdVector$vec
vec <- new(vClass)

data <- 1:10
vec$assign(data)
vec[[3]] <- vec[[3]] + 1

data[[4]] <- data[[4]] +1

stopifnot(identical(all.equal(vec$as.vector(), data), TRUE))

## a few function calls

stopifnot(all.equal(yada$bar(2), 4))

e <- tryCatch(yada$hello(), error = function(x)x)

stopifnot(is(e, "error"), all.equal(e$message, "boom"))

stopifnot(all.equal(yada$foo(2,3), 6))

## properties (at one stage this seqfaulted, so beware)
nc = NumEx$Num
nn <- new(nc)
nn$x <- pi
stopifnot(all.equal(nn$x, pi))



