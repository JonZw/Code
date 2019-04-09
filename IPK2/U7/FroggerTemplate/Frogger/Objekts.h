#ifndef OBJEKTS_H
#define OBJEKTS_H

#include "Terminal.h"
#include "Vec2D.h"
#include <vector>


class Frog
{
private:
  Terminal _term;
  enum class MoveDirection
  {
    LEFT,
    RIGHT,
    UP,
    DOWN
  };
  Vec2D _position;
  MoveDirection _dir;
  std::vector<Vec2D> _hitbox[6];
public:
  Frog(Terminal& term);
  void draw();
  void change_direction(char pressed);
  void update();
  Vec2D position();
};//End Frog

class Car
{
private:
  Terminal _term;
  Vec2D _position;
  std::vector<Vec2D> _hitbox[6];
  enum class MoveDirection
  {
    LEFT,
    RIGHT,
  };
  MoveDirection _dir;
public:
  Car(Terminal& term,Vec2D pos,int dir);
  void draw();
  void update();
  Vec2D position();
};//End Car


#endif
