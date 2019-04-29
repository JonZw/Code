#include <iostream>
#include <map>

void print_frequencies(const std::map<char,int>& frequencies)
{
		 
	int count=0;
	for (auto& entry : frequencies)
	{
		if(std::isalpha(entry.first))
		{	
		std::cout << entry.first << ": "<< entry.second << std::endl;
		count=count+entry.second;		
		}		
	}
	std::cout<<"Buchstaben insgesamt: "<<count<< std::endl;
	for (auto& entry : frequencies)
	{
		if(std::isalpha(entry.first))
		{	
		std::cout << entry.first << ": "<< static_cast<double>(entry.second)/count << std::endl;
				
		}		
	}
}

std::map<char,int> get_frequencies()
{
	std::map<char,int> Count;
	
	
	for(char f='a';f<='z';f++)
	{
		Count[f];
	}

	while (true)
	{
		
		unsigned char c;
		//read in character
		std::cin>>c;
		//abort if input closed
		if(c=='^')
		{
			break;
		}
		if(c>='A'&&c<='Z'){c=c+32;}		
		Count[c]=Count[c]+1;
		
	
	}
	return Count;
}

int main()
{
	
	print_frequencies(get_frequencies());
	
}




