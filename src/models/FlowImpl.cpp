#include "FlowImpl.hpp"

FlowImpl::FlowImpl() {}

FlowImpl::FlowImpl(int id, string title) : m_id(id), m_title(title) {}

FlowImpl::FlowImpl(int id, string title, System *source, System *target)
    : m_id(id), m_title(title), m_source(source), m_target(target) {}

FlowImpl::FlowImpl(const FlowImpl &other) {
  if (this != &other) {
    m_id = other.m_id;
    m_title = other.m_title;
    m_source = other.m_source;
    m_target = other.m_target;
  }
}

FlowImpl &FlowImpl::operator=(const FlowImpl &other) {
  if (this != &other) {
    m_source = other.m_source;
    m_target = other.m_target;
  }
  return *this;
}

FlowImpl::~FlowImpl() {}

int FlowImpl::get_id() const { return m_id; }

System *FlowImpl::get_source() const { return m_source; }

void FlowImpl::set_source(System *source) { m_source = source; }

System *FlowImpl::get_target() const { return m_target; }

void FlowImpl::set_target(System *target) { this->m_target = target; }

bool FlowImpl::clear_source() {
  if (m_source != nullptr) {
    m_source = nullptr;
    return true;
  }
  return false;
}

bool FlowImpl::clear_target() {
  if (m_target != nullptr) {
    m_target = nullptr;
    return true;
  }

  return false;
}
