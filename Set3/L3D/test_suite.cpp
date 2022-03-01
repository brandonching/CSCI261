#include "test_suite.h"
#include "array_functions.h"

#include <iomanip>
#include <iostream>
using namespace std;

const int MESSAGE_WIDTH = 35;

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

int test_int_pointer(int &testNum, const string MESSAGE, const int* LHS, const int* RHS)  {
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

int test_int_pointer_not(int &testNum, const string MESSAGE, const int* LHS, const int* RHS)  {
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

    int *pArray = nullptr;
    int currArraySize = 10;
    
    array_allocate(pArray, currArraySize);
    totalPassed += test_int_pointer_not(   totalNumTests,  "Testing array_allocate",              pArray , nullptr );
    totalPassed += test_int(               totalNumTests,  "Testing array_allocate size",         currArraySize , 10 );
    totalPassed += test_int(               totalNumTests,  "Testing array_get_element_at()",      array_get_element_at(pArray, currArraySize, 3), 0 );
    
    for(int i = 0; i < currArraySize; i++) {
        array_set_element_at(pArray, currArraySize, i, 1);
    }
    totalPassed += test_int(               totalNumTests,  "Testing array_set_element_at()",      array_get_element_at(pArray, currArraySize, 3), 1 );
    totalPassed += test_int(               totalNumTests,  "Testing array_set_element_at()",      array_get_element_at(pArray, currArraySize, 7), 1 );
    totalPassed += test_int(               totalNumTests,  "Testing array_get_element_at()",      array_get_element_at(pArray, currArraySize, -1), 0 );
    totalPassed += test_int(               totalNumTests,  "Testing array_get_element_at()",      array_get_element_at(pArray, currArraySize, 13), 0 );
    
    array_set_element_at(pArray, currArraySize, 3, 3);
    totalPassed += test_int(               totalNumTests,  "Testing array_set_element_at()",      array_get_element_at(pArray, currArraySize, 3), 3 );
    
    array_deallocate(pArray, currArraySize);
    totalPassed += test_int_pointer(       totalNumTests,  "Testing array_deallocate",            pArray , nullptr );
    totalPassed += test_int(               totalNumTests,  "Testing array_deallocate size",       currArraySize , 0 );

    array_allocate(pArray, currArraySize);
    totalPassed += test_int_pointer_not(   totalNumTests,  "Testing array_allocate empty",        pArray , nullptr );
    
    array_insert_at_position(pArray, currArraySize, currArraySize+1, 5);
    totalPassed += test_int(               totalNumTests,  "Testing array_insert size",           currArraySize , 1 );
    totalPassed += test_int(               totalNumTests,  "Testing array_insert_at() back",      array_get_element_at(pArray, currArraySize, 0), 5 );

    array_insert_at_position(pArray, currArraySize, currArraySize, 3);
    totalPassed += test_int(               totalNumTests,  "Testing array_insert size",           currArraySize , 2 );
    totalPassed += test_int(               totalNumTests,  "Testing array_insert_at() back",      array_get_element_at(pArray, currArraySize, 1), 3 );
    
    array_insert_at_position(pArray, currArraySize, 0, 2);
    totalPassed += test_int(               totalNumTests,  "Testing array_insert size",           currArraySize , 3 );
    totalPassed += test_int(               totalNumTests,  "Testing array_insert_at() front",     array_get_element_at(pArray, currArraySize, 1), 5 );
    totalPassed += test_int(               totalNumTests,  "Testing array_insert_at() front",     array_get_element_at(pArray, currArraySize, 0), 2 );
    
    array_insert_at_position(pArray, currArraySize, -5, -1);
    totalPassed += test_int(               totalNumTests,  "Testing array_insert size",           currArraySize , 4 );
    totalPassed += test_int(               totalNumTests,  "Testing array_insert_at() front",     array_get_element_at(pArray, currArraySize, 0), -1 );
    
    array_insert_at_position(pArray, currArraySize, 30, 20);
    totalPassed += test_int(               totalNumTests,  "Testing array_insert size",           currArraySize , 5 );
    totalPassed += test_int(               totalNumTests,  "Testing array_insert_at() back",      array_get_element_at(pArray, currArraySize, 4), 20 );
    
    array_insert_at_position(pArray, currArraySize, 2, 12);
    totalPassed += test_int(               totalNumTests,  "Testing array_insert size",           currArraySize , 6 );
    totalPassed += test_int(               totalNumTests,  "Testing array_insert_at() pos 2",     array_get_element_at(pArray, currArraySize, 2), 12 );
    
    totalPassed += test_int(               totalNumTests,  "Testing array_min",                   array_min(pArray, currArraySize), -1 );
    totalPassed += test_int(               totalNumTests,  "Testing array_max",                   array_max(pArray, currArraySize), 20 );
    
    array_remove_from_position(pArray, currArraySize, currArraySize);
    totalPassed += test_int(               totalNumTests,  "Testing array_remove size",           currArraySize , 5 );
    totalPassed += test_int(               totalNumTests,  "Testing array_remove_from() back",    array_get_element_at(pArray, currArraySize, currArraySize-1) , 3 );
    
    array_remove_from_position(pArray, currArraySize, 0);
    totalPassed += test_int(               totalNumTests,  "Testing array_remove size",           currArraySize , 4 );
    totalPassed += test_int(               totalNumTests,  "Testing array_remove_from() front",   array_get_element_at(pArray, currArraySize, 0) , 2 );
    
    array_insert_at_position(pArray, currArraySize, currArraySize, 12);
    totalPassed += test_int(               totalNumTests,  "Testing array_find()",                array_find(pArray, currArraySize, 12), 1 );
    totalPassed += test_int(               totalNumTests,  "Testing array_find()",                array_find(pArray, currArraySize, 25), -1 );
    totalPassed += test_int(               totalNumTests,  "Testing array_find()",                array_find(pArray, currArraySize, 3), 3 );

    array_remove_from_position(pArray, currArraySize, currArraySize);
    array_remove_from_position(pArray, currArraySize, 1);
    totalPassed += test_int(               totalNumTests,  "Testing array_remove size",        currArraySize , 3 );
    totalPassed += test_int(               totalNumTests,  "Testing array_remove_from() pos 1",array_get_element_at(pArray, currArraySize, 1) , 5 );

    array_remove_from_position(pArray, currArraySize, -2);
    totalPassed += test_int(               totalNumTests,  "Testing array_remove size",        currArraySize , 2 );
    totalPassed += test_int(               totalNumTests,  "Testing array_remove_from() front",array_get_element_at(pArray, currArraySize, 0) , 5 );

    array_remove_from_position(pArray, currArraySize, 2);
    totalPassed += test_int(               totalNumTests,  "Testing array_remove size",        currArraySize , 1 );
    totalPassed += test_int(               totalNumTests,  "Testing array_remove_from() back", array_get_element_at(pArray, currArraySize, currArraySize-1) , 5 );

    array_remove_from_position(pArray, currArraySize, 2);
    totalPassed += test_int(               totalNumTests,  "Testing array_remove size",        currArraySize , 0 );

    array_remove_from_position(pArray, currArraySize, 2);
    totalPassed += test_int(               totalNumTests,  "Testing array_remove size",        currArraySize , 0 );
    totalPassed += test_int(               totalNumTests,  "Testing array_min",                array_min(pArray, currArraySize), 0 );
    totalPassed += test_int(               totalNumTests,  "Testing array_max",                array_max(pArray, currArraySize), 0 );

    array_deallocate(pArray, currArraySize);
    totalPassed += test_int(               totalNumTests,  "Testing array_min",                array_min(pArray, currArraySize), 0 );
    totalPassed += test_int(               totalNumTests,  "Testing array_max",                array_max(pArray, currArraySize), 0 );
    
    cout << endl;
    cout << "Tests Passed: " << setw(3) << right << totalPassed << " / " << setw(3) << totalNumTests << " (" << setprecision(0) << fixed << totalPassed * 100.0f / totalNumTests << "%)" << endl << endl;
    return (totalPassed == totalNumTests);
}