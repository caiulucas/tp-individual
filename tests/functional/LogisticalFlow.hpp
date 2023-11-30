#include "../../src/models/FlowImpl.hpp"

/**
 * @brief Represents a logistical flow in a simulation model.
 */
class LogisticalFlow : public FlowImpl {
public:
  /**
   * @brief Constructor for LogisticalFlow.
   * @param title The title of the logistical flow.
   */
  LogisticalFlow(std::string title);

  /**
   * @brief Executes the logistical flow.
   * @return The result of the logistical flow execution.
   */
  virtual double execute() const;
};
