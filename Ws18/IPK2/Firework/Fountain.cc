#include"Firework.h"

Fountain::Fountain(Terminal& term,Vec2D pos):Firework(term,pos)
{
  std::vector<Vec2D> _sparks;
}

void Fountain::update()
{
  if(_status==Status::FLY)
  {
    _status=Status::EXPLODE;
  }
  if(_status==Status::EXPLODE)
  {
    if(_sparks.size()<4)
    {
      _sparks.push_back({_position.x,_position.y-1});
    }
    for(auto& s:_sparks)
    {
      if(s.y==_height)
      {
        _sparks.erase(_sparks.begin());
        _radius+=1;
      }
      s.y-=1;
    }
    if(_radius==20)
    {
      _status=Status::END;
    }
  }
}

void Fountain::draw()
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
      _term.set_cell(s.x,s.y,boom,_color,0);
    }
    _term.set_cell(_position.x,_position.y-1,'^',_color,0);
    _term.set_cell(_position.x,_position.y,'L',_color,0);
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
    _term.set_cell(_position.x,_position.y,'L',_color,0);
  }
}
