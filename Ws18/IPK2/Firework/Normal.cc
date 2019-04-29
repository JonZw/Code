#include "Firework.h"
#include <string>

Normal::Normal(Terminal& term,Vec2D pos):Firework(term,pos)
{
  std::vector<Vec2D> _sparks;
}
Normal::Normal(const Normal& other):Firework(other){}
void Normal::update()
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
void Normal::draw()
{
  if(_status==Status::EXPLODE)
  {
    for(auto& s: _sparks)
    {
      char boom;
      int selector=rand()%10;
      {
        switch(selector)
        {
          case 0: boom='*';break;
          case 1: boom='X';break;
          case 2: boom='x';break;
          case 3: boom='+';break;
          case 4: boom='#';break;
          case 5: boom='o';break;
          case 6: boom='O';break;
          case 7: boom='0';break;
          case 8: boom='q';break;
          case 9: boom='2';break;
        }
      }
      if(_color!=9)
        _term.set_cell(s.x,s.y,boom,_color,0);
      else
        _term.set_cell(s.x,s.y,boom,rand()%250,0);
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
    _term.set_cell(_position.x,_position.y,'|',_color,0);
  }
}
