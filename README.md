Rcpp: Seamless R and C++ Integration
====================================

[![Build Status](https://travis-ci.org/RcppCore/Rcpp.png)](https://travis-ci.org/RcppCore/Rcpp)

The [Rcpp package](http://cran.r-project.org/package=Rcpp) provides R functions as well as a C++ library
which facilitate the integration of R and C++

R data types (`SEXP`) are matched to C++ objects in a class hierarchy.  All R
types are supported (vectors, functions, environment, etc ...)  and each
type is mapped to a dedicated class. For example, numeric vectors are
represented as instances of the Rcpp::NumericVector class, environments are
represented as instances of Rcpp::Environment, functions are represented as
Rcpp::Function, etc ... 
The
[Rcpp-introduction](http://cran.r-project.org/web/packages/Rcpp/vignettes/Rcpp-introduction.pdf)
vignette (also published as a [JSS paper](http://www.jstatsoft.org/v40/i08/)) provides a good
entry point to Rcpp as do the [Rcpp website](http://www.rcpp.org), the
[Rcpp page](http://dirk.eddelbuettel.com/code/rcpp.html) and the 
[Rcpp Gallery](http://gallery.rcpp.org). Full documentation
is provided by the [Rcpp book](http://www.rcpp.org/book/).

Conversion from C++ to R and back is driven by the templates `Rcpp::wrap` 
and `Rcpp::as` which are highly flexible and extensible, as documented
in the [Rcpp-extending](http://cran.r-project.org/web/packages/Rcpp/vignettes/Rcpp-extending.pdf) vignette.

Rcpp also provides Rcpp modules, a framework that allows exposing 
C++ functions and classes to the R level. The [Rcpp-modules](http://cran.r-project.org/web/packages/Rcpp/vignettes/Rcpp-modules.pdf) vignette
details the current set of features of Rcpp-modules. 

Rcpp includes a concept called Rcpp sugar that brings many R functions
into C++. Sugar takes advantage of lazy evaluation and expression templates
to achieve great performance while exposing a syntax that is much nicer
to use than the equivalent low-level loop code. The [Rcpp-sugar](http://cran.r-project.org/web/packages/Rcpp/vignettes/Rcpp-sugar.pdf)
gives an overview of the feature.

Rcpp attributes provide a high-level syntax for declaring C++
functions as callable from R and automatically generating the code
required to invoke them.  Attributes are intended to facilitate both
interactive use of C++ within R sessions as well as to support R
package development. Attributes are built on top of Rcpp modules and
their implementation is based on previous work in the inline package.
See the [Rcpp-atttributes](http://cran.r-project.org/web/packages/Rcpp/vignettes/Rcpp-attributes.pdf) vignettes for more details. 

## Documentation 

The package ships with nine pdf vignettes. 

Additional documentation is available via the 
[JSS paper](http://www.jstatsoft.org/v40/i08/) by Eddelbuettel and
Francois (2011, JSS) paper (corresponding to the 'intro' vignette) 
and the [book](http://www.rcpp.org/book) by Eddelbuettel (2013, Springer); 
see 'citation("Rcpp")' for details.

## Examples

The [Rcpp Gallery](http://gallery.rcpp.org) showcases over 70 fully documented 
and working examples. 

A number of examples are included as are over 800 unit tests in over 400 unit
test functions provide additional usage examples.  

The [CRAN](http://cran.r-project.org) network contains 
(as over early 2014) over 160 packages which also provide usage examples.  

An earlier version of Rcpp, containing what we now call the 'classic Rcpp
API' was written during 2005 and 2006 by Dominick Samperi.  This code has
been factored out of Rcpp into the package RcppClassic, and it is still
available for code relying on the older interface. New development should 
always use this Rcpp package instead.

## Installation

Released and tested versions of Rcpp are available via the
[CRAN](http://cran.r-project.org) network, and can be installed from within R via 

```R
install.packages("Rcpp")
```

To install from source, ensure you have a 
[complete package development environment](http://www.rstudio.com/ide/docs/packages/prerequisites). 
Also see questions 1.2 and 1.3 in the [Rcpp-FAQ](http://cran.r-project.org/web/packages/Rcpp/vignettes/Rcpp-FAQ.pdf).

## Authors

Dirk Eddelbuettel, Romain Francois, JJ Allaire, Doug Bates, John Chamber and
Kevin Ushey

## License

GPL (>= 2)
