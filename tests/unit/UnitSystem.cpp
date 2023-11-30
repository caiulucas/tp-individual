#include "UnitSystem.hpp"
#include "../../src/models/SystemImpl.hpp"
#include <cassert>
#include <cmath>

void unit_system_constructor() {
  System *system = new SystemImpl();
  assert(system->get_title() == "");
  assert(fabs((round((system->get_value() * 10000)) - 10000 * 0.0)) < 0.0001);

  delete system;
}

void unit_system_constructor_with_fields() {
  System *system = new SystemImpl("System 1", 1.0);
  assert(system->get_title() == "System 1");
  assert(fabs((round((system->get_value() * 10000)) - 10000 * 1.0)) < 0.0001);

  delete system;
}

void unit_system_constructor_copy() {
  System *system = new SystemImpl("System 1", 1.0);
  System *system_copy = new SystemImpl(*system);
  assert(system_copy->get_title() == "System 1");
  assert(fabs((round((system->get_value() * 10000)) - 10000 * 1.0)) < 0.0001);

  delete system;
  delete system_copy;
}

void unit_system_get_title() {
  System *system = new SystemImpl("System 1", 1.0);
  assert(system->get_title() == "System 1");
  delete system;
}

void unit_system_get_value() {
  System *system = new SystemImpl("System 1", 1.0);
  assert(fabs((round((system->get_value() * 10000)) - 10000 * 1.0)) < 0.0001);
  delete system;
}

void unit_system_set_value() {
  System *system = new SystemImpl("System 1", 1.0);
  assert(fabs((round((system->get_value() * 10000)) - 10000 * 1.0)) < 0.0001);

  system->set_value(2.0);
  assert(fabs((round((system->get_value() * 10000)) - 10000 * 2.0)) < 0.0001);
  delete system;
}

void run_system_unit_tests() {
  unit_system_constructor();
  unit_system_constructor_with_fields();
  unit_system_constructor_copy();
  unit_system_get_title();
  unit_system_get_value();
  unit_system_set_value();
}