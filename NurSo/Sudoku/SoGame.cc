#include<iostream>
#include"Sudoku.cc"
#include <stdio.h>

int main(int argc, char** argv)
{
  int Schwierigkeit;
  bool Fehler;
  bool high;
  bool cheat;

  std::cout<<std::endl;
  std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
  std::cout<<"        ______                   __            __                 "<<std::endl;
  std::cout<<"       /      |                 /  |          /  |                "<<std::endl;
  std::cout<<"      /$$$$$$  | __    __   ____$$ |  ______  $$ |   __   __   __  "<<std::endl;
  std::cout<<"      $$ |__$$/ /  |  /  | /    $$ | /      | $$ |  /  | / |  /  | "<<std::endl;
  std::cout<<"      $$      | $$ |  $$ |/$$$$$$$ |/$$$$$$  |$$ |_/$$/ /$$|  $$ |"<<std::endl;
  std::cout<<"       $$$$$$  |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$   $$<  $$ |  $$ |"<<std::endl;
  std::cout<<"      /  |__$$ |$$ |__$$ |$$ |__$$ |$$ |__$$ |$$$$$$  | $$ |__$$ |"<<std::endl;
  std::cout<<"      $$    $$/ $$    $$/ $$    $$ |$$    $$/ $$ | $$  |$$    $$/ "<<std::endl;
  std::cout<<"       $$$$$$/   $$$$$$/   $$$$$$$/  $$$$$$/  $$/   $$/  $$$$$$/  "<<std::endl;
  std::cout<<"\n\n\n\n\n"<<std::endl;
  std::cout<<"    Geben sie die Schwierigkeit ein (0-100): "<<std::flush;
  std::cin>>Schwierigkeit;
  std::cout<<"    Fehler anzeigen (1=Ja/0=Nein)?: "<<std::flush;
  std::cin>>Fehler;
  std::cout<<"    Gleiche Zahlen hervorheben (1=Ja/0=Nein)?: "<<std::flush;
  std::cin>>high;
  std::cout<<"    Tipps aktivieren (1=Ja/0=Nein)?: "<<std::flush;
  std::cin>>cheat;
  std::cout<<"    Lädt bitte warten..."<<std::flush;

  Soduko Spiel(Schwierigkeit,Fehler,high,cheat);
  bool end=false;
  while(true)
{
  Spiel.out();
  if(Spiel.end()||end)
  {
    break;
  }
  system("stty raw");
  char input = getchar();
  switch(input)
  {
    case 'w': Spiel.moveUp();
    break;
    case 'a': Spiel.moveLeft();
    break;
    case 's': Spiel.moveDown();
    break;
    case 'd': Spiel.moveRight();
    break;
    case 'q': end=true;
    break;
    case '1': Spiel.Eingabe(1);
    break;
    case '2': Spiel.Eingabe(2);
    break;
    case '3': Spiel.Eingabe(3);
    break;
    case '4': Spiel.Eingabe(4);
    break;
    case '5': Spiel.Eingabe(5);
    break;
    case '6': Spiel.Eingabe(6);
    break;
    case '7': Spiel.Eingabe(7);
    break;
    case '8': Spiel.Eingabe(8);
    break;
    case '9': Spiel.Eingabe(9);
    break;
    case 127: Spiel.Del();
    break;
    case 'l': Spiel.Del();
    break;
    case 't': Spiel.cheat();
    break;
    default: break;
  }
  system("stty cooked");
}
system("stty cooked");
std::cout<<"sie haben gewonnen"<<std::endl;
}
