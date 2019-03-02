#include<iostream>
#include<string>

class Student
{
private:
  std::string _Vorname;
  std::string _Nachname;
  int _Matrikelnummer;
public:
  Student(std::string Vorname,std::string Nachname,int Matrikelnummer):
  _Vorname(Vorname),_Nachname(Nachname),_Matrikelnummer(Matrikelnummer)
  {}
  friend std::ostream& operator<<(std::ostream& os, Student& st)
  {
    os<<st._Nachname<<", "<<st._Vorname<<": "<<st._Matrikelnummer;
    return os;
  }
};

int main()
{
Student s("Max","Mustermann",321542);
std::cout << s << std::endl;
}
