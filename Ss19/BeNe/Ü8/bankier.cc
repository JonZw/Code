#include<iostream>
#include<fstream>
#include<exception>
#include<vector>
#include<string>

int main(int argc, char *argv[])
{
  int nP;
  int nR;
  std::vector<int> E;
  std::vector<std::vector<int>> C;
  std::vector<std::vector<int>> R;
  std::vector<int> A;

  //Einlesen
  std::ifstream file;
  file.open(argv[1], std::ios::in);
  if(!file.good())
  {
    throw std::invalid_argument("Falsche Datei");
  }
  std::string input;
  int counter=0;
  std::string e;
  int c=0;
  std::vector<int> v;
  while(std::getline(file, input))
  {
    switch(counter)
    {
      case 0: nP=std::stoi(input);
        break;
      case 1: nR=std::stoi(input);
        break;
      case 2:
              for(auto& i: input)
              {
                if(isdigit(i))
                {
                  e+=i;
                }
                else
                {
                  E.push_back(std::stoi(e));
                  e="";
                }
              }
        break;
      case 3: C.push_back(v);
              for(auto& i: input)
              {
                if(isdigit(i))
                {
                  e+=i;
                }
                else
                {
                  C[c].push_back(std::stoi(e));
                  e="";
                  if(i==',')
                  {
                    C.push_back(v);
                    ++c;
                  }
                }
              }
        break;
      case 4: c=0;
              R.push_back(v);
              for(auto& i: input)
              {
                if(isdigit(i))
                {
                  e+=i;
                }
                else
                {
                  R[c].push_back(std::stoi(e));
                  e="";
                  if(i==',')
                  {
                    R.push_back(v);
                    ++c;
                  }
                }
              }
          break;
    }
    ++counter;
  }
  for(int i=0;i<nR;++i)
  {
    int sS=0;
    for(int n=0;n<nP;++n)
    {
      sS+=C[n][i];
    }
    A.push_back(E[i]-sS);
  }
  //Eingabe Ausgeben

  std::cout<<"Anzahl der Prozesse:\n"<<nP<<std::endl;
  std::cout<<"Anzahl der verschiedenen Resourcen:\n"<<nR<<std::endl;
  std::cout<<"Resourcenvector E:"<<std::endl;
  for(auto& e:E)
  {
    std::cout<<e<<" ";
  }
  std::cout<<std::endl;
  std::cout<<"Belegungsmatrix C:"<<std::endl;
  for(auto& c1:C)
  {
    for(auto& c2:c1)
    {
     std::cout<<c2<<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<"Anforderungsmatrix R:"<<std::endl;
  for(auto& r1:R)
  {
    for(auto& r2:r1)
    {
     std::cout<<r2<<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<"Resourcenrestvector A:"<<std::endl;
  for(auto& a:A)
  {
    std::cout<<a<<" ";
  }
  std::cout<<"\n\n\n\n\n";



  //Bankier Algorithmus
  std::vector<int> nPa;
  for(int a=0;a<nP;++a)
  {
    nPa.push_back(a);
  }
  bool blocked=false;
  int oldsize=nPa.size();
  int newsize;
  while(nPa.size()>0)
  {
    for(auto& p:nPa)
    {
      for(int z=0;z<R[p].size();++z)
      {
        if(R[p][z]>A[z])
        {
          blocked=true;
        }
      }
      if(!blocked)
      {
        std::cout<<"Prozess "<<p<<"\t";
        for(auto& a:R[p])
        {
          std::cout<<a<<" ";
        }
        std::cout<<"\npasst in\t";
        for(auto& a:A)
        {
          std::cout<<a<<" ";
        }
        std::cout<<"\n";
        for(int a=0;a<A.size();++a)
        {
          A[a]+=C[p][a];
        }
        std::cout<<"+ C["<<p<<"]\t\t";
        for(auto& a:C[p])
        {
          std::cout<<a<<" ";
        }
        std::cout<<"\n\nneues A:\t";
        for(auto& a:A)
        {
          std::cout<<a<<" ";
        }
        std::cout<<"\n\n";
        nPa.erase(nPa.begin()+p);
      }
      blocked=false;
    }
    newsize=nPa.size();
    if(oldsize==newsize)
    {
      std::cout<<"Deathlock:\n\n";
      for(auto&v:nPa)
      {
        std::cout<<"Prozess "<<v<<"\tR["<<v<<"]:\t";
        for(auto& a:R[v])
        {
          std::cout<<a<<" ";
        }
        std::cout<<"\n";
      }
      std::cout<<"passen nicht in\tA:\t";
      for(auto& a:A)
      {
        std::cout<<a<<" ";
      }
      std::cout<<"\n\n";
      break;
    }
    oldsize=newsize;
  }
}



/*
Ausgabe datei.txt:

./bankier datei.txt
Anzahl der Prozesse:
3
Anzahl der verschiedenen Resourcen:
4
Resourcenvector E:
4 2 3 1
Belegungsmatrix C:
0 0 1 0
2 0 0 1
0 1 2 0
Anforderungsmatrix R:
2 0 0 1
1 0 1 0
2 1 0 0
Resourcenrestvector A:
2 1 0 0




Prozess 2	2 1 0 0
passt in	2 1 0 0
+ C[2]		0 1 2 0

neues A:	2 2 2 0

Prozess 1	1 0 1 0
passt in	2 2 2 0
+ C[1]		2 0 0 1

neues A:	4 2 2 1

Prozess 0	2 0 0 1
passt in	4 2 2 1
+ C[0]		0 0 1 0

neues A:	4 2 3 1

Ausgabe deathlock.txt

./bankier deathlock.txt
Anzahl der Prozesse:
3
Anzahl der verschiedenen Resourcen:
4
Resourcenvector E:
4 2 3 1
Belegungsmatrix C:
0 0 1 0
2 0 0 1
0 1 2 0
Anforderungsmatrix R:
2 0 3 1
1 0 1 0
2 1 0 0
Resourcenrestvector A:
2 1 0 0




Prozess 2	2 1 0 0
passt in	2 1 0 0
+ C[2]		0 1 2 0

neues A:	2 2 2 0

Prozess 1	1 0 1 0
passt in	2 2 2 0
+ C[1]		2 0 0 1

neues A:	4 2 2 1

Deathlock:

Prozess 0	R[0]:	2 0 3 1
passen nicht in	A:	4 2 2 1

*/
