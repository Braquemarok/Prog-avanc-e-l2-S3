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
  scanon.setOrigin(19, 24);
  scanon.setPosition(288, 160);
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
  scanon.setOrigin(19, 24);
  scanon.setPosition(288, 160);
}

//action du joueur
void Joueur::actions(int z, int t) {

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

    sperso.move(5, 0);
    scanon.move(5, 0);
    sens = 1;
    animation( &sperso, &anim, sens );
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

    sperso.move(-5, 0);
    scanon.move(-5, 0);
    sens = 3;
    animation( &sperso, &anim, sens );
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {

    sperso.move(0, -5);
    scanon.move(0, -5);
    sens = 0;
    animation( &sperso, &anim, sens );
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

    sperso.move(0, 5);
    scanon.move(0, 5);
    sens = 2;
    animation( &sperso, &anim, sens );
  }

  rotation( &scanon, z, t );

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock->getElapsedTime().asMilliseconds()>=500) {
    //action de tir
    Tir1* pew = new Tir1(sperso.getPosition().x+32, sperso.getPosition().y+32, z,t);
    rotation( pew->getSTir(), z, t );
    tirs.ajouter(pew);
    clock->restart();
  }
  
  if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && clock->getElapsedTime().asMilliseconds()>=700) {
    //action de tir
    Tir2* pew = new Tir2(sperso.getPosition().x+32, sperso.getPosition().y+32, z,t);
    rotation( pew->getSTir(), z, t );
    tirs.ajouter(pew);
    clock->restart();
  }

  for( int i = 0; i < tirs.size() ; i++ ){

    tirs.get(i)->actions();

    if(tirs.get(i)->done())
      tirs.supprimer(i);
  }
}
