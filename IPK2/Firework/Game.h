#ifndef GAME_H
#define GAME_H

#include"Terminal.h"
#include"Firework.h"
#include <vector>
#include <string>

class Game
{
private:
  Terminal _term;
  bool _game_over=false;
  bool _is_done=false;
  std::vector<Firework*> _firework;
  int _accfire=0;   //aktueller Feuerwerkskörper zum bewegen
  float _elapsed_time;
  int _score;
  int _who=0;
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
  void nFirework(int who);
};

#endif
