class MyFlow : public Flow {
public:
  MyFlow() : Flow() {}

  double execute() { return this->get_source().get_value() * 0.01; }
};

int main() {
  Model model(1, "use_case_8");
  System s1(1, "q1");
  System s2(2, "q2");
  System s3(3, "q3");
  MyFlow f1(1, "f1");
  MyFlow f2(2, "f2");
  MyFlow f3(3, "f3");

  model.add(s1);
  model.add(s2);
  model.add(s3);
  model.add(f1);
  model.add(f2);
  model.add(f3);

  f1.set_target(s1);

  f2.set_source(s2);
  f2.set_target(s1);

  f3.set_source(s1);
  f3.set_target(s3);
}