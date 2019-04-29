#include<iostream>

void out(int num,int weite)
{
  int abstand=weite-num/2;  //Abstand zum linken rand
  std::string ausgabe;
  for(int n=0;n<abstand;++n)  //Abstand eingegeben
  {
    ausgabe=ausgabe+" ";
  }
  for(int n=0;n<num;++n)    //Diamanten hinzugefügt
  {
    ausgabe=ausgabe+"*";
  }
  std::cout<<"\t"<<ausgabe<<std::endl;  //Reihe ausgegeben
}

int main()
{
  int weite;
  std::cout<<"geben sie die Weite an"<<std::endl;
  std::cin>>weite;
  while(weite<0||weite%2==0) //Nicht Negativ/Nicht gerade
  {
    std::cout<<"geben sie die Weite an (ungerade und größer als 0)"<<std::endl;
    std::cin>>weite;
  }
  int dimonds=1;    //Anzahl der Diamnten(*) in der reihe
  bool half=false;  // Ist die hälfte erreicht?
  for(int n=0;n<weite;++n)  //der Diamand ist genauso hoch wie breit
  {
    if(dimonds>weite)       //dh. die hälfte wurde überschritten
    {
      dimonds-=4;
      half=true;
    }
    out(dimonds,weite);    //Ausgabe
    if(half)
    {
      dimonds-=2;
    }
    else
    {
      dimonds+=2;
    }
  }
}
