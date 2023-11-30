#include "../../src/models/FlowImpl.hpp"

/**
 * @brief Represents an exponential flow in a simulation model.
 */
class ExponentialFlow : public FlowImpl {
public:
  /**
   * @brief Constructor for ExponentialFlow.
   * @param title The title of the exponential flow.
   */
  ExponentialFlow(std::string title);

  /**
   * @brief Constructor for ExponentialFlow.
   * @param title The title of the exponential flow.
   * @param source The source system of the exponential flow.
   * @param target The target system of the exponential flow.
   */
  ExponentialFlow(std::string title, System *source, System *target);

  /**
   * @brief Executes the exponential flow.
   * @return The result of the exponential flow execution.
   */
  virtual double execute() const;
};
