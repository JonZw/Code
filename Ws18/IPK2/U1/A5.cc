#include<iostream>

int main()
{
  int sum=0;
  for(int n=0;n<1000;++n)
  {
    if(n%3==0||n%5==0)  //teilbar durch 3 oder 5
    {
      sum+=n;
    }
  }
  std::cout<<sum<<std::endl;
}
//1 min
