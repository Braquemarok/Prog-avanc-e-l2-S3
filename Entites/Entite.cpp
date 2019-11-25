#include "Entite.h"

Entite::Entite() {

  vie = 2000;
  degats = 3;
}

bool Entite::mort() const {

  return vie <= 0;
}

int Entite::getdegat(){

  return degats;
}

//detection collision plus degat si vrai
void Entite::damage( Tir* m, int degats ){

  sf::FloatRect boundingBox = sperso.getGlobalBounds();
  sf::FloatRect otherBox = m->getSprite().getGlobalBounds();

  if (boundingBox.intersects(otherBox)){

    vie -= degats;
    m->setdead();
  }
}

void Entite::damage( sf::Sprite m, int degats ){

  sf::FloatRect boundingBox = sperso.getGlobalBounds();
  sf::FloatRect otherBox = m.getGlobalBounds();

  if (boundingBox.intersects(otherBox))
    vie -= degats;
}

//action du joueur
 void Entite::actions(int clock){

  Tir* tir;

  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock%200 <= 17 ) {

    //action de tir
    tir = new Tir1( sperso.getPosition().x, sperso.getPosition().y, sens );
    tirs.ajouter(tir);
  }
}

//action monstre en fonction du joueur
 void Entite::actions(Entite j, int clock){
  if (j.getEntite().getPosition().y < sperso.getPosition().y) {

    sperso.move(0, -3);
    sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if (j.getEntite().getPosition().y > sperso.getPosition().y) {

    sperso.move(0, 3);
    sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if (j.getEntite().getPosition().x < sperso.getPosition().x) {

    sperso.move(-3, 0);
    sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if (j.getEntite().getPosition().x > sperso.getPosition().x) {

    sperso.move(3, 0);
    sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if ((sperso.getPosition().x > 512) || (sperso.getPosition().x < 0) || (sperso.getPosition().y > 256) || (sperso.getPosition().y < 0)) {

    sperso.setPosition(256, 128);
  }
}

//getters
sf::Sprite Entite::getEntite(){

  return sperso;
}

sf::Sprite Entite::getstir(int i){

  return tirs.get(i)->getSprite();
}

int Entite::gettaillet(){

  return tirs.size();
}

Tir* Entite::getTir(int i){

  return tirs.get(i);
}
