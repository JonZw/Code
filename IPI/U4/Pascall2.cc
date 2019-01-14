#include "fcpp.hh"
int Fak( int n ) // Aus Moodle
{
  return cond( n<=1, 1, n*Fak(n-1) );
}


int Bio(int n, int k)
{
	return (Fak(n)/Fak(k)-Fak(n-k));
}

int main()
{
	int n=enter_int("Gebe n ein");
	int k=enter_int("Gebe k ein");
	print(Bio(n,k));
}

//c)	A(n,k)>=c(1)+B(n,k)			//B ist die Anzahl der Blätter c(1)=3 da 3 operationen durchgeführt werden pro Blatt 
//	B(n,k)=B(Fak(n)/B(Fak(k)-B(Fak(n-1))))
//	B(Fak(x))=x*(Fak(x-1))
//	B(Fak(1))=1


//	Für n=33 und k=14 braucht das Programm 0,005 sekunden, deutlich weniger als das rekursive Programm
//	Auch für höher Werte braucht das Programm nie länger als eine Sekunde, die Werte werden aber auch negativ(Siehe Pascall.cc)


//d) Algorithmus: Eingabe x= anzahl der Spalten die Ausgegeben werden sollen
//			k,n=0
//			
//			wiederhole solange x>=n+1 (da zeile 1 n=0) 
//			{
//				wiederhole solange bis k==n
//				{
//					 Bio(n,k)-> k++
//				} 
//				dann k=0 und n=n++
//			}
//		     					   (x)
//	Dieser Algorithmus hat einen Rechenaufwand von A(x)=E(k) *A(n,k)
//							   (k=1)
