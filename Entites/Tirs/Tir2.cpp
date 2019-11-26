#include "Tir2.h"

Tir2::Tir2(int x, int y, int z, int v) : Tir(z, v){
  if (!tir.loadFromFile("Sprites/fireball.png")) {
    std::cout << "erreur" << std::endl;
  }
  tir.setSmooth(true);
  stir.setTexture(tir);
  stir.setTextureRect(sf::IntRect(32, 0, 64, 64));
  stir.setPosition(x, y);
  degats=10;
  longueur=500;
  vitesse=15;
  t=x;
  u=y;
}
