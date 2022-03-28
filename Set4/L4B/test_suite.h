#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <string>
using namespace std;

#include "Node.h"

/** 
 * @brief Test suite. Runs all tests.
 * @return true if all tests pass, false otherwise
 */
bool run_all_tests();

/**
 * @brief A generic test function, that simply prints "PASSED" if LHS equals RHS 
 * and otherwise prints FAILED. Do not modify this function.
 * 
 * @param testNum Number of the test.  Value will be incremented upon completion
 * @param MESSAGE description of test
 * @param LHS computed result
 * @param RHS expected result
 * @return 1 if test passed, 0 otherwise
 */
int test_node_pointer(int &testNum, const string MESSAGE, const Node* LHS, const Node* RHS);

/**
 * @brief A generic test function, that simply prints "PASSED" if LHS does not equal RHS 
 * and otherwise prints FAILED. Do not modify this function.
 * 
 * @param testNum Number of the test.  Value will be incremented upon completion
 * @param MESSAGE description of test
 * @param LHS computed result
 * @param RHS expected result
 * @return 1 if test passed, 0 otherwise
 */
int test_node_pointer_not(int &testNum, const string MESSAGE, const Node* LHS, const Node* RHS);

/**
 * @brief A generic test function, that simply prints "PASSED" if LHS equals RHS 
 * and otherwise prints FAILED. Do not modify this function.
 * 
 * @param testNum Number of the test.  Value will be incremented upon completion
 * @param MESSAGE description of test
 * @param LHS computed result
 * @param RHS expected result
 * @return 1 if test passed, 0 otherwise
 */
int test_int(int &testNum, const string MESSAGE, const int LHS, const int RHS);

#endif