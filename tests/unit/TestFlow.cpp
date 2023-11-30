#include "TestFlow.hpp"

TestFlow::TestFlow() : FlowImpl() {}

TestFlow::TestFlow(std::string title) : FlowImpl(title) {}

TestFlow::TestFlow(std::string title, System *source, System *target)
    : FlowImpl(title, source, target) {}

TestFlow::TestFlow(Flow &flow) : FlowImpl(flow) {}

double TestFlow::execute() const { return get_source()->get_value() * 0.01; }