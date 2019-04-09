#include<iostream>

int convert_number(std::string number,int basis)
{
  int ergebnis=0;
  for(int n=0;n<number.size();++n)
  {
    ergebnis=ergebnis*basis+number[n]-48;
  }
  return ergebnis;
}

int main()
{
  int basis;
  std::string Zahl;
  std::cout<<"geben sie eine Zahl ein"<<std::endl;
  std::cin>>Zahl;
  std::cout<<"geben sie eine Basis ein"<<std::endl;
  std::cin>>basis;
  std::cout<<convert_number(Zahl,basis)<<std::endl;
}
