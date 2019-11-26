#include "Menu.h"

Menu::Menu(){
  if (!font.loadFromFile("Font/O.ttf")){
      std::cout<< "erreur ttf"<<std::endl;
  }
  for(int i=0; i<4; i++){
    text[i].setFont(font);
    text[i].setPosition(sf::VideoMode::getDesktopMode().width/2-70,sf::VideoMode::getDesktopMode().height/2-66+33*i);
    text[i].setCharacterSize(32);
  }
  text[0].setString("Reprendre");
  text[1].setString("Recommencer");
  text[2].setString("Quitter");
  text[3].setString("(deplacement : fleches, selection : entrer)");
}

void Menu::handleMenu(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
    over=true;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    option--;
    if(option<0){
      option=2;
    }
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    option++;
    if(option>2){
      option=0;
    }
  }
  for(int i=0; i<4; i++){
    text[i].setColor(sf::Color::White);
    if(i==option){
      text[i].setColor(sf::Color::Red);
    }
  }
}


bool Menu::isMenuOver(){
  return over;
}

sf::Text Menu::getText(int i){
  return text[i];
}
void Menu::setMenu(){
  over=false;
}
int Menu::getOpt(){
  return option;
}
