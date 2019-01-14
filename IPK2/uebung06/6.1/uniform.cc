#include"io.hh"
#include<iostream>
#include"statistics.hh"
#include"statistics.cc"
#include"io.cc"

int main()
{
	int k;	
	int N;
	double min;
	double max;
	std::cout<<"Gebem sie N ein"<<std::endl;
	std::cin>>N;
	std::cout<<"Geben sie min ein"<<std::endl;
	std::cin>>min;
	std::cout<<"Geben sie max ein"<<std::endl;
	std::cin>>max;
	std::vector<double> v =uniform_distribution(random_seed(),N,min,max);
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

