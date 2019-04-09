
#include<iostream>

int main()
{
  std::string input;
  char op=0;        //Operator
  int Zahl1=0;
  int Zahl2=0;
  std::cout<<"Rechnung eingeben: "<<std::endl;
  std::cin>>input;
  for(int n=0;n<input.size();++n) //String durchgehen
  {
    if(input[n]=='+'||input[n]=='-'||input[n]=='*'||input[n]=='/')
    {
      op=input[n];
    }
    else
    {
      if(op==0)     //dh. bis jetzt kein Operator gelesen
      {
        Zahl1=Zahl1*10+input[n]-48;
      }
      else          //dh. es wurde ein Operator gelesen
      {
        Zahl2=Zahl2*10+input[n]-48;
      }
    }
  }
  switch(op)
  {
    case '+': std::cout<<Zahl1+Zahl2<<std::endl;break;
    case '-': std::cout<<Zahl1-Zahl2<<std::endl;break;
    case '*': std::cout<<Zahl1*Zahl2<<std::endl;break;
    case '/': if(Zahl2==0)
              std::cout<<"Man kann nicht durch 0 teilen!"<<std::endl;
              else
              std::cout<<Zahl1/Zahl2<<std::endl;break;
  }
}
//25min ohne kommentare
