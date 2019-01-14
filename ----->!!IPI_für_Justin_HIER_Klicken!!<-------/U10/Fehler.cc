#include"../fcpp.hh"
#include <iostream>
#include <cmath>

class FehlerWert
{
private:
  double _w;       //Mittelwert
  double _delta;   //Standartabweichung
public:
  FehlerWert() //Default-Konstruktor
  {
    _w=0;
    _delta=0;
  }
  FehlerWert(double w, double delta)
  {
    _w=w;
    _delta=delta;
  }
  FehlerWert operator+(FehlerWert Summand)
  {
    FehlerWert Summe;
    Summe._w=_w+Summand._w;
    Summe._delta=sqrt(pow(_delta,2)+pow(Summand._delta,2));
    return Summe;
  }
  FehlerWert operator*(FehlerWert Faktor)
  {
    FehlerWert Produkt;
    Produkt._w=_w*Faktor._w;
    Produkt._delta=(sqrt(pow((_delta/_w),2)+pow((Faktor._delta/Faktor._w),2)))*Produkt._w;
    return Produkt;
  }
  double wert()
  {
    return _w;
  }
  double absolut()
  {
    return _delta;
  }
  double relativ()
  {
    return _delta/_w;
  }
};//End FehlerWert

int main () {

  // Konstruktor nimmt zwei double-Werte: den Wert und den absoluten Fehler
  FehlerWert a(12.0, 3.0), b(6.0, 2.0);

  FehlerWert s = a + b;

  std::cout << s.wert() << " +- " << s.absolut() <<
    " (" << s.relativ() * 100 << " %)" << std::endl;

  FehlerWert p = a * b;

  std::cout << p.wert() << " +- " << p.absolut() <<
    " (" << p.relativ() * 100 << " %)" << std::endl;
}
