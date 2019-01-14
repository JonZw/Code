#include"fcpp.hh"
#include<cmath>



double funktion(const double x, const double zahl)		//Giebt f(x) zurück
{
	return pow(x,2)-zahl;
}

bool zuschlecht(double x,double zahl)				//testet ob das ergebnis im Rahmen (~10e-12) liegt
{
	if( funktion(x,zahl)>0-10e-12&&funktion(x,zahl)<0+10e-1)
	{
		return false;
	}
	return true;
}


double Mittelwert(double a, double b)				//Giebt den Mittelwert zurück
{
		return ((a+b)/2);
}

double Nullstelle(double zahl)					//f(x)=x²-zahl
{
	double x=0;
	double a=0;
	double b=4;						//Man Muss für höhere Wurzeln ein höheres b wählen 
	int counter=0;		
	while(zuschlecht(x,zahl))
	{
				
		if(funktion(Mittelwert(a,b),zahl)>=0)		//Ist y=0 zwischen a und m oder m und b?
		{
			b=(Mittelwert(a,b));
			x=b;		
		}
		else
		{
			a=Mittelwert(a,b);
			x=a;
		}
		

	counter++;
	};
	print("#Mittelwerte gebieldet: ");
	print(counter);	
	return x;
}

double wurzel( double a )
{
  return Nullstelle(a);
}



int main()
{
	double zahl=enter_int("geben sie eine Zahl ein ");
	print(wurzel(zahl));
	}
//sqrt(2)=3 Mittelwertbildungen		newton:	6
//sqrt(3)=4 	"	"		   "	6
//sqrt(4)=1	"	"		   "	6
//NewTon ist hier schneller

