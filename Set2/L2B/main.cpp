/* CSCI 261: Assignment 2: Lab 2B - Procedural Programming with Functions
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: create 2 funcitions to generate random ints or doubles
 */

// Libraries
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>  // For cin, cout, etc.

// Library namespace
using namespace std;

// Constants
void generate_random_integer(int minValue, int maxValue, bool includeMin,
                             bool includeMax) {
  // test for inclusivity and adjust accodingly
  if (includeMin == false) {
    minValue++;
  }
  if (includeMax == false) {
    maxValue--;
  }

  // Generate random numbers and print 10 of them
  cout << rand() % (maxValue - minValue + 1) + minValue << endl;
}

void generate_random_float(float minValue, float maxValue, bool includeMin,
                           bool includeMax) {
  // test for inclusivity and adjust accodingly
  if (includeMin == false) {
    minValue += 0.0001;
  }
  if (includeMax == false) {
    maxValue -= 0.0001;
  }

  // set to 3 decimal places
  std::cout << std::fixed << std::setprecision(3);

  // Generate random numbers and print 10 of them
  cout << rand() / (double)RAND_MAX * (maxValue - minValue) + minValue << endl;
}

void output_range(int minValue, int maxValue, bool includeMin,
                  bool includeMax) {
  if (includeMin) {
    cout << "[" << minValue << "," << maxValue;
  } else {
    cout << "(" << minValue << "," << maxValue;
  }
  if (includeMax) {
    cout << "] -=-" << endl;
  } else {
    cout << ") -=-" << endl;
  }
}
int main() {
  float minValue;
  float maxValue;
  bool includeMin;
  bool includeMax;
  // Welcom Prompt
  cout << "Welcome to Random Number Generator!" << endl;
  cout << "Please provide bounds for number generation" << endl;

  // Get Min/Max values from user
  cout << "Min Value: ";
  cin >> minValue;
  cout << "Is this inclusive? (1/0)";
  cin >> includeMin;
  cout << "Max Value: ";
  cin >> maxValue;
  cout << "Is this inclusive? (1/0) ";
  cin >> includeMax;

  // Random seeding
  srand(time(0));
  rand();

  // Output random integers
  cout << "-=- Random Integers on Range: ";
  output_range(minValue, maxValue, includeMin, includeMax);
  for (int i = 0; i < 10; i++) {
    generate_random_integer(minValue, maxValue, includeMin, includeMax);
  }

  // output random floats
  cout << "-=- Random Floats on Range: ";
  output_range(minValue, maxValue, includeMin, includeMax);
  for (int i = 0; i < 10; i++) {
    generate_random_float(minValue, maxValue, includeMin, includeMax);
  }
  return 0;
}