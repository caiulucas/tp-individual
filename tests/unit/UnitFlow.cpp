#include "UnitFlow.hpp"
#include "../../src/models/SystemImpl.hpp"
#include "TestFlow.hpp"
#include <cassert>
#include <cmath>
#include <cstdio>
#include <future>

void unit_flow_constructor() {
  Flow *flow = new TestFlow();
  assert(flow->get_id() == 0);
  assert(flow->get_title() == "");
  assert(flow->get_source() == nullptr);
  assert(flow->get_target() == nullptr);

  delete flow;
}

void unit_flow_constructor_with_id_and_title() {
  Flow *flow = new TestFlow(1, "Flow 1");
  assert(flow->get_id() == 1);
  assert(flow->get_title() == "Flow 1");
  assert(flow->get_source() == nullptr);
  assert(flow->get_target() == nullptr);

  delete flow;
}

void unit_flow_constructor_with_all_fields() {
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);

  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(flow->get_id() == 1);
  assert(flow->get_title() == "Flow 1");
  assert(flow->get_source() == source);
  assert(flow->get_target() == target);

  delete source;
  delete target;
  delete flow;
}

void unit_flow_constructor_copy() {
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);

  Flow *flow = new TestFlow(1, "Flow 1", source, target);
  Flow *flow_copy = new TestFlow(*flow);

  assert(flow_copy->get_id() == 1);
  assert(flow_copy->get_title() == "Flow 1");
  assert(flow_copy->get_source() == source);
  assert(flow_copy->get_target() == target);

  delete source;
  delete target;
  delete flow;
  delete flow_copy;
}

void unit_flow_get_id() {
  Flow *flow = new TestFlow(1, "Flow 1");
  assert(flow->get_id() == 1);
  delete flow;
}

void unit_flow_get_title() {
  Flow *flow = new TestFlow(1, "Flow 1");
  assert(flow->get_title() == "Flow 1");
  delete flow;
}

void unit_flow_get_source() {
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);

  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(flow->get_source() == source);

  delete source;
  delete target;
  delete flow;
}

void unit_flow_set_source() {
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);

  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(flow->get_source() == source);

  System *new_source = new SystemImpl(3, "New Source", 1.0);
  flow->set_source(new_source);

  assert(flow->get_source() == new_source);
  assert(flow->get_target() == target);

  delete source;
  delete target;
  delete flow;
}

void unit_flow_clear_source() {
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);

  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(flow->get_source() == source);

  flow->clear_source();

  assert(flow->get_source() == nullptr);
  assert(flow->get_target() == target);

  delete source;
  delete target;
  delete flow;
}

void unit_flow_get_target() {
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);

  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(flow->get_target() == target);

  delete source;
  delete target;
  delete flow;
}

void unit_flow_set_target() {
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);

  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(flow->get_target() == target);

  System *new_target = new SystemImpl(3, "New Target", 1.0);
  flow->set_target(new_target);

  assert(flow->get_target() == new_target);
  assert(flow->get_source() == source);

  delete source;
  delete target;
  delete flow;
}

void unit_flow_clear_target() {
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);

  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(flow->get_target() == target);

  flow->clear_target();

  assert(flow->get_target() == nullptr);
  assert(flow->get_source() == source);

  delete source;
  delete target;
  delete flow;
}

void unit_flow_execute() {
  System *source = new SystemImpl(1, "Source", 10.1);
  System *target = new SystemImpl(2, "Target", 200.0);

  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  double expected_result = 0.101;

  assert(fabs((round((flow->execute() * 10000)) - 10000 * expected_result)) <
         0.0001);

  delete source;
  delete target;
  delete flow;
}

void run_flow_unit_tests() {
  unit_flow_constructor();
  unit_flow_constructor_with_id_and_title();
  unit_flow_constructor_with_all_fields();
  unit_flow_constructor_copy();
  unit_flow_get_id();
  unit_flow_get_title();
  unit_flow_get_source();
  unit_flow_set_source();
  unit_flow_clear_source();
  unit_flow_get_target();
  unit_flow_set_target();
  unit_flow_clear_target();
  unit_flow_execute();
}