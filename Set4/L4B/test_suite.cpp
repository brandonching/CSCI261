#include "test_suite.h"
#include "linked_list_functions.h"

#include <iomanip>
#include <iostream>
using namespace std;

const int MESSAGE_WIDTH = 60;

int test_int(int &testNum, const string MESSAGE, const int LHS, const int RHS)  {
    cout << "Test #" << setw(3) << right << ++testNum;
    cout << setw(MESSAGE_WIDTH) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " !!>FAILED<!! Returned: \"" << LHS << "\" != Expected: \"" << RHS << "\"\n";
    return LHS == RHS ? 1 : 0;
}

int test_node_pointer(int &testNum, const string MESSAGE, const Node* LHS, const Node* RHS)  {
    cout << "Test #" << setw(3) << right << ++testNum;
    cout << setw(MESSAGE_WIDTH) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
        cout << "    PASSED   \n";
    else
        cout << " !!>FAILED<!! Returned: \"" << LHS << "\" != Expected: \"" << RHS << "\"\n";
    return LHS == RHS ? 1 : 0;
}

int test_node_pointer_not(int &testNum, const string MESSAGE, const Node* LHS, const Node* RHS)  {
    cout << "Test #" << setw(3) << right << ++testNum;
    cout << setw(MESSAGE_WIDTH) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS != RHS)
        cout << "    PASSED   \n";
    else
        cout << " !!>FAILED<!! Returned: \"" << LHS << "\" != Expected: \"" << RHS << "\"\n";
    return LHS != RHS ? 1 : 0;
}

bool run_all_tests()  {
    int totalPassed = 0, totalNumTests = 0;

    Node *pHead = nullptr;

    cout << "Testing growing the list" << endl << endl;

    totalPassed += test_node_pointer( totalNumTests, "Testing linked list head is null", pHead, nullptr);

    pHead = linked_list_make_node(5);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing make_node pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing make_node value", pHead->value, 5);
    totalPassed += test_node_pointer( totalNumTests, "Testing make_node pNext", pHead->pNext, nullptr);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 1);

    pHead = linked_list_add_value_to_front(pHead, 3);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing add_value_to_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing add_value_to_front value", pHead->value, 3);
    totalPassed += test_int( totalNumTests, "Testing add_value_to_front value", pHead->pNext->value, 5);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing add_value_to_front pNext", pHead->pNext, nullptr);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 2);

    pHead = linked_list_add_value_to_front(pHead, 1);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing add_value pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing add_value value", pHead->value, 1);
    totalPassed += test_int( totalNumTests, "Testing add_value value", pHead->pNext->value, 3);
    totalPassed += test_int( totalNumTests, "Testing add_value value", pHead->pNext->pNext->value, 5);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing make_node pNext", pHead->pNext, nullptr);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing make_node pNext", pHead->pNext->pNext, nullptr);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 3);

    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 0), 1);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 1), 3);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 2), 5);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, -1), -1);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 3), -1);

    pHead = linked_list_add_value_to_front(pHead, 2);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing add_value_to_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing add_value_to_front value", linked_list_get_value_at_position(pHead, 0), 2);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 4);

    pHead = linked_list_add_value_to_front(pHead, 4);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing add_value_to_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing add_value_to_front value", linked_list_get_value_at_position(pHead, 0), 4);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 5);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(0)", linked_list_get_value_at_position(pHead, 0), 4);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(1)", linked_list_get_value_at_position(pHead, 1), 2);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(2)", linked_list_get_value_at_position(pHead, 2), 1);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(3)", linked_list_get_value_at_position(pHead, 3), 3);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(4)", linked_list_get_value_at_position(pHead, 4), 5);

    cout << endl << "Testing accessing the list" << endl << endl;

    totalPassed += test_int( totalNumTests, "Testing min", linked_list_min(pHead), 1);

    totalPassed += test_int( totalNumTests, "Testing max", linked_list_max(pHead), 5);

    totalPassed += test_int( totalNumTests, "Testing find(1)", linked_list_find(pHead, 1), 2);
    totalPassed += test_int( totalNumTests, "Testing find(2)", linked_list_find(pHead, 2), 1);
    totalPassed += test_int( totalNumTests, "Testing find(3)", linked_list_find(pHead, 3), 3);
    totalPassed += test_int( totalNumTests, "Testing find(4)", linked_list_find(pHead, 4), 0);
    totalPassed += test_int( totalNumTests, "Testing find(5)", linked_list_find(pHead, 5), 4);
    totalPassed += test_int( totalNumTests, "Testing find(6)", linked_list_find(pHead, 6), -1);

    cout << endl << "Testing shrinking the list" << endl << endl;

    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing remove_node_from_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing remove_node_from_front value", pHead->value, 2);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 4);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(0)", linked_list_get_value_at_position(pHead, 0), 2);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(1)", linked_list_get_value_at_position(pHead, 1), 1);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(2)", linked_list_get_value_at_position(pHead, 2), 3);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(3)", linked_list_get_value_at_position(pHead, 3), 5);

    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing linked_list_remove_node_from_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing linked_list_remove_node_from_front value", pHead->value, 1);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 3);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(0)", linked_list_get_value_at_position(pHead, 0), 1);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(1)", linked_list_get_value_at_position(pHead, 1), 3);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(2)", linked_list_get_value_at_position(pHead, 2), 5);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(3)", linked_list_get_value_at_position(pHead, 3), -1);

    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing linked_list_remove_node_from_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing linked_list_remove_node_from_front value", pHead->value, 3);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 2);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 0), 3);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 1), 5);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 2), -1);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 3), -1);

    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing linked_list_remove_node_from_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 1);

    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer( totalNumTests, "Testing linked_list_remove_node_from_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 0);

    cout << endl << "Testing manipulating the list" << endl << endl;

    pHead = linked_list_add_value_to_front(pHead, 7);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 0), 7);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 1);

    pHead = linked_list_add_value_to_front(pHead, 11);
    pHead = linked_list_add_value_to_front(pHead, 13);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 1), 11);

    pHead = linked_list_set_value_at_position(pHead, 1, 15);
    totalPassed += test_int( totalNumTests, "Testing set_value_at_position(1)", linked_list_get_value_at_position(pHead, 1), 15);

    pHead = linked_list_set_value_at_position(pHead, -1, 17);
    pHead = linked_list_set_value_at_position(pHead, 14, 19);
    totalPassed += test_int( totalNumTests, "Testing set_value_at_position(-1)", linked_list_get_value_at_position(pHead, 0), 13);
    totalPassed += test_int( totalNumTests, "Testing set_value_at_position(14)", linked_list_get_value_at_position(pHead, 2), 7);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(1)", linked_list_get_value_at_position(pHead, 1), 15);

    pHead = linked_list_remove_node_from_front(pHead);
    pHead = linked_list_remove_node_from_front(pHead);
    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer( totalNumTests, "Testing linked_list_remove_node_from_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 0);

    pHead = linked_list_add_value_to_front(pHead, 8);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position", linked_list_get_value_at_position(pHead, 0), 8);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 1);

    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer( totalNumTests, "Testing linked_list_remove_node_from_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 0);

    cout << endl << "Performing Tests on empty list" << endl << endl;

    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer( totalNumTests, "Testing linked_list_remove_node_from_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 0);

    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer( totalNumTests, "Testing linked_list_remove_node_from_front pointer value", pHead, nullptr);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 0);

    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(3)", linked_list_get_value_at_position(pHead, 3), -1);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(0)", linked_list_get_value_at_position(pHead, 0), -1);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(-1)", linked_list_get_value_at_position(pHead, -1), -1);

    totalPassed += test_int( totalNumTests, "Testing min", linked_list_min(pHead), -1);

    totalPassed += test_int( totalNumTests, "Testing max", linked_list_max(pHead), -1);

    totalPassed += test_int( totalNumTests, "Testing find(1)", linked_list_find(pHead, 1), -1);

    cout << endl << "Performing Tests with duplicate values" << endl << endl;

    pHead = linked_list_add_value_to_front(pHead, 9);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(0)", linked_list_get_value_at_position(pHead, 0), 9);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 1);

    pHead = linked_list_add_value_to_front(pHead, 9);
    totalPassed += test_int( totalNumTests, "Testing get_value_at_position(0)", linked_list_get_value_at_position(pHead, 0), 9);
    totalPassed += test_int( totalNumTests, "Testing get_size", linked_list_get_size(pHead), 2);

    totalPassed += test_int( totalNumTests, "Testing min", linked_list_min(pHead), 9);

    totalPassed += test_int( totalNumTests, "Testing max", linked_list_max(pHead), 9);

    totalPassed += test_int( totalNumTests, "Testing find(9)", linked_list_find(pHead, 9), 0);

    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer_not( totalNumTests, "Testing linked_list_remove_node_from_front pointer value", pHead, nullptr);
    pHead = linked_list_remove_node_from_front(pHead);
    totalPassed += test_node_pointer( totalNumTests, "Testing linked_list_remove_node_from_front pointer value", pHead, nullptr);

    cout << endl << "Sanity check" << endl << endl;

    totalPassed += test_int( totalNumTests, "Testing 1==1", 1, 1);
    
    cout << endl;
    cout << "Tests Passed: " << setw(3) << right << totalPassed << " / " << setw(3) << totalNumTests << " (" << setprecision(0) << fixed << totalPassed * 100.0f / totalNumTests << "%)" << endl << endl;
    return (totalPassed == totalNumTests);
}