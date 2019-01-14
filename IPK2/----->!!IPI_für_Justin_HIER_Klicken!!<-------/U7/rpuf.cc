#include"..//fcpp.hh"				//Um unötige Kopien von fcpp.hh zu vermeiden greifen alle Programme auf das gleiche fcpp.hh (im ordner darüber) zu


void output(int puffer[], int in, int out)	//Giebt den Puffer und in (<) und out(>) aus
{

	for(int i=0;i<10;i++)
	{
		std::cout<<puffer[i]<<std::flush;				
		if(in==i||out==i)
 		{					
			if (in==i){std::cout<<"<"<<std::flush;}
			if (out==i){std::cout<<">"<<std::flush;}
		}		
		std::cout<<std::endl;	
	}
}


void ringpuffer()
{
	bool eingeholt=false;								
	bool voll=false;								//Wurde der Puffer schon einmal komplett gefüllt?
	int zahl=0;									//Eingabevariable
	int in=1;
	int out=0;
	int puffer[10]={1,0,0,0,0,0,0,0,0,0};
	
	while(zahl>=0)
	{
		if(puffer[in]!=0||voll)							
		{
			if(!eingeholt||in==out)						//Wird ausgegebe wenn der schreiber auf den ältesten wert zeigt oder auf einen wert der noch nicht ausgegeben wurde
			{			
				print("!Ihre eingabe würde Überschreiben!");
			}
			voll=true;
			
		}		
		zahl=enter_int("geben sie eine Zahl ein: ");
		if(zahl>0)
		{		
			if(in==out&&!eingeholt&&voll)							//Wenn die eingabe den ältesten wert an [i] überschreibt ist derr neue ältester wert [i+1]
			{								
				++out;
				if(out>9){out=0;}
			}
			if(in==out&&eingeholt)
			{
				eingeholt=false;
			}			
 
			
			puffer[in]=zahl;						//Zahl wird eingeschrieben unnd das neue in wird "berechnet"
			++in;
			if(in>9){in=0;}	
			output(puffer,in,out);
		}
		
		
		
		if(zahl==0)
		{
			std::cout<<"Wert: "<<puffer[out]<<std::endl;			//der älteste Wert [out] wird ausgegeben und dann gelöscht, der neue älteste Wert ist [out+1]
			++out;
			if(out>9){out=0;}
			if(out==in+1)
			{
				if(eingeholt||!voll)					
				{
					std::cout<<"Fehler beim Auslesen"<<std::endl;
					break;
				}
				eingeholt=true;	
			}
			output(puffer,in,out);
		}
		
		
		
		
	}

}





int main()
{
	ringpuffer();
}
