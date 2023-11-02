#pragma once

#include "Element.h"
#include <string>

using namespace std;

class System : public Element {
private:
  double value;

public:
  /**
   * Constructor that creates a new System.
   */
  System();

  /**
   * Constructor that creates a new System.
   *
   * @param id The id of the System.
   * @param title The title of the System.
   * @param value The value of the System.
   */
  System(int id, string title, double value);

  /**
   * Copy constructor that creates a new System.
   *
   * @param other The System to copy.
   */
  System(const System &other);

  /**
   * Copy assignment operator that copies a System.
   *
   * @param other The System to copy.
   * @return The copied System.
   */
  System &operator=(const System &other);

  /**
   * Destructor that destroys a System.
   */
  virtual ~System() = 0;

  /**
   * Gets the id of the System.
   *
   * @return The id of the System.
   */
  const double get_value();

  /**
   * Sets the value of the System.
   *
   * @param new_value The new value of the System.
   */
  void set_value(double new_value);
};