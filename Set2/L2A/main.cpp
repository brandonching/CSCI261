/* CSCI 261: Assignment 2: Lab 2A - The Secret Moosage
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Take an input file, decrypt the message contained within, and
 * save to a new file
 */

// Libraries
#include <fstream>
#include <iostream>  // For cin, cout, etc.

// Library namespace
using namespace std;

// Constants

int main() {
  // Declate fstream objects
  ifstream secretMessage("secretMessage.txt");
  ofstream decipheredMessage("decipheredMessage.txt");

  // check for an error
  if (secretMessage.fail()) {
    cerr << "Error opening input file";
    return -1;
  }
  if (decipheredMessage.fail()) {
    cerr << "Error opening output file";
    return -1;
  }

  char c;
  // read the data and do something with it
  while (secretMessage.get(c)) {
    if (c == '\n') {
      decipheredMessage << '\n';
    } else if (c == '~') {
      decipheredMessage << ' ';
    } else {
      decipheredMessage << char(c + 1);
    }
  }

  // close the files
  secretMessage.close();
  decipheredMessage.close();
  return 0;
}