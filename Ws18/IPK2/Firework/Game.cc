#include"Game.h"

Game::Game(Terminal& term):_term(term),_elapsed_time(0.f)
{
  Normal* neu=new Normal(_term,{_term.width()/2,_term.height()-2});
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
    Normal* neu=new Normal(_term,{_firework[_accfire-1]->x(),_term.height()-2});
    _firework.push_back(neu);
  }
  if(_who==0)
  {
    Fountain* neu=new Fountain(_term,{_firework[_accfire-1]->x(),_term.height()-2});
    _firework.push_back(neu);
  }
  if(_who==2)
  {
    Big* neu=new Big(_term,{_firework[_accfire-1]->x(),_term.height()-2});
    _firework.push_back(neu);
  }
  if(_who==3)
  {
    Maxi* neu=new Maxi(_term,{_firework[_accfire-1]->x(),_term.height()-2});
    _firework.push_back(neu);
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
          _who=(_who+1)%4;
          nFirework(_who);
          break;
    }
    _elapsed_time += dt;
    if (_elapsed_time >= 0.1f)
    {
        if (true)
        {
          for(auto& f:_firework)
          {
            f->update();
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
  if(_game_on)
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
  }
  else
  {
    _term.draw_text(0,0,"___________.__                                   __    ");
    _term.draw_text(0,1,"\\_   _____/|__|______   ______  _  _____________|  | __");
    _term.draw_text(0,2," |    __)  |  \\_  __ \\_/ __ \\ \\/ \\/ /  _ \\_  __ \\  |/ /");
    _term.draw_text(0,3," |     \\   |  ||  | \\/\\  ___/\\     (  <_> )  | \\/    < ");
    _term.draw_text(0,4," \\___  /   |__||__|    \\___  >\\/\\_/ \\____/|__|  |__|_ \\");
    _term.draw_text(0,5,"     \\/                    \\/                        \\/");

    _term.draw_text(10,6,"  _________.__              .__          __               ");
    _term.draw_text(10,7," /   _____/|__| _____  __ __|  | _____ _/  |_  ___________");
    _term.draw_text(10,8," \\_____  \\ |  |/     \\|  |  \\  | \\__  \\\\   __\\/  _ \\_  __ \\");
    _term.draw_text(10,9," /        \\|  |  Y Y  \\  |  /  |__/ __ \\|  | (  <_> )  | \\/");
    _term.draw_text(10,10,"/_______  /|__|__|_|  /____/|____(____  /__|  \\____/|__|   ");
    _term.draw_text(10,11,"        \\/          \\/                \\/                  ");


    _term.draw_text(0,_term.height()-2,"w/s-adjust height a/d-move firework p-change firework space-set firework\n1-9-change color i-start firework s-start game");
  }
  _term.sleep(16);  //für 60 fps
}
void Game::reset()
{
  for(auto& f:_firework)
  {
    delete f;
  }
  _firework.clear();
  Normal* neu=new Normal(_term,{_term.width()/2,_term.height()-2});
  _firework.push_back(neu);
  _accfire=0;
  _who=0;
}
