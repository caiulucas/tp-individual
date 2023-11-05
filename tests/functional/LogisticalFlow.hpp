#include "../../src/models/Flow.hpp"

class LogisticalFlow : public Flow {
public:
  LogisticalFlow(int id, string title) : Flow(id, title) {}

  virtual double execute() const {
    double value = get_target()->get_value();
    return 0.01 * value * (1 - value / 70);
  }

  virtual ~LogisticalFlow() {}
};