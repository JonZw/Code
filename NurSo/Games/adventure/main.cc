#include <stdlib.h>
#include<iostream>
#include<experimental/random>
#include <fstream>
#include <string>
#include <iostream>
#include"Spiel.cc"

void sleep(int n) //27~1sek
{
  while(n!=0)
  {
  sleep(n-1);
  n--;
  }
}

int main()
{
  Raum raum;
  raum.out();
  bool end=false;
  while(!end)
  {
    raum.out();
    system("stty raw");
    char input = getchar();
    switch(input)
    {
      case 'w': raum.moveUp();
      break;
      case 'a': raum.moveLeft();
      break;
      case 's': raum.moveDown();
      break;
      case 'd': raum.moveRight();
      break;
      case'q': end=true;
      break;
      default: break;
    }
    raum.omove();
    system("stty cooked");
  }
  std::cout<<std::endl;
}
