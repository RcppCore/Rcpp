
## Contributing to Rcpp

Interested in contributing? Great!  We really welcome bug reports and pull
requests that expand and improve the functionality of Rcpp from all
contributors.

### Reporting an Issue

When reporting an issue, the most important thing you can provide is a
[reproducible example](http://www.sscce.org/). Please include the smallest
possible example that illustrates the issue -- when possible, provide a snippet
of C++ code that can be run using `Rcpp::sourceCpp()`; if it's not possible or
feasible to provide such an example, provide clear instructions on how to
reproduce the problem. The less effort it takes to reproduce an issue, the more
likely a contributor will be able to investigate the issue + resolve the
problem. Also see this StackOverflow answer on
[creating a reproducible example](http://stackoverflow.com/a/5963610/143305).

Issues that cannot be reproduced are unlikely to receive attention, as it is
often difficult, if not impossible, to ascertain whether Rcpp is truly the
culprit, or what part of Rcpp could be responsible.

Please also supply the output of `sessionInfo()` when reporting an issue.

### Submitting a Pull Request

Considering submitting a pull request? It is strongly recommended that you first
post an issue outlining some motivation for your pull request to ensure that
some discussion around the appropriate resolution for the issue occurs first.

We would prefer it if your PR also included
[unit tests](https://github.com/RcppCore/Rcpp/tree/master/inst/tinytest). Additions
to the [ChangeLog](https://github.com/RcppCore/Rcpp/blob/master/ChangeLog) and
[NEWS](https://github.com/RcppCore/Rcpp/blob/master/inst/NEWS.Rd) are also
appreciated.

Please note that C++ code in Rcpp must adhere to the C++98 standard. C++11 (and
above) extensions are allowed, but must be appropriately guarded so that such
code still successfully compiles under the C++98 standard.

### Coding Style

It would be nice if the contributed code followed existing conventions for
whitespace and indentation.  We mostly follow the R Core style for with four
spaces, and curlies where K&R would put them.

### Asking Questions

Please direct general questions to the
[Rcpp-devel](http://lists.r-forge.r-project.org/cgi-bin/mailman/listinfo/rcpp-devel)
mailing list (preferred, note that only subscribers can post), or alternatively
post a question on
[Stack Overflow](http://stackoverflow.com/questions/tagged/rcpp) using the
`[Rcpp]` tag.

Are you a new user of Rcpp? You might find the
[vignettes](https://cran.r-project.org/package=Rcpp) helpful in getting
acquainted with the functionality Rcpp provides. The
[Rcpp Gallery](http://gallery.rcpp.org/) contains a large number of examples.

### Copyright

Rcpp is released as a [CRAN](https://cran.r-project.org/package=Rcpp) package,
licensed under the
[GPL-2](http://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html) (or later)
[Open Source](https://opensource.org) /
[Free Software](http://www.gnu.org/philosophy/free-sw.en.html)
license -- just like R itself.  Aggregated works, i.e. code linking to R such as
Rcpp will always be under this license.  Your contribution has to be under a
compatible licence.  And to simplify matters, we strongly prefer contributions
under the same terms of the GPL (>= 2) and will in general assume this license
unless explicitly stated otherwise.
