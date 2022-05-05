#include "functions.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <sstream>

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

int main_menu() {
  int option;
  cout << endl << "Main Menu" << endl;
  cout << "   1 - Show Catalog" << endl;
  cout << "   2 - Open Schedule Planner" << endl;
  cout << "   0 - Close Program" << endl;
  cout << "Menu Selection: ";
  cin >> option;
  return option;
}

void schedule_planner(const LinkedList<Course> *CATALOG) {
  int option = 1;
  while (option != 0) {
    cout << endl << "Schedule Planner Menu" << endl;
    cout << "   1 - New Schedule" << endl;
    cout << "   0 - Exit to Main Menu" << endl;
    cout << "Menu Selection: ";
    cin >> option;
    switch (option) {
      case 0:
        break;
      case 1:
        string firstName, lastName;
        int studentID, gradYear;
        char completedCourseWork;
        cout << endl
             << "Welcome to the Schedule Planner! Before we began, Please tell "
                "me a little about yourself"
             << endl;
        cout << "First Name: ";
        cin >> firstName;
        cout << "Last Name: ";
        cin >> lastName;
        cout << "Student ID: ";
        cin >> studentID;
        cout << "Expected Graduation Year (YYYY): ";
        cin >> gradYear;
        cout << "Do you have any completed course work? [y/n]:";
        cin >> completedCourseWork;
        LinkedList<Course> *completedCourses = new LinkedList<Course>;
        if (completedCourseWork == 'y' || completedCourseWork == 'Y') {
          cout << endl<<"Let's add your completed courses. I'll have you add one "
                  "course at a time, and when your done just type "
               << '"' << "Done" << '"' << endl;
          cout << "Example Entry:" << endl << "I've Completed: ABCD123" << endl << endl;

          string nextCompletedCourse;
          while (nextCompletedCourse != "Done") {
            cout << "I've Completed: ";
            cin >> nextCompletedCourse;
            if (nextCompletedCourse != "Done") {
              string department =
                  nextCompletedCourse.substr(0, nextCompletedCourse.size() - 3);
              completedCourses->pushBack(getCourse(
                  CATALOG,
                  nextCompletedCourse.substr(0, nextCompletedCourse.size() - 3),
                  stoi(
                      nextCompletedCourse.substr(nextCompletedCourse.size() - 3,
                                                 nextCompletedCourse.size()))));
            }
          }
          for (unsigned int i = 0; i < completedCourses->size(); i++) {
            if (completedCourses->at(i).getDepartment() != "NULL") {
              cout << completedCourses->at(i).getDepartment()
                   << completedCourses->at(i).getCourseID() << " "
                   << completedCourses->at(i).getName() << endl;
            } else {
              cout << "error";
            }
          }
        }
        cout << "--------------------------------------------------------------"
             << endl;
        cout << "| Student: " << lastName << "," << firstName << right
             << setw(50 - firstName.length() - lastName.length()) << "|"
             << endl;
        cout << "| ID: " << left << setw(20) << studentID << right << setw(30)
             << "Expected Graduation: " << gradYear << " |" << endl;
        cout << "--------------------------------------------------------------"
             << endl;
    }
  }
}

Course getCourse(const LinkedList<Course> *CATALOG, const string DEPARTMENT,
                 const int COURSE_ID) {
  for (unsigned int i = 0; i < CATALOG->size(); i++) {
    if ((CATALOG->at(i).getDepartment() == DEPARTMENT) &&
        (CATALOG->at(i).getCourseID() == COURSE_ID)) {
      return CATALOG->at(i);
    }
  }
  Course nullCourse;
  return nullCourse;
}
