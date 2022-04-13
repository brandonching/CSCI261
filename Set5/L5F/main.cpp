/* CSCI 261: Assignment 5: Lab 5F - A Needle in the Haystack
 the Call Stack
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: sorting list and finding a record via binary search
 */

// Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>  // For cin, cout, etc.

#include "mergeSort.hpp"

// Library namespace
using namespace std;

// Constants

int main() {
  int numCount;
  cout << "How many numbers would you like to create?: ";
  cin >> numCount;

  // Generate random seed
  srand(time(0));
  rand();

  // build list of random numbers
  LinkedList<int> *list = new LinkedList<int>;
  for (int i = 0; i < numCount; i++) {
    list->pushBack(rand() % 100 + 1);
  }

  // print list
  cout << "Print List Forward: ";
  list->print();

  // Sort the list
  cout << endl << endl << "Sorting Ascending... " << endl;
  mergeSort(list, true);

  // print sorted list
  cout << "Print List Forward: ";
  list->print();

  // Binary Search
  int numTargets;
  int target;
  bool targetFound;
  cout << endl << "How many numbers would you like find: ";
  cin >> numTargets;
  for (int i = 1; i <= numTargets; i++) {
    cout << "Target " << i << ": ";
    cin >> target;
    targetFound = false;
    // find first instance of target and print POS
    for (unsigned int j = 0; j < list->size(); j++) {
      if (list->at(j) == target) {
        cout << "Target found in POS: " << j<<endl;
        targetFound = true;
        break;
      }
    }

    //if not found print -1
    if (targetFound == false) {
      cout << "-1"<<endl;
    }
  }

  delete list;
  return 0;
}