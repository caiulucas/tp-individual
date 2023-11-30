#pragma once

/**
 * @file
 * @brief Contains unit tests for the System class.
 */

/**
 * @brief Test case for constructing a System object.
 *
 * This test verifies the construction of a System object.
 */
void unit_system_constructor();

/**
 * @brief Test case for constructing a System object with initial fields.
 *
 * This test verifies the construction of a System object with specified
 * fields.
 */
void unit_system_constructor_with_fields();

/**
 * @brief Test case for copying a System object.
 *
 * This test verifies the copy constructor of the System class.
 */
void unit_system_constructor_copy();

/**
 * @brief Test case for retrieving the title of a System object.
 *
 * This test verifies the functionality of the get_title() method.
 */
void unit_system_get_title();

/**
 * @brief Test case for retrieving the value of a System object.
 *
 * This test verifies the functionality of the get_value() method.
 */
void unit_system_get_value();

/**
 * @brief Test case for setting the value of a System object.
 *
 * This test verifies the functionality of the set_value() method.
 */
void unit_system_set_value();

/**
 * @brief Run all unit tests related to the System class.
 *
 * This function executes all the unit tests for the System class.
 */
void run_system_unit_tests();
