// ListOf.h: Rcpp R/C++ interface class library -- templated List container
//
// Copyright (C) 2014 Dirk Eddelbuettel, Romain Francois and Kevin Ushey
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

#ifndef Rcpp_vector_ListOf_h_
#define Rcpp_vector_ListOf_h_

namespace Rcpp {
    template <typename T> class ListOf;
}

#include <Rcpp/proxy/ListOfProxy.h>

namespace Rcpp {

// defines used to clean up some of the code repetition
#define THIS static_cast<List>(list)[index]
#define LHS  static_cast<List>(lhs.list)[lhs.index]
#define RHS  static_cast<List>(rhs.list)[rhs.index]

  template <typename T>
  class ListOf: public List {

  public:

    ListOf() {}

    ListOf(SEXP data_): List(data_) {}

    template <typename U>
    ListOf(const U& data_): List(data_) {}

    operator SEXP() const {
      return wrap(static_cast<const List&>(*this));
    }

    ListOfProxy<T> operator[](int i) {
      return ListOfProxy<T>(*this, i);
    }

    const ListOfProxy<T> operator[](int i) const {
      return ListOfProxy<T>(const_cast< ListOf<T>& >(*this), i);
    }

    ListOfProxy<T> operator[](std::string str) {
      std::vector<std::string> names = as< std::vector<std::string> >(this->attr("names"));
      for (int i=0; i < this->size(); ++i) {
        if (names[i] == str) {
          return ListOfProxy<T>(*this, i);
        }
      }
      std::stringstream ss;
      ss << "No name '" << str << "' in the names of the list supplied";
      stop(ss.str());
      return ListOfProxy<T>(*this, -1); // silence compiler
    }

    const ListOfProxy<T> operator[](std::string str) const {
      std::vector<std::string> names = as< std::vector<std::string> >(this->attr("names"));
      for (int i=0; i < this->size(); ++i) {
        if (names[i] == str) {
          return ListOfProxy<T>(const_cast< ListOf<T>& >(*this), i);
        }
      }
      std::stringstream ss;
      ss << "No name '" << str << "' in the names of the list supplied";
      return ListOfProxy<T>(*this, -1); // silence compiler
    }

  }; // ListOf<T>

} // Rcpp

#undef THIS
#undef LHS
#undef RHS

#endif
