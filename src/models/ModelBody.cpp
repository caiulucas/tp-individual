#include "ModelBody.hpp"
#include "Flow.hpp"
#include "ModelBody.hpp"
#include "System.hpp"
#include "SystemBody.hpp"

std::vector<Model *> ModelBody::m_models;

ModelBody::ModelBody() {}

ModelBody::ModelBody(std::string title)
    : m_title(title), m_systems({}), m_flows({}) {}

ModelBody::ModelBody(const Model &other) {
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

ModelBody &ModelBody::operator=(const Model &other) {
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

ModelBody::~ModelBody() {
  if (!m_flows.empty()) {
    for (Flow *item : m_flows) {
      delete (item);
    }
    m_flows.clear();
  }

  // Delete Systems
  if (!m_systems.empty()) {
    for (System *item : m_systems) {
      delete (item);
    }
    m_systems.clear();
  }

  // Delete Model
  auto i = models_begin();
  for (Model *m : m_models) {
    if (this == (ModelBody *)m) {
      m_models.erase(i);
      break;
    }
    ++i;
  }
};

std::string ModelBody::get_title() const { return m_title; }

void ModelBody::set_title(const std::string &title) { m_title = title; }

Model &ModelBody::create_model(std::string title) {
  Model *model = new ModelBody(title);
  add(model);

  return *model;
}

System &ModelBody::create_system(std::string title, double value) {
  System *system = new SystemBody(title, value);
  add(system);

  return *system;
}

bool ModelBody::remove_system(System *system) {
  for (auto it = m_systems.begin(); it != m_systems.end(); ++it) {
    if (*it == system) {
      m_systems.erase(it);
      return true;
    }
  }

  return false;
}

bool ModelBody::remove_flow(Flow *flow) {
  for (auto it = m_flows.begin(); it != m_flows.end(); ++it) {
    if (*it == flow) {
      m_flows.erase(it);
      return true;
    }
  }

  return false;
}

bool ModelBody::remove_model(Model *model) {
  for (auto it = m_models.begin(); it != m_models.end(); ++it) {
    if (*it == model) {
      m_models.erase(it);
      return true;
    }
  }

  return false;
}

ModelBody::SystemIterator ModelBody::systems_begin() const {
  return m_systems.begin();
}

ModelBody::SystemIterator ModelBody::systems_end() const {
  return m_systems.end();
}

ModelBody::FlowIterator ModelBody::flows_begin() const {
  return m_flows.begin();
}

ModelBody::FlowIterator ModelBody::flows_end() const { return m_flows.end(); }

ModelBody::ModelIterator ModelBody::models_begin() const {
  return m_models.begin();
}

ModelBody::ModelIterator ModelBody::models_end() const {
  return m_models.end();
}

bool ModelBody::add(System *system) {
  m_systems.push_back(system);
  return true;
}

bool ModelBody::add(Flow *flow) {
  m_flows.push_back(flow);
  return true;
}

bool ModelBody::add(Model *model) {
  m_models.push_back(model);
  return true;
}

int ModelBody::execute(int initial_time, int end_time, int step) const {
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
  return ModelBody::create_model(title);
}
