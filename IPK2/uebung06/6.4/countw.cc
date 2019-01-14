#include <iostream>
#include <map>
#include <cctype>
#include <iterator>
#include <algorithm>
#include <utility>

#include "sanitizeword.hh"

std::string sanitize_word(const std::string& s)
{
  std::string out;
  std::copy_if(begin(s),end(s),back_inserter(out),[](auto c)
               {
                 return std::isalpha(c);
               });
  std::transform(begin(out),end(out),begin(out),[](auto c)
                 {
                   return std::tolower(c);
                 });
  return out;
}



void  print_frequencies(std::map<std::string,int> v)
{
	for (std::pair<const std::string, int>& entry : v)
		{
		std::cout << entry.first << ": "<< entry.second <<" %: "<< static_cast<double>(entry.second)/v.size()<<std::endl;
		}
}

void print_Char(std::map<std::string,int> v)
{
	std::map<char,int> c;
	for(char f='a';f<='z';f++)
	{
		c[f];
	}
	for (std::pair<const std::string, int>& entry : v)
	{
		for(int i=0;i<entry.first.size();i++)
		c[entry.first[i]]=c[entry.first[i]]+1;
	}
	for (auto& entry : c)
	{
		if(std::isalpha(entry.first))
		{	
		std::cout << entry.first << ": "<< entry.second << std::endl;
				
		}		
	}
	
}

std::map<std::string,int> get_frequencies()
{
	std::map<std::string,int> Count;
	
	int wordcount=0;
	

	while (true)
	{
		
		std::string s;
		//read in character
		std::cin>>s;
		//abort if input closed
		if(s=="^")
		{
			break;
		}
		s=sanitize_word(s);
		if(s!="")
		{
			Count[s]=Count[s]+1;
			wordcount++;
		}		
	
	}
	std::cout<<"#Wörter: "<<wordcount<<std::endl;	
	print_Char(Count);
	return Count;
}

int main()
{
	
	print_frequencies(get_frequencies());
	
}




