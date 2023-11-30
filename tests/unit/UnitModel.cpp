#include "UnitModel.hpp"
#include "../../src/models/ModelImpl.hpp"
#include "TestFlow.hpp"
#include <cassert>

void unit_model_constructor() {
  Model *model = new ModelImpl();
  assert(model->get_title() == "");
  assert(model->systems_begin() == model->systems_end());
  assert(model->flows_begin() == model->flows_end());

  delete model;
}

void unit_model_constructor_with_id_and_title() {
  Model *model = new ModelImpl("Model 1");
  assert(model->get_title() == "Model 1");
  assert(model->systems_begin() == model->systems_end());
  assert(model->flows_begin() == model->flows_end());

  delete model;
}

void unit_model_get_title() {
  Model *model = new ModelImpl("Model 1");
  assert(model->get_title() == "Model 1");

  delete model;
}

void unit_model_add_system() {
  Model *model = new ModelImpl("Model 1");
  System &system = model->create_system("System 1", 1.0);

  assert(model->systems_begin() != model->systems_end());

  delete model;
}

void unit_model_remove_system() {
  Model *model = new ModelImpl("Model 1");
  System &system = model->create_system("System 1", 1.0);

  assert(model->systems_begin() != model->systems_end());
  model->remove_system(&system);
  assert(model->systems_begin() == model->systems_end());

  delete model;
}

void unit_model_add_flow() {
  Model *model = new ModelImpl("Model 1");
  System &source = model->create_system("Source", 1.0);
  System &target = model->create_system("Target", 1.0);
  Flow &flow = model->create_flow<TestFlow>("Flow 1", &source, &target);

  assert(model->flows_begin() != model->flows_end());

  delete model;
}

void unit_model_remove_flow() {
  Model *model = new ModelImpl("Model 1");
  System &source = model->create_system("Source", 1.0);
  System &target = model->create_system("Target", 1.0);
  Flow &flow = model->create_flow<TestFlow>("Flow 1", &source, &target);

  assert(model->flows_begin() != model->flows_end());
  model->remove_flow(&flow);
  assert(model->flows_begin() == model->flows_end());

  delete model;
}

void unit_model_systems_begin() {
  Model *model = new ModelImpl("Model 1");
  System &system = model->create_system("System 1", 1.0);

  assert(model->systems_begin() != model->systems_end());
  assert((*model->systems_begin())->get_title() == "System 1");
  assert((*model->systems_begin())->get_value() == 1.0);

  delete model;
}

void unit_model_systems_end() {
  Model *model = new ModelImpl("Model 1");
  System &system = model->create_system("System 1", 1.0);

  assert(model->systems_begin() != model->systems_end());
  assert(++model->systems_begin() == model->systems_end());

  delete model;
}

void unit_model_flows_begin() {
  Model *model = new ModelImpl("Model 1");
  Flow &flow = model->create_flow<TestFlow>("Flow 1");

  assert(model->flows_begin() != model->flows_end());
  assert((*model->flows_begin())->get_title() == "Flow 1");

  delete model;
}

void unit_model_flows_end() {
  Model *model = new ModelImpl("Model 1");
  Flow &flow = model->create_flow<TestFlow>("Flow 1");

  assert(model->flows_begin() != model->flows_end());
  assert(++model->flows_begin() == model->flows_end());

  delete model;
}

void unit_model_execute() {
  Model *model = new ModelImpl("Model 1");

  int initial_time = 10;
  int end_time = 100;
  int steps = model->execute(initial_time, end_time, 1);

  assert(steps == (end_time - initial_time));

  delete model;
}

void run_model_unit_tests() {
  unit_model_constructor();
  unit_model_constructor_with_id_and_title();
  unit_model_get_title();
  unit_model_add_system();
  unit_model_remove_system();
  unit_model_add_flow();
  unit_model_remove_flow();
  unit_model_systems_begin();
  unit_model_systems_end();
  unit_model_flows_begin();
  unit_model_flows_end();
  unit_model_execute();
}