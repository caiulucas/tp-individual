#pragma once

#include "Flow.hpp"
#include "System.hpp"
#include <cstddef>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

class Model {
private:
  int m_id;
  string m_title;
  vector<System *> m_systems;
  vector<Flow *> m_flows;

public:
  Model() {}

  Model(int id, string title)
      : m_id(id), m_title(title), m_systems({}), m_flows({}) {}

  Model(const Model &other) {
    if (this != &other) {
      m_id = other.m_id;
      m_title = other.m_title;
      m_systems = other.m_systems;
      m_flows = other.m_flows;
    }
  }

  Model &operator=(const Model &other) {
    if (this != &other) {
      m_id = other.m_id;
      m_title = other.m_title;
      m_systems = other.m_systems;
      m_flows = other.m_flows;
    }
    return *this;
  }

  virtual ~Model(){};

  bool add(System *system) {
    for (System *&s : m_systems) {
      if (s->get_id() == system->get_id()) {
        return false;
      }
    }

    m_systems.push_back(system);
    return true;
  }

  bool add(Flow *flow) {
    for (Flow *&f : m_flows) {
      if (f->get_id() == flow->get_id()) {
        return false;
      }
    }

    m_flows.push_back(flow);
    return true;
  }

  vector<System *> get_systems() const { return m_systems; }

  vector<Flow *> get_flows() const { return m_flows; }

  bool execute(int initial_time, int end_time, int step) {
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
};