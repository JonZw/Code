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
  //für ticktack()
  int _ticktack=1;
public:
  Frog(Terminal& term);
  void draw();
  void change_direction(char pressed);
  void update();
  //giebt die position zurück
  Vec2D position();
  //jeder 5te aufruf giebt true zurück
  bool ticktack();
  void reset();
};//End Frog

class Car
{
private:
  Terminal _term;
  Vec2D _position;
  enum class MoveDirection
  {
    LEFT,
    RIGHT,
  };
  MoveDirection _dir;
  int _ticktack=1;
  int _color;
public:
  Car(Terminal& term,Vec2D pos,int dir,int _color);
  void draw();
  void update();
  Vec2D position();
  bool ticktack();
  void reset();
};//End Car
class Bush
{
private:
  Terminal _term;
  Vec2D _position;
  int _ticktack=1;
  bool _random;
public:
  Bush(Terminal& term,Vec2D pos,bool rand);
  void update();
  void draw();
  bool ticktack();
  void reset();
  Vec2D position();
};

#endif
