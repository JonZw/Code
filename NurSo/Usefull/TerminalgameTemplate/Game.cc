#include"Game.h"

Game::Game(Terminal& term):_term(term),_elapsed_time(0.f),_score(0)
{
  reset(); //Setzt Frösch,Büsche und Autos an die richtige stelle
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
      default:
          break;
  }
  _elapsed_time += dt;
  if (_elapsed_time >= 0.1f)
  {
      if (!_game_over)
      {

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

  _term.sleep(16);  //für 60 fps
}
void Game::check_collision()
{

}
void Game::reset()
{
  
}
