#include "UnitModel.hpp"
#include "../../src/models/ModelImpl.hpp"
#include "../../src/models/SystemImpl.hpp"
#include "TestFlow.hpp"
#include <cassert>
#include <complex>
#include <cstdio>

void unit_model_constructor() {
  Model *model = new ModelImpl();
  assert(model->get_id() == 0);
  assert(model->get_title() == "");
  assert(model->systems_begin() == model->systems_end());
  assert(model->flows_begin() == model->flows_end());

  delete model;
}

void unit_model_constructor_with_id_and_title() {
  Model *model = new ModelImpl(1, "Model 1");
  assert(model->get_id() == 1);
  assert(model->get_title() == "Model 1");
  assert(model->systems_begin() == model->systems_end());
  assert(model->flows_begin() == model->flows_end());

  delete model;
}

void unit_model_get_id() {
  Model *model = new ModelImpl(1, "Model 1");
  assert(model->get_id() == 1);

  delete model;
}

void unit_model_get_title() {
  Model *model = new ModelImpl(1, "Model 1");
  assert(model->get_title() == "Model 1");

  delete model;
}

void unit_model_add_system() {
  Model *model = new ModelImpl(1, "Model 1");
  System *system = new SystemImpl(1, "System 1", 1.0);

  assert(model->add(system));
  assert(model->systems_begin() != model->systems_end());
  assert(model->flows_begin() == model->flows_end());

  delete model;
  delete system;
}

void unit_model_add_flow() {
  Model *model = new ModelImpl(1, "Model 1");
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);
  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(model->add(flow));
  assert(model->systems_begin() == model->systems_end());
  assert(model->flows_begin() != model->flows_end());

  delete model;
  delete source;
  delete target;
  delete flow;
}

void unit_model_systems_begin() {
  Model *model = new ModelImpl(1, "Model 1");
  System *system = new SystemImpl(1, "System 1", 1.0);

  assert(model->add(system));
  assert(model->systems_begin() != model->systems_end());
  assert((*model->systems_begin())->get_id() == 1);
  assert((*model->systems_begin())->get_title() == "System 1");
  assert((*model->systems_begin())->get_value() == 1.0);

  delete model;
  delete system;
}

void unit_model_systems_end() {
  Model *model = new ModelImpl(1, "Model 1");
  System *system = new SystemImpl(1, "System 1", 1.0);

  assert(model->add(system));
  assert(model->systems_begin() != model->systems_end());
  assert(++model->systems_begin() == model->systems_end());

  delete model;
  delete system;
}

void unit_model_flows_begin() {
  Model *model = new ModelImpl(1, "Model 1");
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);
  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(model->add(flow));
  assert(model->flows_begin() != model->flows_end());
  assert((*model->flows_begin())->get_id() == 1);
  assert((*model->flows_begin())->get_title() == "Flow 1");
  assert((*model->flows_begin())->get_source() == source);
  assert((*model->flows_begin())->get_target() == target);

  delete model;
  delete source;
  delete target;
  delete flow;
}

void unit_model_flows_end() {
  Model *model = new ModelImpl(1, "Model 1");
  System *source = new SystemImpl(1, "Source", 1.0);
  System *target = new SystemImpl(2, "Target", 1.0);
  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(model->add(flow));
  assert(model->flows_begin() != model->flows_end());
  assert(++model->flows_begin() == model->flows_end());

  delete model;
  delete source;
  delete target;
  delete flow;
}

void unit_model_execute() {
  Model *model = new ModelImpl(1, "Model 1");
  System *source = new SystemImpl(1, "Source", 300.0);
  System *target = new SystemImpl(2, "Target", 100.0);
  Flow *flow = new TestFlow(1, "Flow 1", source, target);

  assert(model->add(source));
  assert(model->add(target));
  assert(model->add(flow));

  int steps = model->execute(0, 100, 1);

  const double expected_source_value = 109.8097;
  const double expected_target_value = 290.1903;

  assert(fabs(round((source->get_value() * 10000)) -
              10000 * expected_source_value) < 0.0001);
  assert(fabs(round((target->get_value() * 10000)) -
              10000 * expected_target_value) < 0.0001);
  assert(steps == 100);

  delete model;
  delete source;
  delete target;
  delete flow;
}

void run_model_unit_tests() {
  unit_model_constructor();
  unit_model_constructor_with_id_and_title();
  unit_model_get_id();
  unit_model_get_title();
  unit_model_add_system();
  unit_model_add_flow();
  unit_model_systems_begin();
  unit_model_systems_end();
  unit_model_flows_begin();
  unit_model_flows_end();
  unit_model_execute();
}