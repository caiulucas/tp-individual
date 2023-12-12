#pragma once

#include "Flow.hpp"
#include "System.hpp"
#include <type_traits>
#include <vector>

/**
 * @brief Represents a simulation model.
 */
class Model {
protected:
  /**
   * @brief Adds a flow to the model.
   * @param flow Pointer to the Flow object to be added.
   * @return True if the flow was added successfully, false otherwise.
   */
  virtual bool add(Flow *flow) = 0;

  /**
   * @brief Adds a model to the application.
   * @param model Pointer to the Model object to be added.
   * @return True if the model was added successfully, false otherwise.
   */
  static bool add(Model *model);

public:
  /**
   * @brief Destructor of the model.
   */
  virtual ~Model(){};

  /**
   * @brief Returns the title of the model.
   * @return The title of the model.
   */
  virtual std::string get_title() const = 0;

  /**
   * @brief Create a model object
   *
   * @param title The title of the model.
   * @return Model& A Model that belongs to this model.
   */
  static Model &create_model(std::string title);

  /**
   * @brief Create a system object
   *
   * @param title The title of the system.
   * @param value The initial value of the system.
   * @return System& A System that belongs to this model.
   */
  virtual System &create_system(std::string title, double value) = 0;

  /**
   * @brief Removes a system from the model.
   * @param system Pointer to the System object to be removed.
   * @return The confirmation of the removal.
   */
  virtual bool remove_system(System *system) = 0;

  /**
   * @brief Create a flow object
   *
   * @param title The title of the flow
   * @return A Flow that belongs to this model.
   */
  template <typename T> Flow &create_flow(std::string title) {
    static_assert(std::is_base_of<Flow, T>::value, "T must inherit from Flow");

    T *flow = new T(title);
    add(flow);
    return *flow;
  }

  /**
   * @brief Create a flow object
   *
   * @param title The title of the flow
   * @param source The source system of the flow.
   * @param target The target system of the flow.
   * @return Flow & A Flow that belongs to this model.
   */
  template <typename T>
  Flow &create_flow(std::string title, System *source, System *target) {
    static_assert(std::is_base_of<Flow, T>::value, "T must inherit from Flow");

    T *flow = new T(title, source, target);
    add(flow);
    return *flow;
  };

  /**
   * @brief Removes a flow from the model.
   * @param flow Pointer to the Flow object to be removed.
   * @return The confirmation of the removal.
   */
  virtual bool remove_flow(Flow *flow) = 0;

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

  typedef std::vector<Model *>::const_iterator ModelIterator;

  /**
   * @brief Returns an iterator pointing to the beginning of the models.
   * @return Iterator pointing to the beginning of the models.
   */
  virtual ModelIterator models_begin() const = 0;

  /**
   * @brief Returns an iterator pointing to the end of the models.
   * @return Iterator pointing to the end of the models.
   */
  virtual ModelIterator models_end() const = 0;

  /**
   * @brief Executes the model within the specified time range.
   * @param initial_time The starting time of the simulation.
   * @param end_time The ending time of the simulation.
   * @param step The time step for the simulation.
   * @return The number of steps executed
   */
  virtual int execute(int initial_time, int end_time, int step) const = 0;
};