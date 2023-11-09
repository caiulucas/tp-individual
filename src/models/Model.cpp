#include "Model.hpp"

using namespace std;

Model::Model() {}

Model::Model(int id, string title)
    : m_id(id), m_title(title), m_systems({}), m_flows({}) {}

Model::Model(const Model &other) {
  if (this != &other) {
    m_id = other.m_id;
    m_title = other.m_title;
    m_systems = other.m_systems;
    m_flows = other.m_flows;
  }
}

Model::SystemIterator Model::systems_begin() const { return m_systems.begin(); }

Model::SystemIterator Model::systems_end() const { return m_systems.end(); }

Model::FlowIterator Model::flows_begin() const { return m_flows.begin(); }

Model::FlowIterator Model::flows_end() const { return m_flows.end(); }

// TODO proibir a cópia
Model &Model::operator=(const Model &other) {
  if (this == &other)
    return *this;

  m_id = other.m_id;
  m_title = other.m_title;

  for (SystemIterator it = other.systems_begin(); it != other.systems_end();
       ++it) {
    add(*it);
  }
  for (FlowIterator it = other.flows_begin(); it != other.flows_end(); ++it) {
    add(*it);
  }
  return *this;
}

Model::~Model(){};

bool Model::add(System *system) {
  for (System *&s : m_systems) {
    if (s->get_id() == system->get_id()) {
      return false;
    }
  }

  m_systems.push_back(system);
  return true;
}

bool Model::add(Flow *flow) {
  for (Flow *&f : m_flows) {
    if (f->get_id() == flow->get_id()) {
      return false;
    }
  }

  m_flows.push_back(flow);
  return true;
}

bool Model::execute(int initial_time, int end_time, int step) {
  for (int i = initial_time; i < end_time; i += step) {
    double flows_results[m_flows.size()];

    for (auto it = m_flows.begin(); it != m_flows.end(); ++it) {
      double result = (*it)->execute();
      flows_results[it - m_flows.begin()] = result;
    }

    for (size_t j = 0; j < m_flows.size(); j++) {
      System *source = m_flows[j]->get_source();
      source->set_value(source->get_value() - flows_results[j]);

      System *target = m_flows[j]->get_target();
      target->set_value(target->get_value() + flows_results[j]);
    }
  }

  return true;
}
