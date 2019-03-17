#include"DObjects.cc"
#include<vector>
#include<iostream>
#include<algorithm>

class System
{
private:
 Object* Galaxy[25];
 const std::string resCol="\033[0m";
 const std::string green="\033[1;32m";
 const std::string blue="\033[0;36m";
 const std::string red="\033[0;31m";
 const std::string magenta="\033[0;35m";
 std::string pointCol="";
 std::string info="";
 int Zeiger=12;
public:
  System()
  {
    for(int n=0;n<25;n++)
    {
      Planet* planet= new Planet(0);
      Galaxy[n]=planet;
    }
  }
  ~System()
  {
    for(int n=0;n<25;n++)
    {
      delete Galaxy[n];
    }
  }
  Object* create(int who, int team=0)
  {
    if(who==1)
    {
      Planet* planet=new Planet(team);
      return planet;
    }
    if(who==2)
    {
      Ship* ship=new Ship;
      return ship;
    }
    if(who==3)
    {
      Mine* mine=new Mine;
      return mine;
    }
    if(who==4)
    {
      Astroid* astroid=new Astroid;
      return astroid;
    }
  }
  int where()
  {
    return Zeiger;
  }
  void setInfo()
  {
    std::string who;
    switch(Galaxy[Zeiger]->who())
    {
      case 1:info="Planet: Bevölkerung: "+std::to_string(Galaxy[Zeiger]->_population);
             info+=" Wachstum: +"+std::to_string(Galaxy[Zeiger]->_Hpr);
             break;
      case 2:info="Schiff";break;
      case 3:info="Mine";break;
      case 4:info="Astroid";break;
      case 5:info="Space";break;
    }
  }
  void Abstand(int where,int dist=1)
  {
    const int saveZeiger=Zeiger;
    Zeiger=where;
    if(dist==1)
      Galaxy[Zeiger]->distance=0;
    for(int n=0;n<8;n++)
    {
      switch(n)
      {
       case 0:movUp();if(dist<8){Abstand(Zeiger,dist+1);}break;
       case 1:movDo();if(dist<8){Abstand(Zeiger,dist+1);}break;
       case 2:movLe();if(dist<8){Abstand(Zeiger,dist+1);}break;
       case 3:movRi();if(dist<8){Abstand(Zeiger,dist+1);}break;
       /*case 4:movLup();if(dist<5){Abstand(dist+1);}break;
       case 5:movRup();if(dist<5){Abstand(dist+1);}break;
       case 6:movLown();if(dist<5){Abstand(dist+1);}break;
       case 7:movRown();if(dist<5){Abstand(dist+1);}break;*/
      }
      Galaxy[Zeiger]->distance=std::min(Galaxy[Zeiger]->distance,dist);
      Zeiger=saveZeiger;
    }
  }
  void Rab()
  {
    for(auto& n: Galaxy)
    {
      n->distance=99;
    }
  }
  void movUp()
  {
    Zeiger-=5;
    if(Zeiger<0){Zeiger+=5;}
    setInfo();
  }
  void movLe()
  {
    Zeiger-=1;
    if(Zeiger%5==4||Zeiger<0){Zeiger+=1;}
    setInfo();
  }
  void movDo()
  {
    Zeiger+=5;
    if(Zeiger>24){Zeiger-=5;}
    setInfo();
  }
  void movRi()
  {
    Zeiger+=1;
    if(Zeiger%5==0){Zeiger-=1;}
    setInfo();
  }
  void movLup()
  {
    Zeiger-=6;
    if(Zeiger<0||Zeiger%5==4){Zeiger+=6;}
  }
  void movRup()
  {
    Zeiger-=4;
    if(Zeiger<0||Zeiger%5==0){Zeiger+=4;}
  }
  void movLown()
  {
    Zeiger+=4;
    if(Zeiger>24||Zeiger%5==4){Zeiger-=4;}
  }
  void movRown()
  {
    Zeiger+=6;
    if(Zeiger>24||Zeiger%5==0){Zeiger-=6;}
  }
  bool alloc(int team)
  {
    if(Galaxy[Zeiger]->Team==0&&(Galaxy[Zeiger]->who()==1||Galaxy[Zeiger]->who()==3))
    {
      Galaxy[Zeiger]->Team=team+1;
      Galaxy[Zeiger]->_Hpr=1;
      Galaxy[Zeiger]->up();
      return true;
    }
    return false;
  }
  void change(int team)
  {
      for(auto& n :Galaxy)
      {
        if(n->Team==team+1)
          n->up();
      }
      if(team==0){pointCol=red;}
      else{pointCol=magenta;}
      Zeiger=12;
  }
  int who()
  {
    return Galaxy[Zeiger]->who();
  }
  bool mine(int team)
  {
    return Galaxy[Zeiger]->Team==team+1;
  }
  void out()
  {
    std::string Farbe;
    int Feld=0;
    int count=0;
    int Spalte=0;
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t ";
    for(int n=0;n<100;n++)
    {
      switch(Galaxy[Feld]->distance)
      {
        case 0: Farbe="";break;
        case 1: Farbe=green;break;
        case 2:Farbe=blue;break;
        case 3:Farbe=magenta;break;
        case 4:Farbe=red;break;
      }
      if(Zeiger==Feld){Farbe=pointCol;}
      std::cout<<Farbe+Galaxy[Feld]->Image(Spalte)+resCol;
      count++;
      Feld++;
      if(count==5)
      {
        if(Spalte==3)
        {
          Spalte=-1;
          Feld+=5;
        }
        Feld-=5;
        count=0;
        Spalte++;
        std::cout<<"\n\t\t ";
      }
    }
    std::cout<<"\n\n";
    std::cout<<info;
  }
};//End System
