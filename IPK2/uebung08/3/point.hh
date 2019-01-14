#ifndef IO_HH
#define IO_HH

#include<array>
#include<cmath>

template<typename Coord, int dim>
class Point
{
	private:
	Coord _point[dim];
	
	typedef Coord Coordinate;
	
	public:
	
	static const int dimension = dim;
	
	Point()
	{
		for(int i=0; i<dim;++i)
		{
			_point[i]=0;
		}
	}
	
	Point(Coordinate c[dim])
	{
		
		for(int i=0;i<dim;++i)
		{
			
			_point[i]=c[i];
		
		}
	}
	Point(Coordinate c)
	{
		_point[0]=c;
	}
	Coord& x(int i)
	{
		
		return _point[i];
	}
	
	auto norm()
	{
		double Norm;
		
		for(int i=0;i<dim;++i)
		{
			Norm+=pow(x(i),2);
		}
		
		return sqrt(Norm);
	}
	
	Coord& operator[](int i)
	{
		return x(i);
	}
	const Coord& operator[](int i) const
	{
		std::cout<<"const"<<std::endl;
		return x(i);
	}

};

#endif // IO_HH

