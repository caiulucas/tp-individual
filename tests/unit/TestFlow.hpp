#include "../../src/models/FlowImpl.hpp"

/**
 * @brief TestFlow class derived from FlowImpl.
 *
 * This class extends the functionality of FlowImpl and is used for testing
 * purposes.
 */
class TestFlow : public FlowImpl {

public:
  /**
   * @brief Default constructor for TestFlow.
   */
  TestFlow();

  /**
   * @brief Constructor for TestFlow with ID and title.
   *
   * @param id The ID of the TestFlow.
   * @param title The title of the TestFlow.
   */
  TestFlow(int id, std::string title);

  /**
   * @brief Constructor for TestFlow with ID, title, source, and target systems.
   *
   * @param id The ID of the TestFlow.
   * @param title The title of the TestFlow.
   * @param source The source system for the TestFlow.
   * @param target The target system for the TestFlow.
   */
  TestFlow(int id, std::string title, System *source, System *target);

  /**
   * @brief Copy constructor for TestFlow.
   *
   * @param flow Another Flow object to copy from.
   */
  TestFlow(Flow &flow);

  /**
   * @brief Virtual method to execute the TestFlow.
   *
   * @return The execution result.
   */
  virtual double execute() const;
};
