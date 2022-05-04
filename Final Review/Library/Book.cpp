#include "Book.h"

#include <string>

Book::Book() {
  title = "The C++ Programing Language";
  author = "Bjarne Stroustrup";
  publicationYear = 1986;
}

Book::Book(const std::string TITLE, const std::string AUTHOR, const int YEAR) {
  title = TITLE;
  author = AUTHOR;
  publicationYear = YEAR;
}

std::string Book::getAuthor() { return author; }

std::string Book::getTitle() { return title; }

int Book::getPublicationYear() { return publicationYear; }