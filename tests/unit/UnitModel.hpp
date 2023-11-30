#pragma once

/**
 * @file
 * @brief Contains unit tests for the Model class.
 */

/**
 * @brief Test case for constructing a model.
 *
 * This test verifies the construction of a model object.
 */
void unit_model_constructor();

/**
 * @brief Test case for constructing a model with ID and title.
 *
 * This test verifies the construction of a model object with specified ID
 * and title.
 */
void unit_model_constructor_with_id_and_title();

/**
 * @brief Test case for retrieving the title of a model.
 *
 * This test verifies the functionality of the get_title() method.
 */
void unit_model_get_title();

/**
 * @brief Test case for adding a system to a model.
 *
 * This test verifies the functionality of adding a system to the model.
 */
void unit_model_add_system();

/**
 * @brief Test case for removing a system from a model.
 *
 * This test verifies the functionality of removing a system from the model.
 */
void unit_model_remove_system();

/**
 * @brief Test case for adding a flow to a model.
 *
 * This test verifies the functionality of adding a flow to the model.
 */
void unit_model_add_flow();

/**
 * @brief Test case for removing a flow from a model.
 *
 * This test verifies the functionality of removing a flow from the model.
 */
void unit_model_remove_flow();

/**
 * @brief Test case for iterating through systems in a model (begin).
 *
 * This test verifies the functionality of beginning iteration through
 * systems in the model.
 */
void unit_model_systems_begin();

/**
 * @brief Test case for iterating through systems in a model (end).
 *
 * This test verifies the functionality of ending iteration through systems in
 * the model.
 */
void unit_model_systems_end();

/**
 * @brief Test case for iterating through flows in a model (begin).
 *
 * This test verifies the functionality of beginning iteration through flows in
 * the model.
 */
void unit_model_flows_begin();

/**
 * @brief Test case for iterating through flows in a model (end).
 *
 * This test verifies the functionality of ending iteration through flows in the
 * model.
 */
void unit_model_flows_end();

/**
 * @brief Test case for executing a model.
 *
 * This test verifies the functionality of executing the model.
 */
void unit_model_execute();

/**
 * @brief Run all tests related to the UnitModel class.
 *
 * This function executes all the tests for the UnitModel class.
 */
void run_model_unit_tests();
