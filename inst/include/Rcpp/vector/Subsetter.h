// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Subsetter.h: Rcpp R/C++ interface class library -- vector subsetting
//
// Copyright (C) 2014  Dirk Eddelbuettel, Romain Francois and Kevin Ushey
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//                                                              
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef Rcpp_vector_Subsetter_h_
#define Rcpp_vector_Subsetter_h_

namespace Rcpp {

template <int RTYPE, template <class> class StoragePolicy, typename T>
class Subsetter {
  
  typedef Vector<RTYPE, StoragePolicy> VECTOR;
  
  public:
  
  explicit Subsetter(const Subsetter& rhs): vec(rhs.vec), other(rhs.other) {};
  Subsetter(const VECTOR& vec_, const T& other_): vec(vec_), other(other_) {};
  
  inline operator SEXP() const {
    return subset_impl(vec, other).get__();
  }
  
  inline operator VECTOR() const {
    return subset_impl(vec, other);
  }
  
  private:
  
  Subsetter() {};
  
  // helper function used for the subset methods when going from logical to int
  template <template <class> class OtherStoragePolicy>
  static Vector<INTSXP, StoragePolicy> which_na( const Vector<LGLSXP, OtherStoragePolicy>& x) {
    std::vector<int> output;
    int n = x.size();
    output.reserve(n);
    for (int i=0; i < n; ++i) {
      if (x[i] == NA_LOGICAL) {
        output.push_back(NA_INTEGER);
      } else if (x[i]) {
        output.push_back(i);
      }
    }
    int n_ = output.size();
    Vector<INTSXP, StoragePolicy> output_ = no_init(n_);
    for (int i=0; i < n_; ++i) {
        output_[i] = output[i];
    };
    return output_;
  }
  
  // Subsetting for logicals
  template <template <class> class OtherStoragePolicy>
  inline Vector<RTYPE, StoragePolicy> subset_impl( const VECTOR& this_, const Vector<LGLSXP, OtherStoragePolicy>& x ) const {
    Vector<INTSXP, StoragePolicy> tmp = which_na(x);
    if (!tmp.size()) return Vector<RTYPE, StoragePolicy>(0);
    else return subset_impl__hidden(this_, tmp);
  }
  
  // Subsetting for characters
  template <template <class> class OtherStoragePolicy>
  inline Vector<RTYPE, StoragePolicy> subset_impl( const VECTOR& this_, const Vector<STRSXP, OtherStoragePolicy>& x ) const {
    Vector<STRSXP, StoragePolicy> names = as< Vector<STRSXP, StoragePolicy> >(Rf_getAttrib(this_, R_NamesSymbol));
    Vector<INTSXP, StoragePolicy> idx = match(x, names); // match returns 1-based index
    // apparently, we don't see sugar, so we have to do this manually
    Vector<INTSXP, StoragePolicy> idxm1 = no_init(idx.size());
    for (int i=0; i < idx.size(); ++i) {
        idxm1[i] = idx[i] - 1;
    }
    Vector<RTYPE, StoragePolicy> output = subset_impl__hidden(this_, idxm1);
    int n = output.size();
    if (n == 0) return Vector<RTYPE, StoragePolicy>(0);
    Vector<STRSXP, StoragePolicy> out_names = no_init(n);
    for (int i=0; i < n; ++i) {
      if (idx[i] == NA_INTEGER) out_names[i] = NA_STRING;
      else out_names[i] = names[ idx[i] - 1 ];
    }
    output.attr("names") = out_names;
    return output;
  }
  
  const VECTOR& vec;
  const T& other;
  
  private:
  
  // Subsetting for integers -- note that it is 0-based
  template <template <class> class OtherStoragePolicy>
  inline Vector<RTYPE, StoragePolicy> 
  subset_impl( const VECTOR this_, const Vector<INTSXP, OtherStoragePolicy>& x ) const {
    stop("Subset is not yet implemented for IntegerVectors");
    return Vector<RTYPE, StoragePolicy>();
  }
  
  // Subsetting for integers -- note that it is 0-based
  // hidden until we decide whether to go with 0 or 1 based indexing
  template <template <class> class OtherStoragePolicy>
  inline Vector<RTYPE, StoragePolicy> 
  subset_impl__hidden( const VECTOR this_, const Vector<INTSXP, OtherStoragePolicy>& x ) const {
    int n = x.size();
    if (n == 0) return this_;
    Vector<RTYPE, StoragePolicy> output = no_init(n);
    for (int i=0; i < n; ++i) {
      if (x[i] == NA_INTEGER) output[i] = traits::get_na<RTYPE>();
      else if (x[i] < 0) stop("Cannot subset with an integer vector with elements <= 0");
      else if (x[i] > this_.size() - 1) output[i] = traits::get_na<RTYPE>();
      else output[i] = (this_)[ x[i] ];
    }
    if (!Rf_isNull( Rf_getAttrib( this_, R_NamesSymbol) )) {
      Vector<STRSXP, StoragePolicy> thisnames = as<Vector<STRSXP, StoragePolicy> >(Rf_getAttrib(this_, R_NamesSymbol));
      Vector<STRSXP, StoragePolicy> outnames = no_init(n);
      for (int i=0; i < n; ++i) {
        if (x[i] == NA_INTEGER) outnames[i] = NA_STRING;
        else if (x[i] > this_.size() - 1) outnames[i] = NA_STRING;
        else if (x[i] >= 0) outnames[i] = thisnames[ x[i] ];
      }
      output.attr("names") = outnames;
    }
    return wrap(output);
  }
  
};

} // namespace Rcpp

#endif
