#ifndef COURSE_H
#define COURSE_H

using namespace std;
#include <string>

#include "LinkedList.hpp"

class Course {
 public:
  Course();
  Course(const string DEPARTMENT, const int COURSE_ID, const double CREDITS,
         const string COURSE_NAME);
  ~Course();

  string getDepartment();
  int getCourseID();
  double getCredits();
  string getName();

  void setDepartment(const string DEPARTMENT);
  void setCourseID(const int COURSE_ID);
  void setCredits(const double CREDITS);
  void addPreReq(Course newPreReq);
  void addCoReq(Course newCoReq);

 private:
  string department;
  int courseID;
  double credits;
  string courseName;
  LinkedList<Course> preReq;
  LinkedList<Course> coReq;
};

#endif