#pragma once

#include "Flow.hpp"
#include "Handle.hpp"
#include <string>

template <typename T> class FlowHandle : public Flow, public Handle<T> {
public:
  FlowHandle();

  FlowHandle(std::string title, System *source, System *target);

  virtual ~FlowHandle();

  /**
   * @brief Get the title object
   * @return The title of the flow.
   */
  std::string get_title() const;

  /**
   * @brief Gets the source system of the flow.
   * @return Pointer to the source system.
   */

  System *get_source() const;

  /**
   * @brief Sets the source system of the flow.
   * @param source Pointer to the source system.
   */
  void set_source(System *source);

  /**
   * @brief Gets the target system of the flow.
   * @return Pointer to the target system.
   */
  System *get_target() const;

  /**
   * @brief Sets the target system of the flow.
   * @param target Pointer to the target system.
   */
  void set_target(System *target);

  /**
   * @brief Clears the source system of the flow.
   * @return True if the source was cleared successfully, false otherwise.
   */
  bool clear_source();

  /**
   * @brief Clears the target system of the flow.
   * @return True if the target was cleared successfully, false otherwise.
   */
  bool clear_target();
};