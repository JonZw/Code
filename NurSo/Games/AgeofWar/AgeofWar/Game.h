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
  int _player1=999999;
  int _player2=999999;
public:
  //Konstruktor
  Game(Terminal& term);
  //Destruktor
  ~Game();
  //Spawn units
  void spawn(int team,int unit);
  //return _is_done
  bool is_done();
  //updatet das Spiel
  void update(float dt);
  //Malt das Spiel
  void draw();
  //Überprüft ob Game over
  void check_collision();
  //chekt kollision
  void trainer(int team,int trainer);
  //handlet trainer
  void reset();
  //setzt das Spiel zurück
};

#endif
