#include "../fcpp.hh"
#include <string.h> 

typedef int eingabe;					//Abgeschrieben aus den Skript

const int stacksize=4;
eingabe stack[stacksize];
int top=0;


void push(eingabe e)
{
	stack[top] = e ;
	top = top + 1;
}
bool empty ()
{
	return top == 0 ;
}
eingabe pop()
{
	top = top-1;
	return stack[top];
}



void rechne()
{
	
	int operatorr=pop();				//Speichern des Operators zum öfteren vergleichen
	if(top<2)
	{
		throw std::runtime_error("Nicht genügent Zahlen im Stack");		//Beendet das Programm 
	}	
	int speicher;
	
	if(operatorr=='*')
	{
		
		speicher=pop();				//Muss gespeichert werden da nicht alle rechnungen kommutativ sind
		push((pop())*speicher);
	}
	if(operatorr=='/')
	{
		
		speicher=pop();	
		push((pop())/speicher);
	}
	if(operatorr=='+')
	{
		
		speicher=pop();			
		push((pop())+speicher);
	}
	if(operatorr=='-')
	{
		
		speicher=pop();		
		push((pop())-speicher);
	}
	
	
}

int main( int argc, char *argv[] )			//Die Eingabe darf nicht mit " " verwendet werden da diese die Eingabe beendet
{							
							
	char *arg = argv[1];

	
	int zahl=0;
	bool ziffer=false;
	
	
 
  for ( int i=0; i<strlen(arg); i=i+1 )
  {
	char zeichen = arg[i];
	
	if(zeichen<='9'&&zeichen>='0')	
	{
				
		zahl=zahl*10+(zeichen-48);		//Ziffer wird ent-Ascii (-48) und "hinten drangeschrieben"
		ziffer=true;	
	}
	
	else if(zeichen=='+'||zeichen=='/'||zeichen=='-'||zeichen=='*')
	{
				
		push(zeichen);
		rechne();				//Wird ein Rechenzeichen erkannt werden die obersten beiden zahlen mit diesem verrechnet
	}
	else
	{
		if(ziffer)				
		{		
			
			push(zahl);
			zahl=0;
			ziffer=false;
		}
	}
  	

   }
	if(top!=1)
	{
		throw std::runtime_error("Etwas ist schiefgegangen :(");
	}	
	print(pop());
	
return 0;
}
