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
void Monstre::actions(Entite* j, int clock) {
  if (j->getEntite().getPosition().y < sperso.getPosition().y) {
    sperso.move(0, -3);
    y=96;
    //sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if (j->getEntite().getPosition().y > sperso.getPosition().y) {
    sperso.move(0, 3);
    y=0;
    //sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if (j->getEntite().getPosition().x < sperso.getPosition().x) {
    sperso.move(-3, 0);
    y=32;
    //sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if (j->getEntite().getPosition().x > sperso.getPosition().x) {
    sperso.move(3, 0);
    y=64;
    //sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
}
