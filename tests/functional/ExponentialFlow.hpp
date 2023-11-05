#include "../../src/models/Flow.hpp"

class ExponentialFlow : public Flow {
public:
  ExponentialFlow(int id, string title) : Flow(id, title) {}

  virtual double execute() const { return get_source()->get_value() * 0.01; }

  virtual ~ExponentialFlow() {}
};