#include "Firework.h"
#include <string>

Big::Big(Terminal& term,Vec2D pos):Firework(term,pos)
{
  std::vector<Vec2D> _sparks;
  _max_radius=rand()%10+5;
}
void Big::update()
{
  if(_status==Status::FLY)
  {
    _position.y-=1;
  }
  if(_status==Status::EXPLODE)
  {
    if(rand()%2==1)
    {
      if(rand()%10<7){_sparks.push_back({_position.x-_radius,_position.y});}
      if(rand()%10<7){_sparks.push_back({_position.x+_radius,_position.y});}
      if(rand()%10<7){_sparks.push_back({_position.x,_position.y-_radius});}
      if(rand()%10<9){_sparks.push_back({_position.x,_position.y+_radius});}
      if(rand()%10<7){_sparks.push_back({_position.x+_radius,_position.y+_radius});}
      if(rand()%10<5){_sparks.push_back({_position.x-_radius,_position.y-_radius});}
      if(rand()%10<3){_sparks.push_back({_position.x+_radius,_position.y-_radius});}
      if(rand()%10<2){_sparks.push_back({_position.x-_radius,_position.y+_radius});}
    }
    _radius+=1;
  }
  if(_position.y==_height)
  {
    _status=Status::EXPLODE;
  }
  if(_radius>=_max_radius)
  {
    _status=Status::END;
  }
}
void Big::draw()
{
  if(_status==Status::EXPLODE)
  {
    for(auto& s: _sparks)
    {
      char boom=' ';
      if(_color!=9)
        _term.set_cell(s.x,s.y,boom,_color,1);
      else
        _term.set_cell(s.x,s.y,boom,rand()%250,1);
    }
    if(_sparks.size()!=0)
      _sparks.erase(_sparks.begin());
  }
  if(_status==Status::FLY)
  {
    _term.set_cell(_position.x,_position.y,'x',_color,0);
  }
  if(_status==Status::GROUND)
  {
    if(_is_placed==false)
    {
      for(int n=0;n<_term.height()-3-_height;++n)
      {
        _term.set_cell(_position.x,_height+n,':',_color,0);
      }
      _term.set_cell(_position.x,_height,'x',_color,0);
    }
    _term.set_cell(_position.x,_position.y-1,'^',_color,0);
    _term.set_cell(_position.x,_position.y,'B',_color,0);
  }
}
