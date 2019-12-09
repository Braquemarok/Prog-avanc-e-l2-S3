#include "Monstre.h"

Monstre::Monstre(int x, int y) : Entite() {
  vie=1;
  if (!perso.loadFromFile("Sprites/Mobs/tank4.png")) {
    std::cout << "erreur" << std::endl;
  }
  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect( 0, 0, 64, 64 ));
  sperso.setPosition(x, y);

}
//action monstre en fonction du joueur
void Monstre::actions(Entite* j) {
  if (j->getEntite().getPosition().y < sperso.getPosition().y) {
    sperso.move(0, -3);
    y=96;
    sens = 0;
    anim++;

    if ( anim > 3) {

      anim = 0;
    }
    animation( sperso, anim, sens );

  }
  if (j->getEntite().getPosition().y > sperso.getPosition().y) {
    sperso.move(0, 3);
    y=0;
    sens = 2;
    anim++;

    if ( anim > 3) {

      anim = 0;
    }
  }
  if (j->getEntite().getPosition().x < sperso.getPosition().x) {
    sperso.move(-3, 0);
    y=32;
    sens = 3;
    anim++;

    if ( anim > 3) {

      anim = 0;
    }
    animation( sperso, anim, sens );

  }
  if (j->getEntite().getPosition().x > sperso.getPosition().x) {
    sperso.move(3, 0);
    y=64;
    sens = 1;
    anim++;

    if ( anim > 3) {

      anim = 0;
    }

    animation( sperso, anim, sens );

  }

  switch(sens){

    case 0:
      sperso.setTextureRect(sf::IntRect(64 * anim, 0, 64, 64));
    break;

    case 1:
      sperso.setTextureRect(sf::IntRect(64 * anim, 64, 64, 64));
    break;

    case 2:
      sperso.setTextureRect(sf::IntRect(64 * anim, 128, 64, 64));
    break;

    case 3:
      sperso.setTextureRect(sf::IntRect(64 * anim, 192, 64, 64));
    break;
  }
}
