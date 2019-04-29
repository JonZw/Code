#include <iostream>

class TwoDBoolArray
{
public:
  // Initialisiere ein n x m Array
  TwoDBoolArray( int n = 0, int m = 0 );
  // Copy-Konstruktor
  TwoDBoolArray( const TwoDBoolArray& other );
  // Destruktor
  ~TwoDBoolArray();
  // Zuweisungsoperator
  TwoDBoolArray& operator=( const TwoDBoolArray& other );
  // Gebe Zeilenzahl zurueck
  int rows();
  // Gebe Spaltenzahl zurueck
  int cols();
  
  // ein Objekt das vom operator[] zurueckgegeben wird
  class RowProxy
  {
  public:
    // Konstruktor
    RowProxy( bool* daten, int zeilenindex, int spaltenzahl );
    // der "innere" Klammerzugriffsoperator
    bool& operator[]( int j );
  private:
    bool* _daten;
    int zeilenindex;
    int spaltenzahl;
  };
  // der "aeussere" Klammerzugriffsoperator
  RowProxy operator[]( int i );
private:
  bool* daten;
  int m, n;
};

