/* CSCI 261: Assignment 6: Lab 6A - Multidimensional Data
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: creating and working with multidimentional data
 */

// Libraries
#include <fstream>
#include <iostream>  // For cin, cout, etc.
#include <string>

#include "functions.cpp"

// Library namespace
using namespace std;

// Constants

int main(int argc, char* argv[]) {
  string filename;
  if (argc == 1) {
    filename = prompt_user_for_filename();
  } else if (argc == 2) {
    filename = argv[1];
  } else {
    cerr << "Usage: " << argv[0] << " [filename]" << endl;
    cerr << "  filename   - optional file to open upon start" << endl;
    return -2;
  }

  // open file for parsing
  ifstream fileIn;
  if (!open_file(fileIn, filename)) {
    cerr << "Could not open file \"" << filename << "\"" << endl;
    cerr << "Shutting down" << endl;
    return -1;
  } else {
    cout << "Opening file " << filename << endl
         << "File successfully opened!" << endl;
  }

  // read the data and do something with it
  int n;
  fileIn >> n;
  // Create 2D Array
  int table[n][n];
  int nextNum;
  // Iterate through file and build array
  for (int row = 0; row < n; row++) {
    for (int column = 0; column < n; column++) {
      fileIn >> nextNum;
      table[row][column] = nextNum;
    }
  }

  // Print Table and find min/max
  int minValue = table[0][0];
  int maxValue = table[0][0];
  for (int row = 0; row < n; row++) {
    for (int column = 0; column < n; column++) {
      cout << table[row][column] << " ";
      // Check If Max
      if (table[row][column] > maxValue) {
        maxValue = table[row][column];
      }
      // Check if Min
      if (table[row][column] < minValue) {
        minValue = table[row][column];
      }
    }
    cout << endl;
  }

  //Print Min/Max
  cout << "The min is: " << minValue << endl;
  cout << "The max is: " << maxValue << endl;
}