#include<iostream>
#include"Vec2D.h"
#include"Terminal.h"
#include<vector>

class Objects
{
protected:
  Terminal _term;
  Vec2D _position;
  int _team;
  int _hp;
  int _mp;
  int _dmg;
  int _xp;
  enum Status
  {
    ALIFE,
    DEAD,
    IDLE,
    ATTAK
  };
  Status status=Status::ALIFE;
public:
  Objects(Terminal& term,Vec2D pos,int team):_term(term),_position(pos),_team(team){}
  Objects(const Objects& other)
  {
    _term=other._term;
    _position=other._position;
  }
  int getx(){return _position.x;}
  int getteam(){return _team;}
  void attack(){if(status!=DEAD){status=Status::ATTAK;}}
  virtual ~Objects(){}
  virtual void update()=0;
  virtual void draw()=0;
  void idle(){if(status!=DEAD){status=Status::IDLE;}}
  void aua(int damage){_hp-=damage;}
  int getdmg(){return _dmg;}
  int getxp(){return _xp;}
  void alife(){if(status!=DEAD){status=Status::ALIFE;}}
  bool loluded(){return (status==DEAD);}
  virtual bool train(){return false;}
  virtual int who(){return 0;}
  virtual void up(){}
  virtual int cost(){return 0;}
};//End Objects

class Base:public Objects
{
public:
  Base(Terminal& term, Vec2D pos,int team);
  Base(const Base& other);
  void update();
  void draw();
};//end Base

class Club:public Objects
{
private:
  int _count=0;
public:
  Club(Terminal& term, Vec2D pos,int team);
  Club(const Base& other);
  void update();
  void draw();
  bool loluded(){return (status==DEAD);}
};//end Club

class King:public Objects
{
private:
  int _count=0;
public:
  King(Terminal& term, Vec2D pos,int team);
  King(const Base& other);
  void update();
  void draw();
  bool loluded(){return (status==DEAD);}
};//end Club

class Queen:public Objects
{
private:
  int _count=0;
public:
  Queen(Terminal& term, Vec2D pos,int team);
  Queen(const Base& other);
  void update();
  void draw();
  bool loluded(){return (status==DEAD);}
};//end Club

class Clubtrainer:public Objects
{
private:
  int _count=150;
  int _level=0;
  bool _train;
  int _cost=200;
  int _time=150;
public:
  Clubtrainer(Terminal& term, Vec2D pos,int team);
  Clubtrainer(const Base& other);
  void update();
  void draw();
  bool train();
  int who();
  void up();
  int cost();
};//end Club
