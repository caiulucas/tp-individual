#pragma once

#include <string>
#include <vector>

using namespace std;

/**
 * @brief Represents a system in a simulation model.
 */
class System {
public:
  /**
   * @brief Destructor.
   */
  virtual ~System(){};

  /**
   * @brief Gets the ID of the system.
   * @return The ID of the system.
   */
  virtual int get_id() const = 0;

  /**
   * @brief Gets the current value of the system.
   * @return The current value of the system.
   */
  virtual double get_value() const = 0;

  /**
   * @brief Sets a new value for the system.
   * @param new_value The new value to be set.
   */
  virtual void set_value(double new_value) = 0;
};
