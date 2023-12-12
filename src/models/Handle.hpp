#pragma once

template <class T> class Handle {
protected:
  T *_pImpl;

public:
  Handle<T>();

  virtual ~Handle<T>();

  Handle<T>(const Handle<T> &other);
};