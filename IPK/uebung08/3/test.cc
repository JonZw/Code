#include<iostream>
#include"point.hh"
#include<array>

int main()
{
	int menge[3]={1,2,3};
	double menge2[1]={7};
	std::cout<<"Menge: "<<menge[0]<<menge[1]<<menge[2]<<std::endl;
	
	Point<double,1> oned(7);
	Point<float,2> empty;
	Point<int,3> 	three(menge);
	
	std::cout<<"oned (1D):"<<std::endl;
	std::cout<<oned.x(0)<<std::endl;
	
	std::cout<<"empty (2D):"<<std::endl;
	std::cout<<empty.x(0)<<std::endl;
	std::cout<<empty.x(1)<<std::endl;
	
	std::cout<<"three (3D):"<<std::endl;
	std::cout<<three.x(0)<<std::endl; 
	std::cout<<three.x(1)<<std::endl;
	std::cout<<three.x(2)<<std::endl;
	
	std::cout<<"Norm von oned: "<<oned.norm()<<std::endl;
	std::cout<<"Norm von empty: "<<empty.norm()<<std::endl;
	std::cout<<"Norm von three: "<<three.norm()<<std::endl;
	
	std::cout<<"oned (1D):"<<std::endl;
	std::cout<<oned[0]<<std::endl;
	
	std::cout<<"empty (2D):"<<std::endl;
	std::cout<<empty[0]<<std::endl;
	std::cout<<empty[1]<<std::endl;
	
	three[1]=5;
	
	std::cout<<"three (3D):"<<std::endl;
	std::cout<<three[0]<<std::endl; 
	std::cout<<three[1]<<std::endl;
	std::cout<<three[2]<<std::endl;
}
