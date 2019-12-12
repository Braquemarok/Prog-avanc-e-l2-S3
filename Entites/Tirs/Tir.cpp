#include "Tir.h"

Tir::Tir(int z, int v) {

  mousex=z;
  mousey=v;
  degats=10;
  longueur=300;
  vitesse=10;
}

void Tir::setdead(){
  ded=true;
}
void Tir::actions(){
  stir.move((mousex-t)/distance(t,u,mousex,mousey)*vitesse, (mousey-u)/distance(t,u,mousex,mousey)*vitesse);
  longueur-=vitesse;
  if(longueur<=0){
    setdead();
  }
}
void Tir::collision(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height){
  sf::RectangleShape rs;
  rs.setScale(64,64);

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if(tiles[i + j * width]<3){
        rs.setPosition(sf::Vector2f(i * tileSize.x, j * tileSize.y));
        //std::cout<<rs.getPosition().y<<std::endl;
      }
      if (stir.getGlobalBounds().contains(rs.getPosition().x, rs.getPosition().y) || stir.getGlobalBounds().contains(rs.getPosition().x+tileSize.x, rs.getPosition().y+tileSize.y) || stir.getGlobalBounds().contains(rs.getPosition().x+tileSize.x, rs.getPosition().y) || stir.getGlobalBounds().contains(rs.getPosition().x, rs.getPosition().y+tileSize.y)){
        setdead();
      }
    }
  }
}

//getters
sf::Sprite Tir::getSprite(){
  return stir;
}

sf::Sprite* Tir::getSTir(){

  return &stir;
}

bool Tir::done(){
  return ded;
}
