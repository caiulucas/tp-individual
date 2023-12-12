#include "TestFlow.hpp"

TestFlow::TestFlow() : FlowBody() {}

TestFlow::TestFlow(std::string title) : FlowBody(title) {}

TestFlow::TestFlow(std::string title, System *source, System *target)
    : FlowBody(title, source, target) {}

TestFlow::TestFlow(Flow &flow) : FlowBody(flow) {}

double TestFlow::execute() const { return get_source()->get_value() * 0.01; }