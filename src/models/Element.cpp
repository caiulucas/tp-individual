#include "Element.h"

Element::Element() {}

Element::Element(int id, string title) : id(id), title(title) {}

Element::Element(const Element &other) {
  if (this != &other) {
    id = other.id;
    title = other.title;
  }
}

Element &Element::operator=(const Element &other) {
  if (this != &other) {
    id = other.id;
    title = other.title;
  }
  return *this;
}

Element ::~Element(){};

int Element::get_id() const { return id; }