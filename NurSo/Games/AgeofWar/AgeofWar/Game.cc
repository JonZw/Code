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
  Clubtrainer* neu3=new Clubtrainer(_term,{1,1},1);
  Clubtrainer* neu4=new Clubtrainer(_term,{1,1},2);
  _objects.push_back(neu);
  _objects.push_back(neu2);
  _objects.push_back(neu3);
  _objects.push_back(neu4);
}
Game::~Game()
{
  for(Objects*& o:_objects)
  {
    delete o;
  }
}
void Game::spawn(int team,int unit)
{
  Vec2D where;
  if(team==1)
  {
    where={2,(_term.height()/3)*2};
  }
  if(team==2)
  {
    where={_term.width()-3,(_term.height()/3)*2};
  }
  if(unit==1)
  {
    try
    {
      Club* neu=new Club(_term,where,team);
      _objects.push_back(neu);
    }
    catch(...)
    {

    }
  }
  if(unit==2)
  {
    King* neu=new King(_term,where,team);
    _objects.push_back(neu);
  }
  if(unit==3)
  {
    Queen* neu=new Queen(_term,where,team);
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
              spawn(1,1);
              _player1-=50;
            }
            break;
        case 's':
            if(_player1-300>=0)
            {
              spawn(1,2);
              _player1-=300;
            }
            break;
        case 'd':
            if(_player1-1500>=0)
              {
                spawn(1,3);
                _player1-=1500;
              }
        case 'y':
            trainer(1,1);
            break;
        case 'l':
            if(_player2-50>=0)
            {
              spawn(2,1);
              _player2-=50;
            }
            break;
        case 'k':
            if(_player2-300>=0)
            {
              spawn(2,2);
              _player2-=300;
            }
            break;
        case 'j':
            if(_player2-1500>=0)
            {
              spawn(2,3);
              _player2-=1500;
            }
            break;
        case ',':
            trainer(2,1);
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
            if(o->train())
            {
              spawn(o->getteam(),o->who());
            }
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
void Game::trainer(int team,int trainer)
{
  for(auto& o: _objects)
  {
    if(o->getteam()==team&&o->who()==trainer)
    {
      if((o->getteam()==1&&o->cost()<_player1)||(o->getteam()==2&&o->cost()<_player2))
      {
        if(o->getteam()==1)
        {
          _player1-=o->cost();
        }
        if(o->getteam()==2)
        {
          _player2-=o->cost();
        }
        o->up();
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
