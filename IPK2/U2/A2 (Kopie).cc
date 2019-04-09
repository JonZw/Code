#include<iostream>

bool  is_prime(int number)
{
  if(number<0)
  {
    return false;
  }
  bool prim=true;
  for(int n=2;n<number;++n)
  {
    if(number%n==0)
    {
      prim=false;
    }
  }
  if(prim)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int zahl;
  std::cout<<"geben sie eine zahl ein"<<std::endl;
  std::cin>>zahl;
  if(is_prime(zahl))
  {
    std::cout<<"Ist Prim"<<std::endl;
  }
  else
  {
      std::cout<<"Ist nicht Prim"<<std::endl;
  }

}
