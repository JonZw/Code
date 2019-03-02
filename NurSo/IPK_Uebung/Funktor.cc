#include<iostream>
#include<vector>
#include<algorithm>

class Baum
{
public:
  std::string Name;
  int Aeste;
  int hoehe;

  friend std::ostream& operator<<(std::ostream& os, Baum& B)
  {
    os<<B.Name<<": "<<"#Äste: "<<B.Aeste<<" Höhe: "<<B.hoehe;
    return os;
  }
  Baum operator+=(Baum other)
  {

  }
};//Baum end

struct sorthight
{
  bool operator()(const Baum& b1,const Baum& b2)const
  {
    return b1.hoehe>b2.hoehe;
  }
};

int main()
{
  std::vector<Baum> Baeume={{"James",32,22},{"Jeremy",33,243},{"Kastanie",12,23}};
  for(auto& i : Baeume)
  {
    std::cout<<i<<std::endl;
  }
  std::cout<<"höehe"<<std::endl;
  std::sort(Baeume.begin(),Baeume.end(),sorthight());
  for(auto& i : Baeume)
  {
    std::cout<<i<<std::endl;
  }
  std::sort(Baeume.begin(),Baeume.end(),[](Baum& a,Baum&b){return a.Name>b.Name;});
    std::cout<<"Alphabetisch"<<std::endl;
  for(auto& i : Baeume)
  {
    std::cout<<i<<std::endl;
  }
  std::sort(Baeume.begin(),Baeume.end(),[](Baum& a, Baum& b){return a.Aeste>b.Aeste;});
  std::cout<<"#Aeste"<<std::endl;
for(auto& i : Baeume)
{
  std::cout<<i<<std::endl;
}
}
