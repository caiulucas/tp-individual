#include "UnitFlow.hpp"
#include "UnitModel.hpp"
#include "UnitSystem.hpp"
#include <cstdlib>

#define DEBUGGING
#ifdef DEBUGGING
int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;
#endif

int main() {
  run_system_unit_tests();
  run_flow_unit_tests();
  run_model_unit_tests();

  return EXIT_SUCCESS;
}