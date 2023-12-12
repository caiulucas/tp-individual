#pragma once

#include "Body.hpp"
#include "Flow.hpp"
#include "Model.hpp"
#include <vector>

/**
 * @brief Represents a simulation model.
 */
class ModelBody : public Model, public Body {
private:
  std::string m_title;                  ///< The title of the model
  std::vector<System *> m_systems;      ///< The systems in the model.
  std::vector<Flow *> m_flows;          ///< The flows in the model.
  static std::vector<Model *> m_models; ///< The models of the application.

  /**
   * @brief Default constructor.
   */
  ModelBody();

  /**
   * @brief Parameterized constructor.
   * @param title The title of the model.
   */
  ModelBody(std::string title);

  /**
   * @brief Copy constructor (private to prevent unintended usage).
   */
  ModelBody(const Model &other);

  /**
   * @brief Destructor of the model.
   */
  virtual ~ModelBody();

  /**
   * @brief Assignment operator (private to prevent unintended usage).
   */
  ModelBody &operator=(const Model &other);

  /**
   * @brief Adds a model to the application.
   * @param model Pointer to the Model object to be added.
   * @return True if the model was added successfully, false otherwise.
   */
  static bool add(Model *model);

  /**
   * @brief Adds a system to the model.
   * @param system Pointer to the System object to be added.
   * @return True if the system was added successfully, false otherwise.
   */
  virtual bool add(System *system);

protected:
  /**
   * @brief Adds a flow to the model.
   * @param flow Pointer to the Flow object to be added.
   * @return True if the flow was added successfully, false otherwise.
   */
  virtual bool add(Flow *flow);

public:
  /**
   * @brief Returns the title of the model.
   * @return The title of the model.
   */
  virtual std::string get_title() const;

  /**
   * @brief Sets the title of the model.
   * @param title The new title of the model.
   */
  virtual void set_title(const std::string &title);

  /**
   * @brief Create a model object and add it to the list of models.
   *
   * @param title The title of the model.
   * @return Model& A Model object.
   */
  static Model &create_model(std::string title);

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
   * @brief Removes a model from the application.
   * @param model Pointer to the Model object to be removed.
   * @return The confirmation of the removal.
   */
  static bool remove_model(Model *model);

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
   * @brief Returns an iterator pointing to the beginning of the models.
   * @return ModelIterator
   */
  virtual ModelIterator models_begin() const;

  /**
   * @brief Returns an iterator pointing to the end of the models.
   * @return ModelIterator
   */
  virtual ModelIterator models_end() const;

  /**
   * @brief Executes the model within the specified time range.
   * @param initial_time The starting time of the simulation.
   * @param end_time The ending time of the simulation.
   * @param step The time step for the simulation.
   * @return The number of steps executed.
   */
  virtual int execute(int initial_time, int end_time, int step) const;
};