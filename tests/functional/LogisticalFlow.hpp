#include "../../src/models/Flow.hpp"

class LogisticalFlow : public Flow {
public:
  LogisticalFlow(int id, string title);

  virtual double execute() const;
};