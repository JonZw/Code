#include "Objects.h"
#include <string>
Clubtrainer::Clubtrainer(Terminal& term,Vec2D pos,int team):Objects(term,pos,team)
{
}
//Clubtrainer::Clubtrainer(const Clubtrainer& other):Objects(other){}
void Clubtrainer::update()
{
  if(_level==0){}
  else
  {
   _count--;
   if(_count==0)
   {
     _train=true;
     _count=_time;
   }
   else
   {
     _train=false;
   }
 }
}
void Clubtrainer::draw()
{
  if(_level>0)
  {
    if(_team==1)
    {
      _term.set_cell(2+3,(_term.height()/3)*2+4,'|',_team,0);
      _term.set_cell(2+3,(_term.height()/3)*2+3,'o',_team,0);
      _term.draw_text(2+5,(_term.height()/3)*2+4,std::to_string(_count));
      _term.draw_text(2-2,(_term.height()/3)*2+4,std::to_string(_cost));
    }
    if(_team==2)
    {
      _term.set_cell(_term.width()-8,(_term.height()/3)*2+4,'|',_team,0);
      _term.set_cell(_term.width()-8,(_term.height()/3)*2+3,'o',_team,0);
      _term.draw_text(_term.width()-12,(_term.height()/3)*2+4,std::to_string(_count));
      _term.draw_text(_term.width()-6,(_term.height()/3)*2+4,std::to_string(_cost));
    }
  }
}
void Clubtrainer::up()
{
  if(_level<=6)
  {
    ++_level;
    _cost+=100;
    _time-=20;
  }
  else
  {
    _cost=0;
  }
}
int Clubtrainer::cost()
{
  return _cost;
}
bool Clubtrainer::train(){return _train;}
int Clubtrainer::who(){return 1;}
