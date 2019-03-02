 #include <fstream>
#include <string>
#include <iostream>


void addline(std::string Datei)
{
  int n=0;      //counter

  std::string zeile;
  std::string nummer;
  std::string out;    //ausgabe

  std::ifstream input;
  input.open(Datei+".txt");
  if(!input.good())
  {
    throw std::runtime_error("fehler beim Lesen der Datei");
  }
  else
  {
    std::cout<<"Lesen erfolgreich, bitte warten"<<std::endl;
  }

  std::ofstream output(Datei+"-a.txt");


  while(input.good())
  {
    nummer=std::to_string(n)+": ";  //Zeilennummer setzem
    getline(input,zeile);            //Zeile in zeile Schreiben
    out=out+"\n"+nummer+zeile;      //und an out dranhängen

    n++;                            //Counter erhöhen
  }

  output <<out<< std::endl ;        //out in output "setzten"
  output.close();                      //und schließen
  input.close();
}


int main()
{
  std::string Datei;

  std::cout<<"geben die den Dateiname ein (ohne .txt) "<<std::flush;
  std::cin>>Datei;                  //Dateiname einlesen

  addline(Datei);
}
