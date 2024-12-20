#pragma once

#include "Body.hpp"
#include "System.hpp"

/**
 * @brief Represents a system in a simulation model.
 */
class SystemBody : public System, public Body {
private:
  std::string m_title; ///< The title of the system.
  double m_value;      ///< The value associated with the system.

public:
  /**
   * @brief Default constructor.
   */
  SystemBody();

  /**
   * @brief Creates a System implementation.
   * @param title The title of the system.
   * @param value The initial value of the system.
   */
  SystemBody(std::string title, double value);

  /**
   * @brief Copy constructor.
   * @param other The system to be copied.
   */
  SystemBody(const System &other);

  /**
   * @brief Assignment operator.
   * @param other The system to be assigned.
   * @return Reference to the assigned system.
   */
  virtual SystemBody &operator=(const SystemBody &other);

  /**
   * @brief Destructor.
   */
  virtual ~SystemBody();

  /**
   * @brief Gets the title of the system.
   * @return The title of the system.
   */
  virtual std::string get_title() const;

  /**
   * @brief Sets a new title for the system.
   * @param new_title The new title to be set.
   */
  virtual void set_title(std::string new_title);

  /**
   * @brief Gets the current value of the system.
   * @return The current value of the system.
   */
  virtual double get_value() const;

  /**
   * @brief Sets a new value for the system.
   * @param new_value The new value to be set.
   */
  virtual void set_value(double new_value);
};