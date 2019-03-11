#include<iostream>

int main()
{
  for(int i=0;i<10;i++)
  {
    for(int n=0;n<10;n++)
    {
      if(n==i){break;}
      for(int z=0;z<10;z++)
      {
        if(((i*100)+(i*10)+n)*n==((z*1000)+(n*100)+50+n))
        {
          std::cout<<"x= "<<i<<" y= "<<n<<" z= "<<z<<std::endl;
        }

      }
    }
  }
}
