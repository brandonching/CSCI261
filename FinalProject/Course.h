#ifndef COURSE_H
#define COURSE_H

using namespace std;
#include <string>
#include "LinkedList.hpp"

class Course {
 public:
  Course();
  Course(const string DEPARTMENT, const int COURSE_ID, const int CREDITS);
  ~Course();

  string getDepartment();
  int getCourseID();
  int getCredits();

  void setDepartment(const string DEPARTMENT);
  void setCourseID(const int COURSE_ID);
  void setCredits(const int CREDITS);
  void addPreReq(Course newPreReq);
  void addCoReq(Course newCoReq);

 private:
  string department;
  int courseID;
  int credits;
  LinkedList<Course> preReq;
  LinkedList<Course> coReq;
};

#endif