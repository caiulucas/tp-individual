#pragma once

#include "Flow.hpp"

/**
 * @brief Represents a flow in a simulation model.
 */
class FlowImpl : public Flow {
private:
  int m_id;         ///< The ID of the flow.
  string m_title;   ///< The title of the flow.
  System *m_source; ///< The source system of the flow.
  System *m_target; ///< The target system of the flow.

public:
  /**
   * @brief Default constructor.
   */
  FlowImpl();

  /**
   * @brief Parameterized constructor.
   * @param id The ID of the flow.
   * @param title The title of the flow.
   */
  FlowImpl(int id, string title);

  /**
   * @brief Parameterized constructor with source and target systems.
   * @param id The ID of the flow.
   * @param title The title of the flow.
   * @param source The source system of the flow.
   * @param target The target system of the flow.
   */
  FlowImpl(int id, string title, System *source, System *target);

  /**
   * @brief Copy constructor.
   * @param other The flow to be copied.
   */
  FlowImpl(const Flow &other);

  /**
   * @brief Assignment operator.
   * @param other The flow to be assigned.
   * @return Reference to the assigned flow.
   */
  FlowImpl &operator=(const Flow &other);

  /**
   * @brief Virtual destructor.
   */
  virtual ~FlowImpl();

  /**
   * @brief Gets the ID of the flow.
   * @return The ID of the flow.
   */
  virtual int get_id() const;

  /**
   * @brief Get the title object
   * @return The title of the flow.
   */
  virtual string get_title() const;

  /**
   * @brief Gets the source system of the flow.
   * @return Pointer to the source system.
   */

  virtual System *get_source() const;

  /**
   * @brief Sets the source system of the flow.
   * @param source Pointer to the source system.
   */
  virtual void set_source(System *source);

  /**
   * @brief Gets the target system of the flow.
   * @return Pointer to the target system.
   */
  virtual System *get_target() const;

  /**
   * @brief Sets the target system of the flow.
   * @param target Pointer to the target system.
   */
  virtual void set_target(System *target);

  /**
   * @brief Clears the source system of the flow.
   * @return True if the source was cleared successfully, false otherwise.
   */
  virtual bool clear_source();

  /**
   * @brief Clears the target system of the flow.
   * @return True if the target was cleared successfully, false otherwise.
   */
  virtual bool clear_target();

  /**
   * @brief Virtual method to execute the flow.
   * @return The result of the flow execution.
   */
  virtual double execute() const = 0;
};
