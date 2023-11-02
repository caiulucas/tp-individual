class ExponentialFlow : public Flow {
public:
  ExponentialFlow() : Flow() {}

  double execute() { return this.get_source().get_value() * 0.01; }
};

int main() {
  Model model(1, "acceptance_3");
  System q1(1, "q1");
  System q1(2, "q2");
  System q1(3, "q3");
  System q1(4, "q4");
  System q1(5, "q5");

  ExponentialFlow f(1, "f");
  ExponentialFlow g(2, "g");
  ExponentialFlow r(3, "r");
  ExponentialFlow t(4, "t");
  ExponentialFlow u(5, "u");
  ExponentialFlow v(6, "v");

  model.add(q1);
  model.add(q2);
  model.add(q3);
  model.add(q4);
  model.add(q5);

  model.add(f);
  model.add(g);
  model.add(r);
  model.add(t);
  model.add(u);
  model.add(v);

  f.set_source(q1);
  f.set_target(q2);

  g.set_source(q1);
  g.set_target(q3);

  r.set_source(q2);
  r.set_target(q5);

  t.set_source(q2);
  t.set_target(q3);

  u.set_source(q3);
  u.set_target(q4);

  v.set_source(q4);
  v.set_target(q1);

  // Run the model with a time step of 1 until time 100 starting from 0.
  model.execute(0, 100, 1);
}