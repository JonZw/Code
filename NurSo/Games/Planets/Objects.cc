#include<string>

class Object
{
public:
  int Team;           //0=Ohne 1=Player 2=Enemy
  int _population;
  int _Hpr;
  int distance;
  int _dest;
  bool idle;
  virtual void up()=0;
  virtual int out()=0;
  virtual int who()=0; //1=Planet 2=Ship 3=Mine 4=Astroid 5=space
  virtual std::string Image(int line)=0;
};//End Object

class Planet : public Object
{
private:
//  int _population;
//  int _Hpr; //Heal/Round
public:
  std::string Imag[4];
  Planet(int team)
  {
      _population=0;
      _Hpr=1;
      Team=team;
      Imag[0]=" ______ ";
      Imag[1]="|      |";
      Imag[2]="|  P"+std::to_string(_population)+"\t|";
      Imag[3]="|______|";
      if(team==0){_Hpr=0;}
  }
  int who()
  {
    return 1;
  }
  int out()
  {
    return _population;
  }
  void up()
  {
    _population+=_Hpr;
    if(_population>99){_population=99;}
  //  Imag[0]=" ______ ";
  //  Imag[1]="|      |";
    Imag[2]="|  P"+std::to_string(_population)+"\t|";
    //Imag[3]="|______|";
  }
  std::string Image(int line)
  {
    return Imag[line];
  }
  void changePop(int newPop)
  {
    _population+=newPop;
  }
};//End Planet

class Ship:public Object
{
private:
  //int _dest; //Destination
  int _Hp; //Hitpoints
  int _loc;//Location
public:
  std::string Imag[4];
  Ship(int team,int loc,int dest)
  {
    _dest=dest;
    _Hp=5;
    _loc=loc;
    idle=false;
    Team=team;
    Imag[0]=" ______ ";
    Imag[1]="|      |";
    Imag[2]="|  S   |";
    Imag[3]="|______|";
  }
  int who()
  {
    return 2;
  }
  void up()
  {
    //???
  }
  int out()
  {
    return _loc;
  }
  int dest()
  {
    return _dest;
  }
  void newloc(int loc)
  {
    _loc= loc;
  }
  std::string Image(int line)
  {
    return Imag[line];
  }
};//End Ship

class Mine:public Object
{
private:
  //?
public:
  std::string Imag[4];
  Mine()
  {
    Imag[0]=" ______ ";
    Imag[1]="|      |";
    Imag[2]="|  M   |";
    Imag[3]="|______|";
  }
  void up()
  {

  }
  int out()
  {
    return 0;
  }
  int who()
  {
    return 3;
  }
  std::string Image(int line)
  {
    return Imag[line];
  }
};//End Mine

class Astroid:public Object
{
private:
public:
  std::string Imag[4];
  Astroid()
  {
    Imag[0]=" ______ ";
    Imag[1]="|      |";
    Imag[2]="|  A   |";
    Imag[3]="|______|";
  }
  void up()
  {

  }
  int out()
  {
    return 0;
  }
  int who()
  {
    return 4;
  }
  std::string Image(int line)
  {
    return Imag[line];
  }
};//End Astroid
class Space:public Object
{
private:
public:
  std::string Imag[4];
  Space()
  {
    Imag[0]=" ______ ";
    Imag[1]="|      |";
    Imag[2]="|      |";
    Imag[3]="|______|";
  }
  int who()
  {
    return 5;
  }
  void up()
  {

  }
  int out()
  {

  }
  std::string Image(int line)
  {
    return Imag[line];
  }
};//End Space
