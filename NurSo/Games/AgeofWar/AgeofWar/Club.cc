#include "Objects.h"
#include <string>
Club::Club(Terminal& term,Vec2D pos,int team):Objects(term,pos,team)
{
  _count=_team;
}
//Club::Club(const Club& other):Objects(other){}
void Club::update()
{
  if(status==ALIFE)
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
}
void Club::draw()
{
  if(status==ALIFE)
  {
    _term.set_cell(_position.x,_position.y,'|',_team,0);
    _term.set_cell(_position.x,_position.y-1,'o',_team,0);
  }
  if(status==ATTAK)
  {
    _term.set_cell(_position.x,_position.y,'|',_team,0);
    _term.set_cell(_position.x,_position.y-1,'o',_team,0);
    if(_count==0)
    {
      if(_team==1)
        _term.set_cell(_position.x+1,_position.y,'-',_team,0);
      else
        _term.set_cell(_position.x-1,_position.y,'-',_team,0);
    }
    _count=(_count+1)%2;
  }
}
