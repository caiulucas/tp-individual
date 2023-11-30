#include "SystemImpl.hpp"

SystemImpl::SystemImpl(){};

SystemImpl::SystemImpl(std::string title, double value)
    : m_title(title), m_value(value) {}

SystemImpl::SystemImpl(const System &other) {
  if (this != &other) {
    m_title = other.get_title();
    m_value = other.get_value();
  }
}

SystemImpl &SystemImpl::operator=(const SystemImpl &other) {
  if (this != &other) {
    m_title = other.m_title;
    m_value = other.m_value;
  }
  return *this;
}

SystemImpl::~SystemImpl(){};

std::string SystemImpl::get_title() const { return m_title; }

double SystemImpl::get_value() const { return m_value; }

void SystemImpl::set_value(double new_value) { m_value = new_value; }
