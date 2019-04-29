#include <iostream>
#include"array.cc"

int main()
{
  std::cout<<"Erstelle ersten Vektor 'eins' und setze 3 stelle auf 5"<<std::endl;
  Vector<int> eins(5);
  eins[3]=5;
  std::cout<<"gebe 3te stelle aus;"<<std::endl;
  std::cout<<eins[3]<<std::endl;
  std::cout<<"Erstelle zweiten Vecktor 'zwei' mit 'eins'+'eins'"<<std::endl;
  Vector<int> zwei=eins+eins;
  std::cout<<"und gebe die 3te stelle aus:"<<std::endl;
  std::cout<<zwei[3]<<std::endl;
  std::cout<<"die dritte stelle vom Vektor 'zwei'+'eins'"<<std::endl;
  std::cout<<(zwei+eins)[3]<<std::endl;
  std::cout<<"Erstelle dritten Vektor 'drei' mit(1,2,3)"<<std::endl;
  Vector<double> drei(3);
  drei[0]=1;drei[1]=2;drei[2]=3;
  std::cout<<"Erstelle vierten Vektor 'vier' mit 'drei'*3"<<std::endl;
  Vector<double> vier = drei*3.0;
  std::cout<<"und gebe ihn aus:"<<std::endl;
  std::cout<<vier[0]<<" "<<vier[1]<<" "<<vier[2]<<std::endl;
  std::cout<<"der Maximalwert von 'vier': "<<std::endl;
  std::cout<<vier.getMax()<<std::endl;
}
