#pragma once

#include "System.hpp"
#include <string>

class Flow {
private:
  int m_id;
  string m_title;
  System *m_source;
  System *m_target;

public:
  /**
   * Constructor that creates a new Flow.
   */
  Flow() {}

  Flow(int id, string title) : m_id(id), m_title(title) {}

  /**
   * Constructor that creates a new Flow.
   *
   * @param id The id of the Flow.
   * @param title The title of the Flow.
   * @param source The source of the Flow.
   * @param target The target of the Flow.
   */
  Flow(int id, string title, System *source, System *target)
      : m_id(id), m_title(title), m_source(source), m_target(target) {}

  /**
   * Copy constructor that creates a new Flow.
   *
   * @param other The Flow to copy.
   */
  Flow(const Flow &other) {
    if (this != &other) {
      m_id = other.m_id;
      m_title = other.m_title;
      m_source = other.m_source;
      m_target = other.m_target;
    }
  }

  Flow &operator=(const Flow &other) {
    if (this != &other) {
      m_source = other.m_source;
      m_target = other.m_target;
    }
    return *this;
  }

  virtual ~Flow(){};

  int get_id() const { return m_id; }

  System *get_source() const { return m_source; }

  void set_source(System *source) { m_source = source; }

  System *get_target() const { return m_target; }

  void set_target(System *target) { this->m_target = target; }

  bool clear_source() {
    if (m_source != nullptr) {
      m_source = nullptr;
      return true;
    }
    return false;
  }

  bool clear_target() {
    if (m_target != nullptr) {
      m_target = nullptr;
      return true;
    }

    return false;
  }

  virtual double execute() const = 0;
};