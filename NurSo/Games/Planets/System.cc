 #include"Objects.cc"
#include<vector>
#include<iostream>

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
 bool shipmode=false;
public:
  System()
  {
    for(int n=0;n<25;n++)
    {
      Space* space= new Space;
      Galaxy[n]=space;
    }
    create(3,0,0);//who,team,where
    create(3,0,3);
    create(1,1,6);
    create(1,0,10);
    create(4,0,12);
    create(1,0,14);
    create(1,2,18);
    create(3,0,21);
    create(3,0,24);
  }
  ~System()
  {
    for(int n=0;n<25;n++)
    {
      delete Galaxy[n];
    }
  }
  void create(int who, int team,int where)
  {
    delete Galaxy[where];
    if(who==1)
    {
      Planet* planet=new Planet(team);
      Galaxy[where]=planet;
    }
    /*if(who==2)
    {
      Ship* ship=new Ship(team);
      Galaxy[where]=ship;
    }*/
    if(who==3)
    {
      Mine* mine=new Mine;
      Galaxy[where]=mine;
    }
    if(who==4)
    {
      Astroid* astroid=new Astroid;
      Galaxy[where]=astroid;
    }
    if(who==5)
    {
      Space* space=new Space;
      Galaxy[where]=space;
    }
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
  void Abstand(int where,int dist,int dest )
  {
    const int saveloc=where;
    if(dist==1)
      Galaxy[where]->distance=0;
    for(int n=0;n<4;n++)
    {
      switch(n)
      {
       case 0:shUp(where,dest);if(dist<8){Abstand(where,dist+1,dest);}break;
       case 1:shDo(where,dest);if(dist<8){Abstand(where,dist+1,dest);}break;
       case 2:shLe(where,dest);if(dist<8){Abstand(where,dist+1,dest);}break;
       case 3:shRi(where,dest);if(dist<8){Abstand(where,dist+1,dest);}break;
      }
      Galaxy[where]->distance=std::min(Galaxy[where]->distance,dist);
      where=saveloc;
    }
  }
  void Rab()
  {
    for(auto& n: Galaxy)
    {
      n->distance=99;
    }
  }
  void movUp(int dest=0)
  {
    Zeiger-=5;
    if(Zeiger<0){Zeiger+=5;}
    setInfo();
  }
  void movLe(int dest=0)
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
  void shUp(int& loc,int dest)
  {
    loc-=5;
    if(loc<0||Galaxy[loc]->who()!=5&&loc!=dest){loc+=5;}
  }
  void shDo(int& loc,int dest)
  {
    loc+=5;
    if(loc>24||Galaxy[loc]->who()!=5&&loc!=dest){loc-=5;}
  }
  void shLe(int& loc,int dest)
  {
    loc-=1;
    if(loc%5==4||loc<0||Galaxy[loc]->who()!=5&&loc!=dest){loc+=1;}
  }
  void shRi(int& loc,int dest)
  {
    loc+=1;
    if(loc%5==0||Galaxy[loc]->who()!=5&&loc!=dest){loc-=1;}
  }
  int bestMove(int loc,int dest)
  {
    int saveloc=loc;
    int bestmove=0;
    int minabstand=89;
    for(int n=0;n<4;++n)
    {
      Rab();
      switch(n)
      {
        case 0: shUp(loc,dest);break;
        case 1: shDo(loc,dest);break;
        case 2: shLe(loc,dest);break;
        case 3: shRi(loc,dest);break;
      }
      Abstand(loc,1,dest);
      minabstand=std::min(minabstand,Galaxy[dest]->distance);
      if(minabstand==Galaxy[dest]->distance){bestmove=n;}
      loc=saveloc;
    }
    return bestmove;
  }
  bool invade(int team,int where)
  {
    if(Galaxy[Zeiger]->Team==0&&(Galaxy[Zeiger]->who()==1||Galaxy[Zeiger]->who()==3))
    {
      Ship ship(team+1,where,Zeiger);
      shipMove(team+1,where,Zeiger);
      return true;
    }
    return false;
  }
  void alloc()
  {
    //Not Final!
  /*  Galaxy[Zeiger]->Team=team+1;
    Galaxy[Zeiger]->_Hpr=1;
    Galaxy[Zeiger]->up();*/
  }
  void shipMove(int team,int loc,int dest)
  {
    Ship* ship=new Ship(team,loc,dest);
    ship->idle=true;
    switch(bestMove(loc,dest))
    {
      case 0:delete Galaxy[loc-5];ship->newloc(loc-5);Galaxy[loc-5]=ship;break;
      case 1:delete Galaxy[loc+5];ship->newloc(loc+5);Galaxy[loc+5]=ship;break;
      case 2:delete Galaxy[loc-1];ship->newloc(loc-1);Galaxy[loc-1]=ship;break;
      case 3:delete Galaxy[loc+1];ship->newloc(loc+1);Galaxy[loc+1]=ship;break;
    }
    if(Galaxy[loc]->who()==2)
    {
      Space* space=new Space();
      delete Galaxy[loc];Galaxy[loc]=space;
    }
  }
  void change(int team)
  {
    for(auto& n :Galaxy)
    {
      n->idle=false;
    }
    for(auto& n :Galaxy)
    {
      if(n->Team==team+1)
      {
        if(n->who()==2&&n->idle==false)
        {
          shipMove(team+1,n->out(),n->_dest);
        }
        n->up();
      }
    }
    if(team==0){pointCol=red;}
    else{pointCol=magenta;}
    Zeiger=12;
  }
  int who()
  {
    return Galaxy[Zeiger]->who();
  }
  int where()
  {
    return Zeiger;
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
      switch(Galaxy[Feld]->Team)
      {
        case 0: Farbe="";break;
        case 1: Farbe=green;break;
        case 2:Farbe=blue;break;
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
