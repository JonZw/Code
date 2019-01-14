#include "fcpp.hh"
int z=0;
int Bio(int n, int k)
{
	z++;
	return cond(k==0 || k==n,1,cond(k<n && k> 0,Bio(n-1,k-1)+Bio(n-1,k),0));
}

int main()
{
	int n=enter_int("Gebe n ein");
	int k=enter_int("Gebe k ein");
	print(Bio(n,k));
	print(z);
	
}
	//a)	
	//für n=33 und k=14 braucht dieses programm 11,673s
	//für n=34 und k=18 erzeugt dieses Programm eine große negative Zahl.
	//	Das liegt daran, dass die Zahl so groß wurde das sie den Speicherplatz
	//	von int überschritten hat. Zähl man über die größtmögliche Zahl hinaus,
	//	zähl man bei der kleintsmöglichen Zahl weiter. 	
	//b) A(n,k)>=c(1)*B(n,k)       		//B ist die Anzahl der Blätter c(1)=1 da man für jedes Blatt einen Rechenschritt macht.
	//   B(n,k)=B(n-1,k-1)+B(n-1,k) 
	//   B(n,n)=1=(B)(n,o)
