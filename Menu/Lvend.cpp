#include "Lvend.h"

Lvend::Lvend(int x, int y):Menu(x,y){
  text[0].setString("Bravo");
}

void Lvend::handleMenu(){
  if(clock->getElapsedTime().asMilliseconds()>1000){
    over=true;
    clock->restart();
  }
}
