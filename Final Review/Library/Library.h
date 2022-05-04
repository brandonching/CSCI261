#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "LinkedList.hpp"

class Library {
 public:
  Library();
  Library(const Library &);
  ~Library();
  Library &operator=(const Library &);
  Book *checkoutBook(string);
  void returnBook(Book *);

 private:
  LinkedList<Book *> *catalog;
};

#endif