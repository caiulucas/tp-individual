#pragma once

#include "System.hpp"

/**
 * @brief Represents a system in a simulation model.
 */
class SystemImpl : public System {
private:
  int m_id;            ///< The ID of the system.
  std::string m_title; ///< The title of the system.
  double m_value;      ///< The value associated with the system.

public:
  /**
   * @brief Default constructor.
   */
  SystemImpl();

  /**
   * @brief Parameterized constructor.
   * @param id The ID of the system.
   * @param title The title of the system.
   * @param value The initial value of the system.
   */
  SystemImpl(int id, std::string title, double value);

  /**
   * @brief Copy constructor.
   * @param other The system to be copied.
   */
  SystemImpl(const System &other);

  /**
   * @brief Assignment operator.
   * @param other The system to be assigned.
   * @return Reference to the assigned system.
   */
  virtual SystemImpl &operator=(const SystemImpl &other);

  /**
   * @brief Destructor.
   */
  virtual ~SystemImpl();

  /**
   * @brief Gets the ID of the system.
   * @return The ID of the system.
   */
  virtual int get_id() const;

  /**
   * @brief Gets the title of the system.
   * @return The title of the system.
   */
  virtual std::string get_title() const;

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