#ifndef STATISTICS_HH
#define STATISTICS_HH

#include <iostream>
#include <string>
#include <random>
#include <algorithm> 
#include<vector>

template<typename v>
double mean(const v& v1)
{
	double u=0;

		for(auto m:v1)
		{
	 		u=u+m;
		}
		return u/v1.size();
}
template<typename v>
double median(const v& v1)
{
	if(v1.size()==0)
	{
		return 0;
	}	
	std::vector<typename v::value_type> s;
	for(auto m:v1)
	{
		s.push_back(m);
	}
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

template<typename v,typename k>
double moment(const v& v1, const k& k1)
{
	double m=0;	
	for (auto b:v1)
	{
		m=m+pow(b,k1);
	}	
	return m/v1.size();
}



template<typename v1, typename mu1>
double moment2(const v1& v, mu1& mu)
{
	double m=0;	
	for (auto b:v)
	{
		m=m+pow(b-mu,2);
	}	
	return m/v.size();
}

template<typename v1>

double standard_deviation(const v1& v)
{
	double mu=mean(v);
			
	return pow(moment(v,mu),0.5);
}

template<typename v1>
double standard_deviation2(const v1& v)
{
	return (moment(v,2)-(pow(mean(v),2)));
}





#endif // STATISTICS_HH
