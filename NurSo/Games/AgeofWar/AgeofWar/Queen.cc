#include "Objects.h"
#include <string>
Queen::Queen(Terminal& term,Vec2D pos,int team):Objects(term,pos,team)
{
  _count=_team;
  _hp=3000+rand()%1000;
  _mp=_hp;
  _dmg=5;
  _xp=1000;
}
//Queen::Queen(const Queen& other):Objects(other){}
void Queen::update()
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
  if(status==IDLE){}
  if(_hp<=0)
  {
    status=Status::DEAD;
  }
}
void Queen::draw()
{
  if(status==ALIFE||status==IDLE)
  {
    _term.set_cell(_position.x,_position.y,'Y',_team,0);
    _term.set_cell(_position.x,_position.y-1,'o',_team,0);
    _term.set_cell(_position.x,_position.y-2,'W',_team,0);
  }
  if(status==ATTAK)
  {
    _term.set_cell(_position.x,_position.y,'Y',_team,0);
    _term.set_cell(_position.x,_position.y-1,'o',_team,0);
    _term.set_cell(_position.x,_position.y-2,'W',_team,0);
    _term.draw_text(_position.x,_position.y-3,std::to_string((int)(((float)_hp/(float)_mp)*100)));
    if(_count==0)
    {
      if(_team==1)
        _term.set_cell(_position.x+1,_position.y,'~',_team,0);
      else
        _term.set_cell(_position.x-1,_position.y,'~',_team,0);
    }
    _count=(_count+1)%2;
  }
}
