/* CSCI 261: Assignment 1: L1C - Random Generation & Classification
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Generate a random number between two values provided by user and
 *  calculate the quartile of the number
 */

// Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>  // For cin, cout, etc.

// Library namespace
using namespace std;

// Constants

int main() {
  double minValue;
  double maxValue;

  // Get user input for range
  cout << "Enter the minimum value: ";
  cin >> minValue;
  cout << "Enter the maximum value: ";
  cin >> maxValue;

  // Generate random seed
  srand(time(0));
  rand();
  // random double between min and max value provided by user
  double randValue =
      rand() / (double)RAND_MAX * (maxValue - minValue) + minValue;
  cout << "A random value is: " << randValue << endl;

  // Calculate the quartile of random value
  cout << "This is in the ";
  if (randValue < ((((maxValue - minValue) / 4) * 1) + minValue)) {
    cout << "first";
  } else if (randValue < ((((maxValue - minValue) / 4) * 2) + minValue)) {
    cout << "second";
  } else if (randValue < ((((maxValue - minValue) / 4) * 3) + minValue)) {
    cout << "third";
  } else {
    cout << "fourth";
  }

  cout << " quartile" << endl;
  return 0;
}