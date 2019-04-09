#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
public:
    Vec2D() {};
    Vec2D(int x, int y) :
        x(x), y(y) {}

	int x;
	int y;
  bool operator==(Vec2D other)
  {
    if(x==other.x&&y==other.x)
    {
      return true;
    }
    return false;
  }
};

#endif
