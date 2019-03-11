class Planet
{
private:
  int _population;
  int _Hpr; //Heal/Round
  int _target;
public:
  Planet()
  {
    _population=1;
    _Hpr=1;
    _target=0;
  }
  void Up()
  {
    _population+=_Hpr;
  }
  int getPop()
  {
    return _population;
  }
};//End Planet
