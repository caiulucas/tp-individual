#pragma once

#include "Flow.hpp"
#include "System.hpp"
#include <vector>

/**
 * @brief Represents a simulation model.
 */
class Model {

public:
  /**
   * @brief Destructor of the model.
   */
  virtual ~Model(){};

  /**
   * @brief Returns the ID of the model.
   * @return The ID of the model.
   */
  virtual int get_id() const = 0;

  /**
   * @brief Returns the title of the model.
   * @return The title of the model.
   */
  virtual std::string get_title() const = 0;

  /**
   * @brief Adds a system to the model.
   * @param system Pointer to the System object to be added.
   * @return True if the system was added successfully, false otherwise.
   */
  virtual bool add(System *system) = 0;

  /**
   * @brief Adds a flow to the model.
   * @param flow Pointer to the Flow object to be added.
   * @return True if the flow was added successfully, false otherwise.
   */
  virtual bool add(Flow *flow) = 0;

  /**
   * @brief Iterator for accessing systems in the model.
   */
  typedef std::vector<System *>::const_iterator SystemIterator;

  /**
   * @brief Returns an iterator pointing to the beginning of the systems.
   * @return Iterator pointing to the beginning of the systems.
   */
  virtual SystemIterator systems_begin() const = 0;

  /**
   * @brief Returns an iterator pointing to the end of the systems.
   * @return Iterator pointing to the end of the systems.
   */
  virtual SystemIterator systems_end() const = 0;

  /**
   * @brief Iterator for accessing flows in the model.
   */
  typedef std::vector<Flow *>::const_iterator FlowIterator;

  /**
   * @brief Returns an iterator pointing to the beginning of the flows.
   * @return Iterator pointing to the beginning of the flows.
   */
  virtual FlowIterator flows_begin() const = 0;

  /**
   * @brief Returns an iterator pointing to the end of the flows.
   * @return Iterator pointing to the end of the flows.
   */
  virtual FlowIterator flows_end() const = 0;

  /**
   * @brief Executes the model within the specified time range.
   * @param initial_time The starting time of the simulation.
   * @param end_time The ending time of the simulation.
   * @param step The time step for the simulation.
   * @return The number of steps executed
   */
  virtual int execute(int initial_time, int end_time, int step) const = 0;
};