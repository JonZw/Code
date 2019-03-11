#include <iostream>
#include "Tier.cc"

int main()
{
  int anzKinder=3;
  tier* kinder[3];
  tier* kind1;
  tier* kind2;
  tier* kind3;
  otter Justin;
  Lachs Fabian;
  Fuchs Manuel;
  kind1=&Justin;
  kind2=&Fabian;
  kind3=&Manuel;
  kinder[0]=kind1;
  kinder[1]=kind2;
  kinder[2]=kind3;
  for(int n=0;n<anzKinder;n++)
  {
    kinder[n]->gibLaut();
  }
}
