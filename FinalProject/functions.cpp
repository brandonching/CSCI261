#include "functions.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "schedule.h"

/** @brief Ask the user wheter or not the input files are formatted correctly
 * according to README.txt
 *
 * @return true if formatted corret
 * **/
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

/** @brief Open a file and save into inputFile ifstream
 *
 * @param inputFile the ifstream object for the input file
 * @param FILENAME the file directory to the respective file
 *
 * **/
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

/** @brief Print out the catalog
 *
 * @param CATALOG The catalog to be printed
 * **/
void print_catalog(const DoublyLinkedList<Course> *CATALOG) {
  // Print out the catalog
  cout << endl << endl;
  cout << " Course | CH | Name" << endl;
  for (int i = 0; i < CATALOG->size(); i++) {
    Course thisClass = CATALOG->get(i);
    cout << right << setw(4) << thisClass.getDepartment()
         << thisClass.getCourseID() << "  " << left << setw(6)
         << thisClass.getCredits() << thisClass.getName() << endl;
  }
}

/** @brief Display the Main Menu
 *
 * @return Users numeric Selection
 * **/
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

/** @brief Display the Schedule Menu
 *
 * @return Users numeric Selection
 * **/
int schedule_menu() {
  int option;
  cout << endl << "Schedule Planner Menu" << endl;
  cout << "   1 - New Schedule" << endl;
  cout << "   0 - Exit to Main Menu" << endl;
  cout << "Menu Selection: ";
  cin >> option;
  return option;
}

/** @brief Create a schedule
 *
 * @param CATALOG The course catalog
 * **/
void schedule_planner(const DoublyLinkedList<Course> *CATALOG) {
  int option = 1;
  // Keep looping through the schedule planner submenu until user choses to
  // return to main menu
  while (option != 0) {
    option = schedule_menu();
    switch (option) {
      case 0:
        // Return to main menu
        break;
      case 1:
        // New Schedule
        Schedule newSchedule(CATALOG);
        // Get general information for schedule header
        char completedCourseWork;
        cout << endl
             << "Welcome to the Schedule Planner! Before we began, Please tell "
                "me a little about yourself"
             << endl;
        newSchedule.getHeader();
        cout << "Do you have any completed course work? [y/n]:";
        cin >> completedCourseWork;

        // If courses have been completed, have user input these course
        if (completedCourseWork == 'y' || completedCourseWork == 'Y') {
          newSchedule.getCompletedCourseWork();
        }
        newSchedule.printSchedule();

        // Build Schedule term by term
        cout << "Let's build your schedule one semester at a time. Starting "
                "with "
                "your next term."
             << endl;
        cout << "I'll have you enter one course at a time, when your done just "
                "type "
             << '"' << "Done" << '"' << endl;
        cout << "Example Entry:" << endl
             << "Add to Term 0: ABCD101" << endl
             << endl;
        int scheduleSubMenu = 1;
        int termIdx = 1;
        while (scheduleSubMenu != 0) {
          newSchedule.getSemesterCourses(termIdx);
          newSchedule.printSchedule();
          cout << "Schedule Planner Sub-Menu" << endl;
          cout << "   0 - Save Schedule" << endl;
          cout << "   1 - Continue adding courses to next term" << endl;
          cout << "Menu Selection: ";
          cin >> scheduleSubMenu;
          switch (scheduleSubMenu) {
            case 0:
              cout << "SAVING..." << endl;

              cout << "\x1B[32mSAVED SUCESFULLY\x1B[37m" << endl << endl;
              break;
            case 1:
              termIdx++;
          }
        }

        break;
    }
  }

  // if (completedCourseWork == 'y' || completedCourseWork == 'Y') {
  //   cout << "Great, Let's now add classes to your next semester. We'll "
  //           "Start with Fall 2022."
  // } else {
  //   cout << "Let's start by add"
  // }
}
// 2 1 Brandon Ching 10869652 2024 y Csm101 megn200 csci101 csci102

Course getCourse(const DoublyLinkedList<Course> *CATALOG,
                 const string DEPARTMENT, const int COURSE_ID) {
  // compare Department and courseID to catalog. Return Course from catalog if
  // found
  for (int i = 0; i < CATALOG->size(); i++) {
    if ((CATALOG->get(i).getDepartment() == string_to_upper(DEPARTMENT)) &&
        (CATALOG->get(i).getCourseID() == COURSE_ID)) {
      return CATALOG->get(i);
    }
  }
  // If course not found in catalog, create null course and return
  Course nullCourse(DEPARTMENT, COURSE_ID, -1, "NULL");
  return nullCourse;
}

string string_to_upper(const string STR) {
  string result = STR;
  string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string lower = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
    while (result.find(lower[i]) != string::npos) {
      result.replace(result.find(lower[i]), 1, upper.substr(i, 1));
    }
  }
  return result;
}
