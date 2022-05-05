#include "functions.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

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
  cout << "-- Course Catalog --" << endl;
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
        // Get general information for schedule header
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

        // If courses have been completed, have user input these course
        DoublyLinkedList<Course> *completedCourses =
            new DoublyLinkedList<Course>;
        if (completedCourseWork == 'y' || completedCourseWork == 'Y') {
          cout << endl
               << "Let's add your completed courses. I'll have you add one "
                  "course at a time, and when your done just type "
               << '"' << "Done" << '"' << endl;
          cout << "Example Entry:" << endl
               << "I've Completed: ABCD123" << endl
               << endl;

          // Get completed courses
          string nextCompletedCourse;
          while (nextCompletedCourse != "Done") {
            cout << "I've Completed: ";
            cin >> nextCompletedCourse;
            // If user inputs a course, validate against catalog and add to
            // completed list
            if (nextCompletedCourse != "Done") {
              completedCourses->insert(
                  completedCourses->size(),
                  getCourse(CATALOG,
                            nextCompletedCourse.substr(
                                0, nextCompletedCourse.size() - 3),
                            stoi(nextCompletedCourse.substr(
                                nextCompletedCourse.size() - 3,
                                nextCompletedCourse.size()))));

              if (completedCourses->get(completedCourses->size() - 1)
                      .getCredits() != -1) {
                cout << "\x1B[32mAdded Sucesfully: "
                     << completedCourses->get(completedCourses->size() - 1)
                            .getDepartment()
                     << completedCourses->get(completedCourses->size() - 1)
                            .getCourseID()
                     << " "
                     << completedCourses->get(completedCourses->size() - 1)
                            .getName()
                     << "\x1B[37m" << endl;
              } else {
                // Print if course is not found and delete from course complete
                // list
                cout << "\x1B[31mError: "
                     << completedCourses->get(completedCourses->size() - 1)
                            .getDepartment()
                     << completedCourses->get(completedCourses->size() - 1)
                            .getCourseID()
                     << " NOT FOUND\x1B[37m" << endl;
                completedCourses->remove(completedCourses->size() - 1);
              }
            }
          }

          // Print out completed course and if they were found
          for (int i = 0; i < completedCourses->size(); i++) {
          }

          for (int i = 0; i < completedCourses->size(); i++) {
            cout << completedCourses->get(i).getDepartment()
                 << completedCourses->get(i).getCourseID() << " "
                 << completedCourses->get(i).getName() << endl;
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
