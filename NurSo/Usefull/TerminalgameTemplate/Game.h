#ifndef GAME_H
#define GAME_H

#include"Terminal.h"
#include <vector>
#include <string>

class Game
{
private:
  Terminal _term;
  bool _game_over=false;
  bool _is_done=false;
  float _elapsed_time;
  int _score;
public:
  //Konstruktor
  Game(Terminal& term);
  //return _is_done
  bool is_done();
  //updatet das Spiel
  void update(float dt);
  //Malt das Spiel
  void draw();
  //Überprüft ob Game over
  void check_collision();
  //setzt das Spiel zurück
  void reset();
};

#endif
