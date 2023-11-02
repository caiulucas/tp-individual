class LogisticFlow : public Flow {
public:
  LogisticFlow() : Flow() {}

  double execute() {
    double value = this.get_source().get_value();
    return 0.01 * value * (1 - value / 70);
  }
};

int main() {
  Model model(1, "acceptance_1");
  System s1(1, "q1");
  System s2(2, "q2");
  LogisticFlow f1(1, "f1");

  model.add(s1);
  model.add(s2);
  model.add(f1);

  f1.set_source(s1);
  f1.set_target(s2);

  // Run the model with a time step of 1 until time 100 starting from 0.
  model.execute(0, 100, 1);
}