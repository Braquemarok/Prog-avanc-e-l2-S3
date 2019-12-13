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
  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if(tiles[i + j * width]<3){
        sf::FloatRect* r = new sf::FloatRect(i*64,j*64,64,64);
        //std::cout<<rs.getPosition().y<<std::endl;
        if (r->intersects(stir.getGlobalBounds())){
          setdead();
        }
        delete r;
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
