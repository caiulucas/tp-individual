#include "SystemImpl.hpp"

SystemImpl::SystemImpl(){};

SystemImpl::SystemImpl(int id, string title, double value)
    : m_id(id), m_title(title), m_value(value) {}

SystemImpl::SystemImpl(const SystemImpl &other) {
  if (this != &other) {
    m_id = other.m_id;
    m_title = other.m_title;
    m_value = other.m_value;
  }
}

SystemImpl &SystemImpl::operator=(const SystemImpl &other) {
  if (this != &other) {
    m_id = other.m_id;
    m_title = other.m_title;
    m_value = other.m_value;
  }
  return *this;
}

SystemImpl::~SystemImpl(){};

int SystemImpl::get_id() const { return m_id; }

double SystemImpl::get_value() const { return m_value; }

void SystemImpl::set_value(double new_value) { m_value = new_value; }
