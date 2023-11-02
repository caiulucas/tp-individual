#pragma once

#include "Element.h"
#include "Flow.h"
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

class Model {
private:
  int id;
  string title;
  vector<Element> elements;

public:
  Model();

  Model(int id, string title, vector<Element> elements);

  Model(const Model &other);

  Model &operator=(const Model &other);

  virtual ~Model();

  bool add_element(Element element);

  bool remove_element(Element element);

  bool execute(int initial_time, int end_time, int step);
};