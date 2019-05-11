#include "Objects.h"
#include <string>

Base::Base(Terminal& term,Vec2D pos,int team):Objects(term,pos,team)
{
}
Base::Base(const Base& other):Objects(other){}
void Base::update()
{

}
void Base::draw()
{
  _term.set_cell(_position.x,_position.y,'_',_team,0);
  _term.set_cell(_position.x-1,_position.y,'|',_team,0);
  _term.set_cell(_position.x+1,_position.y,'|',_team,0);
  _term.set_cell(_position.x-1,_position.y-1,'/',_team,0);
  _term.set_cell(_position.x+1,_position.y-1,'\\',_team,0);
}
