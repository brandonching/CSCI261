#include "Course.h"

#include <iostream>

Course::Course() { department = "NULL"; }

Course::Course(const string DEPARTMENT, const int COURSE_ID,
               const double CREDITS, const string COURSE_NAME) {
  department = DEPARTMENT;
  courseID = COURSE_ID;
  credits = CREDITS;
  courseName = COURSE_NAME;
}

Course::~Course() {}

string Course::getDepartment() { return department; }

int Course::getCourseID() { return courseID; }

double Course::getCredits() { return credits; }

string Course::getName() { return courseName; }

void Course::setDepartment(const string DEPARTMENT) { department = DEPARTMENT; }

void Course::setCourseID(const int COURSE_ID) { courseID = COURSE_ID; }

void Course::setCredits(const double CREDITS) { credits = CREDITS; }

void Course::addPreReq(Course newPreReq) { preReq.pushBack(newPreReq); }

void Course::addCoReq(Course newCoReq) { coReq.pushBack(newCoReq); }
