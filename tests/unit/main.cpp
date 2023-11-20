#include "UnitFlow.hpp"
#include "UnitModel.hpp"
#include "UnitSystem.hpp"
#include <cstdlib>

int main() {
  run_system_unit_tests();
  run_flow_unit_tests();
  run_model_unit_tests();

  return EXIT_SUCCESS;
}