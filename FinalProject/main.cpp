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
#include <iomanip>
#include <iostream>  // For cin, cout, etc.
#include <sstream>

#include "Course.h"
#include "LinkedList.hpp"
#include "functions.h"

// Library namespace
using namespace std;

// Constants

int main(int argc, char* argv[]) {
  ifstream courseCatalogFileIn;
  string courseCatalogDirectory = "Data/CourseCatalog.csv";
  if (argc == 1) {
    if (!files_are_formatted()) {
      // Ask for files
      cout << "Please Provide the file directory of the following files."
           << endl;
      cout << "Course Catalog Directory: ";
      cin >> courseCatalogDirectory;
    }
  } else if (argc == 2) {
    courseCatalogDirectory = argv[1];
  } else {
    cerr << "Usage: " << argv[0] << " [filename]" << endl;
    cerr << "  CourseCatalogFileName - optional file to open upon start"
         << endl;
    return -2;
  }

  // open files for parsing
  open_file(courseCatalogFileIn, courseCatalogDirectory);

  LinkedList<Course>* courseCatalog = new LinkedList<Course>;
  string line;
  getline(courseCatalogFileIn, line);  // Ignore File Header
  while (getline(courseCatalogFileIn, line)) {
    vector<string> row;
    string column;
    stringstream rawCourse(line);
    while (getline(rawCourse, column, ',')) {
      row.push_back(column);
    }
    Course newCourse(row[0], stoi(row[1]), stod(row[2]), row[3]);
    courseCatalog->pushBack(newCourse);
  }
  int option = 1;
  while (option != 0) {
    cout << endl << "Main Menu" << endl;
    cout << "   1 - Show Catalog" << endl;
    cout << "   2 - Open Schedule Planner" << endl;
    cout << "   0 - Close Program" << endl;
    cout << "Menu Selection: ";
    cin >> option;
    switch (option) {
      case 0:
        cout << "Shutting Down" << endl;
        break;
      case 1:
        print_catalog(courseCatalog);
        break;
      case 2:
        break;
      default:
        break;
    }
  }

  // Gracefully Close Program
  delete courseCatalog;
  courseCatalogFileIn.close();
  return 0;
}