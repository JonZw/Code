#include <iostream>
#include <string>
#include <random>
#include <algorithm> 
#include "io.hh"
#include <cmath>
#include"statistics.cc"


int main()
{
	std::vector<double> v={1,2,3,4};	
	std::vector<double> b;
	std::vector<double> n={1,2,3,4,5};

	if(median(v) ==2.5 && median(b)==0 && median(n)==3)
	{
		return 0;
	}	
else{
		return 1;
	}
}
