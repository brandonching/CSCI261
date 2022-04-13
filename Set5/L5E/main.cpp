/* CSCI 261: Assignment 5: Lab 5E - Procedural and Object-Oriented
 the Call Stack
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: makeing and sorting rectangles
 */

// Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>  // For cin, cout, etc.

#include "mergeSort.hpp"
#include "rectangle.hpp"

// Library namespace
using namespace std;

// Constants

int main() {
  int rectCount;
  cout << "How many rectagles would you like to create?: ";
  cin >> rectCount;

  // Generate random seed
  srand(time(0));
  rand();

  // build list of random rectangles
  LinkedList<rectangle> *list = new LinkedList<rectangle>;
  for (int i = 0; i < rectCount; i++) {
    rectangle newRect;
    newRect.base = rand() / (double)RAND_MAX * (100 - 1) + 1;
    newRect.height = rand() / (double)RAND_MAX * (100 - 1) + 1;
    list->pushBack(newRect);
  }

  // print list
  cout << "Print List Forward: ";
  for (unsigned int i = 0; i < list->size(); i++) {
    rectangle thisRect = list->at(i);
    cout << thisRect.base << "X" << thisRect.height << " ";
  }

  // Sort the list
  cout << endl << endl << "Sorting Ascending... " << endl;
  mergeSort(list, true);

  // Print sorted list
  cout << "Print List Forward: ";
  for (unsigned int i = 0; i < list->size(); i++) {
    rectangle thisRect = list->at(i);
    cout << thisRect.base << "X" << thisRect.height << " ";
  }

  // Sort the list
  cout << endl << endl << "Sorting Descending... " << endl;
  mergeSort(list, false);

  // Print sorted list
  cout << "Print List Forward: ";
  for (unsigned int i = 0; i < list->size(); i++) {
    rectangle thisRect = list->at(i);
    cout << thisRect.base << "X" << thisRect.height << " ";
  }

  delete list;
  return 0;
}