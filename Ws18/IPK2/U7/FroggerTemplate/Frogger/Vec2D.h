#ifndef VEC2D_H
#define VEC2D_H
#include<iostream>

class Vec2D
{
public:
    Vec2D() {};
    Vec2D(int x, int y) :
        x(x), y(y) {}

	int x;
	int y;
  //giebt true zurück wenn der Kopf des Frosches ein gemaltes
  //Zeichen berürt
  bool operator==(Vec2D other)
  {
    for(int i=-1;i<=1;++i)//(alle objekte sind 3x2 groß)
    {
      for(int n=0;n<=1;++n)
      {
        if(x+i==other.x&&y+n==other.y)
        {
          return true;
        }
      }
    }
  return false;
  }
};

#endif
