#pragma once

#include "Element.h"
#include "System.h"
#include <string>

class Flow : public Element {
private:
  System *source;
  System *target;

public:
  /**
   * Constructor that creates a new Flow.
   */
  Flow();

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

  virtual double execute();

  System *get_source();

  void set_source(System *new_source);

  System *get_target();

  void set_target(System *target);

  bool clear_source();

  bool clear_target();
};