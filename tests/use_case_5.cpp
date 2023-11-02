// Adicionar um fluxo e um sistema
class MyFlow : public Flow {
public:
  MyFlow() : Flow() {}

  double execute() { return this->get_source().get_value() * 0.01; }
};

int main() {
  Model model(1, "use_case_5");
  System s1(1, "q1");
  System s2(2, "q2");
  MyFlow f1(1, "f1");
  model.add(s1);
  model.add(f1);
  model.add(s2);
  f1.set_source(s1);
  f1.set_target(s2);
}