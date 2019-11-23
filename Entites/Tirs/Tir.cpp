#include "Tir.h"

Tir::Tir(int z) {

  sens=z;
  degats=10;
  longueur=300;
  vitesse=10;
}

void Tir::setdead(){
  ded=true;
}
//getters
sf::Sprite Tir::getSprite(){
  return stir;
}
bool Tir::done(){
  return ded;
}
