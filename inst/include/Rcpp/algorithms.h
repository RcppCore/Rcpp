namespace Rcpp {
namespace algorithm {

namespace helpers {
    struct log {
        inline double operator()(double val) {
            if (!NumericVector::is_na(val)) {
                return std::log(val);
            }

            return NA_REAL;
        }
    };

    struct exp {
        inline double operator()(double val) {
            if (!NumericVector::is_na(val)) {
                return std::exp(val);
            }

            return NA_REAL;
        }
    };

    struct sqrt {
        inline double operator()(double val) {
            if (!NumericVector::is_na(val)) {
                return std::sqrt(val);
            }

            return NA_REAL;
        }
    };
} // namespace helpers

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type sum(InputIterator begin, InputIterator end) {
    typename std::iterator_traits< InputIterator >::value_type start = *begin++;

    while (begin != end) {
        start += *begin++;
    }

    return start;
}

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type prod(InputIterator begin, InputIterator end) {
    typename std::iterator_traits< InputIterator >::value_type start = *begin++;

    while (begin != end) {
        start *= *begin++;
    }

    return start;
}

template< typename InputIterator, typename OutputIterator >
void log(InputIterator begin, InputIterator end, OutputIterator out) {
    std::transform(begin, end, out, helpers::log());
}

template< typename InputIterator, typename OutputIterator >
void exp(InputIterator begin, InputIterator end, OutputIterator out) {
    std::transform(begin, end, out, helpers::exp());
}

template< typename InputIterator, typename OutputIterator >
void sqrt(InputIterator begin, InputIterator end, OutputIterator out) {
    std::transform(begin, end, out, helpers::sqrt());
}

} // namespace algorithm
} // namespace Rcpp
