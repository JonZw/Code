#include"Objekts.h"

Bush::Bush(Terminal& term,Vec2D pos,bool rand):_term(term),_position(pos),_random(rand){}

void Bush::draw()
{
  _term.set_cell(_position.x,_position.y,'0',2);
  _term.set_cell(_position.x,_position.y+1,'|',130);
}

void Bush::update()
{
  if(ticktack())
  {
     ++_position.y;
     if(_position.y>_term.height())
     {
       if(!_random)
       {
         _position.y=0;
       }
       else
       {
         _position.x=rand()%_term.width();
         _position.y=rand()%30-30;
       }
     }
   }
}


bool Bush::ticktack()
{
  ++_ticktack;
  _ticktack%=5;
  return !_ticktack;
}
Vec2D Bush::position()
{
  return _position;
}
