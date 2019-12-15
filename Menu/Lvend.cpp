#include "Lvend.h"

Lvend::Lvend(int x, int y):Menu(x,y){
  if (!font.loadFromFile("Font/upheavtt.ttf")){
      std::cout<< "erreur ttf"<<std::endl;
  }
  if(!fond.loadFromFile("Sprites/Menus/blackscreen.png"))
  {
    std::cout<< "erreur Image inexistante"<<std::endl;
  }
  text[0].setString("Bravo");
}

void Lvend::handleMenu(){
  if(clock->getElapsedTime().asMilliseconds()>1000){
    over=true;
    clock->restart();
  }
}
