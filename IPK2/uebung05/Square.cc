#include<iostream>


double potenz(double q, int n)	
{
			
		if(n>=0)
		{		
			if(n<1)
			{
				return 1;
			}
			else
			{		
				return(q*potenz(q,n-1));
			}
		}
	else
	{
		return 0;
	}
}


double root_iterative(double q,int n,int steps)
{
	if (n<=0 || q<=0)
	{
		return 0;
	}
	double a =1.0;
	for(int z=0;z!=steps;z++)
		{
		a=a+((q/potenz(a,n-1))-a)/n;
		
		}
	return a;
}

void test_root(double q, int n, int steps)
{
	double a;	
	a =root_iterative(q,n,steps);
	std::cout<<q<<" "<<n<<" "<<a<<" "<<potenz(a,n)<<" "<<q-potenz(a,n)<<std::endl;
}

int main()
{
	double q;
	int n; //€Ni0
	int steps;
	
	std::cout<<"Geben sie q ein:"<<std::flush;
	std::cin>>q;
	std::cout<<"Geben sie n ein:"<<std::flush;
	std::cin>>n;
	std::cout<<"Geben sie #Schritte ein:"<<std::flush;
	std::cin>>steps;
	test_root(q,n,steps);
}
