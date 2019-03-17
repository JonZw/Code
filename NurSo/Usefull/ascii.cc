#include<iostream>
#include <stdio.h>

int main()
{
  system("stty raw");
  char input = getchar();
  system("stty cooked");
  int ascii = input;
  std::cout<<input<<" = "<<ascii<<std::endl;
  std::cout<<"e:\n->\e<-"<<std::endl;
  std::cout<<"r:\n->\r<-"<<std::endl;
  std::cout<<"t:\n->\t<-"<<std::endl;
  std::cout<<"a:\n->\a<-"<<std::endl;
  std::cout<<"f:\n->\f<-"<<std::endl;
  std::cout<<"v:\n->\v<-"<<std::endl;
  std::cout<<"b:\n->\b<-"<<std::endl;
  std::cout<<"n:\n->\n<-"<<std::endl;
}
