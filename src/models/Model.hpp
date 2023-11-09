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

  Model(const Model &other);

  Model &operator=(const Model &other);

public:
  Model();

  Model(int id, string title);

  virtual ~Model();

  bool add(System *system);

  bool add(Flow *flow);

  typedef vector<System *>::const_iterator SystemIterator;
  SystemIterator systems_begin() const;
  SystemIterator systems_end() const;

  typedef vector<Flow *>::const_iterator FlowIterator;
  FlowIterator flows_begin() const;
  FlowIterator flows_end() const;

  bool execute(int initial_time, int end_time, int step);
};