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

void print_primes(int upto)
{
  for(int n=0;n<=upto;++n)
  {
    if(is_prime(n))
    {
      std::cout<<n<<"\t"<<std::endl;
    }
  }
}

int main()
{
  int zahl;
  std::cout<<"geben sie eine zahl ein"<<std::endl;
  std::cin>>zahl;
  print_primes(zahl);
}
