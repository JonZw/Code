#include"io.hh"
#include<iostream>
#include"statistics.hh"
#include"io.cc"
#include"statistics.cc"

int main()
{
	int k;
	
	std::vector<double> v=read_vector();

	for(auto m:v)
	{
	std::cout<<m<<std::endl;
	}
	std::cout<<"Durchschnitt :"<<mean(v)<<std::endl;
	std::cout<<"Median :"<<median(v)<<std::endl;
	std::cout<<"Geben sie K ein"<<std::endl;
	std::cin>>k;
	std::cout<<"statistische Moment von "<<k<<": "<<moment(v,k)<<std::endl;
	std::cout<<"Standartabweichung: "<<standard_deviation(v)<<std::endl;
	std::cout<<"Standartabweichung 2: "<<standard_deviation2(v)<<std::endl;
}
