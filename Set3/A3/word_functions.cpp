#include "word_functions.h"

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

int offset(const unsigned int* LETTERS) {
  // Determine required offset for numbers
  int offset = 1;
  for (int i = 0; i < 26; i++) {
    if (log10(LETTERS[i]) + 1 > offset) {
      offset = log10(LETTERS[i]) + 1;
    }
  }
  return offset;
}

string prompt_user_for_filename() {
  cout << "Please Provide a File Name: ";
  string fileName;
  cin >> fileName;
  return fileName;
}

bool open_file(ifstream& inputFile, const string FILENAME) {
  // Open File
  inputFile.open(FILENAME);

  // Check for an error
  if (inputFile.fail()) {
    cerr << "Error opeing file." << endl;
    return 0;
  }
  // retrun 1 if open sucessful
  return 1;
}

vector<string> read_words_from_file(ifstream& inputFile) {
  vector<string> words;
  string word;
  // Save each word in file to vector
  while (inputFile >> word) {
    words.push_back(word);
  }
  return words;
}

void remove_punctuation(vector<string>& words, const string PUNCTUATION) {
  // Iterate through each word in list
  for (int word = 0; (unsigned)word < words.size(); word++) {
    // Iterate through each punctuation to remove
    for (int punct = 0; (unsigned)punct < PUNCTUATION.length(); punct++) {
      // while word still contains punctuation, keep removing
      while (words[word].find(PUNCTUATION[punct]) != string::npos) {
        // Erase puntuation from word
        words[word].erase(words[word].find(PUNCTUATION[punct]), 1);
      }
    }
  }
}

void capitalize_words(vector<string>& words) {
  string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string lower = "abcdefghijklmnopqrstuvwxyz";
  // Iterate through each word in list
  for (int word = 0; (unsigned)word < words.size(); word++) {
    // Iterate through each letter
    for (int i = 0; i < 26; i++) {
      while (words[word].find(lower[i]) != string::npos) {
        // Replace each letter with its respective uppercase letter
        words[word].replace(words[word].find(lower[i]), 1, upper.substr(i, 1));
      }
    }
  }
}

vector<string> filter_unique_words(const vector<string> WORDS) {
  vector<string> uniqueWords;
  bool isUnique;
  // adds the first word to unique list
  uniqueWords.push_back(WORDS[0]);

  // Iterate through each word in list
  for (int word = 1; (unsigned)word < WORDS.size(); word++) {
    // default each word to being unique
    isUnique = true;

    // check word from main list agains unique words list
    for (int uniqueWord = 0; (unsigned)uniqueWord < uniqueWords.size();
         uniqueWord++) {
      // if match found, set isUnique to false and break loop
      if (WORDS[word] == uniqueWords[uniqueWord]) {
        isUnique = false;
        break;
      }
    }

    // if word is unique, add to unique words list
    if (isUnique) {
      uniqueWords.push_back(WORDS[word]);
    }
  }

  // return the unique words vector
  return uniqueWords;
}

void count_letters(unsigned int* letters, vector<string> words) {
  string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  // Iterate through each word in list
  for (int word = 0; (unsigned)word < words.size(); word++) {
    // Iterate through each letter in word
    for (int letter = 0; (unsigned)letter < words[word].length(); letter++) {
      // Count each letter
      for (int i = 0; i < 26; i++) {
        if (words[word][letter] == upper[i]) {
          letters[i]++;
          break;
        }
      }
    }
  }
}

void print_letter_counts(const unsigned int* LETTERS) {
  string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // Print out number count for each letter
  for (int i = 0; i < 26; i++) {
    cout << upper[i] << ": " << setw(offset(LETTERS));
    cout << LETTERS[i] << endl;
  }
}

void print_max_min_letter(const unsigned int* LETTERS) {
  string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  double maxLetterCount = LETTERS[1];
  double minLetterCount = LETTERS[1];
  int maxLetterID = 0;
  int minLetterID = 0;

  double totalLetters = LETTERS[0];
  // Determin min/max letter and count
  for (int i = 1; i < 26; i++) {
    // sum total letters for use in stats
    totalLetters += LETTERS[i];
    // test if min or max
    if (LETTERS[i] > maxLetterCount) {
      maxLetterCount = LETTERS[i];
      maxLetterID = i;
    } else if (LETTERS[i] < minLetterCount) {
      minLetterCount = LETTERS[i];
      minLetterID = i;
    }
  }

  // calculate stats
  double minPrecent = minLetterCount * 100 / totalLetters;
  double maxPrecent = maxLetterCount * 100 / totalLetters;

  // Print min/max stats
  cout.precision(3);
  cout << "Least Frequent Letter: " << upper[minLetterID] << " "
       << setw(offset(LETTERS)) << minLetterCount << " (" << setw(7) << fixed
       << minPrecent << "%)" << endl;

  cout << " Most Frequent Letter: " << setprecision(0) << upper[maxLetterID]
       << " " << setw(offset(LETTERS)) << maxLetterCount << " (" << setw(7)
       << setprecision(3) << maxPrecent << "%)" << endl;
}
