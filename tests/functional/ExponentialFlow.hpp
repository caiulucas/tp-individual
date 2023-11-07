#include "../../src/models/Flow.hpp"

class ExponentialFlow : public Flow {
public:
  ExponentialFlow(int id, string title);

  virtual double execute() const;
};