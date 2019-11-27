#include "Ptmenu.h"

Ptmenu::Ptmenu(int x, int y):Menu(x,y){
  text[0].setString("Reprendre");
  text[1].setString("Recommencer");
  text[2].setString("Quitter");
  text[3].setString("(deplacement : fleches, selection : entrer)");
}

void Ptmenu::handleMenu(){
  if(clock->getElapsedTime().asMilliseconds()>300){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
      over=true;
      clock->restart();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
      option++;
      if(option>2){
        option=0;
      }
      clock->restart();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
      option--;
      if(option<0){
        option=2;
      }
      clock->restart();
    }
    for(int i=0; i<4; i++){
      text[i].setColor(sf::Color::White);
      if(i==option){
        text[i].setColor(sf::Color::Red);
      }
    }
  }
}
