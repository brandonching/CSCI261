/* CSCI 261: Assignment 3:
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description:
 */

// Libraries
#include <iostream>  // For cin, cout, etc.

// Library namespace
using namespace std;

// Constants

int main() {
  // Initialize array of size 15
  int numbers[15];
  cout << "Enter up to 15 non-zero numbers. Enter zero to signal the end of "
          "data or enter all 15 items: "
       << endl;
  // Get user inputed numbers
  for (int i = 0; i < 15; i++) {
    cout << "Number " << i + 1 << ": ";
    cin >> numbers[i];

    // Test if user inputed 0 and exit loop if so
    if (numbers[i] == 0) {
      break;
    }
  }

  // Print out the inputed numbers
  cout << "The numbers are: ";
  for (int i = 0; i < 15; i++) {
    // stop printing when 0 is reached
    if (numbers[i] == 0) {
      break;
    }
    cout << numbers[i] << " ";
  }

  // Iterate through to find min/max
  int minValue = numbers[0], maxValue = numbers[0];
  for (int i = 1; i < 15; i++) {
    // stop testing when 0 is reached
    if (numbers[i] == 0) {
      break;
    }
    if (numbers[i] < minValue) {
      minValue = numbers[i];
    }
    if (numbers[i] > maxValue) {
      maxValue = numbers[i];
    }
  }
  cout << endl;

  // Print min/max values
  cout << "The maximum value is: " << maxValue << endl;
  cout << "The minimum value is: " << minValue << endl;
  cout << "Have a nice day!";

  return 0;
}