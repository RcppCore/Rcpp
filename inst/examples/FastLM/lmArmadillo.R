#
# lm() via Armadillo -- improving on the previous GSL solution
#
# Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
#
# This file is part of Rcpp.
#
# Rcpp is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Rcpp is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

suppressMessages(require(Rcpp))
suppressMessages(require(inline))

lmArmadillo <- function() {
    src <- '

    Rcpp::NumericVector yr(Ysexp);
    Rcpp::NumericVector Xr(Xsexp);
    std::vector<int> dims = Xr.attr("dim") ;
    int n = dims[0];
    int k = dims[1];
    // use advanced armadillo constructors:

    arma::mat X(Xr.begin(), n, k, false);
    arma::colvec y(yr.begin(), yr.size());

    //std::cout << ay << std::endl;
    //std::cout << aX << std::endl;

    arma::colvec coef = solve(X, y);
    //std::cout << coef << std::endl;

    // compute std. error of the coefficients
    arma::colvec resid = y - X*coef;
    double rss  = trans(resid)*resid;
    double sig2 = rss/(n-k);
    arma::mat covmat = sig2 * arma::inv(arma::trans(X)*X);

    Rcpp::NumericVector coefr(k), stderrestr(k);
    for (int i=0; i<k; i++) {
        coefr[i]      = coef[i];
        stderrestr[i] = sqrt(covmat(i,i));
    }

    Rcpp::Pairlist res(Rcpp::Named( "coef", coefr),
                       Rcpp::Named( "stderr", stderrestr));
    return res;
    '

    ## turn into a function that R can call
    ## compileargs redundant on Debian/Ubuntu as gsl headers are found anyway
    fun <- cfunction(signature(Ysexp="numeric", Xsexp="numeric"),
                     src,
                     includes="#include <armadillo>",
                     Rcpp=TRUE,
                     cppargs="-I/usr/include",
                     libargs="-larmadillo")
}

