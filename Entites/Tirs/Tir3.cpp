#include "Tir3.h"

Tir3::Tir3(int x, int y, int z, int v) : Tir(z, v){
  if (!tir.loadFromFile("Sprites/mine.png")) {
    std::cout << "erreur" << std::endl;
  }
  tir.setSmooth(true);
  stir.setTexture(tir);
  stir.setTextureRect(sf::IntRect( 0, 0, 32, 32 ));
  stir.setOrigin(8, 16);
  stir.setPosition(x, y);
  degats=10;
  longueur=500;
  vitesse=0;
  t=x;
  u=y;
}
