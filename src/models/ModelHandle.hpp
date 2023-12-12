#pragma once

#include "Handle.hpp"
#include "Model.hpp"
#include "ModelBody.hpp"

class ModelHandle : public Model, public Handle<ModelBody> {
public:
  ModelHandle();

  /**
   * @brief Construct a new Model Handle object
   *
   * @param title
   */
  ModelHandle(std::string title);

  /**
   * @brief Destroy the Model Handle object
   *
   */
  ~ModelHandle();

  /**
   * @brief Returns the title of the model.
   * @return The title of the model.
   */
  std::string get_title() const;

  /**
   * @brief Create a model object and add it to the list of models.
   *
   * @param title The title of the model.
   * @return Model& A Model object.
   */
  Model &create_model(std::string title);

  /**
   * @brief Create a system object
   *
   * @param title The title of the system.
   * @param value The initial value of the system.
   * @return System& A System that belongs to this model.
   */
  System &create_system(std::string title, double value);

  /**
   * @brief Removes a system from the model.
   * @param system Pointer to the System object to be removed.
   * @return The confirmation of the removal.
   */
  bool remove_system(System *system);

  /**
   * @brief Removes a flow from the model
   * @param flow Pointer to the Flow object to be removed.
   * @return The confirmation of the removal.
   */
  bool remove_flow(Flow *flow);

  bool remove_model(Model *model);

  /**
   * @brief Returns an iterator pointing to the beginning of the systems.
   * @return Iterator pointing to the beginning of the systems.
   */
  SystemIterator systems_begin() const;

  /**
   * @brief Returns an iterator pointing to the end of the systems.
   * @return Iterator pointing to the end of the systems.
   */
  SystemIterator systems_end() const;

  /**
   * @brief Returns an iterator pointing to the beginning of the flows.
   * @return Iterator pointing to the beginning of the flows.
   */
  FlowIterator flows_begin() const;

  /**
   * @brief Returns an iterator pointing to the end of the flows.
   * @return Iterator pointing to the end of the flows.
   */
  FlowIterator flows_end() const;

  ModelIterator models_begin() const;

  ModelIterator models_end() const;

  /**
   * @brief Executes the model within the specified time range.
   * @param initial_time The starting time of the simulation.
   * @param end_time The ending time of the simulation.
   * @param step The time step for the simulation.
   * @return The number of steps executed.
   */
  int execute(int initial_time, int end_time, int step) const;
};