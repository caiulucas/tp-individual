// Adicionar um fluxo
class MyFlow : public Flow {
public:
  MyFlow() : Flow() {}

  double execute() { return this->get_source().get_value() * 0.01; }
};

int main() {
  Model model(1, "use_case_2");
  Flow f1(1, "f1");
  model.add(1, "f1");
}