#include "Tir1.h"

using namespace std; 

Tir1::Tir1(int x, int y, int z) : Tir(z){
  if (!tir.loadFromFile("Sprites/iceball.png")) {
    std::cout << "erreur" << std::endl;
  }
  tir.setSmooth(true);
  stir.setTexture(tir);
  stir.setTextureRect(sf::IntRect(32, 0, 32, 32));
  stir.setPosition(x, y);
  degats=1000;
  longueur=300;
  vitesse=3;
  z = x;
  t = y;
}
void Tir1::actions(){

  stir.move(sf::Mouse::getPosition().x-z, sf::Mouse::getPosition().y-t);
  longueur-=vitesse;
  if(longueur<=0){
    setdead();
  }
}
 /**
  * \brief La fonction s'occupe de calculer la distance entre deux boules
  */
/*
double Tir1::distance( int x, int y ){

  double res = sqrt( pow(( sf::Mouse::getPosition().x - x ), 2 ) + pow(( sf::Mouse::getPosition().y - y ), 2) );

  return res;
}*/