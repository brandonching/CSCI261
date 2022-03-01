#include "string_functions.h"

int string_length(const string STR) {
  int result = -1;
  result = STR.length();  // set result to the length of the string
  return result;
}

char string_char_at(const string STR, const int IDX) {
  char result = STR[IDX];
  return result;
}

string string_append(const string LEFT, const string RIGHT) {
  string result = LEFT + RIGHT;
  return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
  string result = STR;
  result.insert(IDX, TO_INSERT);
  return result;
}

int string_find(const string STR, const char C) {
  int result = STR.find_first_of(C);
  return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
  char result[LEN];
  STR.copy(result, LEN, IDX);
  return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE,
                      const string REPLACE_WITH) {
  string result = STR;
  if (STR.find(TEXT_TO_REPLACE) != string::npos) {
    result.replace(STR.find(TEXT_TO_REPLACE), TEXT_TO_REPLACE.length(),
                   REPLACE_WITH);
  }
  return result;
}

string string_first_word(const string STR) {
  string result = STR.substr(0, STR.find(" "));
  return result;
}

string string_remove_first_word(const string STR) {
  string result;
  if (STR.find(" ") != string::npos) {
    result = STR.substr(STR.find(" ") + 1);
  }
  return result;
}

string string_second_word(const string STR) {
  string result = string_first_word(string_remove_first_word(STR));
  return result;
}

string string_third_word(const string STR) {
  string result = string_first_word(
      string_remove_first_word(string_remove_first_word(STR)));
  return result;
}

string string_nth_word(const string STR, const int N) {
  string result = STR;
  for (int i = 1; i < N; i++) {
    result = string_remove_first_word(result);
  }
  result = string_first_word(result);
  return result;
}

string string_substitute(const string STR, const char TARGET,
                         const char REPLACEMENT) {
  string result = STR;
  string replace;
  replace += REPLACEMENT;
  while (result.find(TARGET) != string::npos) {
    result.replace(result.find(TARGET), 1, replace);
  }
  return result;
}

string string_to_lower(const string STR) {
  string result = STR;
  string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string lower = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
    while (result.find(upper[i]) != string::npos) {
      result.replace(result.find(upper[i]), 1, lower.substr(i, 1));
    }
  }
  return result;
}

string string_to_upper(const string STR) {
  string result = STR;
  string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string lower = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
    while (result.find(lower[i]) != string::npos) {
      result.replace(result.find(lower[i]), 1, upper.substr(i, 1));
    }
  }
  return result;
}

int string_compare(const string LHS, const string RHS) {
  int result = LHS.compare(RHS);
  if (result < 0) {
    result = -1;
  } else if (result > 0) {
    result = 1;
  }
  return result;
}