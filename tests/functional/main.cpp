
#include "../../src/models/Model.hpp"
#include "../../src/models/System.hpp"
#include "ExponentialFlow.hpp"
#include "LogisticalFlow.hpp"
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>

void only_one_system() {
  Model model(1, "model_1");
  System s1(1, "q1", 0);
  model.add(&s1);

  assert(model.get_systems().size() == 1);
  assert(model.get_systems()[0] == &s1);
}

void only_one_flow() {
  Model model(1, "model_1");
  ExponentialFlow f1(1, "f1");
  model.add(&f1);

  assert(model.get_flows().size() == 1);
  assert(model.get_flows()[0] == &f1);
}

void flow_with_source_without_target() {
  Model model(1, "use_case_3");
  System s1(1, "q1", 0);
  ExponentialFlow f1(1, "f1");
  model.add(&s1);
  model.add(&f1);
  f1.set_source(&s1);

  assert(model.get_flows()[0]->get_source() == &s1);
  assert(f1.get_source() == &s1);
}

void flow_without_source_with_target() {
  Model model(1, "use_case_3");
  System s1(1, "q1", 0);
  ExponentialFlow f1(1, "f1");
  model.add(&s1);
  model.add(&f1);
  f1.set_target(&s1);

  assert(model.get_flows()[0]->get_target() == &s1);
  assert(f1.get_target() == &s1);
}

void flow_with_source_with_target() {
  Model model(1, "use_case_3");
  System s1(1, "q1", 0);
  System s2(2, "q2", 0);
  ExponentialFlow f1(1, "f1");
  model.add(&s1);
  model.add(&s2);
  model.add(&f1);
  f1.set_source(&s1);
  f1.set_target(&s2);

  assert(model.get_flows()[0]->get_source() == &s1);
  assert(f1.get_source() == &s1);
  assert(model.get_flows()[0]->get_target() == &s2);
  assert(f1.get_target() == &s2);
}

void two_flows_with_same_source() {
  Model model(1, "use_case_3");
  System s1(1, "q1", 0);
  ExponentialFlow f1(1, "f1");
  ExponentialFlow f2(2, "f2");
  model.add(&s1);
  model.add(&f1);
  model.add(&f2);
  f1.set_source(&s1);
  f2.set_source(&s1);

  assert(model.get_flows()[0]->get_source() == &s1);
  assert(f1.get_source() == &s1);
  assert(model.get_flows()[1]->get_source() == &s1);
  assert(f2.get_source() == &s1);
}

void two_flows_with_same_target() {
  Model model(1, "use_case_3");
  System s1(1, "q1", 0);
  ExponentialFlow f1(1, "f1");
  ExponentialFlow f2(2, "f2");
  model.add(&s1);
  model.add(&f1);
  model.add(&f2);
  f1.set_target(&s1);
  f2.set_target(&s1);

  assert(model.get_flows()[0]->get_target() == &s1);
  assert(f1.get_target() == &s1);
  assert(model.get_flows()[1]->get_target() == &s1);
  assert(f2.get_target() == &s1);
}

void various_systems_and_flows() {
  Model model(1, "use_case_8");
  System s1(1, "q1", 0);
  System s2(2, "q2", 0);
  System s3(3, "q3", 0);
  ExponentialFlow f1(1, "f1");
  ExponentialFlow f2(2, "f2");
  ExponentialFlow f3(3, "f3");

  model.add(&s1);
  model.add(&s2);
  model.add(&s3);
  model.add(&f1);
  model.add(&f2);
  model.add(&f3);

  f1.set_target(&s1);

  f2.set_source(&s2);
  f2.set_target(&s1);

  f3.set_source(&s1);
  f3.set_target(&s3);

  assert(model.get_systems().size() == 3);
  assert(model.get_systems()[0] == &s1);
  assert(model.get_systems()[1] == &s2);
  assert(model.get_systems()[2] == &s3);

  assert(model.get_flows().size() == 3);
  assert(model.get_flows()[0] == &f1);
  assert(model.get_flows()[1] == &f2);
  assert(model.get_flows()[2] == &f3);
}

void cyclic_model() {
  Model model(1, "use_case_9");
  System s1(1, "q1", 0);
  System s2(2, "q2", 0);
  System s3(3, "q3", 0);
  ExponentialFlow f1(1, "f1");
  ExponentialFlow f2(2, "f2");
  ExponentialFlow f3(3, "f3");

  model.add(&s1);
  model.add(&s2);
  model.add(&s3);
  model.add(&f1);
  model.add(&f2);
  model.add(&f3);

  f1.set_source(&s1);
  f1.set_target(&s2);

  f2.set_source(&s2);
  f2.set_target(&s3);

  f3.set_source(&s3);
  f3.set_target(&s1);

  assert(model.get_systems().size() == 3);
  assert(model.get_systems()[0] == &s1);
  assert(model.get_systems()[1] == &s2);
  assert(model.get_systems()[2] == &s3);

  assert(model.get_flows().size() == 3);
  assert(model.get_flows()[0] == &f1);
  assert(model.get_flows()[1] == &f2);
  assert(model.get_flows()[2] == &f3);

  assert(f1.get_source() == &s1);
  assert(f1.get_target() == &s2);
  assert(f2.get_source() == &s2);
  assert(f2.get_target() == &s3);
  assert(f3.get_source() == &s3);
}

void two_flows_one_system() {
  Model model(1, "use_case_9");
  System s1(1, "q1", 0);
  ExponentialFlow f1(1, "f1");
  ExponentialFlow f2(2, "f2");

  model.add(&s1);
  model.add(&f1);
  model.add(&f2);

  f1.set_target(&s1);
  f2.set_source(&s1);
}

void exponential_functional_test() {
  Model model(1, "model_1");
  System s1(1, "pop1", 100.0);
  System s2(2, "pop2", 0.0);
  ExponentialFlow f1(1, "Exponencial");

  model.add(&s1);
  model.add(&s2);
  model.add(&f1);

  f1.set_source(&s1);
  f1.set_target(&s2);

  model.execute(0, 100, 1);

  assert(fabs((round((s1.get_value() * 10000)) - 10000 * 36.6032)) < 0.0001);
  assert(fabs((round((s2.get_value() * 10000)) - 10000 * 63.3968)) < 0.0001);
}

void logistical_functional_test() {
  Model model(1, "model_1");
  System s1(1, "pop1", 100.0);
  System s2(2, "pop2", 10.0);
  LogisticalFlow f1(1, "Logístico");

  model.add(&s1);
  model.add(&s2);
  model.add(&f1);

  f1.set_source(&s1);
  f1.set_target(&s2);

  model.execute(0, 100, 1);

  // TODO - Fix this test (value * 10000 truncated to int)
  assert(fabs((round((s1.get_value() * 10000)) - 10000 * 88.2167)) < 0.0001);
  assert(fabs((round((s2.get_value() * 10000)) - 10000 * 21.7833)) < 0.0001);
}

void complex_functional_test() {
  Model model(1, "acceptance_3");
  System q1(1, "q1", 100.0);
  System q2(2, "q2", 0.0);
  System q3(3, "q3", 100.0);
  System q4(4, "q4", 0.0);
  System q5(5, "q5", 0.0);

  ExponentialFlow f(1, "f");
  ExponentialFlow t(2, "t");
  ExponentialFlow u(3, "u");
  ExponentialFlow v(4, "v");
  ExponentialFlow g(5, "g");
  ExponentialFlow r(6, "r");

  model.add(&q1);
  model.add(&q2);
  model.add(&q3);
  model.add(&q4);
  model.add(&q5);

  model.add(&f);
  model.add(&t);
  model.add(&u);
  model.add(&v);
  model.add(&g);
  model.add(&r);

  f.set_source(&q1);
  f.set_target(&q2);

  t.set_source(&q2);
  t.set_target(&q3);

  u.set_source(&q3);
  u.set_target(&q4);

  v.set_source(&q4);
  v.set_target(&q1);

  g.set_source(&q1);
  g.set_target(&q3);

  r.set_source(&q2);
  r.set_target(&q5);

  model.execute(0, 100, 1);

  assert(fabs((round((q1.get_value() * 10000)) - 10000 * 31.8513)) < 0.0001);
  assert(fabs((round((q2.get_value() * 10000)) - 10000 * 18.4003)) < 0.0001);
  assert(fabs((round((q3.get_value() * 10000)) - 10000 * 77.1143)) < 0.0001);
  assert(fabs((round((q4.get_value() * 10000)) - 10000 * 56.1728)) < 0.0001);
  assert(fabs((round((q5.get_value() * 10000)) - 10000 * 16.4612)) < 0.0001);
}

int main() {
  only_one_system();
  only_one_flow();
  flow_with_source_without_target();
  flow_without_source_with_target();
  flow_with_source_with_target();
  two_flows_with_same_source();
  two_flows_with_same_target();
  various_systems_and_flows();
  cyclic_model();

  exponential_functional_test();
  logistical_functional_test();
  complex_functional_test();

  return EXIT_SUCCESS;
}