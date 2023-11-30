#include "ExponentialFlow.hpp"

ExponentialFlow::ExponentialFlow(std::string title) : FlowImpl(title) {}

ExponentialFlow::ExponentialFlow(std::string title, System *source,
                                 System *target)
    : FlowImpl(title, source, target) {}

double ExponentialFlow::execute() const {
  return get_source()->get_value() * 0.01;
}