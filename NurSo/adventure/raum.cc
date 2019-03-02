#include <stdlib.h>
#include<iostream>
#include<experimental/random>
#include <fstream>
#include <string>
#include <iostream>
#include "räume"

class Raum
{
private:
  std::string raum;
public:
  Raum()
  {
    raum=raum1;
  }
  std::string out()
  {
    return raum;
  }
};
