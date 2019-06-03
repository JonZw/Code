#include<iostream>
struct RValue
{
  int value;
  int rbit;
};
int main(int argc, char *argv[])
{
  const int _sr=std::stoi(argv[1]);
  RValue pspeicher[_sr];
  int lanfang=0;
  bool read=false;
  for(int i=0;i<_sr;i++)
  {
    pspeicher[i]={99,0};
  }
  while(true)
  {
    char page;
    std::cin>>page;
    if(page=='q')
    {
      break;
    }

    //Push
    for(int n=0;n<_sr;n++)
    {
      if(pspeicher[n].value==page-48)
      {
        pspeicher[n]={page-48,1};
        read=true;
      }
    }
    if(!read)
    {
      while(pspeicher[lanfang].rbit==1)
      {
        pspeicher[lanfang].rbit=0;
        lanfang=(lanfang+1)%_sr;
      }
      if(pspeicher[lanfang].rbit==0)
      {
        pspeicher[lanfang]={(int)page-48,0};
      }
      lanfang=(lanfang+1)%_sr;
    }
    read=false;
    //out
    std::cout<<"\n\n\n\n\n\n\n"<<"\t#Sp\tRBit\tSeite"<<std::endl;
    for(int x=0;x<_sr;x++)
    {
      std::cout<<"\t"<<x<<"\t"<<pspeicher[x].rbit<<"\t"<<pspeicher[x].value<<std::endl;
    }
    std::cout<<"\n\n\n\n\n\n\n"<<std::endl;
  }
}

//A:
/*felix@Sukri:~/Schreibtisch/Code/Ss19/BeNe/Ü6$ ./A5 3

7
	#Sp	RBit	Seite
	0	0	7
	1	0	99
	2	0	99
0
	#Sp	RBit	Seite
	0	0	7
	1	0	0
	2	0	99
1
	#Sp	RBit	Seite
	0	0	7
	1	0	0
	2	0	1
2
	#Sp	RBit	Seite
	0	0	2
	1	0	0
	2	0	1
0
	#Sp	RBit	Seite
	0	0	2
	1	1	0
	2	0	1
3
	#Sp	RBit	Seite
	0	0	2
	1	0	0
	2	0	3
0
	#Sp	RBit	Seite
	0	0	2
	1	1	0
	2	0	3
4
	#Sp	RBit	Seite
	0	0	4
	1	1	0
	2	0	3
2
	#Sp	RBit	Seite
	0	0	4
	1	0	0
	2	0	2
3
	#Sp	RBit	Seite
	0	0	3
	1	0	0
	2	0	2
0
	#Sp	RBit	Seite
	0	0	3
	1	1	0
	2	0	2
3
	#Sp	RBit	Seite
	0	1	3
	1	1	0
	2	0	2
0
	#Sp	RBit	Seite
	0	1	3
	1	1	0
	2	0	2
3
	#Sp	RBit	Seite
	0	1	3
	1	1	0
	2	0	2
2
	#Sp	RBit	Seite
	0	1	3
	1	1	0
	2	1	2
1
	#Sp	RBit	Seite
	0	0	3
	1	0	1
	2	0	2
2
	#Sp	RBit	Seite
	0	0	3
	1	0	1
	2	1	2
0
	#Sp	RBit	Seite
	0	0	0
	1	0	1
	2	0	2
1
	#Sp	RBit	Seite
	0	0	0
	1	1	1
	2	0	2
7
	#Sp	RBit	Seite
	0	0	0
	1	0	1
	2	0	7
0
	#Sp	RBit	Seite
	0	1	0
	1	0	1
	2	0	7
1
	#Sp	RBit	Seite
	0	1	0
	1	1	1
	2	0	7
q
*/
//B:
/*
felix@Sukri:~/Schreibtisch/Code/Ss19/BeNe/Ü6$ ./A5 3
2
	#Sp	RBit	Seite
	0	0	2
	1	0	99
	2	0	99
3
	#Sp	RBit	Seite
	0	0	2
	1	0	3
	2	0	99
2
	#Sp	RBit	Seite
	0	1	2
	1	0	3
	2	0	99
1
	#Sp	RBit	Seite
	0	1	2
	1	0	3
	2	0	1
5
	#Sp	RBit	Seite
	0	0	2
	1	0	5
	2	0	1
2
	#Sp	RBit	Seite
	0	1	2
	1	0	5
	2	0	1
4
	#Sp	RBit	Seite
	0	1	2
	1	0	5
	2	0	4
5
	#Sp	RBit	Seite
	0	1	2
	1	1	5
	2	0	4
3
	#Sp	RBit	Seite
	0	0	2
	1	0	5
	2	0	3
2
	#Sp	RBit	Seite
	0	1	2
	1	0	5
	2	0	3
5
	#Sp	RBit	Seite
	0	1	2
	1	1	5
	2	0	3
2
	#Sp	RBit	Seite
	0	1	2
	1	1	5
	2	0	3
q
*/
