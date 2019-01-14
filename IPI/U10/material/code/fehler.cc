#include <iostream>
#include <cmath>


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

