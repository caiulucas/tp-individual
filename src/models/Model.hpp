#pragma once

#include "Flow.hpp"
#include "System.hpp"
#include <cstddef>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

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
  typedef vector<System *>::const_iterator SystemIterator;

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
  typedef vector<Flow *>::const_iterator FlowIterator;

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
   * @return True if the execution was successful, false otherwise.
   */
  virtual bool execute(int initial_time, int end_time, int step) const = 0;
};