#include "fcpp.hh"
#include <string.h> // fuer strlen, Laenge eines C-Strings

// Definieren Sie hier Ihren Stack und legen Sie eine Instanz als globale
// Variable an

// Funktion, die auf dem Stack eine Rechenoperation durchfuehrt
// Rueckgabewert: ob die Berechnung durchgefuehrt werden konnte
bool rechne( char operation )
{
  // Pruefen Sie zunaechst, ob genuegend Zahlen auf dem Stack liegen, und
  // achten Sie bei der Berechnung auf die Reihenfolge der Zahlen
}

int main( int argc, char *argv[] )
{
  // arg enthaelt die als Eingabe uebergebene Zeichenfolge
  char *arg = argv[1];

  // Schleife, die die Zeichen der Eingabe nacheinander ablaeuft
  for ( int i=0; i<=strlen(arg); i=i+1 )
  {
    char zeichen = arg[i]; // aktuelles Zeichen
    // Beachten Sie: der Inhalt der Variable zeichen ist der ASCII-Code
    // des entsprechenden Zeichens. Dieser stimmt im Falle der Zeichen '0'..'9'
    // nicht mit der entsprechenden Ziffer Ueberein.

    // Fuegen Sie hier Code ein, der das Zeichen verarbeitet, also Ziffern
    // zu Zahlen zusammenfuegt, Operatoren anwendet und andere Zeichen
    // ignoriert
  }

  // Hier muessen Sie evtl. den Sonderfall behandeln, dass die Formel keine
  // Operatoren enthaelt

  // Pruefen Sie, ob der Stack genau eine Zahl (das Ergebnis) enthaelt, und
  // geben Sie sie gegebenenfalls aus

  return 0;
}
