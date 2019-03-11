#include<vector>
#include<iostream>
class Zahl
{
private:
  int n;
public:
  Zahl()
  {
    n=1;
  }
  void Up()
  {
    n+=1;
  }
  int out()
  {
    return n;
  }
};//end zahl

int main()
{
  std::vector<Zahl> v;
  v.push_back({Zahl()});
  std::cout<<v[0].out()<<std::endl;
  {
    v[0].Up();
  }
  std::cout<<v[0].out()<<std::endl;
}
