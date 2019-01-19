#include<iostream>

class tier
{
public:
  std::string Name;
  std::string Farbe;
  std::string Laut;
  bool Fell;
  virtual void gibLaut()=0;
};//end tier
class otter : public tier
{
public:
  otter()
  {
    Fell=true;
    Laut="Miau";
    Farbe="Braun";
  }
  void gibLaut()
  {
    std::cout<<Laut<<std::endl;
  }
};//end otter
class Lachs : public tier
{
public:
  Lachs()
  {
    Fell=false;
    Laut="*plätscher*";
    Farbe="Blau";
  }
  void gibLaut()
  {
    std::cout<<Laut<<std::endl;
  }
};//end Lachs
class Fuchs : public tier
{
public:
  Fuchs()
  {
    Fell=true;
    Laut="warum?";
    Farbe="Braun-Rot";
  }
  void gibLaut()
  {
    std::cout<<Laut<<std::endl;
  }
};//end otter
