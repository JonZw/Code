#include<iostream>
#include"Vec2D.h"
#include"Terminal.h"
#include<vector>

class Firework
{
protected:
  Terminal _term;
  Vec2D _position;
  int _radius=1;
  int _max_radius=(rand()%5+5);//rand()5-10
  int _color=rand()%250;
  std::vector<Vec2D> _sparks;
  bool _is_placed=false;
  int _height;
  enum Status
  {
    GROUND,
    FLY,
    EXPLODE,
    END
  };
  Status _status=Status::GROUND;
public:
  Firework(Terminal& term,Vec2D pos):_term(term),_position(pos),_height(term.height()-3){}
  Firework(const Firework& other)
  {
    _term=other._term;
    _position=other._position;
  }
  virtual ~Firework(){}
  virtual void update()=0;
  virtual void draw()=0;
  virtual void ignite()
  {
    if(_is_placed==true)
    {
      _status=Status::FLY;
    }
    else
    {
      _status=Status::END;
    }
  }
  void move(char dir)
  {
    switch(dir)
    {
      case 'a':_position.x-=1;
        break;
      case 'd':_position.x+=1;
        break;
      case 'w':if(_height>0)
              _height-=1;
        break;
      case 's':if(_height<_term.height()-3)
              _height+=1;
        break;
    }
  }
  virtual void place()
  {
    _position.y-=2;
    _is_placed=true;
    if(_height==_term.height()-3)
    {
      _height=rand()%20;
    }
  }
  virtual void changeColor(int col)
  {
    _color=col;
  }
  void end()
  {
    _status=Status::END;
  }
};//End firework

class Normal:public Firework
{
public:
  Normal(Terminal& term, Vec2D pos);
  Normal(const Normal& other);
  void update();
  void draw();
};//end Normal

class Fountain:public Firework
{
public:
  Fountain(Terminal& term, Vec2D pos);
  void update();
  void draw();
};//end Normal
