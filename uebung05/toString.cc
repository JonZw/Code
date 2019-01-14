#include<iostream>

int parse_int(std::string number)
{
	int a=0;	
	int m=1;
	int stop=0;
	int vz=1;
	if(number[0]==43 ||number[0]==45)  	//43 =+ 45=-
	{
		stop=1;							//man muss früher aufhören sonst wird +/- mitgerechnet
		if(number[0]==43)
		{
			vz=1;
		}
		else
		{
			vz=-1;
		}
	}
	for(int n=number.size()-1; n>=stop;n--)	
	{
		a=a+(number[n]-48)*m;
		m=m*10;
	}
	return a*vz;
}

int main()
{
	std::string number;
	std::cout<<"geben sie eine nummer ein"<<std::endl;
	std::cin>>number;
	std::cout<<parse_int(number)<<std::endl;
}	
