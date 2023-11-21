#include "ExponentialFlow.hpp"

ExponentialFlow::ExponentialFlow(int id, std::string title)
    : FlowImpl(id, title) {}

double ExponentialFlow::execute() const {
  return get_source()->get_value() * 0.01;
}