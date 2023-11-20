#pragma once

#include "System.hpp"
#include <string>

/**
 * @brief Represents a flow in a simulation model.
 */
class Flow {

public:
  /**
   * @brief Virtual destructor.
   */
  virtual ~Flow(){};

  /**
   * @brief Gets the ID of the flow.
   * @return The ID of the flow.
   */
  virtual int get_id() const = 0;

  /**
   * @brief Gets the title of the flow.
   * @return The title of the flow.
   */
  virtual std::string get_title() const = 0;

  /**
   * @brief Gets the source system of the flow.
   * @return Pointer to the source system.
   */
  virtual System *get_source() const = 0;

  /**
   * @brief Sets the source system of the flow.
   * @param source Pointer to the source system.
   */
  virtual void set_source(System *source) = 0;

  /**
   * @brief Gets the target system of the flow.
   * @return Pointer to the target system.
   */
  virtual System *get_target() const = 0;

  /**
   * @brief Sets the target system of the flow.
   * @param target Pointer to the target system.
   */
  virtual void set_target(System *target) = 0;

  /**
   * @brief Clears the source system of the flow.
   * @return True if the source was cleared successfully, false otherwise.
   */
  virtual bool clear_source() = 0;

  /**
   * @brief Clears the target system of the flow.
   * @return True if the target was cleared successfully, false otherwise.
   */
  virtual bool clear_target() = 0;

  /**
   * @brief Virtual method to execute the flow.
   * @return The result of the flow execution.
   */
  virtual double execute() const = 0;
};
