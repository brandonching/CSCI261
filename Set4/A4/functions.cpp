#include "functions.h"

#include <fstream>
#include <iostream>

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

// Print vertex
void printVertex(LinkedList<Vertex<float>>* vertices, int index) {
  cout << "(" << vertices->at(index - 1).x << ", " << vertices->at(index - 1).y
       << ", " << vertices->at(index - 1).z << ")";
}