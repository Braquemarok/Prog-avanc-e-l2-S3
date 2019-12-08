#include "Menu.h"

Menu::Menu(int x, int y){
  clock = new sf::Clock();
  if (!font.loadFromFile("Font/O.ttf")){
      std::cout<< "erreur ttf"<<std::endl;
  }
  if(!fond.loadFromFile("Sprites/OldTextures/fond.jpg"))
  {
    std::cout<< "erreur Image inexistante"<<std::endl;
  }
  else{
    sfond.setTexture(fond);
    sfond.setScale(x / fond.getSize().x, y / fond.getSize().y);
  }
  for(int i=0; i<4; i++){
    text[i].setFont(font);
    text[i].setPosition(x/2-70,y/2-66+33*i);
    text[i].setCharacterSize(32);
  }
}

void Menu::handleMenu(){

}


bool Menu::isMenuOver(){
  return over;
}

sf::Text Menu::getText(int i){
  return text[i];
}
sf::Sprite Menu::getfond(){
  return sfond;
}
void Menu::setMenu(){
  over=false;
}
int Menu::getOpt(){
  return option;
}
Menu::~Menu(){
  delete clock;
}
