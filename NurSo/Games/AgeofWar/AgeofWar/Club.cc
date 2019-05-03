#include "Objects.h"
#include <string>
Club::Club(Terminal& term,Vec2D pos,int team):Objects(term,pos,team)
{
}
//Club::Club(const Club& other):Objects(other){}
void Club::update()
{
  if(_team==1)
  {
    _position.x+=1;
  }
  if(_team==2)
  {
    _position.x-=1;
  }
}
void Club::draw()
{
  if(status==ALIFE)
  {
    _term.set_cell(_position.x,_position.y,'|',_team,0);
    _term.set_cell(_position.x,_position.y-1,'o',_team,0);
  }
}
