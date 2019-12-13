#include "Monstre3.h"

Monstre3::Monstre3(int x, int y) : Entite() {

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

  type=3;
}

void Monstre3::actions(Entite* j, int h, int l) {
  rotation( &scanon, j->getEntite().getPosition().x+32, j->getEntite().getPosition().y+32);
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
}
