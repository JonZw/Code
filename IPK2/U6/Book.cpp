#include"Book.h"

Book::Book(std::string title,std::string author, std::string keywords):
            _title(title),_author(author),_keywords(keywords){}

std::string Book::getTitle(){return _title;}
std::string Book::getAuthor(){return _author;}
std::string Book::getKey(){return _keywords;}

void Book::out()
{
  std::cout<<"\n"<<_title<<"\n\tby: "<<_author<<"\n\tkw:"<<_keywords<<std::endl;
}
