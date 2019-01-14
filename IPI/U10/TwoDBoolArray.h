#include"../fcpp.hh"
#include <iostream>
#include<string>

class TwoDBoolArray
{
public:
  // Initialisiere ein n x m Array
  TwoDBoolArray( int n = 0, int m = 0 )
  {
    _n=n;
    _m=m;
    daten = new bool[n*m];
    for(int i=0;i<n*m;i++)  //Alles auf 0
    {
      daten[i]=false;
    }
  }
  // Copy-Konstruktor
  TwoDBoolArray( const TwoDBoolArray& other )
  {
    _n=other._n;
    _m=other._m;
    daten = new bool[_n*_m];
    for(int i=0;i<_n*_m;i++)
    {
      daten[i]=other.daten[i];
    }
  }
  // Destruktor
  ~TwoDBoolArray()
  {
  delete daten;
  }
  // Zuweisungsoperator
  TwoDBoolArray& operator=( const TwoDBoolArray& other )
  {
    delete daten;
    _n=other._n;
    _m=other._m;
    daten = new bool[_n*_m];
    for(int i=0;i<_n*_m;i++)
    {
      daten[i]=other.daten[i];
    }
  }
  // Gebe Zeilenzahl zurueck
  int& rows()
  {
    return _n;
  }
  // Gebe Spaltenzahl zurueck
  int& cols()
  {
    return _m;
  }


        // ein Objekt das vom operator[] zurueckgegeben wird
        class RowProxy
        {
        public:
          // Konstruktor
          RowProxy( bool* daten, int zeilenindex, int spaltenzahl )
          {
            _daten=&daten[zeilenindex*spaltenzahl]; //=anfang der Spalte
            _zeilenindex=zeilenindex;
            _spaltenzahl=spaltenzahl;
          }
          ~RowProxy()
          {
            //nothing to do here
          }
          // der "innere" Klammerzugriffsoperator
          bool& operator[]( int j )
          {
            return _daten[j];
          }
        private:
          bool* _daten;
          int _zeilenindex;
          int _spaltenzahl;
        };//End RowProxy

  // der "aeussere" Klammerzugriffsoperator
  RowProxy operator[]( int i )
  {
    RowProxy out(daten,i,_m);
    return out;
  }
private:
  bool* daten;
  int _m, _n;
};//End TwoDBoolArray

std::ostream& operator<<(std::ostream& stream,TwoDBoolArray& array)
{
  for (int i = 0; i < array.rows(); i++)    //Zeilen durchgehen
  {
    for (int j = 0; j < array.cols(); j++)  //spalten durchgehen
    {
      stream << array[i][j] << " ";        //wert einfügen
    }
    stream<<"\n";                         //zeilenumbruch
  }

  return stream;
}
std::istream& operator>>(std::istream& stream , TwoDBoolArray& array)
{
  std::string n;            //input zeilen
  std::string m;            //input spalten
  int zeile=0;              //zeilencouner
  int spalte=-1;            //spaltencounter (-1 da in der Schleife zuerst inkrementiert wird)
  getline(stream,n);
  getline(stream,m);
  array.rows()=std::stoi(n);   //stoi=string to int
  array.cols()=std::stoi(m);

  for(int i=0;i<(std::stoi(n)*std::stoi(m));i++)
  {
    if(zeile<stoi(n))
    {
      spalte++;
    }
    else
    {
      spalte=0;
      zeile++;
    }
    int in;
    std::cin>>in;
    if(in<0||in>1){throw std::runtime_error("nur true(1) oder false(0) akzeptiert");}
    array[zeile][spalte]=in;  //einschreiben
  }

  return stream ;
}
