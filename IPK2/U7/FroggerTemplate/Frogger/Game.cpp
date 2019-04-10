#include"Game.h"

Game::Game(Terminal& term):_term(term),frog(_term),_elapsed_time(0.f),_score(0)
{
  reset();
}

void Game::update(float dt)
{
  char pressed = _term.get_key();
  switch (pressed) {
      case 'r':
         _game_over = false;
         reset();
         break;

      case 'q':
          _is_done = true;
          break;
      case 'w':
          frog.change_direction(pressed);
          break;
      case 'a':
          frog.change_direction(pressed);
          break;
      case 's':
          frog.change_direction(pressed);
          break;
      case 'd':
          frog.change_direction(pressed);
          break;
      default:
          break;
  }
  _elapsed_time += dt;
  if (_elapsed_time >= 0.1f)
  {
      if (!_game_over)
      {
        frog.update();
        for(auto& c:cars)
        {
          c.update();
        }
        for(auto& b: bushs)
        {
          b.update();
        }
        ++_score;
        if(_score%500==0)
        {
          cars.push_back({_term,{rand()%_term.width(),rand()%30-30},1,rand()%7+1});
        }
        if(_score%1000==0)
        {
          bushs.push_back({_term,{rand()%_term.width()-1,-5},1});
        }
        check_collision();
      }
      _elapsed_time = 0.f;
  }
}
bool Game::is_done()
{
  return _is_done;
}
void Game::draw()
{
  _term.clear();
  _term.draw_text(_term.width()-14,1,"Score: "+std::to_string(_score));
  frog.draw();
  for(auto& c:cars)
  {
    c.draw();
  }
  for(auto& b:bushs)
  {
    b.draw();
  }
  if(_game_over)
  {
    _term.draw_text(_term.width()/4,_term.height()/2,"Game over: r to restart / q to quit");
  }
  _term.sleep(16);
}
void Game::check_collision()
{
  for(auto& c: cars)
  {
    if(c.position()==frog.position())
    {
      _game_over=true;
    }
  }
  if(frog.position().y>_term.height())
  {
    _game_over=true;
  }
  for(auto& b:bushs)
  {
    if(b.position()==frog.position())
    {
      _game_over=true;
    }
  }
}
void Game::reset()
{
  frog.reset();
  cars.clear();
  bushs.clear();
  for(int n=0;n<2;n++)
  {
  cars.push_back({_term,{rand()%_term.width(),rand()%30-30},1,rand()%7+1});
  }
  for(int n=0;n<_term.height();n+=4)
  {
    bushs.push_back({_term,{0,n},0});
    bushs.push_back({_term,{_term.width()-1,n},0});
  }
  _score=0;
}
