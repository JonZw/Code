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
