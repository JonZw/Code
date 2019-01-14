#include <iostream>
#include<cmath>

int modulo(int zahl,int modulo)
{
  int ergebnis=0;
  int n=0;
  int i=0;

  while(modulo*n<zahl){n++;}
  while(i+modulo*n-modulo!=zahl){i++;}
  if(i==modulo){return 0;}
  return i;
}

int main()
{
const int mod=13;

//for(int i=1;i<mod;i++)  //Multipklikaiontabelle
//{
//  std::cout<<"  "<<i<<std::endl;
//  for(int n=1;n<mod;n++)
//  {
//    std::cout<<(modulo(n*i,mod))<<std::endl;
//  }
//}

std::cout<<modulo(pow(15,83),mod)<<std::endl;
}
