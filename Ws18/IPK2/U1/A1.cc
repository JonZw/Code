#include<iostream>

int main()
{

  std::string Name,Beruf,Alter,Nettoeinkommen;
  std::cout<<"Name eingeben: "<<std::flush;
  std::cin>>Name;
  std::cout<<"Beruf eingeben: "<<std::flush;
  std::cin>>Beruf;
  std::cout<<"Alter eingeben: "<<std::flush;
  std::cin>>Alter;
  std::cout<<"Nettoeinkommen eingeben: "<<std::flush;
  std::cin>>Nettoeinkommen;
  std::cout<<"Name:\t"<<Name<<"\nBeruf:\t"<<Beruf<<"\nAlter:\t"<<Alter<<"\nNettoeinkommen:\t"<<Nettoeinkommen<<std::endl;
}
