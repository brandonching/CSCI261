/* CSCI 261: Final Project: Schedule Planner
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Create multiple classes with inheratance and use SFML to draw a
 * picture from an input file
 */

// Libraries
#include <fstream>
#include <iomanip>
#include <iostream>  // For cin, cout, etc.
#include <sstream>
#include <vector>

#include "Course.h"
#include "DoublyLinkedList.hpp"
#include "functions.h"

// Library namespace
using namespace std;

// Constants

int main(int argc, char* argv[]) {
  // Define File I/O information
  ifstream courseCatalogFileIn;
  string courseCatalogDirectory = "Data/CourseCatalog.csv";

  if (argc == 1) {
    // If no files provided at run, promt user for files
    // If files are not formated as standard, then ask for file locations
    if (!files_are_formatted()) {
      cout << "Please Provide the file directory of the following files."
           << endl;
      cout << "Course Catalog Directory: ";
      cin >> courseCatalogDirectory;
    }
  } else if (argc == 2) {
    // If files provided at run, open
    courseCatalogDirectory = argv[1];
  } else {
    // Error in files provided at run
    cerr << "Usage: " << argv[0] << " [filename]" << endl;
    cerr << "  CourseCatalogFileName - optional file to open upon start"
         << endl;
    return -2;
  }

  // open files for parsing
  open_file(courseCatalogFileIn, courseCatalogDirectory);

  // Build Course Catalog
  DoublyLinkedList<Course>* courseCatalog = new DoublyLinkedList<Course>;
  string line;
  getline(courseCatalogFileIn, line);  // Ignore File Header
  // Iterate through each line of file
  while (getline(courseCatalogFileIn, line)) {
    // create temp vector to store the values of each row
    vector<string> row;
    string column;
    stringstream rawCourse(line);
    // Iterate through each column of each line and add to temp vector
    while (getline(rawCourse, column, ',')) {
      row.push_back(column);
    }
    // Create a new course and add to catalog
    Course newCourse(row[0], stoi(row[1]), stod(row[2]), row[3]);
    courseCatalog->insert(courseCatalog->size(),newCourse);
  }

  // Main Menu
  int option = 1;
  while (option != 0) {
    // Print menu and get user input
    option = main_menu();
    switch (option) {
      case 0:
        // Close the Program
        cout << "Shutting Down" << endl;
        break;
      case 1:
        // Print out the entire catalog
        print_catalog(courseCatalog);
        break;
      case 2:
        // Enter the Schedule planner
        schedule_planner(courseCatalog);
        break;
      default:
        // Selection does not exist
        cerr << "Error: Selection " << '"' << option << '"' << " not recognized"
             << endl;
        break;
    }
  }

  // Gracefully Close Program
  delete courseCatalog;
  courseCatalogFileIn.close();
  return 0;
}