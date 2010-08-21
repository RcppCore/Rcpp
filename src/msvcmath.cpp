#ifdef _MSC_VER

#include <math.h>
#include <stdexcept>
#include <Rcpp/msvc/math.h>

// This is adapted from code by John D. Cook, released to public domain.
// See http://www.johndcook.com/math_h.html.

double log1p(double x) {
    if(x <= -1.0)
	throw std::range_error("log1p: arg <= -1");
    if(fabs(x) > 1.e-4)
	return log(1.0 + x);
    return (-0.5*x + 1.0)*x;
}

double erf(double x)
{
    // constants
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;

    // Save the sign of x
    int sign = 1;
    if (x < 0)
        sign = -1;
    x = fabs(x);

    // A&S formula 7.1.26
    double t = 1.0/(1.0 + p*x);
    double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

    return sign*y;
}

// Compute exp(x) - 1 without loss of precision for small values of x.
double expm1(double x)
{
    if (fabs(x) < 1e-5)
	return x + 0.5*x*x;
    else
	return exp(x) - 1.0;
}
#else
// so that there is a symbol in this file
void dummy_msvc(){}
#endif
