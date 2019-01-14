#include<iostream>
#include<string>
#include<tuple>



std::pair<int,int> parse_int(std::string number)
{
	char a;
	int last=0;
	int zahl=0;
	float m=1;
	int stop=0;
	int vz=1;
	
	
	for(int n=0; n<number.size();n++)	
	{
		a=number[n];
		switch(a)
		{
			case ' ':;
				break;
			case'-':vz=-1;
				break;
			case '0':;
			case '1':;
			case '2':;
			case '3':;
			case '4':;
			case '5':;
			case '6':;
			case '7':;
			case '8':;
			case '9':
				zahl=zahl*10+(a-48);			
	
			break;
			
			default:break;
		}
		if(m>0.1&&a<'9'&&a>0){}
		else{
		last=number[n];		
		break;}
	}
	return std::make_pair(zahl*vz,last);
	
}

int main()
{
	std::string number;
	std::cout<<"geben sie eine nummer ein"<<std::endl;
	std::getline(std::cin,number);
	std::pair<int,int> out = parse_int(number);
	std::cout<<out.first<<" fehler bei: "<<out.second<<std::endl;
}	
