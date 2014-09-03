// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// meat.h: Rcpp R/C++ interface class library --
//
// Copyright (C) 2014    Dirk Eddelbuettel, Romain Francois, and Kevin Ushey
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
#ifndef RCPP_API_MEAT_PROXY_H
#define RCPP_API_MEAT_PROXY_H

namespace Rcpp {

    // Attribute Proxies
    template <typename CLASS>
    template <typename T>
    typename AttributeProxyPolicy<CLASS>::AttributeProxy&
    AttributeProxyPolicy<CLASS>::AttributeProxy::operator=(const T& rhs) {
      set( wrap(rhs) );
      return *this;
    }

    template <typename CLASS>
    template <typename T>
    AttributeProxyPolicy<CLASS>::AttributeProxy::operator T() const {
      return as<T>(get());
    }

    template <typename CLASS>
    AttributeProxyPolicy<CLASS>::AttributeProxy::operator SEXP() const {
      return get();
    }

    template <typename CLASS>
    template <typename T>
    AttributeProxyPolicy<CLASS>::const_AttributeProxy::operator T() const {
      return as<T>(get());
    }

    template <typename CLASS>
    AttributeProxyPolicy<CLASS>::const_AttributeProxy::operator SEXP() const {
      return get();
    }

    // Names proxy

    template <typename CLASS>
    template <typename T>
    typename NamesProxyPolicy<CLASS>::NamesProxy&
    NamesProxyPolicy<CLASS>::NamesProxy::operator=(const T& rhs) {
      set( wrap(rhs) );
      return *this;
    }

    template <typename CLASS>
    template <typename T>
    NamesProxyPolicy<CLASS>::NamesProxy::operator T() const {
        return as<T>( get() );
    }

    template <typename CLASS>
    template <typename T>
    NamesProxyPolicy<CLASS>::const_NamesProxy::operator T() const {
        return as<T>( get() );
    }

    // Slot proxy

    template <typename CLASS>
    template <typename T>
    typename SlotProxyPolicy<CLASS>::SlotProxy&
    SlotProxyPolicy<CLASS>::SlotProxy::operator=(const T& rhs) {
        set(wrap(rhs));
        return *this;
    }

    template <typename CLASS>
    template <typename T>
    SlotProxyPolicy<CLASS>::SlotProxy::operator T() const {
        return as<T>(get());
    }

    // Tag proxy

    template <typename CLASS>
    template <typename T>
    typename TagProxyPolicy<CLASS>::TagProxy&
    TagProxyPolicy<CLASS>::TagProxy::operator=(const T& rhs) {
      set( wrap(rhs) );
      return *this;
    }

    template <typename CLASS>
    template <typename T>
    TagProxyPolicy<CLASS>::TagProxy::operator T() const {
      return as<T>(get());
    }

    template <typename CLASS>
    TagProxyPolicy<CLASS>::TagProxy::operator SEXP() const {
      return get();
    }

    template <typename CLASS>
    template <typename T>
    TagProxyPolicy<CLASS>::const_TagProxy::operator T() const {
      return as<T>(get());
    }

    template <typename CLASS>
    TagProxyPolicy<CLASS>::const_TagProxy::operator SEXP() const {
      return get();
    }

    // Environment Binding
    template <typename CLASS>
    template <typename T>
    typename BindingPolicy<CLASS>::Binding&
    BindingPolicy<CLASS>::Binding::operator=(const T& rhs) {
        set(wrap(rhs));
        return *this;
    }

    template <typename CLASS>
    template <typename T>
    BindingPolicy<CLASS>::Binding::operator T() const {
        return as<T>(get());
    }

    template <typename CLASS>
    template <typename T>
    BindingPolicy<CLASS>::const_Binding::operator T() const {
        return as<T>(get());
    }

    // Dotted pair proxies
    template <typename CLASS>
    template <typename T>
    typename DottedPairProxyPolicy<CLASS>::DottedPairProxy&
    DottedPairProxyPolicy<CLASS>::DottedPairProxy::operator=(const T& rhs) {
        set(wrap(rhs));
        return *this;
    }

    template <typename CLASS>
    template <typename T>
    DottedPairProxyPolicy<CLASS>::DottedPairProxy::operator T() const {
        return as<T>(get());
    }

    template <typename CLASS>
    template <typename T>
    DottedPairProxyPolicy<CLASS>::const_DottedPairProxy::operator T() const {
        return as<T>(get());
    }

}

#endif
