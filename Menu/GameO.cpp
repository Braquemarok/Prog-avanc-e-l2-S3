#include "GameO.h"

GameO::GameO(int x, int y):Menu(x,y){
  if (!font.loadFromFile("Font/upheavtt.ttf")){
      std::cout<< "erreur ttf"<<std::endl;
  }
  if(!fond.loadFromFile("Sprites/Menus/gameover.png"))
  {
    std::cout<< "erreur Image inexistante"<<std::endl;
  }
}

void GameO::handleMenu(){
  if(clock->getElapsedTime().asMilliseconds()>1000){
    over=true;
    clock->restart();
  }
}
