// ListOfProxy.h: Rcpp R/C++ interface class library -- proxy for ListOf<T>
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

#ifndef Rcpp_proxy_ListOfProxy_h_
#define Rcpp_proxy_ListOfProxy_h_

#define THIS static_cast<List>(this->list)[this->index]
#define LHS  static_cast<List>(lhs.list)[lhs.index]
#define RHS  static_cast<List>(rhs.list)[rhs.index]

namespace Rcpp {
    
template <typename T>
class ListOf;

template <typename T>
class ListOfProxy {
public:

  ListOfProxy(ListOf<T>& list_, int index_): list(list_), index(index_) {
    RCPP_DEBUG("ListOfProxy(ListOf& list_, int index_): list(list_), index(index_)\n");
  }

  ~ListOfProxy() {
    RCPP_DEBUG("~ListOfProxy()\n");
  }

  // assignment operators
  inline ListOfProxy& operator=(const ListOfProxy& rhs) {
      THIS = RHS;
      return *this;
  }
  
  inline ListOfProxy& operator=(T rhs) {
      THIS = rhs;
      return *this;
  }

  // addition operators
  inline ListOfProxy operator+(const ListOfProxy& rhs) {
      as<T>(THIS) = as<T>(THIS) + as<T>(RHS);
      return *this;
  }
  
  template <typename U>
  inline ListOfProxy operator+(const U& rhs) {
      as<T>(THIS) = as<T>(THIS) + rhs;
      return *this;
  }
  
  template <typename U>
  friend inline ListOfProxy operator+(const U& lhs, const ListOfProxy& rhs) {
    return const_cast<ListOfProxy<T>&>(rhs).operator+(lhs);
  }

  inline ListOfProxy& operator+=(const ListOfProxy& rhs) {
      as<T>(THIS) += as<T>(RHS);
      return *this;
  }

  template <typename U>
  inline ListOfProxy& operator+=(const U& rhs) {
      as<T>(THIS) += rhs;
      return *this;
  }

  // subtraction operators
  inline ListOfProxy operator-(const ListOfProxy& rhs) {
      as<T>(THIS) = as<T>(THIS) - as<T>(RHS);
      return *this;
  }
  
  template <typename U>
  inline ListOfProxy operator-(const U& rhs) {
      as<T>(THIS) = as<T>(THIS) - rhs;
      return *this;
  }
  
  template <typename U>
  friend inline ListOfProxy operator-(const U& lhs, const ListOfProxy& rhs) {
    return const_cast<ListOfProxy<T>&>(rhs).operator-(lhs);
  }

  inline ListOfProxy& operator-=(const ListOfProxy& rhs) {
      as<T>(THIS) -= as<T>(RHS);
      return *this;
  }

  template <typename U>
  inline ListOfProxy& operator-=(const U& rhs) {
      as<T>(THIS) -= rhs;
      return *this;
  }

  // multiplication operators
  inline ListOfProxy operator*(const ListOfProxy& rhs) {
      as<T>(THIS) = as<T>(THIS) * as<T>(RHS);
      return *this;
  }
  
  template <typename U>
  inline ListOfProxy operator*(const U& rhs) {
      as<T>(THIS) = as<T>(THIS) * rhs;
      return *this;
  }
  
  template <typename U>
  friend inline ListOfProxy operator*(const U& lhs, const ListOfProxy& rhs) {
    return const_cast<ListOfProxy<T>&>(rhs).operator*(lhs);
  }

  inline ListOfProxy& operator*=(const ListOfProxy& rhs) {
      as<T>(THIS) *= as<T>(RHS);
      return *this;
  }

  template <typename U>
  inline ListOfProxy& operator*=(const U& rhs) {
      as<T>(THIS) *= rhs;
      return *this;
  }

  // division operators
  inline ListOfProxy operator/(const ListOfProxy& rhs) {
      as<T>(THIS) = as<T>(THIS) / as<T>(RHS);
      return *this;
  }
  
  template <typename U>
  inline ListOfProxy operator/(const U& rhs) {
      as<T>(THIS) = as<T>(THIS) / rhs;
      return *this;
  }
  
  template <typename U>
  friend inline ListOfProxy operator/(const U& lhs, const ListOfProxy& rhs) {
    return const_cast<ListOfProxy<T>&>(rhs).operator/(lhs);
  }

  inline ListOfProxy& operator/=(const ListOfProxy& rhs) {
      as<T>(THIS) /= as<T>(RHS);
      return *this;
  }

  template <typename U>
  inline ListOfProxy& operator/=(const U& rhs) {
      as<T>(THIS) /= rhs;
      return *this;
  }

  // read
  inline operator T() const {
    RCPP_DEBUG("operator T() const\n");
    return as<T>(THIS);
  }
  
  inline operator SEXP() const {
    return THIS;
  }

  // TODO: reference operator

private:
  ListOf<T>& list;
  int index;
}; // ListOfProxy

}

#undef THIS
#undef LHS
#undef RHS

#endif
