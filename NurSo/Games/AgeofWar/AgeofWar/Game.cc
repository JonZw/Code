#include"Game.h"
#include<string>
#include<vector>
#include <algorithm>

bool vectorContains(std::vector<int>& v,int e)
{
  for(int& i: v)
  {
    if(e==i)
    {
      return true;
    }
  }
  return false;
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
          }
          check_collision();
          _player1++;
          _player2++;
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
        case 's':
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
  std::string hi;
  for(auto& o:_objects)
  {
    hi+=" "+std::to_string(o->getx());
    v.push_back(o->getx());
  }
  for(auto& o:_objects)
  {
    if(o->getteam()==1)
    {
      if(vectorContains(v,o->getx()+3))
      {
        o->attack();
      }
    }
    if(o->getteam()==2)
    {
      if(vectorContains(v,o->getx()-3))
      {
        o->attack();
      }
    }
  }

  _term.draw_text(20,20,hi);
}
void Game::reset()
{
  for(auto& o:_objects)
  {
    delete o;
  }
}
