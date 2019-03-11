#include <stdlib.h>
#include<iostream>
#include<experimental/random>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>



class Raum
{
private:
  std::vector<char> _raum;  //400
  int pposition;
  int oposition;
public:
  Raum()
  {
    _raum.resize(800);
    for(int n=0;n<800;n++)
    {
      if(n<40) //Decke
      {
        _raum[n]='_';
      }
      else if(n>759)
      {
        _raum[n]='T'; //Boden
      }
      else if((n+1)%40==0||n%40==0) //Wand
      {
        _raum[n]='|';
      }
      else
      {
        _raum[n]=' '; //Leerraum
      }
      pposition=41;
      oposition=758;
      Up();
    }
  }
  void Up()
  {
    _raum[pposition]='O';
    _raum[oposition]='X';
  }
  void out()
  {
    std::cout<<"\n\n\n\n\n\t";
    for(int n=0;n<800;n++)
    {
      if(n%40==0)
      {
        std::cout<<"\n\t"<<std::flush;
      }
      if(_raum[n]=='O'&&pposition!=n)
      {
        std::cout<<"\033[1;36m"<<_raum[n]<<"\033[0m"<<std::flush;
      }
      else if(pposition==n)
      {
        std::cout<<"\033[1;35m"<<_raum[n]<<"\033[0m"<<std::flush;
      }
      else
      {
        std::cout<<_raum[n];
      }
    }
    std::cout<<"\n\n\n";
  }
  void moveUp()
  {
    if(_raum[pposition-40]==' '||_raum[pposition-40]=='O'||_raum[pposition-40]=='X')
    {
      pposition=pposition-40;
      Up();
    }
  }
  void moveDown()
  {
    if(_raum[pposition+40]==' '||_raum[pposition+40]=='O'||_raum[pposition+40]=='X')
    {
      pposition=pposition+40;
      Up();
    }
  }
  void moveLeft()
  {
    if(_raum[pposition-1]==' '||_raum[pposition-1]=='O'||_raum[pposition-1]=='X')
    {
      pposition=pposition-1;
      Up();
    }
  }
  void moveRight()
  {
    if(_raum[pposition+1]==' '||_raum[pposition+1]=='O'||_raum[pposition+1]=='X')
    {
      pposition=pposition+1;
      Up();
    }
  }
  void omove()
  {
    int direction=std::experimental::randint(1,4);
    if(direction==1)
    {
      if(_raum[oposition-40]==' '||_raum[oposition-40]=='O'||_raum[oposition-40]=='X')
      {
        oposition=oposition-40;
        Up();
      }
    }
    if(direction==2)
    {
      if(_raum[oposition+40]==' '||_raum[oposition+40]=='O'||_raum[oposition+40]=='X')
      {
        oposition=oposition+40;
        Up();
      }
    }
    if(direction==3)
    {
      if(_raum[oposition-1]==' '||_raum[oposition-1]=='O'||_raum[oposition-1]=='X')
      {
        oposition=oposition-1;
        Up();
      }
    }
    if(direction==4)
    {
      if(_raum[oposition+1]==' '||_raum[oposition+1]=='O'||_raum[oposition+1]=='X')
      {
        oposition=oposition+1;
        Up();
      }
    }
  }
};//End Raum
