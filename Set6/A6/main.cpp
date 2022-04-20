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

  // Search Method Menu
  cout << endl
       << "Enter 1 to search via BFS." << endl
       << "Enter 2 to search via DFS." << endl
       << "Choice: ";
  int searchMethod;
  cin >> searchMethod;
  cout << endl;

  // read the data and do something with it
  int R, C;
  fileIn >> R;
  fileIn >> C;
  // Create 2D Array
  char table[R][C];
  char nextChar;
  // Iterate through file and build array
  for (int row = 0; row < R; row++) {
    for (int column = 0; column < C; column++) {
      fileIn >> nextChar;
      table[row][column] = nextChar;
    }
  }

  // Print Table and find min/max
  for (int row = 0; row < R; row++) {
    for (int column = 0; column < C; column++) {
      cout << table[row][column] << " ";
    }
    cout << endl;
  }
}