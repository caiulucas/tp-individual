#include "Flow.h"
#include "Element.h"

Flow::Flow() {}

Flow::Flow(int id, string title, System *source, System *target)
    : Element(id, title), source(source), target(target) {}

Flow::Flow(const Flow &other) {
  if (this != &other) {
    source = other.source;
    target = other.target;
  }
}

Flow &Flow::operator=(const Flow &other) {
  if (this != &other) {
    source = other.source;
    target = other.target;
  }
  return *this;
}

Flow::~Flow(){};

System *Flow ::get_source() { return source; }

void Flow::set_source(System *new_source) { source = new_source; }

System *Flow ::get_target() { return target; }

void Flow::set_target(System *target) { this->target = target; }

bool Flow::clear_source() {
  if (source != nullptr) {
    source = nullptr;
    return true;
  }
  return false;
}

bool Flow::clear_target() {
  if (target != nullptr) {
    target = nullptr;
    return true;
  }

  return false;
}