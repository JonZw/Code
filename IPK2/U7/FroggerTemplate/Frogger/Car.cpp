#include"Objekts.h"

Car::Car(Terminal& term,Vec2D pos,int dir):_term(term),_position(pos)
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

void Car::draw()
{
  _term.set_cell(_position.x,_position.y,'-');
  _term.set_cell(_position.x-1,_position.y,'o');
  _term.set_cell(_position.x+1,_position.y,'o');
  _term.set_cell(_position.x,_position.y+1,'-');
  _term.set_cell(_position.x-1,_position.y+1,'o');
  _term.set_cell(_position.x+1,_position.y+1,'o');
}
void Car::update()
{
  if(_dir==MoveDirection::LEFT)
  {
    if(_position.x>0)
      _position.x-=1;
    else
      _dir=MoveDirection::RIGHT;
  }
  if(_dir==MoveDirection::RIGHT)
  {
    if(_position.x<_term.width())
      _position.x+=1;
    else
      _dir=MoveDirection::LEFT;
  }
  _hitbox[0].push_back({_position.x-1,_position.y});
  _hitbox[0].push_back({_position.x,_position.y});
  _hitbox[0].push_back({_position.x+1,_position.y});
  _hitbox[0].push_back({_position.x-1,_position.y-1});
  _hitbox[0].push_back({_position.x,_position.y-1});
  _hitbox[0].push_back({_position.x+1,_position.y-1});
}
Vec2D Car::position()
{
  return _position;
}
//o–o
//o–o
