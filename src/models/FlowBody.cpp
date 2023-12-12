#include "FlowBody.hpp"

FlowBody::FlowBody() {}

FlowBody::FlowBody(std::string title) : m_title(title) {}

FlowBody::FlowBody(std::string title, System *source, System *target)
    : m_title(title), m_source(source), m_target(target) {}

FlowBody::FlowBody(const Flow &other) {
  if (this != &other) {
    m_title = other.get_title();
    m_source = other.get_source();
    m_target = other.get_target();
  }
}

FlowBody &FlowBody::operator=(const Flow &other) {
  if (this != &other) {
    m_title = other.get_title();
    m_source = other.get_source();
    m_target = other.get_target();
  }
  return *this;
}

FlowBody::~FlowBody() {}

std::string FlowBody::get_title() const { return m_title; }

System *FlowBody::get_source() const { return m_source; }

void FlowBody::set_source(System *source) { m_source = source; }

System *FlowBody::get_target() const { return m_target; }

void FlowBody::set_target(System *target) { this->m_target = target; }

bool FlowBody::clear_source() {
  if (m_source != nullptr) {
    m_source = nullptr;
    return true;
  }
  return false;
}

bool FlowBody::clear_target() {
  if (m_target != nullptr) {
    m_target = nullptr;
    return true;
  }

  return false;
}
