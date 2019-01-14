#include<iostream>
#include<cmath>
#include"canvas.hh"
#include"point.hh"
#include"point.cc"

class IterationResult
{
  Point c;
  int iterationen;

  public:

IterationResult()
{
  Point Ursprung(0,0);
  c=Ursprung;
  iterationen=0;
}

IterationResult(Point z)
{
  c=z;

}
void change(Point z)
{
  c=z;
  iterationen++;
}
double x()
{
  return c.x();
}
double y()
{
  return c.y();
}
Point z()   //Point c(){} machte probleme
{
  return c;
}
int it()
{
  return iterationen;
}
};//IterationResult End

IterationResult iterate (Point z, Point c, double threshold, int maxIt)
{

    IterationResult R;
    int n=0;
    while(n<=maxIt&&sqrt(pow(R.x(),2)+pow(R.y(),2))<threshold)
    {
      Point z=R.z();
      double x=pow(z.x(),2)-pow(z.y(),2)+c.x();
      double y=2*(z.x()*z.y())+c.y();
   
      Point z2(x,y);
      R.change(z2);
      
      ++n;
    }

    return R;
}

void mandelbrot (Canvas& canvas, double threshold, int maxIt, std::string filename)
{
  Point z(0,0);

  for(int n=0;canvas.horPixels()>n;n++)
  {
    for(int i=0;canvas.vertPixels()-1>i;i++)
    {
      
      IterationResult R=iterate(z,canvas.coord(n,i),threshold,maxIt);
      if(R.it()>=maxIt)
      {
        canvas(n,i)=0;
      }
      else
      {
        canvas(n,i)=std::log(R.it())*100.0;
      }
    }
  }
}

int main()
{
 
  Point zenter(-1,0);
  
  Canvas canvas(zenter,4,3,400,300);
 
  mandelbrot(canvas,1000,1000,"HI");

  canvas.write("mandelbrot.pgm");
}
