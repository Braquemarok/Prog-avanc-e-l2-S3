#include "Tir2.h"

Tir2::Tir2(int x, int y, int z, int v) : Tir(z, v){
  if (!tir.loadFromFile("Sprites/projectiles.png")) {
    std::cout << "erreur" << std::endl;
  }
  tir.setSmooth(true);
  stir.setTexture(tir);
  stir.setTextureRect(sf::IntRect( 16, 0, 16, 32 ));
  stir.setOrigin(8, 16);
  stir.setPosition(x, y);
  degats=10;
  longueur=500;
  vitesse=15;
  t=x;
  u=y;
}
