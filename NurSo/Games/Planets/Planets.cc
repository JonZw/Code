#include<iostream>
#include"System.cc"

int main()
{
  System Game;
  Game.pointer();
  std::cout<<&Game<<std::endl;
  Game.Up();
  Game.pointer();
  std::cout<<&Game<<std::endl;
  Game.foo();
  Game.pointer();
  std::cout<<&Game<<std::endl;

  /*while(true)
  {
    system("stty raw");
    char input = getchar();
    system("stty cooked");
    if(input=='q')
    {
      break;
    }
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
    Game.Up();
    Game.foo();
  }*/
  std::cout<<"Exit"<<std::endl;
}
