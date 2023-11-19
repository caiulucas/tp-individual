#pragma once

/**
 * \brief A test function for the exponential functional model.
 *
 * GIVEN a model in the file /tests/examples/model_1.mdl \n
 * WHEN the user simulate the model \n
 * THEN the system pop_1 should have the value 36.6032 \n
 * AND the system pop_2 should have the value 63.3968 \n
 */
void exponential_functional_test();

/**
 * \brief A test function for the logistical functional model.
 *
 * GIVEN a model in the file /tests/examples/model_2.mdl \n
 * WHEN the user simulate the model \n
 * THEN the system pop_1 should have the value 88.2167 \n
 * AND the system pop_2 should have the value 21.7833 \n
 */
void logistical_functional_test();

/**
 * \brief A test function for the complex functional model.
 *
 * GIVEN a model in the file /tests/examples/model_3.mdl \n
 * WHEN the user simulate the model \n
 * THEN the system q1 should have the value 31.8513 \n
 * AND the system q2 should have the value 18.4003 \n
 * AND the system q3 should have the value 77.1143 \n
 * AND the system q4 should have the value 56.1728 \n
 * AND the system q5 should have the value 16.4612 \n
 */
void complex_functional_test();