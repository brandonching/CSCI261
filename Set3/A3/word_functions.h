#ifndef WORD_FUNCTIONS_H
#define WORD_FUNCTIONS_H

#include <string>
#include <vector>
using namespace std;

int offset(const unsigned int* LETTERS);
string prompt_user_for_filename();
bool open_file(ifstream& inputFile, const string FILENAME);
vector<string> read_words_from_file(ifstream& inputFile);
void remove_punctuation(vector<string>& words, const string PUNCTUATION);
void capitalize_words(vector<string>& words);
vector<string> filter_unique_words(const vector<string> WORDS);
void count_letters(unsigned int* letters, vector<string> words);
void print_letter_counts(const unsigned int* LETTERS);
void print_max_min_letter(const unsigned int* LETTERS);

#endif