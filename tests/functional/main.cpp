#include "../../src/models/Model.hpp"
#include "../../src/models/ModelImpl.hpp"
#include "../../src/models/System.hpp"
#include "ExponentialFlow.hpp"
#include "LogisticalFlow.hpp"
#include "tests.hpp"
#include <cassert>
#include <cmath>

void exponential_functional_test() {
  Model *model = new ModelImpl("model_1");
  System &s1 = model->create_system("pop1", 100.0);
  System &s2 = model->create_system("pop2", 0.0);
  Flow &f1 = model->create_flow<ExponentialFlow>("Exponencial", &s1, &s2);

  model->execute(0, 100, 1);

  assert(fabs((round((s1.get_value() * 10000)) - 10000 * 36.6032)) < 0.0001);
  assert(fabs((round((s2.get_value() * 10000)) - 10000 * 63.3968)) < 0.0001);

  delete model;
}

void logistical_functional_test() {
  Model *model = new ModelImpl("model_1");
  System &s1 = model->create_system("pop1", 100.0);
  System &s2 = model->create_system("pop2", 10.0);
  Flow &f1 = model->create_flow<LogisticalFlow>("Logístico");

  f1.set_source(&s1);
  f1.set_target(&s2);

  model->execute(0, 100, 1);

  assert(fabs((round((s1.get_value() * 10000)) - 10000 * 88.2167)) < 0.0001);
  assert(fabs((round((s2.get_value() * 10000)) - 10000 * 21.7833)) < 0.0001);

  delete model;
}

void complex_functional_test() {
  Model *model = new ModelImpl("acceptance_3");
  System &q1 = model->create_system("q1", 100.0);
  System &q2 = model->create_system("q2", 0.0);
  System &q3 = model->create_system("q3", 100.0);
  System &q4 = model->create_system("q4", 0.0);
  System &q5 = model->create_system("q5", 0.0);

  Flow &f = model->create_flow<ExponentialFlow>("f", &q1, &q2);
  Flow &t = model->create_flow<ExponentialFlow>("t", &q2, &q3);
  Flow &u = model->create_flow<ExponentialFlow>("u", &q3, &q4);
  Flow &v = model->create_flow<ExponentialFlow>("v", &q4, &q1);
  Flow &g = model->create_flow<ExponentialFlow>("g", &q1, &q3);
  Flow &r = model->create_flow<ExponentialFlow>("r", &q2, &q5);

  model->execute(0, 100, 1);

  assert(fabs((round((q1.get_value() * 10000)) - 10000 * 31.8513)) < 0.0001);
  assert(fabs((round((q2.get_value() * 10000)) - 10000 * 18.4003)) < 0.0001);
  assert(fabs((round((q3.get_value() * 10000)) - 10000 * 77.1143)) < 0.0001);
  assert(fabs((round((q4.get_value() * 10000)) - 10000 * 56.1728)) < 0.0001);
  assert(fabs((round((q5.get_value() * 10000)) - 10000 * 16.4612)) < 0.0001);

  delete model;
}

int main() {
  exponential_functional_test();
  logistical_functional_test();
  complex_functional_test();

  return EXIT_SUCCESS;
}