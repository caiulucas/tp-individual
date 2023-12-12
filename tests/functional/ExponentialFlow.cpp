#include "ExponentialFlow.hpp"

ExponentialFlow::ExponentialFlow(std::string title) : FlowBody(title) {}

ExponentialFlow::ExponentialFlow(std::string title, System *source,
                                 System *target)
    : FlowBody(title, source, target) {}

double ExponentialFlow::execute() const {
  return get_source()->get_value() * 0.01;
}