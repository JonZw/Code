#include"Objekts.h"

Car::Car(Terminal& term,Vec2D pos,int dir,int col):_term(term),_position(pos),_color(col)
{
  if(dir==1)
  {
    _dir=MoveDirection::LEFT;
  }
  else
  {
    _dir=MoveDirection::RIGHT;
  }
}
//Car::Car(){}//?
void Car::draw()
{
  _term.set_cell(_position.x,_position.y,'-',_color);
  _term.set_cell(_position.x-1,_position.y,'o',_color);
  _term.set_cell(_position.x+1,_position.y,'o',_color);
  _term.set_cell(_position.x,_position.y+1,'-',_color);
  _term.set_cell(_position.x-1,_position.y+1,'o',_color);
  _term.set_cell(_position.x+1,_position.y+1,'o',_color);
}
void Car::update()
{
  if(_dir==MoveDirection::LEFT)
  {
    if(_position.x>3)
    {
      _position.x-=2;
      if(ticktack())
        _position.y+=1;
    }
    else
      _dir=MoveDirection::RIGHT;
  }
  if(_dir==MoveDirection::RIGHT)
  {
    if(_position.x<_term.width()-3)
    {
      _position.x+=2;
      if(ticktack())
        _position.y+=1;
    }
    else
      _dir=MoveDirection::LEFT;
  }
  if(_position.y>_term.height()+5)
  {
    _position.y=-2;
  }
}
Vec2D Car::position()
{
  return _position;
}
bool Car::ticktack()
{
  ++_ticktack;
  _ticktack%=5;
  return !_ticktack;
}
void Car::reset()
{
  _position.y=std::rand()%30-30;
  _position.x=std::rand()%_term.width();
  _color=rand()%7+1;
}
//o–o
//o–o
