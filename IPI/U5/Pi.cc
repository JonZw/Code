#include<iostream>
#include"fcpp.hh"

int count(int r,int x, int y, int c)
{
	
	return cond(x==r&&y==-1*r,			//Ich gehe von Links nach rechts, oben nach unten durch
		c,
		cond(x*x+y*y<=r*r,			
			cond(x==r,			//an der rechten Seite angekommen, 
				count(r,-1*r,y-1,c+1),	
				count(r,x+1,y,c+1)),
			cond(x==r,
				count(r,-1*r,y-1,c),
				count(r,x+1,y,c))));
}

int imkreis( int n )
{
	return count(n,-1*n,n,0);	
}

int main()
{
	double n=enter_int("geben sie den Radius an");	//double damit Pi nicht gerundet wird
	int A = (imkreis(n)); 				//Flächeninhalt	
	double Pi = A/(n*n);				//A(Kreis)=Pi*r²
	print(A);		
	print(Pi);
}
