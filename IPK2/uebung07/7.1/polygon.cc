#include<iostream>
#include"point.hh"
#include"point.cc"
#include<vector>

class Polygon
{
	private:
	std::vector<Point> Punkte;  //gegen den Uhrzeigersinn eingegeben
	public:
	Polygon(const std::vector<Point>& corners)
	{
		Punkte=corners;
	}

	Polygon(const std::vector<double>& x,const std::vector<double >& y)
	{
		for(int i=0;i<x.size();i++)		
		{
		Point Ecke(x[i],y[i]);
			
		Punkte[i]=Ecke;
		}	
	}

	std::size_t corners() const
	{
		return Punkte.size();
	}

	const Point& corner(std::size_t i)const
	{
		return Punkte[i];
	}

	double volume() const
	{
		if(Punkte.size()<3)
		{
			return 0;	
		}		
				
		double A=0;		
				
		for(int i=0;i<Punkte.size();i++)
		{
			A=A+(Punkte[i].x()*(Punkte[i+1].y())-Punkte[i+1].x()*Punkte[i].y());
		}	
		return 0.5*A;
	}

}; //End polygon
