#include "Monstre.h"

Monstre::Monstre(int x, int y) : Entite() {

  if (!perso.loadFromFile("Sprites/Mobs/tank4.png")) {

    std::cout << "erreur" << std::endl;
  }

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect( 0, 0, 64, 64 ));
  sperso.setPosition(x, y);
  if (!canon.loadFromFile("Sprites/Mobs/canon4.png"))
    std::cout << "erreur" << std::endl;

  canon.setSmooth(true);
  scanon.setTexture(canon);
  scanon.setTextureRect(sf::IntRect(0, 0, 38, 48));
  scanon.setOrigin(19, 24);
  scanon.setPosition(x+32, y+32);
  type=1;
}

//action monstre en fonction du joueur
void Monstre::actions(Entite* j, int h, int l) {
  rotation( &scanon, j->getEntite().getPosition().x+32, j->getEntite().getPosition().y+32);
  if (clock->getElapsedTime().asMilliseconds()>=500) {
    //action de tir
    Tir1* pew = new Tir1(sperso.getPosition().x+32, sperso.getPosition().y+32, j->getEntite().getPosition().x+32, j->getEntite().getPosition().y+32);
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
