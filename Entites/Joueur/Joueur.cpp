#include "Joueur.h"

Joueur::Joueur() : Entite(){

  sens = 0;

  if (!perso.loadFromFile("Sprites/Joueur/player.png"))
    std::cout << "erreur" << std::endl;

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect(0, 0, 64, 64));
  sperso.setPosition(256, 128);

  if (!canon.loadFromFile("Sprites/Joueur/canonp.png"))
    std::cout << "erreur" << std::endl;

  canon.setSmooth(true);
  scanon.setTexture(canon);
  scanon.setTextureRect(sf::IntRect(0, 0, 38, 48));
  scanon.setPosition(269, 133);
}
Joueur::Joueur(int x, int y) : Entite(){

  sens = 0;

  if (!perso.loadFromFile("Sprites/Joueur/player.png"))
    std::cout << "erreur" << std::endl;

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect(0, 0, 64, 64));
  sperso.setPosition(256, 128);

  if (!canon.loadFromFile("Sprites/Joueur/canonp.png"))
    std::cout << "erreur" << std::endl;

  canon.setSmooth(true);
  scanon.setTexture(canon);
  scanon.setTextureRect(sf::IntRect(0, 0, 38, 48));
  scanon.setPosition(269, 133);
}

//action du joueur
void Joueur::actions(int z, int t) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

    sperso.move(5, 0);
    scanon.move(5, 0);
    sens = 1;
    anim++;

    if ( anim > 3) {
    
      anim = 0;
    }

    animation( sperso, anim, sens );
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

    sperso.move(-5, 0);
    scanon.move(-5, 0);
    sens = 3;
    anim++;

    if ( anim > 3) {
    
      anim = 0;
    }
    animation( sperso, anim, sens );
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {

    sperso.move(0, -5);
    scanon.move(0, -5);
    sens = 0;
    anim++;

    if ( anim > 3) {
    
      anim = 0;
    }
    animation( sperso, anim, sens );
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

    sperso.move(0, 5);
    scanon.move(0, 5);
    sens = 2;
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

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock->getElapsedTime().asMilliseconds()>=500) {
    //action de tir
    tirs.ajouter(new Tir1(sperso.getPosition().x, sperso.getPosition().y, z,t));
    clock->restart();
  }
  if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && clock->getElapsedTime().asMilliseconds()>=700) {
    //action de tir
    tirs.ajouter(new Tir2(sperso.getPosition().x, sperso.getPosition().y, z,t));
    clock->restart();
  }
  for( int i = 0; i < tirs.size() ; i++ ){

    tirs.get(i)->actions();

    if(tirs.get(i)->done())
      tirs.supprimer(i);
  }
}
