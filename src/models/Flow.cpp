#include "Flow.hpp"

Flow::Flow() {}

Flow::Flow(int id, string title) : m_id(id), m_title(title) {}

Flow::Flow(int id, string title, System *source, System *target)
    : m_id(id), m_title(title), m_source(source), m_target(target) {}

Flow::Flow(const Flow &other) {
  if (this != &other) {
    m_id = other.m_id;
    m_title = other.m_title;
    m_source = other.m_source;
    m_target = other.m_target;
  }
}

Flow &Flow::operator=(const Flow &other) {
  if (this != &other) {
    m_source = other.m_source;
    m_target = other.m_target;
  }
  return *this;
}

Flow::~Flow() {}

int Flow::get_id() const { return m_id; }

System *Flow::get_source() const { return m_source; }

void Flow::set_source(System *source) { m_source = source; }

System *Flow::get_target() const { return m_target; }

void Flow::set_target(System *target) { this->m_target = target; }

bool Flow::clear_source() {
  if (m_source != nullptr) {
    m_source = nullptr;
    return true;
  }
  return false;
}

bool Flow::clear_target() {
  if (m_target != nullptr) {
    m_target = nullptr;
    return true;
  }

  return false;
}
