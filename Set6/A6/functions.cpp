#include "functions.h"

#include <fstream>
#include <iostream>

string prompt_user_for_filename() {
  cout << "What file do you wish to open: ";
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

template <typename T>
void search(T &positionToSearch) {
  bool solved = false;
  while (!positionsToCheck.isEmpty() && !solved) {
    Position currentPosition = positionsToCheck.pop();
    if (maze[currentPosition.row][currentPosition.column] != '#') {
      if (maze[currentPosition.row][currentPosition.column] == 'E') {
        cout << "End was Reached!" << endl;
        solved = true;
      } else {
        if (!visited[currentPosition.row + 1][currentPosition.column] &&
            currentPosition.row != R - 1) {
          positionsToCheck.push(
              Position(currentPosition.row + 1, currentPosition.column));
          visited[currentPosition.row + 1][currentPosition.column] = true;
        }
        if (!visited[currentPosition.row][currentPosition.column + 1] &&
            currentPosition.column != C - 1) {
          positionsToCheck.push(
              Position(currentPosition.row, currentPosition.column + 1));
          visited[currentPosition.row][currentPosition.column + 1] = true;
        }
        if (!visited[currentPosition.row - 1][currentPosition.column] &&
            currentPosition.row != 0) {
          positionsToCheck.push(
              Position(currentPosition.row - 1, currentPosition.column));
          visited[currentPosition.row - 1][currentPosition.column] = true;
        }
        if (!visited[currentPosition.row][currentPosition.column - 1] &&
            currentPosition.column != 0) {
          positionsToCheck.push(
              Position(currentPosition.row, currentPosition.column - 1));
          visited[currentPosition.row][currentPosition.column - 1] = true;
        }
      }
    }
  }
}