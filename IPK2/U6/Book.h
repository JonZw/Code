#ifndef BOOK_H
#define BOOK_H
#include <iostream>

class Book
{
private:
  std::string _title,_author,_keywords;
public:
  //Konstruktor
  Book(std::string title,std::string author, std::string keywords);
  //giebt den Titel zurück
  std::string getTitle();
  //giebt den Author zurück
  std::string getAuthor();
  //giebt die Keywords zurück
  std::string getKey();
  //Giebt das Buch im Terminal aus
  void out();
};//End Book



#endif
