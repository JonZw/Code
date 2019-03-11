#include"Planet.cc"
#include<vector>

class System
{
private:
  std::vector<Planet> Galaxy;
public:
  System()
  {
    Galaxy.push_back({Planet()});
  }
  void pointer()
  {
    for(auto n:Galaxy)
    {
      std::cout<<&n<<std::endl;
      std::cout<<n.getPop()<<std::endl;
    }
  }
  void Up()
  {
    for(auto n:Galaxy)
    {
      n.Up();
      std::cout<<n.getPop()<<std::endl;
    }
  }
  void foo()
  {
    for(auto n: Galaxy)
    {
      std::cout<<n.getPop()<<std::endl;
    }
  }
};
