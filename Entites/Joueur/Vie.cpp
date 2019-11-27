#include "Vie.h"

Vie::Vie(){
  if (!font.loadFromFile("Font/O.ttf")){
      std::cout<< "erreur ttf"<<std::endl;
  }
  text.setFont(font);
  text.setPosition(10,10);
  text.setCharacterSize(32);
  text.setColor(sf::Color::Blue);
}
void Vie::handlevie(int nbvie){
  text.setString("vie :"+std::to_string(nbvie));
}

sf::Text Vie::getText(){
  return text;
}
