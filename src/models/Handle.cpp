#include "Handle.hpp"

template <class T> Handle<T>::Handle() {
  _pImpl = new T();
  _pImpl->attach();
}

template <class T> Handle<T>::~Handle() { _pImpl->detach(); }

template <class T> Handle<T>::Handle(const Handle<T> &other) {
  if (this != &other) {
    other->attach();
    _pImpl->detach();
    _pImpl = other._pImpl;
  }
}