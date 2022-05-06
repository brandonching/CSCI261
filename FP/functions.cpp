#include "functions.h"

#include <stdio.h>

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
  // Continue asking for input until valid
  while (!(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')) {
    cout << "Is you input data formated correctly (see README.txt)? [y/n]"
         << endl;
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
      return true;
    } else if (answer == 'n' || answer == 'N') {
      return false;
    } else {
      cout << "\x1B[31mError: Invalid Selection\x1B[37m" << endl;
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
    cerr << "\x1B[31mError: Counld not open " << '"' << FILENAME << '"'
         << " Please Restart The Program\x1B[37m" << endl;
  } else {
    cout << "Opening file " << '"' << FILENAME << '"' << endl
         << "\x1B[32mFile successfully opened!\x1B[37m" << endl;
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
  // Loop thorugh each course in catalog
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
  cout << "   3 - Export All Schedules" << endl;
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
  cout << "   2 - View Schedule" << endl;
  cout << "   0 - Exit to Main Menu" << endl;
  cout << "Menu Selection: ";
  cin >> option;
  return option;
}

/** @brief Create a schedule
 *
 * @param CATALOG The course catalog
 * @param scheduleList The list containing the list of saved schedules
 * **/
void schedule_planner(const DoublyLinkedList<Course> *CATALOG,
                      DoublyLinkedList<Schedule> &scheduleList) {
  int option = 1;
  // Keep looping through the schedule planner submenu until user choses to
  // return to main menu
  while (option != 0) {
    option = schedule_menu();
    switch (option) {
      case 0:
        // Return to main menu
        break;
      case 1: {
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
                "with your next term."
             << endl;
        cout << "I'll have you enter one course at a time, when your done just "
                "type "
             << '"' << "Done" << '"' << endl;
        cout << "Example Entry:" << endl
             << "Add to Term 0: ABCD101" << endl
             << endl;

        // Default to adding courses
        int scheduleSubMenu = 1;
        int termIdx = 1;
        while (scheduleSubMenu != 0) {
          // Show the submenu
          cout << "Schedule Planner Sub-Menu" << endl;
          cout << "   0 - Save Schedule" << endl;
          cout << "   1 - Continue adding courses to next term" << endl;
          cout << "Menu Selection: ";
          cin >> scheduleSubMenu;
          switch (scheduleSubMenu) {
            case 0: {
              // get name for schedule and save
              string scheduleName;
              cout << "Please name your Schedule (No Spaces! Only Letters): ";
              cin >> scheduleName;
              cout << "SAVING..." << endl;
              newSchedule.setScheuleName(scheduleName);
              scheduleList.insert(scheduleList.size() - 1, newSchedule);
              cout << endl
                   << "\x1B[32mSAVED SUCESFULLY\x1B[37m" << endl
                   << endl;
              break;
            }
            case 1:
              newSchedule.getSemesterCourses(termIdx);
              newSchedule.printSchedule();
              // Go to next term and continue adding classes
              termIdx++;
              break;
            default:
              // Selection does not exist
              cerr << "\x1B[31mError: Selection " << '"' << scheduleSubMenu
                   << '"' << " not recognized\x1B[37m" << endl;
              break;
          }
        }
        break;
        // Finish Making New Schedule and send back to Schedule Planner Menu
      }
        // 2 1 Brandon Ching 1234567890 2024 Y csm101 MEgn200 Done Done 0
      case 2: {
        // View previously saved schedules
        int scheduleToView = -1;
        while (scheduleToView != 0) {
          if (scheduleList.size() != 0) {
            // If previously saved schdules exist, prompt user for which one to
            // dispaly
            cout << "Which schedule would you like to view?" << endl;
            cout << "   0 - Return to Schedule Planner" << endl;
            for (int i = 0; i < scheduleList.size(); i++) {
              cout << "   " << i + 1 << " - "
                   << scheduleList.get(i).getScheduleName() << endl;
            }
            cout << "view: ";
            cin >> scheduleToView;
            if (scheduleToView != 0) {
              scheduleList.get(scheduleToView - 1).printSchedule();
            }
          } else {
            // If no saved schedules exist, output an error
            cout << "\x1B[31mError: No Schedule Found\x1B[37m" << endl;
            break;
          }
        }
        break;
      }
      default:
        // Selection does not exist
        cerr << "\x1B[31mError: Selection " << '"' << option << '"'
             << " not recognized\x1B[37m" << endl;
        break;
    }
  }
}

/** @brief Takes the inputed course and returns the matching course info from
 * the catalog if the course exist. If no course exist, creates and return a
 * null course
 *
 * @param CATALOG the catalog of courses to compare against
 * @param DEPARTMENT The course department being searched for
 * @param COURSE_ID The courseID being searched for
 *
 * @return The matching course from the CATALOG if found
 * **/
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

/** @brief Converts a string to all uppercase
 *
 * @param STR The string to be converted to all uppercase
 *
 * @return An all upercase string
 * **/
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
