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
void Tir::collision(const int* tiles, unsigned int width, unsigned int height){
  for(unsigned int i=0; i<width; i++){
    for(unsigned int j=0; j<height; j++){
      if(tiles[i + j * width]<3){
        sf::FloatRect* r = new sf::FloatRect(i*TSIZE,j*TSIZE,TSIZE,TSIZE);
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
Tir::~Tir(){}
