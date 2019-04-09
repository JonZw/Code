#include"Library.h"
#include<string>


void Library::addBook(Book newBook)
{
  _books.push_back(newBook);
}

void Library::searchTitle(std::string title)
  {
    for(Book& b: _books)
    {
      if(b.getTitle()==title)
      {
        b.out();
      }
    }
  }

  void Library::searchKeyword(std::string keyword)
  {
    for(auto& b: _books)
    {
      if(b.getKey().find(keyword)!=std::string::npos) //find prüft ob der String im
      {                                  //im String enthalten ist
        b.out();
      }
    }
  }
