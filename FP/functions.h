#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <string>

#include "Course.h"
#include "DoublyLinkedList.hpp"
#include "schedule.h"
using namespace std;

bool files_are_formatted();
void open_file(ifstream& inputFile, const string FILENAME);
void print_catalog(const DoublyLinkedList<Course>* CATALOG);
int main_menu();
int scedule_menu();
string string_to_upper(const string STR);
void schedule_planner(const DoublyLinkedList<Course>* CATALOG,
                      DoublyLinkedList<Schedule>& scheduleList);
Course getCourse(const DoublyLinkedList<Course>* CATALOG,
                 const string DEPARTMENT, const int COURSE_ID);

#endif