#include "Monstre2.h"

Monstre2::Monstre2(int x, int y) : Entite() {

  if (!perso.loadFromFile("Sprites/Mobs/tank2.png")) {

    std::cout << "erreur" << std::endl;
  }

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect( 0, 0, 64, 64 ));
  sperso.setPosition(x, y);
  if (!canon.loadFromFile("Sprites/Mobs/canon2.png"))
    std::cout << "erreur" << std::endl;

  canon.setSmooth(true);
  scanon.setTexture(canon);
  scanon.setTextureRect(sf::IntRect(0, 0, 38, 48));
  scanon.setOrigin(19, 24);
  scanon.setPosition(x+32, y+32);

  type=2;
}

void Monstre2::actions(Entite* j){
  rotation( &scanon, j->getEntite().getPosition().x+TSIZE/2, j->getEntite().getPosition().y+TSIZE/2);
  if (j->getEntite().getPosition().y < sperso.getPosition().y) {

    sperso.move(0, -2);
    scanon.move(0, -2);
    sens = 0;
    animation( &sperso, &anim, sens );
  }
  if (j->getEntite().getPosition().y > sperso.getPosition().y) {

    sperso.move(0, 2);
    scanon.move(0, 2);
    sens = 2;
    animation( &sperso, &anim, sens );
  }
  if (j->getEntite().getPosition().x < sperso.getPosition().x) {

    sperso.move(-2, 0);
    scanon.move(-2, 0);
    sens = 3;
    animation( &sperso, &anim, sens );
  }
  if (j->getEntite().getPosition().x > sperso.getPosition().x) {

    sperso.move(2, 0);
    scanon.move(2, 0);
    sens = 1;
    animation( &sperso, &anim, sens );
  }
  if (clock->getElapsedTime().asMilliseconds()>=500) {
    //action de tir
    Tir1* pew = new Tir1(sperso.getPosition().x+TSIZE/2, sperso.getPosition().y+TSIZE/2, j->getEntite().getPosition().x+TSIZE/2, j->getEntite().getPosition().y+TSIZE/2);
    rotation( pew->getSTir(), j->getEntite().getPosition().x+TSIZE/2, j->getEntite().getPosition().y+TSIZE/2);
    tirs.ajouter(pew);
    clock->restart();
  }
  for( int i = 0; i < tirs.size() ; i++ ){

    tirs.get(i)->actions();
    if(tirs.get(i)->done())
      tirs.supprimer(i);
  }
}
