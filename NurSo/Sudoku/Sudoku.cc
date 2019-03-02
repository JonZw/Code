#include<vector>
#include<experimental/random>
#include<iostream>
#include <ctime>
#include <iostream>

class Watch
{
private:
  int year;
  int month;
  int day;
  int hour;
  int min;
  int sec;
  int syear;
  int smonth;
  int sday;
  int shour;
  int smin;
  int ssec;
  int eyear;
  int emonth;
  int eday;
  int ehour;
  int emin;
  int esec;
public:
  int getYear()
  {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    year=now->tm_year + 1900;
    return year;
  }
  int getMonth()
  {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    month=now->tm_mon + 1;
    return month;
  }
  int getDay()
  {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    day=now->tm_mday;
    return day;
  }
  int getHour()
  {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    hour=now->tm_hour;
    return hour;
  }
  int getMin()
  {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    min=now->tm_min;
    return min;
  }
  int getSec()
  {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    sec=now->tm_sec;
    return sec;
  }
  void sWatchStart()
  {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    syear=now->tm_year + 1900;
    smonth=now->tm_mon + 1;
    sday=now->tm_mday;
    shour=now->tm_hour;
    smin=now->tm_min;
    ssec=now->tm_sec;
  }
  int sWatchSec()
  {
    int time=0;
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int cyear=syear;
    int cmonth=smonth;
    int cday=sday;
    int chour=shour;
    int cmin=smin;
    int csec=ssec;
    eyear=now->tm_year + 1900;
    emonth=now->tm_mon + 1;
    eday=now->tm_mday;
    ehour=now->tm_hour;
    emin=now->tm_min;
    esec=now->tm_sec;
    while(csec!=esec)
    {
      csec++;
      time++;
    }
    while(cmin!=emin)
    {
      cmin++;
      time=time+60;
    }
    while(chour!=ehour)
    {
      chour++;
      time=time+3600;
    }
    while(cday!=eday)
    {
      cday++;
      time=time+86400;
    }
    return time;
  }
};//End Watch








class Soduko
{
private:
  std::vector<char> _trueField;
  std::vector<char> _playerField;
  int pointer=0;
  std::vector<char> _startField;
  std::string info;
  bool _Fehler;
  bool _high;
  bool _cheat;
  int tips=0;
  Watch Uhr;
public:
  Soduko(int Schwierigkeit,bool Fehler,bool high,bool cheat)
  {
    _trueField=createField();
    _playerField=_trueField;
    for(int n=0;n<Schwierigkeit;n++)
    {
      _playerField[std::experimental::randint(0,80)]=' ';
    }
    _startField=_playerField;
    _Fehler=Fehler;
    _high=high;
    _cheat=cheat;
    Uhr.sWatchStart();
  }
  std::vector<char> createField()
  {
      std::vector<char> Feld(9*9);
      for(int i=0;i<9*9;i++)
      {
        Feld[i]=' ';
      }
      bool voll=false;
      int Pos=0;
      int reihe=0;
      int kasten=0;
      int counter=0; // zählt ob man neu starten muss
      int kastencounter=1;  //zählt ob zahl ein kasten ist
      while(Pos<81)
      {
        bool allein=true;
        int Num=std::experimental::randint(1,9)+48;
        versuch:
        int kc=-1; //kastencounter
        for(int n=0;n<9;n++)    //Prüfe Vertikal
        {
          if(Feld[((Pos+(n*9))%81)]==Num)
          {
            allein=false;
            break;
          }
          if(Feld[reihe+n]==Num)  //Prüfe Horizontal
          {
            allein=false;
            break;
          }
          if(n%3==0){++kc;}
          if(Feld[kasten+n+(kc*6)]==Num)   //Prüfe Kasten
          {
            allein=false;
            break;
          }
        }
        if(allein)
        {
          Feld[Pos]=Num;
          ++Pos;
          if(kastencounter==9)
          {
            kastencounter=0;
          }
          counter=0;
          if(Pos%9==0)//reihenzähler
          {
            reihe=Pos;
          }
          if(Pos%3==0)//Kastenzähler
          {
            if(kastencounter<3)
            {
            kasten=Pos;
            }
            else if(kastencounter<3&kastencounter>7)
            {
              kasten=Pos-9;
            }
            else
            {
              kasten=Pos-18;
            }
            kastencounter++;
          }
        }
          else
          {
            counter++;
            Num=(((Num-48)+1)%10)+48;
            if(Num==48){++Num;}
            if(counter==9)
            {
              //std::cout<<"neustart"<<std::endl; //Reset
              for(int i=0;i<9*9;i++)
              {
                Feld[i]=' ';
              }
              counter=0;
              kastencounter=1;
              kasten=0;
              Pos=0;
              continue;
            }
            allein=true;
            goto versuch;
          }
      }
      return Feld;
  }
  void out()
  {
    unsigned counterKastenVer=0;
    unsigned counterLine=0;
    unsigned counterKastenHor=0;
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t";
    for(int i=0;i<81;i++) //? entfernen
    {
      if(_playerField[i]=='?')
      {
        _playerField[i]=' ';
      }
    }

    for(int i=0;i<9*9;i++)  //Feld Ausgeben
    {
      if(pointer==i)  //Pointer anzeigen
      {
        if(_playerField[i]==' '){_playerField[i]='?';}
        std::cout<<"\033[1;31m"<<_playerField[i]<<"\033[0m"<<" "<<std::flush;
      }
      else if(_playerField[i]==_playerField[pointer]&&_high) //Gleiche Zahlen Anzeigen
      {
        std::cout<<"\033[1;33m"<<_playerField[i]<<"\033[0m"<<" "<<std::flush;
      }
      else if(_playerField[i]!=_startField[i])  //Hinzugefüget Zahlen anzeigen
      {
        std::cout<<"\033[1;36m"<<_playerField[i]<<"\033[0m"<<" "<<std::flush;
      }
      else          //Normale Zahlen anzeigen
      {
      std::cout<<_playerField[i]<<" "<<std::flush;
      }
      ++counterKastenVer;
      ++counterLine;
      if(counterKastenVer==3)
      {
        std::cout<<"|"<<std::flush;
        counterKastenVer=0;
      }
      if(counterLine==9)
      {
        std::cout<<"\n\t"; //std::cout<<std::endl;
        counterLine=0;
        ++counterKastenHor;
      }
      if(counterKastenHor==3)
      {
        std::cout<<"___________________\n\t"; //std::cout<<"___________________"<<std::endl;
        counterKastenHor=0;
      }
    }
    std::cout<<"\n\n\t"<<info<<"\n\tZeit: "<<Uhr.sWatchSec()<<"sec"<<std::endl;
    if(_cheat){std::cout<<"\tTipps: "<<tips<<"\n"<<std::endl;}else{std::cout<<"\n\n"<<std::endl;}
  }
  void Eingabe(int Zahl)
  {
    if(_playerField[pointer]=='?')
    {
      if(_Fehler)
      {
        if(_trueField[pointer]==Zahl+48)
        {
          _playerField[pointer]=Zahl+48;
          info="Richtig!   ";
        }
        else
        {
          info="Falsch!   ";
        }
      }
      else
      {
        _playerField[pointer]=Zahl+48;
      }
    }
  }
  void cheat()
  {
    if(_cheat)
    {
      _playerField[pointer]=_trueField[pointer];
      tips++;
    }
    else
    {
      info="Tipps sind deaktiviert";
    }
  }
  bool end()
  {
  if(_playerField==_trueField)
  {
    return true;
  }
  return false;
  }
  void moveUp()
  {
    if(pointer<10){pointer=pointer+81;}
    pointer=(pointer-9)%81;
    info="";
  }
  void moveDown()
  {
    pointer=(pointer+9)%81;
    info="";
  }
  void moveRight()
  {
    if((pointer+1)%9==0)
    {
      pointer=pointer-8;
    }
    else
    {
      pointer=(pointer+1)%81;
    }
    info="";
  }
  void moveLeft()
  {
    if(pointer%9==0)
    {
      pointer=pointer+8;
    }
    else
    {
      pointer=pointer-1;
      if(pointer==-1)
        pointer=80;
    }
    info="";
  }
  void Del()
  {
    if(_startField[pointer]!=_playerField[pointer])
    {
      _playerField[pointer]=' ';
      info="Feld Gelöscht";
    }
    else
    {
      info="Feld kann nicht gelöscht werden";
    }
  }
};//End Soduko
