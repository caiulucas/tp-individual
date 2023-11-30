#include "ModelImpl.hpp"
#include "Flow.hpp"
#include "System.hpp"
#include "SystemImpl.hpp"

std::vector<Model *> ModelImpl::m_models;

ModelImpl::ModelImpl() {}

ModelImpl::ModelImpl(std::string title)
    : m_title(title), m_systems({}), m_flows({}) {}

ModelImpl::ModelImpl(const Model &other) {
  if (this != &other) {
    m_title = other.get_title();

    for (SystemIterator it = other.systems_begin(); it != other.systems_end();
         ++it) {
      add(*it);
    }
    for (FlowIterator it = other.flows_begin(); it != other.flows_end(); ++it) {
      add(*it);
    }
  }
}

ModelImpl &ModelImpl::operator=(const Model &other) {
  if (this == &other)
    return *this;

  m_title = other.get_title();
  m_systems.clear();
  m_flows.clear();

  for (SystemIterator it = other.systems_begin(); it != other.systems_end();
       ++it) {
    add(*it);
  }
  for (FlowIterator it = other.flows_begin(); it != other.flows_end(); ++it) {
    add(*it);
  }
  return *this;
}

ModelImpl::~ModelImpl() {
  for (auto it = m_systems.begin(); it != m_systems.end(); ++it) {
    delete *it;
  }
  for (auto it = m_flows.begin(); it != m_flows.end(); ++it) {
    delete *it;
  }
};

std::string ModelImpl::get_title() const { return m_title; }

Model &ModelImpl::create_model(std::string title) {
  Model *model = new ModelImpl(title);
  add(model);

  return *model;
}

System &ModelImpl::create_system(std::string title, double value) {
  System *system = new SystemImpl(title, value);
  add(system);

  return *system;
}

bool ModelImpl::remove_system(System *system) {
  for (auto it = m_systems.begin(); it != m_systems.end(); ++it) {
    if (*it == system) {
      m_systems.erase(it);
      return true;
    }
  }

  return false;
}

bool ModelImpl::remove_flow(Flow *flow) {
  for (auto it = m_flows.begin(); it != m_flows.end(); ++it) {
    if (*it == flow) {
      m_flows.erase(it);
      return true;
    }
  }

  return false;
}

ModelImpl::SystemIterator ModelImpl::systems_begin() const {
  return m_systems.begin();
}

ModelImpl::SystemIterator ModelImpl::systems_end() const {
  return m_systems.end();
}

ModelImpl::FlowIterator ModelImpl::flows_begin() const {
  return m_flows.begin();
}

ModelImpl::FlowIterator ModelImpl::flows_end() const { return m_flows.end(); }

bool ModelImpl::add(System *system) {
  m_systems.push_back(system);
  return true;
}

bool ModelImpl::add(Flow *flow) {
  m_flows.push_back(flow);
  return true;
}

bool ModelImpl::add(Model *model) {
  m_models.push_back(model);

  return true;
}

int ModelImpl::execute(int initial_time, int end_time, int step) const {
  int steps_count = 0;

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

    steps_count++;
  }

  return steps_count;
}

Model &Model::create_model(std::string title) {
  return ModelImpl::create_model(title);
}
