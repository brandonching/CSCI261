/* CSCI 261: Assignment 1: L1D - Holy Loops Batman!
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Execute the same repetitive task using 3 diffrent methods:
 * while, do-while, and for loop
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

// Library namespace
using namespace std;

// Constants

int main() {
  // While
  int count = 1;
  while (count <= 11) {
    cout << "Na ";
    count += 1;
  }
  cout << "Batman!" << endl;

  // Do-While
  count = 1;
  do {
    cout << "Na ";
    count += 1;
  } while (count <= 11);
  cout << "Batman!" << endl;

  // For
  for (int i = 1; i <= 11; i++) {
    cout << "Na ";
  }
  cout << "Batman!" << endl;

  return 0;
}