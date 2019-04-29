#include <iostream>
int  main ()
{
  std::cout << "Summing  all  squares  until (and including) n = " ;
  int  number ;
  std::cin >> number ;  //<< -> >>
  int sum=0; //added =0
  for(int i=0;i<=number;i++) //< -> <=
  {
    sum += i*i;          // ∗->*
  }
  std::cout<<"Result :" << sum << std::endl; //>> -> << und << for sum eingefügt
}
