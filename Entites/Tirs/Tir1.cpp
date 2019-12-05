#include "Tir1.h"

Tir1::Tir1(int x, int y, int z, int v) : Tir(z, v){
  if (!tir.loadFromFile("Sprites/OldTextures/iceball.png")) {
    std::cout << "erreur" << std::endl;
  }
  tir.setSmooth(true);
  stir.setTexture(tir);
  stir.setTextureRect(sf::IntRect(32, 0, 64, 64));
  stir.setPosition(x, y);
  degats=1000;
  longueur=300;
  vitesse=3;
  t=x;
  u=y;
}
