#include "Joueur.h"

Joueur::Joueur() : Entite(){

  arme = "";
  sens = 0;

  if (!perso.loadFromFile("Sprites/OldTextures/sprite.png"))
    std::cout << "erreur" << std::endl;

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect(0, 0, 64, 64));
  sperso.setPosition(256, 128);
}
Joueur::Joueur(int vie) : Entite(vie){

  arme = "";
  sens = 0;

  if (!perso.loadFromFile("Sprites/sprite.png"))
    std::cout << "erreur" << std::endl;

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect(0, 0, 64, 64));
  sperso.setPosition(256, 128);
}

//action du joueur
void Joueur::actions(int clock, int z, int t) {

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

    sens = 0;
    y = 96;
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

    sens = 1;
    y = 0;
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

    sens = 2;
    y = 32;
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

    sens = 3;
    y = 64;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

    sperso.move(5, 0);
    //sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

    sperso.move(-5, 0);
    //sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {

    sperso.move(0, -5);
    //sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    sperso.move(0, 5);
    //sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock%200<=17) {
    //action de tir
    tirs.ajouter(new Tir1(sperso.getPosition().x, sperso.getPosition().y, z,t));
  }
  if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && clock%200<=17) {
    //action de tir
    tirs.ajouter(new Tir2(sperso.getPosition().x, sperso.getPosition().y, z,t));
  }
  for( int i = 0; i < tirs.size() ; i++ ){

    tirs.get(i)->actions();

    if(tirs.get(i)->done())
      tirs.supprimer(i);
  }
}
