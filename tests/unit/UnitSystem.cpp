#include "UnitSystem.hpp"
#include "../../src/models/SystemImpl.hpp"
#include <cassert>

void unit_system_constructor() {
  System *system1 = new SystemImpl();
  assert(system1->get_id() == 0);
  assert(system1->get_title() == "");
  assert(system1->get_value() == 0.0);

  System *system2 = new SystemImpl(1, "System 1", 1.0);
  assert(system2->get_id() == 1);
  assert(system2->get_title() == "System 1");
  assert(system2->get_value() == 1.0);

  delete system1;
  delete system2;
}

void unit_system_get_id() {
  System *system = new SystemImpl(1, "System 1", 1.0);
  assert(system->get_id() == 1);
  delete system;
}

void unit_system_get_title() {
  System *system = new SystemImpl(1, "System 1", 1.0);
  assert(system->get_title() == "System 1");
  delete system;
}

void unit_system_get_value() {
  System *system = new SystemImpl(1, "System 1", 1.0);
  assert(system->get_value() == 1.0);
  delete system;
}

void unit_system_set_value() {
  System *system = new SystemImpl(1, "System 1", 1.0);
  assert(system->get_value() == 1.0);

  system->set_value(2.0);
  assert(system->get_value() == 2.0);
  delete system;
}