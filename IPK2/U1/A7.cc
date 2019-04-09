#include<iostream>

int main()
{
    int oldFib=0;
    int newFib=1;
    for(int n=0;n<20;++n)
    {
      int a;
      a=newFib+oldFib;
      oldFib=newFib;
      newFib=a;
      std::cout<<a<<std::endl;
    }
}
