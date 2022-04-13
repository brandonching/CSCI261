/* CSCI 261: Assignment 5: Lab 5D - Sorting II & Recursion II: Merge Sort via
 the Call Stack
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: sorting list
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "mergeSort.hpp"

// Library namespace
using namespace std;

// Constants

int main() {
  // build list
  LinkedList<int> *list = new LinkedList<int>;
  list->pushBack(4);
  list->pushBack(3);
  list->pushBack(8);
  list->pushBack(1);
  list->pushBack(5);
  list->pushBack(9);
  list->pushBack(7);
  list->pushBack(2);
  list->pushBack(6);

  // print list
  cout << "Print List Forward: ";
  list->print();

  // Sort the list
  cout << endl << endl << "Sorting... " << endl << endl;
  mergeSort(list);

  // Print sorted list
  cout << "Print List Forward: ";
  list->print();
  delete list;
  return 0;
}