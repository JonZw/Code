#ifndef GAME_H
#define GAME_H

#include"Terminal.h"
#include"Objects.h"
#include <vector>
#include <string>

class Game
{
private:
  Terminal _term;
  bool _is_done=false;
  std::vector<Objects*> _objects;
  float _elapsed_time;
  bool _game_on=false;
public:
  //Konstruktor
  Game(Terminal& term);
  //Destruktor
  ~Game();
  //return _is_done
  bool is_done();
  //updatet das Spiel
  void update(float dt);
  //Malt das Spiel
  void draw();
  //Überprüft ob Game over
  void check_collision();
  //
  void reset();
  //setzt das Spiel zurück
};

#endif
