#include "Tir1.h"

Tir1::Tir1(int x, int y, int z, int v) : Tir(z, v){
  if (!tir.loadFromFile("Sprites/projectiles.png")) {
    std::cout << "erreur" << std::endl;
  }
  tir.setSmooth(true);
  stir.setTexture(tir);
  stir.setTextureRect(sf::IntRect( 0, 0, 16, 32 ));
  stir.setOrigin(8, 16);
  stir.setPosition(x, y);
  degats=1000;
  longueur=300;
  vitesse=3;
  t=x;
  u=y;
}
