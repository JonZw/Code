#include"fcpp.hh"

void makesortedarray()
{
	bool gefunden=false;
	int array[10]={0,0,0,0,0,0,0,0,0,0};					//Array füllen (Ein "leeres" Array würde zufällige zahlen enthalten)
	int counter=0;	
	int zahl=1;								//=1 Damit die while-schleife startet
	while(zahl>=0 && counter<11)								
	{
		zahl=enter_int("Geben sie eine Zahl ein ");
	
		
		if(zahl!=0)							//Die Null soll nicht mit einsortiert werden
		{


			for(int i=0;i<9;i++)
			{
						
				if(zahl>array[i]&&zahl<=array[i+1])				//rechte zahl größer, linke kleiner
				{				
					gefunden=true;				
					for(int n=0;n<i;n++)						//das array bis zur iten stellen nach links schieben
					{
						array[n]=array[n+1];
					}
					array[i]=zahl;								//und zahl auf das Feld in der mitte setzen
				}
			}
			if(gefunden==false)							//"zahl" ist größer als alle zahlen
			{
				for(int n=0;n<10;n++)						//Alle Zahlen 1 nach links und "zahl" an die größte stelle (9)
				{
				array[n]=array[n+1];
				}
		
				array[9]=zahl;
			}
			counter++;
			gefunden=false;
		}
		else
		{
		for(int i=0;i<10;i++)
			{
				print(array[i]);
			}								//Quasi "break;" aber dürfen wir das schon?
		}
	}
	if(zahl<-1 || zahl>0)
	{
		print("fehlermeldung");
	}
	
}
	//Alles in einer Funktion da ich probleme hatte arrays zu returnen
int main()
{
	makesortedarray();
}

