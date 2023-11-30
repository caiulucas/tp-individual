#pragma once

/**
 * @file
 * @brief Contains unit tests for the Flow class.
 */

/**
 * @brief Test case for constructing a flow.
 *
 * This test verifies the construction of a flow object.
 */
void unit_flow_constructor();

/**
 * @brief Test case for constructing a flow with ID and title.
 *
 * This test verifies the construction of a flow object with specified ID
 * and title.
 */
void unit_flow_constructor_with_id_and_title();

/**
 * @brief Test case for constructing a flow with all fields.
 *
 * This test verifies the construction of a flow object with all specified
 * fields.
 */
void unit_flow_constructor_with_all_fields();

/**
 * @brief Test case for copying a flow.
 *
 * This test verifies the copy constructor of the flow class.
 */
void unit_flow_constructor_copy();

/**
 * @brief Test case for retrieving the title of a flow.
 *
 * This test verifies the functionality of the get_title() method.
 */
void unit_flow_get_title();

/**
 * @brief Test case for retrieving the source of a flow.
 *
 * This test verifies the functionality of the get_source() method.
 */
void unit_flow_get_source();

/**
 * @brief Test case for setting the source of a flow.
 *
 * This test verifies the functionality of the set_source() method.
 */
void unit_flow_set_source();

/**
 * @brief Test case for clearing the source of a flow.
 *
 * This test verifies the functionality of the clear_source() method.
 */
void unit_flow_clear_source();

/**
 * @brief Test case for retrieving the target of a flow.
 *
 * This test verifies the functionality of the get_target() method.
 */
void unit_flow_get_target();

/**
 * @brief Test case for setting the target of a flow.
 *
 * This test verifies the functionality of the set_target() method.
 */
void unit_flow_set_target();

/**
 * @brief Test case for clearing the target of a flow.
 *
 * This test verifies the functionality of the clear_target() method.
 */
void unit_flow_clear_target();

/**
 * @brief Test case for executing a flow.
 *
 * This test verifies the functionality of the execute() method.
 */
void unit_flow_execute();

/**
 * @brief Run all tests related to the UnitFlow class.
 *
 * This function executes all the tests for the UnitFlow class.
 */
void run_flow_unit_tests();
