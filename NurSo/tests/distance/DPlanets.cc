#include<iostream>
#include"DSystem.cc"

int main()
{
 System Game;
 bool end=false;
 int chosen=0;
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
      case 't':end=true;break;
      case 'w':Game.movUp();break;
      case 'a':Game.movLe();break;
      case 's':Game.movDo();break;
      case 'd':Game.movRi();break;
      case 'q':Game.movLup();break;
      case 'e':Game.movRup();break;
      case 'y':Game.movLown();break;
      case 'c':Game.movRown();break;
      case 32 :switch(chosen)
               {
                  case 0:if(Game.mine(Player))
                          {
                            chosen=Game.who();
                          }
                          break;
                  case 1:if(Game.alloc(Player))
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
    Game.Abstand(Game.where());
    Game.out();
    Game.Rab();
  }
  std::cout<<"Exit"<<std::endl;
}
