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
  Flow();

  Flow(int id, string title);

  /**
   * Constructor that creates a new Flow.
   *
   * @param id The id of the Flow.
   * @param title The title of the Flow.
   * @param source The source of the Flow.
   * @param target The target of the Flow.
   */
  Flow(int id, string title, System *source, System *target);

  /**
   * Copy constructor that creates a new Flow.
   *
   * @param other The Flow to copy.
   */
  Flow(const Flow &other);

  Flow &operator=(const Flow &other);

  virtual ~Flow();

  int get_id() const;

  System *get_source() const;

  void set_source(System *source);

  System *get_target() const;

  void set_target(System *target);

  bool clear_source();

  bool clear_target();

  virtual double execute() const = 0;
};