#ifndef FUNCTIONS_CPP
#define FUNCTIONS_CPP

#include "functions.h"

#include <cmath>

string prompt_user_for_filename() {
  cout << "Please Provide a File Name: ";
  string fileName;
  cin >> fileName;
  return fileName;
}

bool open_file(ifstream& inputFile, const string FILENAME) {
  // Open File
  inputFile.open(FILENAME);

  // Check for an error
  if (inputFile.fail()) {
    cerr << "Error opeing file." << endl;
    return 0;
  }
  // retrun 1 if open sucessful
  return 1;
}

float pointDistance(const sf::Vector2f P1, const sf::Vector2f P2) {
  return abs(sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2)));
}
#endif