#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

#include "Course.h"
#include "LinkedList.hpp"
using namespace std;

bool files_are_formatted();
string prompt_user_for_filename();
void open_file(ifstream& inputFile, const string FILENAME);
void print_catalog(const LinkedList<Course>* CATALOG);

#endif