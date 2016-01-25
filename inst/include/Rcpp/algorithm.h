namespace Rcpp {
namespace algorithm {

namespace helpers {
    template< typename T >
    struct rtype_helper {
        static const int RTYPE = REALSXP;
        static const double NA;
        static const double ZERO = 0.0;
        static const double ONE = 1.0;
    };

    template< typename T >
    const double rtype_helper< T >::NA = NA_REAL;

    template<>
    struct rtype_helper< double > {
        static const int RTYPE = REALSXP;
        static const double NA;
        static const double ZERO = 0.0;
        static const double ONE = 1.0;
    };

    const double rtype_helper< double >::NA = NA_REAL;

    template<>
    struct rtype_helper< int > {
        static const int RTYPE = INTSXP;
        static const int NA = INT_MIN;
        static const int ZERO = 0;
        static const int ONE = 1;
    };

    template< typename T >
    struct rtype {
        static const int RTYPE =
            rtype_helper< typename traits::remove_const_and_reference< T >::type >::RTYPE;
        static const T NA =
            rtype_helper< typename traits::remove_const_and_reference< T >::type >::NA;
        static const T ZERO =
            rtype_helper< typename traits::remove_const_and_reference< T >::type >::ZERO;
        static const T ONE =
            rtype_helper< typename traits::remove_const_and_reference< T >::type >::ONE;
    };

    struct log {
        template< typename T >
        inline double operator()(T val) {
            if (!Vector< rtype< T >::RTYPE >::is_na(val)) {
                return std::log(val);
            }

            return NA_REAL;
        }
    };

    struct exp {
        template< typename T >
        inline double operator()(T val) {
            if (!Vector< rtype< T >::RTYPE >::is_na(val)) {
                return std::exp(val);
            }

            return NA_REAL;
        }
    };

    struct sqrt {
        template< typename T >
        inline double operator()(T val) {
            if (!Vector< rtype< T >::RTYPE >::is_na(val)) {
                return std::sqrt(val);
            }

            return NA_REAL;
        }
    };
} // namespace helpers

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type sum(InputIterator begin, InputIterator end) {
    
    typedef typename std::iterator_traits< InputIterator >::value_type value_type;
    typedef typename helpers::rtype< value_type > rtype;

    if (begin != end) {
         value_type start = rtype::ZERO;

        while (begin != end) {
            if (!Vector< rtype::RTYPE >::is_na(*begin)) {
                start += *begin++;
            } else {
                return rtype::NA;
            }
        }

        return start;
    }

    return rtype::ZERO;
}

template< typename InputIterator >
typename std::iterator_traits< InputIterator >::value_type prod(InputIterator begin, InputIterator end) {

    typedef typename std::iterator_traits< InputIterator >::value_type value_type;
    typedef typename helpers::rtype< value_type > rtype;

    if (begin != end) {
        value_type start = rtype::ONE;

        while (begin != end) {
            if (!Vector< rtype::RTYPE >::is_na(*begin)) {
                start *= *begin++;
            } else {
                return rtype::NA;
            }
        }

        return start;
    }

    return rtype::ZERO;
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
