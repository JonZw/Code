#include <iostream>
#include <string>
#include <random>
#include <algorithm> 
#include "io.hh"
#include <cmath>

double mean(const std::vector<double>& v)
{
	if(v.size()==0)
	{
		return 0;
	}	
	
	double u=0;

	for(auto m:v)
	{
	 	u=u+m;
	}
	return u/v.size();
}

double median(const std::vector<double>& v)
{
	if(v.size()==0)
	{
		return 0;
	}	
		
	std::vector<double> s=v;
	std::sort(s.begin(),s.end());
	
	if(s.size()%2==0)
	{
		return 0.5*(s[s.size()/2-1]+s[s.size()/2]);
	}
	else
	{
		return s[((s.size()+1)/2)-1];
	}
}
double moment(const std::vector<double>& v,int k)
{
	double m=0;	
	for (auto b:v)
	{
		m=m+pow(b,k);
	}	
	return m/v.size();
}
double moment2(const std::vector<double>& v,int mu)
{
	double m=0;	
	for (auto b:v)
	{
		m=m+pow(b-mu,2);
	}	
	return m/v.size();
}
double standard_deviation(const std::vector<double>& v)
{
	double mu=mean(v);
			
	return pow(moment(v,mu),0.5);
}
double standard_deviation2(const std::vector<double>& v)
{
	return (moment(v,2)-(pow(mean(v),2)));
}








































