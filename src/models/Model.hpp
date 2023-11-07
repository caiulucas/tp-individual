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
  Model();

  Model(int id, string title);

  Model(const Model &other);

  Model &operator=(const Model &other);

  virtual ~Model();

  bool add(System *system);

  bool add(Flow *flow);

  vector<System *> get_systems() const;

  vector<Flow *> get_flows() const;

  bool execute(int initial_time, int end_time, int step);
};