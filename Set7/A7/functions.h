#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

string prompt_user_for_filename();
bool open_file(ifstream& inputFile, const string FILENAME);
float pointDistance(const sf::Vector2f P1, const sf::Vector2f P2);
#endif