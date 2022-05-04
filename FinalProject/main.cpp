/* CSCI 261: Assignment 7: A7 - Triangle Land
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Create multiple classes with inheratance and use SFML to draw a
 * picture from an input file
 */

// Libraries
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>  // For cin, cout, etc.
#include <sstream>

#include "LinkedList.hpp"
#include "functions.h"

// Library namespace
using namespace std;

// Constants

int main(int argc, char* argv[]) {
  char answer;
  cout << "Is you input data formated correctly (see README.txt)? [y/n]" << endl;
  cin >> answer;

  
  string filename;
  if (argc == 1) {
    cout << "Please Provide a File Name: ";
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

  
  return 0;
}