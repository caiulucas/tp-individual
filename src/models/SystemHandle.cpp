#include "SystemHandle.hpp"
#include "System.hpp"

SystemHandle::SystemHandle() : System(), Handle<SystemBody>() {}

SystemHandle::SystemHandle(std::string title, double value)
    : Handle<SystemBody>() {
  this->_pImpl = new SystemBody(title, value);
}

SystemHandle::SystemHandle(const System &system) : Handle<SystemBody>() {
  this->_pImpl = new SystemBody(system.get_title(), system.get_value());
}

SystemHandle &SystemHandle::operator=(const System &system) {
  this->_pImpl->set_title(system.get_title());
  this->_pImpl->set_value(system.get_value());
  return *this;
}

SystemHandle::~SystemHandle() { delete this->_pImpl; }

std::string SystemHandle::get_title() const {
  return this->_pImpl->get_title();
}

double SystemHandle::get_value() const { return this->_pImpl->get_value(); }

void SystemHandle::set_value(double value) { this->_pImpl->set_value(value); }

void SystemHandle::set_title(std::string new_title) {
  this->_pImpl->set_title(new_title);
}
