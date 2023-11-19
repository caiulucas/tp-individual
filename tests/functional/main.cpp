#include "../../src/models/Model.hpp"
#include "../../src/models/ModelImpl.hpp"
#include "../../src/models/System.hpp"
#include "../../src/models/SystemImpl.hpp"
#include "ExponentialFlow.hpp"
#include "LogisticalFlow.hpp"
#include "tests.hpp"
#include <cassert>
#include <cmath>

void exponential_functional_test() {
  Model *model = new ModelImpl(1, "model_1");
  System *s1 = new SystemImpl(1, "pop1", 100.0);
  System *s2 = new SystemImpl(2, "pop2", 0.0);
  ExponentialFlow *f1 = new ExponentialFlow(1, "Exponencial");

  model->add(s1);
  model->add(s2);
  model->add(f1);

  f1->set_source(s1);
  f1->set_target(s2);

  model->execute(0, 100, 1);

  assert(fabs((round((s1->get_value() * 10000)) - 10000 * 36.6032)) < 0.0001);
  assert(fabs((round((s2->get_value() * 10000)) - 10000 * 63.3968)) < 0.0001);

  delete s1;
  delete s2;
  delete f1;
  delete model;
}

void logistical_functional_test() {
  Model *model = new ModelImpl(1, "model_1");
  System *s1 = new SystemImpl(1, "pop1", 100.0);
  System *s2 = new SystemImpl(2, "pop2", 10.0);
  LogisticalFlow *f1 = new LogisticalFlow(1, "Logístico");

  model->add(s1);
  model->add(s2);
  model->add(f1);

  f1->set_source(s1);
  f1->set_target(s2);

  model->execute(0, 100, 1);

  assert(fabs((round((s1->get_value() * 10000)) - 10000 * 88.2167)) < 0.0001);
  assert(fabs((round((s2->get_value() * 10000)) - 10000 * 21.7833)) < 0.0001);

  delete s1;
  delete s2;
  delete f1;
  delete model;
}

void complex_functional_test() {
  Model *model = new ModelImpl(1, "acceptance_3");
  System *q1 = new SystemImpl(1, "q1", 100.0);
  System *q2 = new SystemImpl(2, "q2", 0.0);
  System *q3 = new SystemImpl(3, "q3", 100.0);
  System *q4 = new SystemImpl(4, "q4", 0.0);
  System *q5 = new SystemImpl(5, "q5", 0.0);

  ExponentialFlow *f = new ExponentialFlow(1, "f");
  ExponentialFlow *t = new ExponentialFlow(2, "t");
  ExponentialFlow *u = new ExponentialFlow(3, "u");
  ExponentialFlow *v = new ExponentialFlow(4, "v");
  ExponentialFlow *g = new ExponentialFlow(5, "g");
  ExponentialFlow *r = new ExponentialFlow(6, "r");

  model->add(q1);
  model->add(q2);
  model->add(q3);
  model->add(q4);
  model->add(q5);

  model->add(f);
  model->add(t);
  model->add(u);
  model->add(v);
  model->add(g);
  model->add(r);

  f->set_source(q1);
  f->set_target(q2);

  t->set_source(q2);
  t->set_target(q3);

  u->set_source(q3);
  u->set_target(q4);

  v->set_source(q4);
  v->set_target(q1);

  g->set_source(q1);
  g->set_target(q3);

  r->set_source(q2);
  r->set_target(q5);

  model->execute(0, 100, 1);

  assert(fabs((round((q1->get_value() * 10000)) - 10000 * 31.8513)) < 0.0001);
  assert(fabs((round((q2->get_value() * 10000)) - 10000 * 18.4003)) < 0.0001);
  assert(fabs((round((q3->get_value() * 10000)) - 10000 * 77.1143)) < 0.0001);
  assert(fabs((round((q4->get_value() * 10000)) - 10000 * 56.1728)) < 0.0001);
  assert(fabs((round((q5->get_value() * 10000)) - 10000 * 16.4612)) < 0.0001);

  delete q1;
  delete q2;
  delete q3;
  delete q4;
  delete q5;
  delete f;
  delete t;
  delete u;
  delete v;
  delete g;
  delete r;
  delete model;
}

int main() {
  exponential_functional_test();
  logistical_functional_test();
  complex_functional_test();

  return EXIT_SUCCESS;
}