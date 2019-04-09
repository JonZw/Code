#include<iostream>
#include<cmath>

int main()
{
  double x1,x2;
  double a=0,b=0,c=0;
  //Einlesen
  std::cout<<"ax²+bx+c=0"<<std::endl;
  std::cout<<"a = "<<std::flush;
  std::cin>>a;
  std::cout<<"b = "<<std::flush;
  std::cin>>b;
  std::cout<<"c = "<<std::flush;
  std::cin>>c;
  std::cout<<a<<b<<c<<std::endl;
  //Mitternacht
  x1=((-b)+(sqrt((b*b)-4*a*c)))/(2*a);
  x2=((-b)-sqrt((b*b)-4*a*c))/(2*a);
  std::cout<<"x1= "<<x1<<std::endl;
  std::cout<<"x2= "<<x2<<std::endl;
}
