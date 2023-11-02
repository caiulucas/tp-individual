#pragma once

#include <string>

using namespace std;

class Element {
private:
  int id;
  string title;

public:
  Element();

  Element(int id, string title);

  Element(const Element &other);

  Element &operator=(const Element &other);

  virtual ~Element();

  int get_id() const;
};