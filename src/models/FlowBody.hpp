#pragma once

#include "Body.hpp"
#include "Flow.hpp"

/**
 * @brief Represents a flow in a simulation model.
 */
class FlowBody : public Flow, public Body {
private:
  std::string m_title; ///< The title of the flow.
  System *m_source;    ///< The source system of the flow.
  System *m_target;    ///< The target system of the flow.

public:
  /**
   * @brief Default constructor.
   */
  FlowBody();

  /**
   * @brief Parameterized constructor.
   * @param title The title of the flow.
   */
  FlowBody(std::string title);

  /**
   * @brief Parameterized constructor with source and target systems.
   * @param title The title of the flow.
   * @param source The source system of the flow.
   * @param target The target system of the flow.
   */
  FlowBody(std::string title, System *source, System *target);

  /**
   * @brief Copy constructor.
   * @param other The flow to be copied.
   */
  FlowBody(const Flow &other);

  /**
   * @brief Assignment operator.
   * @param other The flow to be assigned.
   * @return Reference to the assigned flow.
   */
  FlowBody &operator=(const Flow &other);

  /**
   * @brief Virtual destructor.
   */
  virtual ~FlowBody();

  /**
   * @brief Get the title object
   * @return The title of the flow.
   */
  virtual std::string get_title() const;

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
};
