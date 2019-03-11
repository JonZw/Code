#include <ctime>
#include <iostream>
#include"watch.cc"

int main()
{
    /*std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         << now->tm_hour
         <<  now->tm_min
         << now->tm_sec
         << "\n";*/
         Watch Uhr;
         std::cout<<Uhr.getYear()<<std::endl;
         std::cout<<Uhr.getMonth()<<std::endl;
         std::cout<<Uhr.getDay()<<std::endl;
         std::cout<<Uhr.getMin()<<std::endl;
         std::cout<<Uhr.getSec()<<std::endl;
         Uhr.sWatchStart();
         int i;
         std::cin>>i;
         std::cout<<Uhr.sWatchSec()<<std::endl;

}
