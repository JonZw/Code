#include "Objects.h"
#include <string>
King::King(Terminal& term,Vec2D pos,int team):Objects(term,pos,team)
{
  _count=_team;
  _hp=500+rand()%500;
  _mp=_hp;
  _dmg=2;
  _xp=150;
}
//King::King(const King& other):Objects(other){}
void King::update()
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
void King::draw()
{
  if(status==ALIFE||status==IDLE)
  {
    _term.set_cell(_position.x,_position.y,'|',_team,0);
    _term.set_cell(_position.x,_position.y-1,'o',_team,0);
    _term.set_cell(_position.x,_position.y-2,'M',_team,0);
  }
  if(status==ATTAK)
  {
    _term.set_cell(_position.x,_position.y,'|',_team,0);
    _term.set_cell(_position.x,_position.y-1,'o',_team,0);
    _term.set_cell(_position.x,_position.y-2,'M',_team,0);
    _term.draw_text(_position.x,_position.y-3,std::to_string((int)(((float)_hp/(float)_mp)*100)));
    if(_count==0)
    {
      if(_team==1)
        _term.set_cell(_position.x+1,_position.y,'/',_team,0);
      else
        _term.set_cell(_position.x-1,_position.y,'\\',_team,0);
    }
    _count=(_count+1)%2;
  }
}
