#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "DoublyLinkedList.hpp"
#include "Course.h"

class Schedule {
 public:
  Schedule();
  Schedule(const DoublyLinkedList<Course> *CATALOG);
  ~Schedule();

  void getHeader();
  void getCompletedCourseWork();
  void getSemesterCourses(const int TERM);

  void printSchedule();

 private:
  string firstName, lastName;
  int studentID, gradYear;
  DoublyLinkedList<Course> *completed;
  DoublyLinkedList<DoublyLinkedList<Course>*> *courseSchedule;
  const DoublyLinkedList<Course> *catalog;
};

#endif