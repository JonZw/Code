#include<iostream>

int main()
{
  int* werte;
  int array[10];
  array[0]=7;
  array[5]=5;
  werte=&array[0];
  std::cout<<werte[0]<<werte[5]<<std::endl;
}
