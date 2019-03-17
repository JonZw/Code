#include<iostream>
#include"System.cc"

int main()
{
 System Game;
 bool end=false;
 int chosen=0;
 int where=0;
 int Player=0;
 Game.change(Player);
 Game.out();

  while(!end)
  {
    system("stty raw");
    char input = getchar();
    system("stty cooked");
    switch(input)
    {
      case 'q':end=true;break;
      case 'w':Game.movUp();break;
      case 'a':Game.movLe();break;
      case 's':Game.movDo();break;
      case 'd':Game.movRi();break;
      case 'i':Player=(Player+1)%2;Game.change(Player);break;
      case 32 :switch(chosen)
               {
                  case 0:if(Game.mine(Player))
                          {
                            chosen=Game.who();
                            where=Game.where();
                          }
                          break;
                  case 1:if(Game.invade(Player,where))
                          {
                            Player=(Player+1)%2;
                            Game.change(Player);
                          }
                          chosen=0;
                          break;
                  default: if(Game.mine(Player))
                          {
                            chosen=Game.who();
                          }
                          break;
               }
               break;
    }
    Game.out();
  }
  std::cout<<"Exit"<<std::endl;
}
