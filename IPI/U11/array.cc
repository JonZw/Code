#include<iostream>
#include<vector>

template<typename datenform> class Vector
{
private:
  int _menge=0;
  std::vector<datenform> _array;
public:
  Vector(int menge)  //Default-Konstruktor
  {

    _array.resize(menge);
    _menge=menge;
  }
  Vector(const Vector<datenform>& other)  //Copy-Konstruktor
  {
    _array[other._menge];
    _menge=other._menge;
    for(int i=0;i<_menge;i++)
    {
      _array[i]=other._array[i];
    }
  }
  ~Vector()        //Destrukor
  {
    //Nothing to do here
  }
  datenform& operator[](int position) //[]
  {
    return _array[position];
  }
  Vector operator+(Vector& other)    //+
  {
    if(_menge!=other._menge)
    {
      throw std::runtime_error("Vektor nicht gleichlang");
    }
    Vector<datenform> out(_menge);

    for(int i=0;i<_menge;i++)
    {
      out[i]=_array[i]+other._array[i];
    }
    return out;
  }
  Vector operator*(datenform skalar)
  {
      Vector<datenform> out(_menge);
      for(int i=0;i<_menge;i++)
      {
        out[i]=_array[i]*skalar;
      }
      return out;
  }
  datenform getMax()
  {
    if(_menge==0)
    {
      return 0;
    }
    datenform max=_array[0];
    for(int i=0;i<_menge;i++)
    {
      if(_array[i]>max)
      {
        max=_array[i];
      }
    }
    return max;
  }
};//End arary
