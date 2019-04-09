#include"Game.h"

Game::Game(Terminal& term):_term(term),frog(_term),_elapsed_time(0.f)
{
  cars.push_back({_term,{10,15},1});
  cars.push_back({_term,{10,5},2});
}

void Game::update(float dt)
{
  char pressed = _term.get_key();
  switch (pressed) {
      case 'r':
          _game_over = false;
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
  frog.draw();
  for(auto& c:cars)
  {
    c.draw();
  }
}
void Game::check_collision()
{
  for(auto& c: cars)
  {
    if(c.position()==frog.position())
    {
      _game_over=true;
      _is_done=true;
    }
  }
}
