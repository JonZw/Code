#include"Game.h"
#include<string>
#include<vector>
#include <algorithm>

int vectorContains(std::vector<int>& v,int e)
{
  for(unsigned i=0;i<v.size();++i)
  {
    if(e==v[i])
    {
      return i;
    }
  }
  return v.size();
}


Game::Game(Terminal& term):_term(term),_elapsed_time(0.f)
{
  Base* neu=new Base(_term,{2,(_term.height()/3)*2},1);
  Base* neu2=new Base(_term,{term.width()-3,(_term.height()/3)*2},2);
  _objects.push_back(neu);
  _objects.push_back(neu2);
}
Game::~Game()
{
  for(Objects*& o:_objects)
  {
    delete o;
  }
}
void Game::spawn(int team)
{
  if(team==1)
  {
    Club* neu=new Club(_term,{2,(_term.height()/3)*2},1);
    _objects.push_back(neu);
  }
  if(team==2)
  {
    Club* neu=new Club(_term,{_term.width()-3,(_term.height()/3)*2},2);
    _objects.push_back(neu);
  }
}
void Game::update(float dt)
{
  char pressed = _term.get_key();
  if(_game_on)
  {
    switch (pressed)
    {
        case 'r':
           reset();
           break;
        case 'q':
            _is_done = true;
            break;
        case 'a':
            if(_player1-50>=0)
            {
              spawn(1);
              _player1-=50;
            }
            break;
        case 'l':
            if(_player2-50>=0)
            {
              spawn(2);
              _player2-=50;
            }
            break;
        default:
            break;
    }
    _elapsed_time += dt;
    if (_elapsed_time >= 0.1f)
    {
        if (true)
        {
          for(auto& o:_objects)
          {
            o->update();
            check_collision();
          }
          _player1++;
          _player2++;
          for(unsigned i=0;i<_objects.size();++i) //Prüft ob Tot
          {
            if(_objects[i]->loluded())
            {
              if(_objects[i]->getteam()==1)
              {
                _player2+=_objects[i]->getxp();
              }
              else
              {
                _player1+=_objects[i]->getxp();
              }
              delete _objects[i];
              _objects.erase(_objects.begin()+i);
            }
          }
        }
        _elapsed_time = 0.f;
    }
  }
  else
  {
    switch (pressed)
    {
        case 'q':
            _is_done = true;
            break;
        case 'p':
            _game_on=true;
            break;
    }
  }
}
bool Game::is_done()
{
  return _is_done;
}
void Game::draw()
{
  _term.clear();
  for(auto& o:_objects)
  {
    o->draw();
  }
  _term.draw_text(0,0,std::to_string(_player1));
  _term.draw_text(_term.width()-4,0,std::to_string(_player2));
  _term.sleep(16);  //für 60 fps
}

void Game::check_collision()
{
  std::vector<int> v;
  for(auto& o:_objects)
  {
    v.push_back(o->getx());
  }
  for(auto& o:_objects)
  {
    if(o->getteam()==1)
    {
      if((unsigned)vectorContains(v,o->getx()+3)<v.size())
      {
        if(_objects[vectorContains(v,o->getx()+3)]->getteam()==2)
        {
          o->attack();
          _objects[vectorContains(v,o->getx()+3)]->aua(o->getdmg());
        }
        else
          o->idle();
      }
      else
      {
          o->alife();
      }
    }
    if(o->getteam()==2)
    {
      if((unsigned)vectorContains(v,o->getx()-3)<v.size())
      {
        if(_objects[vectorContains(v,o->getx()-3)]->getteam()==1)
        {
          o->attack();
          _objects[vectorContains(v,o->getx()-3)]->aua(o->getdmg());
        }
        else
          o->idle();
      }
      else
      {
        o->alife();
      }
    }
  }
}
void Game::reset()
{
  for(unsigned i=0;i<_objects.size();++i)
  {
    delete _objects[i];
  }
  _objects.clear();
  Base* neu=new Base(_term,{2,(_term.height()/3)*2},1);
  Base* neu2=new Base(_term,{_term.width()-3,(_term.height()/3)*2},2);
  _objects.push_back(neu);
  _objects.push_back(neu2);
}
