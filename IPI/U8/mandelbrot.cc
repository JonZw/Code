#include "../fcpp.hh"
#include<iostream>
#include "save_image.hh"


struct Complex
{
	float real;
	float imag;
};


Complex erzeuge_complex( float re, float im )
{
	Complex t;
	t.real = re; t.imag = im;
	return t;
}

float real( Complex q ) { return q.real; }
float imag( Complex q ) { return q.imag; }

// Summiert zwei komplexe Zahlen p und q und schreibt das Ergebnis in p
void add_complex( Complex& p, Complex q)
{
	p.real=p.real+q.real;
	p.imag=p.imag+q.imag;
}

// Multipliziert zwei komplexe Zahlen p und q und schreibt das Ergebnis in p
void multiply_complex(Complex& p, Complex q)
{
	float preal=p.real;							//Zwischenspeicher;
	float pimag=p.imag;
	float qreal=q.real;
	float qimag=q.imag;
 
	p.real=preal*qreal-pimag*qimag;
	p.imag=preal*qimag+pimag*qreal;
}

// Berechnet einen Schritt der Mandelbrot-Folge fuer die komplexe Zahl
// c, gegeben dem aktuellen Folgenelement z und schreibt das Ergebnis in z
void schritt(Complex& z, Complex c)
{
	 multiply_complex(z,z);			//z²+c:= y=z*z und y+c
	 add_complex(z,c);
}

// Betrag einer komplexen Zahl
float betrag(Complex z) 
{
	
	return std::sqrt(z.real*z.real+z.imag*z.imag);
}

// Betrag des n-ten Elements der Mandelbrot-Folge  zu c
float trajektorie(Complex c, int n )
{	
	Complex z;		//Z(0)=0
 	z.real=0;
  	z.imag=0;
  
  	for(int i=0;i<n;++i)
  	{
  		schritt(z,c);
  	}
  	return betrag(z);
}

//// Teil b)

// Datentyp fuer Bilder der Hoehe H und Breite W
struct Image 
{
  	int H, W;
  	float* pixel;
};

// Erzeugt ein neues Bild der Hoehe H und Breite W
Image create_image(int h, int w) 
{
	Image I;
	I.H=h;
	I.W=w;
  
  	I.pixel=new float[I.H*I.W];
  	
  	return I; 
}

// Wert eines Bildes I in der i-ten Zeile und j-ten Spalte
float get_pixel( Image I, int i, int j) 
{
  	return I.pixel[(j+(i*(I.W)))];  	//der Index von Pixel(i,j) sind alle Spalten bis dahin (i*I.H) plus j
}

// Setzt den Wert von Bild I in der i-ten Zeile und j-ten Spalte auf den
// Wert value
void set_pixel( Image& I, int i, int j, float value) 
{
	I.pixel[(j+(i*(I.W)))]=value;		//s.O.
}

//// Teil c)

// Initialisiert die Werte zweier Bilder x_coords und y_coords, so dass die
// Pixel den x und y Koordinaten eines Gitters (x_min, x_max, y_min, y_max)
// entsprechen. D.h. links oben entspricht (x_min, y_min), rechts oben
// (x_max, y_min), links unten (x_min, y_max) und rechts unten (x_max,
// y_max)
void init_grid(Image& x_coords,Image& y_coords,float x_min, float x_max,float y_min, float y_max) 
{
  	int j=0;
	int i=-1;
	
	for(int n=0;n<x_coords.W*x_coords.H;++n)	//geht alle wert von oben nach unten, links nach rechts durch;
	{
		j=n%(x_coords.W);
		if(j==0){++i;}
		set_pixel(x_coords,j,i,((x_max-x_min)/(x_coords.W-1)*(i%x_coords.W))+x_min);
							//  |Der Abstand|
							//	|	Die einzelteile			|
							//	|       Die Schritte 		   |
							//						Modulo da jede Zeile gleich
							//                         Um x_min verrücken
	}
	j=-1;
	i=0;
	
	for(int n=0;n<y_coords.W*y_coords.H;++n)	//geht alle wert von links nach rechts, oben nach unten durch;
	{
		i=n%(y_coords.W-1);
		if(i==0){++j;}
		set_pixel(y_coords,i,j,((y_max-y_min)/(y_coords.W-1)*(i%y_coords.W))+y_min);
							//s.O.
	}
}

// Reduziert Hoehe und Breite eines Bildes I um einen Faktor 2.
void downsample(Image& I) 
{
	Image Neu= create_image(I.H/2,I.W/2);
	
	int j=0;
	int i=-1;
	
	for(int n=0;n<Neu.W*Neu.H;++n)		//Kopiere I in Neu
	{
		j=n%(Neu.W);
		if(j==0){++i;}
		
		set_pixel(Neu,i,j,get_pixel(I,i,j));
	}
	delete [] I.pixel;					//Lösche I		
	I=Neu;								//Und setze I=Neu
  }

int main()
{
  int H = 256;
  int W = 256;
  int N = 100;
  float xmin = -1.5,	
        xmax =  0.5,	
        ymin = -1.0,
        ymax =  1.0;
        
        Complex z;
        z.real=0;
        z.imag=0;
        Complex w;
        w.real=160;
        w.imag=150;
        schritt(z,w);
       	std::cout<<z<<std::endl;
        throw std::runtime_error("hi");

  //b) Erzeugen und initialisieren Sie x_coords und y_coords
  Image x_coords=create_image(H,W);
  Image y_coords=create_image(H,W);
  init_grid(x_coords,y_coords,xmin,xmax,ymin,ymax);
  //  c) Erzeugen Sie ein Bild bild, welches den Betrag des N-ten
  //         Elements der Mandelbrot Folge visualisiert
  	Image bild=create_image(H,W);
  	
  	int i=-1;
  	int j=0;
  	Complex c;
  	
  	for(int n=0;n<H*W;++n)				//Alle pixel durchgehen
  	{
  		j=n%(bild.W);					//Zeile
		if(j==0){++i;}					//Spalte
		c=erzeuge_complex(get_pixel(x_coords,i,j),get_pixel(y_coords,i,j)); //C erzeugt
		set_pixel(bild,i,j,trajektorie(c,N));		//und eingesetzt
	}

  save_image("bild.png", bild.pixel, bild.W, bild.H);
  // d) Nutzen Sie downsample um das Bild bild herunterzuskalieren
  downsample(bild);
  save_image("bild_klein.png", bild.pixel, bild.W, bild.H);
}
