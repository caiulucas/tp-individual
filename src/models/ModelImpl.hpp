#pragma once

#include "Model.hpp"

/**
 * @brief Represents a simulation model.
 */
class ModelImpl : public Model {
private:
  int m_id;                   ///< The ID of the model.
  string m_title;             ///< The title of the model
  vector<System *> m_systems; ///< The systems in the model.
  vector<Flow *> m_flows;     ///< The flows in the model.

  /**
   * @brief Copy constructor (private to prevent unintended usage).
   */
  ModelImpl(const ModelImpl &other);

  /**
   * @brief Assignment operator (private to prevent unintended usage).
   */
  ModelImpl &operator=(const ModelImpl &other);

public:
  /**
   * @brief Default constructor.
   */
  ModelImpl();

  /**
   * @brief Parameterized constructor.
   * @param id The ID of the model.
   * @param title The title of the model.
   */
  ModelImpl(int id, string title);

  /**
   * @brief Destructor of the model.
   */
  virtual ~ModelImpl();

  /**
   * @brief Adds a system to the model.
   * @param system Pointer to the System object to be added.
   * @return True if the system was added successfully, false otherwise.
   */
  virtual bool add(System *system);

  /**
   * @brief Adds a flow to the model.
   * @param flow Pointer to the Flow object to be added.
   * @return True if the flow was added successfully, false otherwise.
   */
  virtual bool add(Flow *flow);

  /**
   * @brief Iterator for accessing systems in the model.
   */
  typedef vector<System *>::const_iterator SystemIterator;

  /**
   * @brief Returns an iterator pointing to the beginning of the systems.
   * @return Iterator pointing to the beginning of the systems.
   */
  virtual SystemIterator systems_begin() const;

  /**
   * @brief Returns an iterator pointing to the end of the systems.
   * @return Iterator pointing to the end of the systems.
   */
  virtual SystemIterator systems_end() const;

  /**
   * @brief Iterator for accessing flows in the model.
   */
  typedef vector<Flow *>::const_iterator FlowIterator;

  /**
   * @brief Returns an iterator pointing to the beginning of the flows.
   * @return Iterator pointing to the beginning of the flows.
   */
  virtual FlowIterator flows_begin() const;

  /**
   * @brief Returns an iterator pointing to the end of the flows.
   * @return Iterator pointing to the end of the flows.
   */
  virtual FlowIterator flows_end() const;

  /**
   * @brief Executes the model within the specified time range.
   * @param initial_time The starting time of the simulation.
   * @param end_time The ending time of the simulation.
   * @param step The time step for the simulation.
   * @return True if the execution was successful, false otherwise.
   */
  virtual bool execute(int initial_time, int end_time, int step) const;
};