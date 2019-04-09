#include<iostream>

int main()
{
  int Celsius,Fahrenheit;
  std::cout<<"Grad  in Fahrenheit eingeben: "<<std::flush;
  std::cin>>Fahrenheit;
  Celsius=((Fahrenheit-32)*5)/9;
  std::cout<<Fahrenheit<<"° Fahrenheit = "<<Celsius<<"° Celsius";
}
