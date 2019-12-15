#include "Joueur.h"

Joueur::Joueur() : Entite(){

  sens = 0;

  if (!perso.loadFromFile("Sprites/Joueur/player.png"))
    std::cout << "erreur" << std::endl;

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect(0, 0, 64, 64));
  sperso.setPosition(608, 320);

  if (!canon.loadFromFile("Sprites/Joueur/canonp.png"))
    std::cout << "erreur" << std::endl;

  canon.setSmooth(true);
  scanon.setTexture(canon);
  scanon.setTextureRect(sf::IntRect(0, 0, 38, 48));
  scanon.setOrigin(19, 24);
  scanon.setPosition(640, 352);
  type=0;
}
Joueur::Joueur(int x, int y) : Entite(){

  sens = 0;

  if (!perso.loadFromFile("Sprites/Joueur/player.png"))
    std::cout << "erreur" << std::endl;

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect(0, 0, 64, 64));
  sperso.setPosition(x, y);

  if (!canon.loadFromFile("Sprites/Joueur/canonp.png"))
    std::cout << "erreur" << std::endl;

  canon.setSmooth(true);
  scanon.setTexture(canon);
  scanon.setTextureRect(sf::IntRect(0, 0, 38, 48));
  scanon.setOrigin(19, 24);
  scanon.setPosition(x+32, y+32);
  type=0;
}
