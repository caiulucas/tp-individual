#include "ModelHandle.hpp"

ModelHandle::ModelHandle() {
  _pImpl->set_title("Model");
  add((Model *)_pImpl);
}

ModelHandle::ModelHandle(std::string title) {
  _pImpl->set_title(title);
  add((Model *)_pImpl);
}

ModelHandle::~ModelHandle() {
  for (auto it = models_begin(); it != models_end(); ++it) {
    if (*it == _pImpl) {
      remove_model(*it);
      break;
    }
  }
}

std::string ModelHandle::get_title() const { return _pImpl->get_title(); }

Model &ModelHandle::create_model(std::string title) {
  return _pImpl->create_model(title);
}

System &ModelHandle::create_system(std::string name, double value) {
  return _pImpl->create_system(name, value);
}

bool ModelHandle::remove_system(System *system) {
  return _pImpl->remove_system(system);
}

bool ModelHandle::remove_flow(Flow *flow) { return _pImpl->remove_flow(flow); }

bool ModelHandle::remove_model(Model *model) {
  return _pImpl->remove_model(model);
}

Model::ModelIterator ModelHandle::models_begin() const {
  return _pImpl->models_begin();
}

Model::ModelIterator ModelHandle::models_end() const {
  return _pImpl->models_end();
}

Model::SystemIterator ModelHandle::systems_begin() const {
  return _pImpl->systems_begin();
}

Model::SystemIterator ModelHandle::systems_end() const {
  return _pImpl->systems_end();
}

Model::FlowIterator ModelHandle::flows_begin() const {
  return _pImpl->flows_begin();
}

Model::FlowIterator ModelHandle::flows_end() const {
  return _pImpl->flows_end();
}

int ModelHandle::execute(int initial_time, int end_time, int step) const {
  return _pImpl->execute(initial_time, end_time, step);
}
