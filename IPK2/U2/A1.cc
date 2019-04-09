#include <iostream>

int main()
{
  //a)
  int zahl=0;
  int sum=0;
  std::cout<<"Zahl eingeben: "<<std::flush;
  std::cin>>zahl;
  for(int n=0;n<zahl;++n)
  {
    if(n%2!=0)
    {
      sum+=n;
    }
  }
  std::cout<<sum<<std::endl;
  //b)
  for(int n=2;n<20;n=n+2)
  {
    std::cout<<n<<" : "<<n*n<<std::endl;
  }
  //c)
  int count=0;
  int multiply=1;
  std::cout<<"Zahl eingeben: "<<std::flush;
  std::cin>>zahl;
  std::cout<<"X\t"<<std::flush;
  for(int n=0;n<=zahl;++n)
  {
    std::cout<<n<<"\t"<<std::flush;
  }
  std::cout<<std::endl;
  for(int n=0;n<=zahl;++n)
  {
    std::cout<<n<<"\t"<<std::flush;
    for(int i=0;i<=zahl;i++)
    {
      std::cout<<i*n<<"\t"<<std::flush;
    }
    std::cout<<std::endl;
  }
}
