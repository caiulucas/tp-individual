#pragma once

#include <string>

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
   * @brief Gets the title of the system.
   * @return The title of the system.
   */
  virtual std::string get_title() const = 0;

  /**
   * @brief Sets a new title for the system.
   * @param new_title The new title to be set.
   */
  virtual void set_title(std::string new_title) = 0;

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
