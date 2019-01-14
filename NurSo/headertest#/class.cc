#include "header.hh"
#include<iostream>

//default-Konstruktor
komma::komma()
{
  vor=0;
  nach=0;
}
//Konstruktor
komma::komma(int a,int b)
{
  vor=a;
  nach=b;
}
//Ausgabe
void komma::drucken()
{
  std::cout<<vor<<","<<nach<<std::endl;
}
