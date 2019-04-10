#include"Objekts.h"
#include<iostream>

Frog::Frog(Terminal& term):_term(term),_position(term.width()/2,term.height()-2),_dir(MoveDirection::DOWN){}

void Frog::draw()
{
  _term.set_cell(_position.x,_position.y,'o',10);
  _term.set_cell(_position.x-1,_position.y,'l',10);
  _term.set_cell(_position.x+1,_position.y,'1',10);
  _term.set_cell(_position.x,_position.y+1,'U',10);
  _term.set_cell(_position.x-1,_position.y+1,'<',10);
  _term.set_cell(_position.x+1,_position.y+1,'>',10);
}
void Frog::change_direction(char pressed)
{
  switch(pressed) {
      case 'w':
        _dir = MoveDirection::UP;
        break;
      case 'a':
        _dir = MoveDirection::LEFT;
        break;
      case 's':
        _dir = MoveDirection::DOWN;
        break;
      case 'd':
        _dir = MoveDirection::RIGHT;
        break;
      default:
        break;
  }
}
void Frog::update()
{
  switch(_dir)
  {
    case MoveDirection::UP:
      if(_position.y+1>1)
      {
        _position.y-=1;
      }
      if(ticktack())
      {
        _position.y+=1;
      }
      break;
    case MoveDirection::DOWN:
      if(_position.y+1<_term.height()-1)
      {
        _position.y+=1;
      }
        if(ticktack())
        {
          _position.y+=1;
        }
      break;
    case MoveDirection::LEFT:
      if(_position.x-1>0)
      {
        _position.x-=1;
      }
      else
      {
        _dir=MoveDirection::RIGHT;
      }
      if(ticktack())
      {
        _position.y+=1;
      }
      break;
    case MoveDirection::RIGHT:
      if(_position.x+1<_term.width()-1)
      {
        _position.x+=1;
      }
      else
      {
        _dir=MoveDirection::LEFT;
      }
      if(ticktack())
      {
        _position.y+=1;
      }
      break;
  }
}
Vec2D Frog::position()
{
  return _position;
}
bool Frog::ticktack()
{
  ++_ticktack;
  _ticktack%=5;
  return !_ticktack;
}
void Frog::reset()
{
  _position.x=_term.width()/2;
  _position.y=_term.height()-2;
}
//lo1
//<U>
