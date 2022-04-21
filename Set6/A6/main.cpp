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

#include "Position.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
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
  Stack<Position> positionsToCheck;
 

  // read the data and do something with it
  int R, C;
  fileIn >> R;
  fileIn >> C;

  // Create 2D Array
  char maze[R][C];
  bool visited[R][C] = {};
  char nextChar;

  // Iterate through file and build array
  for (int row = 0; row < R; row++) {
    for (int column = 0; column < C; column++) {
      fileIn >> nextChar;
      maze[row][column] = nextChar;

      // Starting point
      if (nextChar == 'S') {
        positionsToCheck.push(Position(row, column));
        visited[row][column] = true;
      }
    }
  }

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
    // Print visited
    // cout << endl;
    // for (int row = 0; row < R; row++) {
    //   for (int column = 0; column < C; column++) {
    //     cout << visited[row][column] << " ";
    //   }
    //   cout << endl;
    // }
  }

  // Print maze
  // for (int row = 0; row < R; row++) {
  //   for (int column = 0; column < C; column++) {
  //     cout << maze[row][column] << " ";
  //   }
  //   cout << endl;
  // }

  // Print visited
  // for (int row = 0; row < R; row++) {
  //   for (int column = 0; column < C; column++) {
  //     cout << visited[row][column] << " ";
  //   }
  //   cout << endl;
  // }

  if (!solved) {
    cout << "End cannot be reached" << endl;
  }

  // Print Solved Maze
  for (int row = 0; row < R; row++) {
    for (int column = 0; column < C; column++) {
      if (maze[row][column] == '.' && visited[row][column] == true) {
        cout << "@ ";
      } else {
        cout << maze[row][column] << " ";
      }
    }
    cout << endl;
  }
}