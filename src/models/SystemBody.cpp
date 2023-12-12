#include "SystemBody.hpp"

SystemBody::SystemBody(){};

SystemBody::SystemBody(std::string title, double value)
    : m_title(title), m_value(value) {}

SystemBody::SystemBody(const System &other) {
  if (this != &other) {
    m_title = other.get_title();
    m_value = other.get_value();
  }
}

SystemBody &SystemBody::operator=(const SystemBody &other) {
  if (this != &other) {
    m_title = other.m_title;
    m_value = other.m_value;
  }
  return *this;
}

SystemBody::~SystemBody(){};

std::string SystemBody::get_title() const { return m_title; }

void SystemBody::set_title(std::string new_title) { m_title = new_title; }

double SystemBody::get_value() const { return m_value; }

void SystemBody::set_value(double new_value) { m_value = new_value; }
