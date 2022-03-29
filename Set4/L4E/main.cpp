/* CSCI 261: Assignment 4: Lab 4E - A Linked List Class Part III: Test, Copy,
 * Print
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description:
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

#include "LinkedList.cpp"

// Library namespace
using namespace std;

// Constants

int main() {
  LinkedList list;
  cout << "List 1 Size: " << list.size() << endl;
  list.pushFront(1);
  list.pushBack(2);
  list.pushFront(3);
  list.pushBack(4);
  list.pushFront(5);
  list.pushBack(6);
  cout << "List 1 Size: " << list.size() << endl;

  cout << "The Contents of the list are: ";
  for (unsigned int i = 0; i < list.size(); i++) {
    cout << list.at(i) << " ";
  }

  LinkedList list2;
  cout << endl << "List 2 Size: " << list2.size() << endl;
  list2 = list;
  cout << "Set list2 = list1" << endl;
  cout << "List 1 Size: " << list.size() << endl;
  cout << "List 2 Size: " << list2.size() << endl;
  return 0;
}