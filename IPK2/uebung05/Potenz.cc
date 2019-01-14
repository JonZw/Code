#include<iostream>

namespace power      //wut?
{
	int iterativ(int q,int n)
	{
		int f=q;		
		if(n>=0)
		{
			for(int z=0;z<n-1;z++)
			{
				q=q*f;
			}
			if(n==0){q=1;}
			return q;	
		}
		else
		{
			return 0;
		}	
	}
	int recursive(int q, int n)
	{
		if(n>=0)
			{		
				if(n<1)
				{
					return 1;
				}
				else
				{		
					return(q*recursive(q,n-1));
				}
			}
		else
		{
			return 0;
		}
	}
	int unnaive(int q, int n)
	{
		if(n>=0)
			{		
			if (n==1)
			{
				return q;		
			}		
			else
			{
				if(n%2==0)
				{
					return unnaive(unnaive(q,n/2),2);
				}
				else
				{
					return q*unnaive(q,n-1);
				}
			}
		}
		else
		{
			return 0;
		}
	}	
}
int main()
{
	int q; //€Z
	int n; //€Ni0
	
	std::cout<<"Geben sie q ein:"<<std::flush;
	std::cin>>q;
	std::cout<<"Geben sie n ein:"<<std::flush;
	std::cin>>n;
	std::cout<<power::iterativ(q,n)<<std::endl;
	std::cout<<power::recursive(q,n)<<std::endl;
	std::cout<<power::recursive(q,n)<<std::endl;
	
}
