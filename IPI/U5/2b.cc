#include <iostream>
#include <cmath>
#include"fcpp.hh"

int main()
{
	  float n;
	  std::cout<<"Enter a value for n:"<<std::flush;
	  std::cin>>n;
	  //a=pow(10,n);
	  //b=-a;
	  //c=1.0/a;
	  std::cout.precision(16);
	  std::cout<<"a="<<pow(10,n)<<" b="<<-(pow(10,n))<<" c="<<1.0/(pow(10,n))<<std::endl;
	  float z=((pow(10,n)+-pow(10,n))+(1.0/pow(10,n)));//(a+b)=0 everytime -> outputs unrounded c
	  float u=(pow(10,n)+(-pow(10,n)+(1.0/pow(10,n))));//(b+c)=b, because of too litle digit precision of a float
	  //-> (b+c)=b -> a+b=0
	print(z);
	print(u);
}
//Bei der Rechnung (a+b)+c wird zuerst a+b berechnet, was gleich null ist.
//Daraus folgt, dass das Ergebnis c ist.

//Wenn a+(b+c) berechnet wird wird zuerst b+c berechnet.
//Da der float Datentyp eine relativ kleine Gleitkommagenauigkeit hat
//ist die das Ergebnis der Rechnung (b+c) das gleiche wie nur b, wegen rundungsfehler.
//Daraus folgt a+(b+c)=a+b=0 ab n=9.
