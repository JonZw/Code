#include<iostream>
#include<string>

struct FiFo
{
  int werte[10]={0,0,0,0,0,0,0,0,0,0};  //Speicherarray
  int size=0; //Die aktuelle größe (und unser Zeiger)
  void push(int wert)
  {
    if(size==10)
    {
      for(int n=0;n<9;++n)  //alles nach links schieben
      {
        werte[n]=werte[n+1];
      }
      werte[9]=wert;
    }
    else
    {
      werte[size]=wert;
      ++size;
    }
  }
  int pop()
  {
    if(size>0)
    {
      int out=werte[0]; //unsere ausgabe
      for(int n=0;n<9;++n)  //wieder alles nach links schieben
      {
        werte[n]=werte[n+1];
      }
      werte[9]=0;
      --size;
      return out;
    }
    else //d.h. das array ist leer
    {
      return 0;
    }
  }
};//end FiFo

int main()
{
  FiFo speicher;
  std::string in;
  while(true)
  {
    //Eingabe
    std::cout<<"Geben sie eine Zahl ein (oder o für ausgabe/q zum beenden):  "<<std::flush;
    std::cin>>in;
    std::cout<<std::endl;
    //Verabeitung
    if(in=="o") //Auslesen
    {
      std::cout<<"\n"<<speicher.pop()<<"\n"<<std::endl;
    }
    else if(in=="q")  //Beenden
    {
      break;
    }
    else    //Einlesen
    {
        int wert;
        wert=std::stoi(in);
        speicher.push(wert);
    }
    //Speicher ausgeben
    for(int n=9;n>=0;--n) //Ausgabe des Arrays
                          //(andersrum damit es wie im Beispiel aussieht)
    {
      std::cout<<speicher.werte[n]<<" "<<std::flush;
    }
    std::cout<<"\n\n"<<std::endl;
  }
}
