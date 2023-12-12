#include "FlowHandle.hpp"
#include "FlowBody.hpp"
#include "Handle.hpp"

template <typename T> FlowHandle<T>::FlowHandle() : Handle<FlowBody>() {}

template <typename T>
FlowHandle<T>::FlowHandle(std::string title, System *source, System *target) {
  Handle<T>::_pImpl->set_title(title);
  Handle<T>::_pImpl->set_source(source);
  Handle<T>::_pImpl->set_target(target);
}

template <typename T> FlowHandle<T>::~FlowHandle() {}

template <typename T> std::string FlowHandle<T>::get_title() const {
  return Handle<T>::_pImpl->get_title();
}

template <typename T> System *FlowHandle<T>::get_source() const {
  return Handle<T>::_pImpl->get_source();
}

template <typename T> void FlowHandle<T>::set_source(System *source) {
  Handle<T>::_pImpl->set_source(source);
}

template <typename T> System *FlowHandle<T>::get_target() const {
  return Handle<T>::_pImpl->get_target();
}

template <typename T> void FlowHandle<T>::set_target(System *target) {
  Handle<T>::_pImpl->set_target(target);
}

template <typename T> bool FlowHandle<T>::clear_source() {
  return Handle<T>::_pImpl->clear_source();
}

template <typename T> bool FlowHandle<T>::clear_target() {
  return Handle<T>::_pImpl->clear_target();
}