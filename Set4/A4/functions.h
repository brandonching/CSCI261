#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include "LinkedList.hpp"
using namespace std;

string prompt_user_for_filename();
bool open_file(ifstream& inputFile, const string FILENAME);
void printVertex(LinkedList<Vertex<float>>* vertices, int index);

#endif