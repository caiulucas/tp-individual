#include "System.h"
#include "Element.h"

System::System(){};

System::System(int id, string title, double value)
    : Element(id, title), value(value) {}

System::System(const System &other) {
  if (this != &other) {
    value = other.value;
  }
}

System &System::operator=(const System &other) {
  if (this != &other) {
    value = other.value;
  }
  return *this;
}

System::~System(){};

const double System::get_value() { return value; }

void System::set_value(double new_value) { value = new_value; }