#include"Game.h"

Game::Game(Terminal& term):_term(term),_elapsed_time(0.f),_score(0)
{

  Fountain* neu=new Fountain(_term,{_term.width()/2,_term.height()-2});

   _firework.push_back(neu);

}
Game::~Game()
{
  for(Firework*& f:_firework)
  {
    delete f;
  }
}
void Game::nFirework(int _who)
{
  if(_who==1)
  {
    Normal* neu=new Normal(_term,{_term.width()/2,_term.height()-2});
    _firework.push_back(neu);
  }
  if(_who==0)
  {
    Fountain* neu=new Fountain(_term,{_term.width()/2,_term.height()-2});
    _firework.push_back(neu);
  }
}
void Game::update(float dt)
{
  char pressed = _term.get_key();
  switch (pressed)
  {
      case 'r':
         _game_over = false;
         reset();
         break;

      case 'q':
          _is_done = true;
          break;
      case 'i':
        for(auto& f: _firework)
        {
          f->ignite();
        }
          break;
      case 'w':
      case 'a':
      case 's':
      case 'd':
        _firework[_accfire]->move(pressed);
        break;
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9': _firework[_accfire]->changeColor(pressed);
        break;
      case ' ':
        _firework[_accfire]->place();
        _accfire+=1;
        nFirework(_who);
        break;
      case 'p':
        _firework[_accfire]->end();
        _accfire+=1;
        _who=(_who+1)%2;
        nFirework(_who);
        break;
  }
  _elapsed_time += dt;
  if (_elapsed_time >= 0.1f)
  {
      if (!_game_over)
      {
        for(auto& f:_firework)
        {
          f->update();
        }
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
  if(_firework.size()==0)
  {
    _term.draw_text(20,20,"hi");
 }
  for(auto& f:_firework)
  {
    f->draw();
  }
  _term.sleep(16);  //für 60 fps
}
void Game::check_collision()
{

}
void Game::reset()
{

}
