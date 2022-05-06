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
#include "Schedule.h"
#include "functions.h"

// Library namespace
using namespace std;

// Constants

int main(int argc, char* argv[]) {
  // Define File I/O information
  ifstream courseCatalogFileIn;
  string courseCatalogDirectory = "Data/CourseCatalog.txt";

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
    while (getline(rawCourse, column, '\t')) {
      row.push_back(column);
    }
    // Create a new course and add to catalog
    Course newCourse(row[0], stoi(row[1]), stod(row[2]), row[3]);
    courseCatalog->insert(courseCatalog->size(), newCourse);
  }

  // Print welcome mesage
  cout << endl
       << "Welcome to the Schedule Planner!" << endl
       << "For the best user expierance, expand your window until the line "
          "below is all on the same row."
       << endl
       << "--------------------------------------------------------------"
          "--------------------------------------------"
       << endl;

  DoublyLinkedList<Schedule> scheduleList;
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
        schedule_planner(courseCatalog, scheduleList);
        break;
      case 3:
        // Export any saved schedules to individual files matching the schedule
        // name
        if (scheduleList.size() != 0) {
          for (int i = 0; i < scheduleList.size(); i++) {
            scheduleList.get(i).exportSchedule();
            cout << "\x1B[32m" << scheduleList.get(i).getScheduleName()
                 << "Exported Sucessfully\x1B[37m" << endl;
          }
        } else {
          cerr << "\x1B[31mError: No Schedule's to Export\x1B[37m" << endl;
        }

        break;
      default:
        // Selection does not exist
        cerr << "\x1B[31mError: Selection " << '"' << option << '"'
             << " not recognized\x1B[37m" << endl;
        break;
    }
  }

  // Gracefully Close Program
  delete courseCatalog;
  courseCatalogFileIn.close();
  return 0;
}