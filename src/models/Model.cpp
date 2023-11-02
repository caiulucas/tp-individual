#include "Model.h"

Model::Model() {}

Model::Model(int id, string title, vector<Element> elements)
    : id(id), title(title), elements(elements) {}

Model::Model(const Model &other) {
  if (this != &other) {
    id = other.id;
    title = other.title;
    elements = other.elements;
  }
}

Model &Model ::operator=(const Model &other) {
  if (this != &other) {
    id = other.id;
    title = other.title;
    elements = other.elements;
  }
  return *this;
}

Model::~Model(){};

bool Model::add_element(Element element) {
  elements.push_back(element);
  return true;
}

bool Model::remove_element(Element element) {
  for (auto it = elements.begin(); it != elements.end(); ++it) {
    if (it->get_id() == element.get_id()) {
      elements.erase(it);
      return true;
    }
  }

  return false;
}

bool Model::execute(int initial_time, int end_time, int step) {
  vector<Flow> flows{};

  for (auto &element : elements) {
    if (typeid(element) == typeid(Flow)) {
      flows.push_back((Flow &)element);
    }
  }

  for (int i = initial_time; i <= end_time; i += step) {
    for (auto &flow : flows) {
      double result = flow.execute();
      flow.get_source()->set_value(flow.get_source()->get_value() - result);
      flow.get_target()->set_value(flow.get_target()->get_value() + result);
    }
  }

  return true;
}