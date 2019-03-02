#include <stdlib.h>
#include<iostream>
#include<experimental/random>
#include <fstream>
#include <string>
#include <iostream>
#include"raum.cc"

void sleep(int n) //27~1sek
{
  while(n!=0)
  {
  sleep(n-1);
  n--;
  }
}

int main()
{
  Raum raum;
  int hi=0;
  while(hi==0)
  {
    //int wait=std::experimental::randint(23,27);
    sleep(25);
    std::string out=raum.out();
    std::cout<<out<<std::flush;
    hi=hi+1;
  }
}
