#include <iostream>
//A1
struct Node
{
int data;
Node* pointer;
};
//A3
class linkedList
{
private:
  Node* root=new Node;
public:
  linkedList(int data)
  {
    root->data=data;
    root->pointer=0;
  }
  ~linkedList()
  {
    Node* schaffner=root;
    Node* papierkorb; //Platzhalter zum Löschen
    while(schaffner->pointer!=0)
    {
      papierkorb=schaffner;
      schaffner=schaffner->pointer;
      delete papierkorb;
      papierkorb=0;
    }
    delete schaffner;
    schaffner=0;
  }
  void add(int data)
  {
    Node* schaffner=root;
    Node* newNode = new Node;
    newNode->data=data;
    newNode->pointer=0;
    while(schaffner->pointer!=0)
    {
      schaffner=schaffner->pointer;
    }

    schaffner->pointer=newNode;
  }
  void erase(int data)
  {
    Node* schaffner=root;
    Node* papierkorb;
    if(root->data==data)//erste soll gelöscht werden
    {
      root->data=root->pointer->data;
      delete root->pointer;
      root->pointer=root->pointer->pointer;
    }
    while(schaffner->pointer!=0)
    {
      if(schaffner->pointer->data==data)//der nächste hat den gesuchten wert
      {
        papierkorb=schaffner->pointer;  //dh. der nächste muss gelöscht werden
        if(schaffner->pointer->pointer!=0)
        {
          schaffner->pointer=schaffner->pointer->pointer; //aber zuerst hängen wir den wert an
        }                                                  //auf den der zu löschende zeigt
        else                                            //Das Letzte element wird gelöscht
        {
          schaffner->pointer=0;
        }
        delete papierkorb;
      }
      if(schaffner->pointer!=0)                        //dh. das letzte element wurde gelöscht
      {
        schaffner=schaffner->pointer;
      }
    }
  }
  void print()
  {
    Node* schaffner=root;
    while(schaffner->pointer!=0)
    {
      std::cout<<schaffner->data<<std::endl;
      schaffner=schaffner->pointer;
    }
    std::cout<<schaffner->data<<std::endl;//der letze hat zwar den Nullptr aber trotzdem
                                          //noch einen gültigen wert
  }
};//end linkedList

//A2
void out(Node* Root)
{
  Node* schaffner=Root;
  while(schaffner->pointer!=0)
  {
    std::cout<<schaffner->data<<std::endl;
    schaffner=schaffner->pointer;
  }
  std::cout<<schaffner->data<<std::endl;
}
void in(Node* Root,int daten)
{
  Node* schaffner=Root;
  Node* newNode = new Node;
  newNode->data=daten;
  newNode->pointer=0;
  while(schaffner->pointer!=0)
  {
    schaffner=schaffner->pointer;
  }
  schaffner->pointer=newNode;
}
void loesche(Node* Root)
{
  Node* schaffner=Root;
  Node* papierkorb;
  while(schaffner->pointer!=0)
  {
    papierkorb=schaffner;
    schaffner=schaffner->pointer;
    delete papierkorb;
    papierkorb=0;
  }
  delete schaffner;
  schaffner=0;
}

int main()
{ //A1
  std::cout<<"A1-test des Node:"<<std::endl;
  Node* n1=new Node;
  n1->data=1;
  n1->pointer=0;
  Node n2({2,n1});
  std::cout<<n2.data<<n2.pointer->data<<std::endl;
  delete n1;

  //A2
  std::cout<<"A2-Methoden für das Node Schreiben:"<<std::endl;
  Node* Root=new Node;
  Root->data=1;
  Root->pointer=0;
  in(Root,2);
  in(Root,3);
  in(Root,4);
  out(Root);
  loesche(Root);
  Root=0;

  //A3
  std::cout<<"A3-linkedList Klasse schreiben: "<<std::endl;
  linkedList list(1);
  list.add(2);
  list.add(3);
  list.add(4);
  list.print();
  std::cout<<"3 soll gelöscht werden: "<<std::endl;
  list.erase(3);
  list.print();
}
