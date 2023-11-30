#include "FlowImpl.hpp"

FlowImpl::FlowImpl() {}

FlowImpl::FlowImpl(std::string title) : m_title(title) {}

FlowImpl::FlowImpl(std::string title, System *source, System *target)
    : m_title(title), m_source(source), m_target(target) {}

FlowImpl::FlowImpl(const Flow &other) {
  if (this != &other) {
    m_title = other.get_title();
    m_source = other.get_source();
    m_target = other.get_target();
  }
}

FlowImpl &FlowImpl::operator=(const Flow &other) {
  if (this != &other) {
    m_title = other.get_title();
    m_source = other.get_source();
    m_target = other.get_target();
  }
  return *this;
}

FlowImpl::~FlowImpl() {}

std::string FlowImpl::get_title() const { return m_title; }

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
