#include "Monstre.h"

Monstre::Monstre(int x, int y) : Entite() {

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

    sperso.move(0, -1);
    sens = 0;
    animation( &sperso, &anim, sens );

  }
  if (j->getEntite().getPosition().y > sperso.getPosition().y) {

    sperso.move(0, 1);
    sens = 2;
    animation( &sperso, &anim, sens );
  }

  if (j->getEntite().getPosition().x < sperso.getPosition().x) {

    sperso.move(-1, 0);
    sens = 3;
    animation( &sperso, &anim, sens );
  }

  if (j->getEntite().getPosition().x > sperso.getPosition().x) {

    sperso.move(1, 0);
    sens = 1;
    animation( &sperso, &anim, sens );

  }
}
