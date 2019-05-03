#include"Game.h"
#include<string>

Game::Game(Terminal& term):_term(term),_elapsed_time(0.f)
{
  Base* neu=new Base(_term,{2,(_term.height()/3)*2},1);
  Base* neu2=new Base(_term,{term.width()-3,(_term.height()/3)*2},2);
  Club* neu3=new Club(_term,{2,(_term.height()/3)*2},1);
  Club* neu4=new Club(_term,{term.width()-3,(_term.height()/3)*2},2);
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
  //_term.clear();
  for(auto& o:_objects)
  {
    o->draw();
  }
  _term.sleep(16);  //für 60 fps
}
void Game::check_collision()
{

}
void Game::reset()
{
  for(auto& o:_objects)
  {
    delete o;
  }
}
