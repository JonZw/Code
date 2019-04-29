#include<iostream>
#include"Vec2D.h"
#include"Terminal.h"
#include<vector>

class Objects
{
protected:
  Terminal _term;
  Vec2D _position;
  int _team;
public:
  Objects(Terminal& term,Vec2D pos,int team):_term(term),_position(pos),_team(team){}
  Objects(const Objects& other)
  {
    _term=other._term;
    _position=other._position;
  }
  virtual ~Objects(){}
  virtual void update()=0;
  virtual void draw()=0;
};//End Objects

class Base:public Objects
{
public:
  Base(Terminal& term, Vec2D pos,int team);
  Base(const Base& other);
  void update();
  void draw();
};//end Base

class Club:public Objects
{
public:
  Club(Terminal& term, Vec2D pos,int team);
  Club(const Base& other);
  void update();
  void draw();
};//end Club
