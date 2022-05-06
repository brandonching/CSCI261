#include "Schedule.h"

#include <cstring>
#include <iomanip>

#include "functions.h"

/** @brief Default Constructor
 * **/
Schedule::Schedule() {}

/** @brief Paramaterzed Constructor which creates the completed and schedule
 * list
 *
 * @param CATALOG The catalog to which the schedule can be built on
 * **/
Schedule::Schedule(const DoublyLinkedList<Course> *CATALOG) {
  catalog = CATALOG;
  completed = new DoublyLinkedList<Course>;
  courseSchedule = new DoublyLinkedList<DoublyLinkedList<Course> *>;
}

/** @brief Detroy the completed and schedule list
 * **/
Schedule::~Schedule() {}

/** @brief Get header information from user and sets the respective class
 * memebrs
 * **/
void Schedule::getHeader() {
  // Get Information for header
  cout << "First Name: ";
  cin >> firstName;
  cout << "Last Name: ";
  cin >> lastName;
  cout << "Student ID: ";
  cin >> studentID;
  cout << "Expected Graduation Year (YYYY): ";
  cin >> gradYear;

  // Convert name to uppercase
  firstName = string_to_upper(firstName);
  lastName = string_to_upper(lastName);
}

/** @brief Have the user input any completed course work they may have achived
 * **/
void Schedule::getCompletedCourseWork() {
  // Print out instructions
  cout << endl
       << "Let's add your completed courses. I'll have you add one "
          "course at a time, and when your done just type "
       << '"' << "Done" << '"' << endl;
  cout << "Example Entry:" << endl << "I've Completed: ABCD123" << endl << endl;

  // Get completed courses
  string nextCourse;
  while (string_to_upper(nextCourse) != "DONE") {
    cout << "I've Completed: ";
    cin >> nextCourse;
    // If user inputs a course, validate against catalog and add to
    // completed list
    if (string_to_upper(nextCourse) != "DONE") {
      completed->insert(
          completed->size(),
          getCourse(catalog, nextCourse.substr(0, nextCourse.size() - 3),
                    stoi(nextCourse.substr(nextCourse.size() - 3,
                                           nextCourse.size()))));
      // Print out the course if found as added sucessfully
      if (completed->get(completed->size() - 1).getCredits() != -1) {
        cout << "\x1B[32mAdded Sucesfully: "
             << completed->get(completed->size() - 1).getDepartment()
             << completed->get(completed->size() - 1).getCourseID() << " "
             << completed->get(completed->size() - 1).getName() << "\x1B[37m"
             << endl;
      } else {
        // Print course if not found and delete from list
        cout << "\x1B[31mError: "
             << completed->get(completed->size() - 1).getDepartment()
             << completed->get(completed->size() - 1).getCourseID()
             << " NOT FOUND\x1B[37m" << endl;
        completed->remove(completed->size() - 1);
      }
    }
  }
}

/** @brief Have the user input any course work they plan to complete for a given
 * TERM
 *
 * @param TERM The term in which course work will be completed
 * **/
void Schedule::getSemesterCourses(const int TERM) {
  DoublyLinkedList<Course> *newTerm = new DoublyLinkedList<Course>;
  string nextCourse;
  while (string_to_upper(nextCourse) != "DONE") {
    cout << "Add to Term " << TERM << ": ";
    cin >> nextCourse;
    // If user inputs a course, validate against catalog and add to term
    if (string_to_upper(nextCourse) != "DONE") {
      newTerm->insert(
          newTerm->size(),
          getCourse(catalog, nextCourse.substr(0, nextCourse.size() - 3),
                    stoi(nextCourse.substr(nextCourse.size() - 3,
                                           nextCourse.size()))));
      // Print out the course if found as added sucessfully
      if (newTerm->get(newTerm->size() - 1).getCredits() != -1) {
        cout << "\x1B[32mAdded Sucesfully: "
             << newTerm->get(newTerm->size() - 1).getDepartment()
             << newTerm->get(newTerm->size() - 1).getCourseID() << " "
             << newTerm->get(newTerm->size() - 1).getName() << "\x1B[37m"
             << endl;
      } else {
        // Print course if not found and delete from list
        cout << "\x1B[31mError: "
             << newTerm->get(newTerm->size() - 1).getDepartment()
             << newTerm->get(newTerm->size() - 1).getCourseID()
             << " NOT FOUND\x1B[37m" << endl;
        newTerm->remove(newTerm->size() - 1);
      }
    }
  }
  courseSchedule->insert(TERM - 1, newTerm);
}

/** @brief Get a schedules name
 *
 * @return The name of the schedule
 * **/
string Schedule::getScheduleName() const { return scheduleName; }

/** @brief sets the scheudles name
 * **/
void Schedule::setScheuleName(const string NAME) { scheduleName = NAME; }

/** @brief Print out the Formatted Schedule
 * **/
void Schedule::printSchedule() const {
  string divider =
      "--------------------------------------------------------------"
      "----------------------------------";
  cout << endl << divider << endl;
  cout << "| Student: " << lastName << ", " << firstName << right
       << setw(83 - firstName.length() - lastName.length()) << "|" << endl;
  cout << "| ID: " << left << setw(20) << studentID << right << setw(64)
       << "Expected Graduation: " << gradYear << " |" << endl;
  cout << divider << endl;
  // Print completed if there are any completed courses
  if (completed->size() > 0) {
    // get completed course credit hours
    double completedHours = 0;
    for (int i = 0; i < completed->size(); i++) {
      completedHours += completed->get(i).getCredits();
    }
    cout << "| COMPLETED COURSES" << right << setw(72) << completedHours
         << " CH |" << endl;
    cout << divider << endl;
    for (int i = 0; i < completed->size(); i++) {
      Course thisCourse = completed->get(i);
      cout << "| " << right << setw(4) << thisCourse.getDepartment() << left
           << setw(3) << thisCourse.getCourseID() << left << " " << left
           << setw(3) << thisCourse.getCredits() << " " << left << setw(80)
           << thisCourse.getName() << " |" << endl;
    }
    cout << divider << endl;
  }

  for (int term = 0; term < courseSchedule->size(); term++) {
    double completedHours = 0;
    for (int course = 0; course < courseSchedule->get(term)->size(); course++) {
      completedHours += courseSchedule->get(term)->get(course).getCredits();
    }
    cout << "| TERM " << term + 1 << right << setw(83) << completedHours
         << " CH |" << endl;
    cout << divider << endl;
    for (int course = 0; course < courseSchedule->get(term)->size(); course++) {
      Course thisCourse = courseSchedule->get(term)->get(course);
      cout << "| " << right << setw(4) << thisCourse.getDepartment() << left
           << setw(3) << thisCourse.getCourseID() << left << " " << left
           << setw(3) << thisCourse.getCredits() << " " << left << setw(80)
           << thisCourse.getName() << " |" << endl;
    }
    cout << divider << endl;
  }
  cout << endl;
}

/** @brief Expor the Formated Schedule
 * **/
void Schedule::exportSchedule() const {
  // Define outputFile
  ofstream exportFile("Exports/" + scheduleName + ".txt");

  // check for error
  if (exportFile.fail()) {
    cerr << "Error: Could not open output file " << scheduleName << ".txt"
         << endl;
  }

  // Write Data to file
  string divider =
      "--------------------------------------------------------------"
      "----------------------------------";
  exportFile << endl << divider << endl;
  exportFile << "| Student: " << lastName << ", " << firstName << right
             << setw(83 - firstName.length() - lastName.length()) << "|"
             << endl;
  exportFile << "| ID: " << left << setw(20) << studentID << right << setw(64)
             << "Expected Graduation: " << gradYear << " |" << endl;
  exportFile << divider << endl;
  // Print completed if there are any completed courses
  if (completed->size() > 0) {
    // get completed course credit hours
    double completedHours = 0;
    for (int i = 0; i < completed->size(); i++) {
      completedHours += completed->get(i).getCredits();
    }
    exportFile << "| COMPLETED COURSES" << right << setw(72) << completedHours
               << " CH |" << endl;
    exportFile << divider << endl;
    for (int i = 0; i < completed->size(); i++) {
      Course thisCourse = completed->get(i);
      exportFile << "| " << right << setw(4) << thisCourse.getDepartment()
                 << left << setw(3) << thisCourse.getCourseID() << left << " "
                 << left << setw(3) << thisCourse.getCredits() << " " << left
                 << setw(80) << thisCourse.getName() << " |" << endl;
    }
    exportFile << divider << endl;
  }

  for (int term = 0; term < courseSchedule->size(); term++) {
    double completedHours = 0;
    for (int course = 0; course < courseSchedule->get(term)->size(); course++) {
      completedHours += courseSchedule->get(term)->get(course).getCredits();
    }
    exportFile << "| TERM " << term + 1 << right << setw(83) << completedHours
               << " CH |" << endl;
    exportFile << divider << endl;
    for (int course = 0; course < courseSchedule->get(term)->size(); course++) {
      Course thisCourse = courseSchedule->get(term)->get(course);
      exportFile << "| " << right << setw(4) << thisCourse.getDepartment()
                 << left << setw(3) << thisCourse.getCourseID() << left << " "
                 << left << setw(3) << thisCourse.getCredits() << " " << left
                 << setw(80) << thisCourse.getName() << " |" << endl;
    }
    exportFile << divider << endl;
  }
  exportFile << endl;
}