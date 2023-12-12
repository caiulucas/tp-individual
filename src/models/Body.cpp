#include "Body.hpp"

Body::Body() : _reference_count(0) {}

Body::~Body() {}

void Body::attach() { ++_reference_count; }

void Body::detach() {
  if (--_reference_count == 0)
    delete this;
}

int Body::reference_count() const { return _reference_count; }