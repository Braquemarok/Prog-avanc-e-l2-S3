#include "Monstre3.h"

Monstre3::Monstre3(int x, int y) : Entite() {

  if (!perso.loadFromFile("Sprites/Mobs/tank3.png")) {

    std::cout << "erreur" << std::endl;
  }

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect( 0, 0, 64, 64 ));
  sperso.setPosition(x, y);
  if (!canon.loadFromFile("Sprites/Mobs/canon3.png"))
    std::cout << "erreur" << std::endl;

  canon.setSmooth(true);
  scanon.setTexture(canon);
  scanon.setTextureRect(sf::IntRect(0, 0, 38, 48));
  scanon.setOrigin(19, 24);
  scanon.setPosition(x+32, y+32);

  type=3;
}

void Monstre3::actions(Entite* j, int* map, int h, int l) {
  rotation( &scanon, j->getEntite().getPosition().x+32, j->getEntite().getPosition().y+32);
  if (clock->getElapsedTime().asMilliseconds()>=700) {
    //action de tir
    Tir2* pew = new Tir2(sperso.getPosition().x+32, sperso.getPosition().y+32, j->getEntite().getPosition().x+32, j->getEntite().getPosition().y+32);
    rotation( pew->getSTir(), j->getEntite().getPosition().x+32, j->getEntite().getPosition().y+32);
    tirs.ajouter(pew);
    clock->restart();
  }
  for( int i = 0; i < tirs.size() ; i++ ){

    tirs.get(i)->actions();
    if(tirs.get(i)->done())
      tirs.supprimer(i);
  }
}
