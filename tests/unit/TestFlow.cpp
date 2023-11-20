#include "TestFlow.hpp"

TestFlow::TestFlow() : FlowImpl() {}

TestFlow::TestFlow(int id, string title) : FlowImpl(id, title) {}

TestFlow::TestFlow(int id, string title, System *source, System *target)
    : FlowImpl(id, title, source, target) {}

TestFlow::TestFlow(Flow &flow) : FlowImpl(flow) {}

double TestFlow::execute() const { return get_source()->get_value() * 0.01; }