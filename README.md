## Rcpp: Seamless R and C++ Integration

[![Build Status](https://travis-ci.org/RcppCore/Rcpp.svg)](https://travis-ci.org/RcppCore/Rcpp)
[![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](https://www.gnu.org/licenses/gpl-2.0.html)
[![CRAN](https://www.r-pkg.org/badges/version/Rcpp)](https://cran.r-project.org/package=Rcpp)
[![Dependencies](https://tinyverse.netlify.com/badge/Rcpp)](https://cran.r-project.org/package=Rcpp)
[![Coverage Status](https://codecov.io/gh/RcppCore/Rcpp/graph/badge.svg)](https://codecov.io/github/RcppCore/Rcpp?branch=master)
[![Debian package](https://img.shields.io/debian/v/r-cran-rcpp/sid?color=brightgreen)](https://packages.debian.org/sid/r-cran-rcpp)
[![Last Commit](https://img.shields.io/github/last-commit/RcppCore/Rcpp)](https://github.com/RcppCore/Rcpp)
[![Downloads](https://cranlogs.r-pkg.org/badges/Rcpp?color=brightgreen)](https://www.r-pkg.org/pkg/Rcpp)
[![CRAN use](https://jangorecki.gitlab.io/rdeps/Rcpp/CRAN_usage.svg?sanitize=true)](https://cran.r-project.org/package=Rcpp)
[![CRAN indirect](https://jangorecki.gitlab.io/rdeps/Rcpp/indirect_usage.svg?sanitize=true)](https://cran.r-project.org/package=Rcpp)
[![BioConductor use](https://jangorecki.gitlab.io/rdeps/Rcpp/BioC_usage.svg?sanitize=true)](https://cran.r-project.org/package=Rcpp)
[![StackOverflow](https://img.shields.io/badge/stackoverflow-rcpp-orange.svg)](https://stackoverflow.com/questions/tagged/rcpp)
[![JSS](https://img.shields.io/badge/JSS-10.18637%2Fjss.v040.i08-brightgreen)](https://dx.doi.org/10.18637/jss.v040.i08)
[![Springer useR!](https://img.shields.io/badge/Springer%20useR!-10.1007%2F978--1--4614--6868--4-brightgreen)](https://www.springer.com/gp/book/9781461468677)
[![TAS](https://img.shields.io/badge/TAS-10.1080%2F00031305.2017.1375990-brightgreen)](https://dx.doi.org/10.1080/00031305.2017.1375990)

### Synopsis

The [Rcpp package](https://cran.r-project.org/package=Rcpp) integrates R and C++ via R functions and a (header-only) C++ library.

All underlying R types and objects, _i.e._, everything a `SEXP` represents internally
in R, are matched to corresponding C++ objects. This covers anything from vectors,
matrices or lists to environments, functions and more. Each `SEXP` variant is
automatically mapped to a dedicated C++ class. For example, numeric vectors are
represented as instances of the `Rcpp::NumericVector` class, environments are
represented as instances of `Rcpp::Environment`, functions are represented as
`Rcpp::Function`, etc ...  The
[Rcpp-introduction](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-introduction.pdf)
vignette (now published as a
[TAS paper](https://amstat.tandfonline.com/doi/abs/10.1080/00031305.2017.1375990); an
[earlier introduction](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-jss-2011.pdf)
was also published as a [JSS paper](https://www.jstatsoft.org/v40/i08/))
provides a good entry point to Rcpp as do the [Rcpp
website](http://www.rcpp.org), the [Rcpp
page](https://dirk.eddelbuettel.com/code/rcpp.html) and the [Rcpp
Gallery](https://gallery.rcpp.org). Full documentation is provided by the
[Rcpp book](http://www.rcpp.org/book/).

Other highlights:

- The conversion from C++ to R and back is driven by the templates `Rcpp::wrap`
and `Rcpp::as` which are highly flexible and extensible, as documented
in the [Rcpp-extending](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-extending.pdf) vignette.

- Rcpp also provides Rcpp modules, a framework that allows exposing
C++ functions and classes to the R level. The [Rcpp-modules](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-modules.pdf) vignette
details the current set of features of Rcpp-modules.

- Rcpp includes a concept called Rcpp sugar that brings many R functions
into C++. Sugar takes advantage of lazy evaluation and expression templates
to achieve great performance while exposing a syntax that is much nicer
to use than the equivalent low-level loop code. The [Rcpp-sugar](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-sugar.pdf)
gives an overview of the feature.

- Rcpp attributes provide a high-level syntax for declaring C++
functions as callable from R and automatically generating the code
required to invoke them.  Attributes are intended to facilitate both
interactive use of C++ within R sessions as well as to support R
package development. Attributes are built on top of Rcpp modules and
their implementation is based on previous work in the inline package.
See the [Rcpp-atttributes](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-attributes.pdf) vignettes for more details.

### Documentation

The package ships with nine pdf vignettes, including a [recent introduction to
Rcpp](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-introduction.pdf) now
published as a [paper in
TAS](https://amstat.tandfonline.com/doi/abs/10.1080/00031305.2017.1375990) (and as a
[preprint in PeerJ](https://peerj.com/preprints/3188/)). Also available is an
[earlier
introduction](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-jss-2011.pdf)
which was published as a [JSS paper](https://www.jstatsoft.org/v40/i08/))

Among the other vignettes are the [Rcpp
FAQ](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-FAQ.pdf) and the
introduction to [Rcpp
Attributes](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-attributes.pdf).
Additional documentation is available via the [Rcpp book](http://www.rcpp.org/book)
by Eddelbuettel (2013, Springer); see 'citation("Rcpp")' for details.

### Examples

The [Rcpp Gallery](https://gallery.rcpp.org) showcases over one hundred fully
documented and working examples. The
[package RcppExamples](https://cran.r-project.org/package=RcppExamples) contains a few basic
examples covering the core data types.

A number of examples are included, as are well over one thousand unit tests which provide
additional usage examples.

An earlier version of Rcpp, containing what we now call the 'classic Rcpp
API' was written during 2005 and 2006 by Dominick Samperi.  This code has
been factored out of Rcpp into the package RcppClassic, and it is still
available for code relying on the older interface. New development should
always use this Rcpp package instead.

Other usage examples are provided by packages using Rcpp. As of June 2020,
there are 1990 [CRAN](https://cran.r-project.org) packages using Rcpp, a further
203 [BioConductor](https://www.bioconductor.org) packages in its current release
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
[Rcpp-devel](https://lists.r-forge.r-project.org/cgi-bin/mailman/listinfo/rcpp-devel)
mailing list hosted at R-forge.  Note that in order to keep spam down, you must
be a subscriber in order to post.  One can also consult the list archives to see
if your question has been asked before.

Another option is to use
[StackOverflow and its 'rcpp' tag](https://stackoverflow.com/questions/tagged/rcpp).
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
