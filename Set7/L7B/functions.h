#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string prompt_user_for_filename();
bool open_file(ifstream& inputFile, const string FILENAME);

#endif