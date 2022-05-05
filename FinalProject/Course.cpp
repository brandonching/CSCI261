#include "Course.h"

#include <iostream>

/** @brief Default constructor for Course class, sets Department to NULL
 *
 * **/
Course::Course() { department = "NULL"; }

/** @breif Parameterized constructor for Course class
 *
 * @param DEPARTMENT sets the department
 * @param COURSE_ID sets the course ID
 * @param CREDITS sets the number of credits the class is worth
 * @param COURSE_NAME name of the course
 * **/
Course::Course(const string DEPARTMENT, const int COURSE_ID,
               const double CREDITS, const string COURSE_NAME) {
  department = DEPARTMENT;
  courseID = COURSE_ID;
  credits = CREDITS;
  courseName = COURSE_NAME;
}

/** @brief Destruct the course object
 *
 * **/
Course::~Course() {}

/** @brief Get the department of a course
 *
 * @return Course Department **/
string Course::getDepartment() const { return department; }

/** @brief Get the course ID
 *
 * @return Course ID
 * */
int Course::getCourseID() const { return courseID; }

/** @brief get the credits the class is worth
 *
 * @return Class Credits
 * */
double Course::getCredits() const { return credits; }

/** @brief get the course name
 *
 * @return Course Name
 * */
string Course::getName() const { return courseName; }

/** @brief Set the Department of a course
 *
 * @param DEPARTMENT new Department of course
 * */
void Course::setDepartment(const string DEPARTMENT) { department = DEPARTMENT; }

/** @brief Set the course ID of a course
 *
 * @param COURSE_ID new course IF of course
 * */
void Course::setCourseID(const int COURSE_ID) { courseID = COURSE_ID; }

/** @brief set the credits a class is worth
 *
 * @param CREDITS the number of credits a class is worth
 * */
void Course::setCredits(const double CREDITS) { credits = CREDITS; }

/** @brief Add preReqs to a course
 *
 * @param newPreReq adds this course to the preReq list
 * */
void Course::addPreReq(Course newPreReq) { preReq.insert(preReq.size(),newPreReq); }

/** @brief Add coReqs to a course
 *
 * @param newCoReq adds this course to the coReq list
 * */
void Course::addCoReq(Course newCoReq) { coReq.insert(coReq.size(),newCoReq); }
