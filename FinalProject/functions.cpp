#include "functions.h"

#include <fstream>
#include <iostream>
#include <iomanip>

bool files_are_formatted() {
  char answer;
  while (!(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')) {
    cout << "Is you input data formated correctly (see README.txt)? [y/n]"
         << endl;
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
      return true;
    } else if (answer == 'n' || answer == 'N') {
      return false;
    } else {
      cout << "Error: Invalid Selection" << endl;
    }
  }
  return false;
}

string prompt_user_for_filename() {
  cout << "What file do you wish to open: ";
  string fileName;
  cin >> fileName;
  return fileName;
}

void open_file(ifstream &inputFile, const string FILENAME) {
  // Open File
  inputFile.open(FILENAME);

  // Check for an error
  if (inputFile.fail()) {
    cerr << "Error: Counld not open " << '"' << FILENAME << '"' << endl;
    cerr << "Shutting Down" << endl;
  } else {
    cout << "Opening file " << '"' << FILENAME << '"' << endl
         << "File successfully opened!" << endl;
  }
}

void print_catalog(const LinkedList<Course> *CATALOG) {
  // Print out the catalog
  cout << "-- Course Catalog --" << endl;
  cout << " Course | CH | Name" << endl;
  for (unsigned int i = 0; i < CATALOG->size(); i++) {
    Course thisClass = CATALOG->at(i);
    cout << right << setw(4) << thisClass.getDepartment()
         << thisClass.getCourseID() << "  " << left << setw(6)
         << thisClass.getCredits() << thisClass.getName() << endl;
  }
}