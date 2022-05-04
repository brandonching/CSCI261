#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
 public:
  Book();
  Book(const std::string TITLE, const std::string AUTHOR, const int YEAR);
  std::string getAuthor();
  std::string getTitle();
  int getPublicationYear();

 private:
  std::string author;
  std::string title;
  int publicationYear;
};
#endif