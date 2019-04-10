#ifndef GAME_H
#define GAME_H

#include"Terminal.h"
#include "Objekts.h"
#include <vector>
#include <string>

class Game
{
private:
  Terminal _term;
  std::vector<Car> cars;
  std::vector<Bush> bushs;
  Frog frog;
  bool _game_over=false;
  bool _is_done=false;
  float _elapsed_time;
  int _score;
public:
  Game(Terminal& term);
  bool is_done();
  void update(float dt);
  void draw();
  void check_collision();
  void reset();
};

#endif
