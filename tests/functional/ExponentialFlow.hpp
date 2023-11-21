#include "../../src/models/FlowImpl.hpp"

/**
 * @brief Represents an exponential flow in a simulation model.
 */
class ExponentialFlow : public FlowImpl {
public:
  /**
   * @brief Constructor for ExponentialFlow.
   * @param id The ID of the exponential flow.
   * @param title The title of the exponential flow.
   */
  ExponentialFlow(int id, std::string title);

  /**
   * @brief Executes the exponential flow.
   * @return The result of the exponential flow execution.
   */
  virtual double execute() const;
};
