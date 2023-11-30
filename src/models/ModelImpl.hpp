#pragma once

#include "Flow.hpp"
#include "Model.hpp"
#include <vector>

/**
 * @brief Represents a simulation model.
 */
class ModelImpl : public Model {
private:
  std::string m_title;             ///< The title of the model
  std::vector<System *> m_systems; ///< The systems in the model.
  std::vector<Flow *> m_flows;     ///< The flows in the model.

  /**
   * @brief Copy constructor (private to prevent unintended usage).
   */
  ModelImpl(const Model &other);

  /**
   * @brief Assignment operator (private to prevent unintended usage).
   */
  ModelImpl &operator=(const Model &other);

protected:
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

public:
  /**
   * @brief Default constructor.
   */
  ModelImpl();

  /**
   * @brief Parameterized constructor.
   * @param title The title of the model.
   */
  ModelImpl(std::string title);

  /**
   * @brief Destructor of the model.
   */
  virtual ~ModelImpl();

  /**
   * @brief Returns the title of the model.
   * @return The title of the model.
   */
  virtual std::string get_title() const;

  /**
   * @brief Create a system object
   *
   * @param title The title of the system.
   * @param value The initial value of the system.
   * @return System& A System that belongs to this model.
   */
  virtual System &create_system(std::string title, double value);

  /**
   * @brief Removes a system from the model.
   * @param system Pointer to the System object to be removed.
   * @return The confirmation of the removal.
   */
  virtual bool remove_system(System *system);

  /**
   * @brief Removes a flow from the model
   * @param flow Pointer to the Flow object to be removed.
   * @return The confirmation of the removal.
   */
  virtual bool remove_flow(Flow *flow);

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
   * @return The number of steps executed.
   */
  virtual int execute(int initial_time, int end_time, int step) const;
};