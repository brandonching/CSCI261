/* CSCI 261: Assignment 7: Lab 7B - Starcraft
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description:
 */

// Libraries
#include <fstream>
#include <iostream>  // For cin, cout, etc.
#include <sstream>

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

  // Read in file
  string line;
  while (getline(fileIn, line)) {
    istringstream columns(line);
    float x,y,z,brightness;
    columns >> x;
    columns >> y;
    columns >> z;
    columns >> brightness;
    cout << line << endl;
  }
  return 0;
}