#include "fcpp.hh"
//float outputs '10000' instead of '10000.0001'
//-> changing a and the function to double fixes that
double determinante(double a, float b, float c, float d){
  a=a*d-b*c;
  return a;
}
//double has more than 2x the digit precision of a float
int main(){
  print(determinante(100,0.01,-0.01,100));
}
