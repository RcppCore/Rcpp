## Rcpp [![Build Status](https://travis-ci.org/RcppCore/Rcpp.svg)](https://travis-ci.org/RcppCore/Rcpp) [![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](http://www.gnu.org/licenses/gpl-2.0.html) [![CRAN](http://www.r-pkg.org/badges/version/Rcpp)](https://cran.r-project.org/package=Rcpp) [![Downloads](http://cranlogs.r-pkg.org/badges/Rcpp?color=brightgreen)](http://www.r-pkg.org/pkg/Rcpp) [![Coverage Status](https://codecov.io/gh/RcppCore/Rcpp/graph/badge.svg)](https://codecov.io/github/RcppCore/Rcpp?branch=master)

### Seamless R and C++ Integration

The [Rcpp package](https://cran.r-project.org/package=Rcpp) provides R functions and a C++ library
facilitating the integration of R and C++.

R data types (`SEXP`) are matched to C++ objects in a class hierarchy.  All R
types are supported (vectors, functions, environment, etc ...)  and each
type is mapped to a dedicated class. For example, numeric vectors are
represented as instances of the Rcpp::NumericVector class, environments are
represented as instances of Rcpp::Environment, functions are represented as
Rcpp::Function, etc ... 
The
[Rcpp-introduction](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-introduction.pdf)
vignette (also published as a [JSS paper](http://www.jstatsoft.org/v40/i08/)) provides a good
entry point to Rcpp as do the [Rcpp website](http://www.rcpp.org), the
[Rcpp page](http://dirk.eddelbuettel.com/code/rcpp.html) and the 
[Rcpp Gallery](http://gallery.rcpp.org). Full documentation
is provided by the [Rcpp book](http://www.rcpp.org/book/).

Conversion from C++ to R and back is driven by the templates `Rcpp::wrap` 
and `Rcpp::as` which are highly flexible and extensible, as documented
in the [Rcpp-extending](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-extending.pdf) vignette.

Rcpp also provides Rcpp modules, a framework that allows exposing 
C++ functions and classes to the R level. The [Rcpp-modules](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-modules.pdf) vignette
details the current set of features of Rcpp-modules. 

Rcpp includes a concept called Rcpp sugar that brings many R functions
into C++. Sugar takes advantage of lazy evaluation and expression templates
to achieve great performance while exposing a syntax that is much nicer
to use than the equivalent low-level loop code. The [Rcpp-sugar](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-sugar.pdf)
gives an overview of the feature.

Rcpp attributes provide a high-level syntax for declaring C++
functions as callable from R and automatically generating the code
required to invoke them.  Attributes are intended to facilitate both
interactive use of C++ within R sessions as well as to support R
package development. Attributes are built on top of Rcpp modules and
their implementation is based on previous work in the inline package.
See the [Rcpp-atttributes](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-attributes.pdf) vignettes for more details. 

### Documentation 

The package ships with nine pdf vignettes. 

Additional documentation is available via the 
[JSS paper](http://www.jstatsoft.org/v40/i08/) by Eddelbuettel and
Francois (2011, JSS) paper (corresponding to the 'intro' vignette) 
and the [book](http://www.rcpp.org/book) by Eddelbuettel (2013, Springer); 
see 'citation("Rcpp")' for details.

### Examples

The [Rcpp Gallery](http://gallery.rcpp.org) showcases over one hundred fully
documented and working examples.

A number of examples are included as are 1394 unit tests in 606 unit
test functions provide additional usage examples.

An earlier version of Rcpp, containing what we now call the 'classic Rcpp
API' was written during 2005 and 2006 by Dominick Samperi.  This code has
been factored out of Rcpp into the package RcppClassic, and it is still
available for code relying on the older interface. New development should 
always use this Rcpp package instead.

Other usage examples are provided by packages using Rcpp. As of March 2018,
there are 1309 [CRAN](https://cran.r-project.org) packages using Rcpp, a further
91 [BioConductor](http://www.bioconductor.org) packages in its current release
as well as an unknown number of GitHub, Bitbucket, R-Forge, ... repositories
using Rcpp.  All these packages provide usage examples for Rcpp.

### Installation

Released and tested versions of Rcpp are available via the
[CRAN](https://cran.r-project.org) network, and can be installed from within R via 

```R
install.packages("Rcpp")
```

To install from source, ensure you have a complete package development
environment for R as discussed in the relevant documentation; also see
questions 1.2 and 1.3 in the
[Rcpp-FAQ](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-FAQ.pdf).

### Support

The best place for questions is the
[Rcpp-devel](http://lists.r-forge.r-project.org/cgi-bin/mailman/listinfo/rcpp-devel)
mailing list hosted at R-forge.  Note that in order to keep spam down, you must
be a subscriber in order to post.  One can also consult the list archives to see
if your question has been asked before.

Another option is to use
[StackOverflow and its 'rcpp' tag](http://stackoverflow.com/questions/tagged/rcpp).
Search functionality (use `rcpp` in squared brackets as in 
[[rcpp] my question terms](https://stackoverflow.com/search?q=[rcpp]%20my%20question%20terms)
to tag the query) is very valuable as many questions have indeed been asked, and
answered, before.

The [issue tickets at the GitHub repo](https://github.com/RcppCore/Rcpp/issues)
are the primary bug reporting interface.  As with the other web resources,
previous issues can be searched as well.


### Authors

Dirk Eddelbuettel, Romain Francois, JJ Allaire, Kevin Ushey, Qiang Kou,
Nathan Russell, Doug Bates, and John Chambers 

### License

GPL (>= 2)
