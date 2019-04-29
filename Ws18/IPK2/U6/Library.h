#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>

class Library
{
private:
  std::vector<Book> _books;
public:
  //Fügt ein Buch hinzu
  void addBook(Book newBook);
  //Sucht nach dem Title eines Buches und gibt
  //beim Finden seine Daten aus
  void searchTitle(std::string title);
  //Sucht nach dem Keyword eines Buches und gibt
  //beim Finden seine Daten aus
  void searchKeyword(std::string keyword);
};//End Library

#endif
