
## Rcpp 0.11.4 Upload Notes

### R CMD check output: Known Isssues Common With Previous Releases

#### Package Size

```
* checking installed package size ... NOTE
  installed size is 12.6Mb
  sub-directories of 1Mb or more:
    doc       1.6Mb
    include   6.1Mb
    libs      3.4Mb
```

#### Foreign Function Calls

```
* checking foreign function calls ... NOTE
Registration problem:
  symbol ‘symbol’ in the local frame:
   .Call(symbol)
See chapter ‘System and foreign language interfaces’ in the ‘Writing R Extensions’ manual.
```

#### Tested Successfully

- Linux r-devel (Ubuntu 14.10)
- Linux r-release (Ubuntu 14.10)
- Linux r-release (Ubuntu 12.04, via Travis)
- Windows r-release (Winbuilder)
- Windows r-devel (Winbuilder)

#### Tests Skipped For Lack Of Platform

- OS X
- Solaris

### Reverse Dependencies

Full check against all first-level reverse depends.

Test details as usual at https://github.com/RcppCore/rcpp-logs

Test summary:

```
edd@max:~/git/rcpp-logs/results$ ./Rcpp-Summary-20150119.R 
./Rcpp-Summary-20150119.R 
Good          313 
  AsIs        311 
  w/Patches   2 
Bad           9 
  NotRcpp     7 
Skipped       2 
Total         322 
Bad Percent   0.00621118 
edd@max:~/git/rcpp-logs/results$
```






