#include<iostream>
#include <stdio.h>

int main()
{
  system("stty raw");
  char input = getchar();
  int ascii = input;
  std::cout<<input<<" = "<<ascii<<std::endl;
    system("stty cooked");
}
