#include "Menu.h"

Menu::Menu(int x, int y){
  clock = new sf::Clock();
  if (!font.loadFromFile("Font/upheavtt.ttf")){
      std::cout<< "erreur ttf"<<std::endl;
  }
  if(!fond.loadFromFile("Sprites/Menus/fond.png"))
  {
    std::cout<< "erreur Image inexistante"<<std::endl;
  }
  else{
    sfond.setTexture(fond);
    sfond.setScale(x / fond.getSize().x, y / fond.getSize().y);
  }

  for( int i = 0 ; i < 4 ; i++ ){

    text[i].setFont(font);
    text[i].setCharacterSize(32);

    if( i == 0 ){


      text[i].setPosition(x/2-53,y/2-36+33*i);
    }

    else if( i < 3 ){

      text[i].setPosition(x/2-70,y/2-36+33*i);
    }

    else{

      text[i].setPosition(x/4-60,y/2-36+33*i);
    }
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
  clock->restart();
  over=false;
}
int Menu::getOpt(){
  return option;
}
Menu::~Menu(){
  delete clock;
}
