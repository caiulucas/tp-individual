#include "LogisticalFlow.hpp"

LogisticalFlow::LogisticalFlow(int id, string title) : Flow(id, title) {}

double LogisticalFlow::execute() const {
  double value = get_target()->get_value();
  return 0.01 * value * (1 - value / 70);
}
