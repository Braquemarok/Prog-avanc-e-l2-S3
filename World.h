#ifndef DEF_W
#define DEF_W

#include <string.h>
#include "Entites/Joueur/Joueur.h"
#include "Entites/Monstres/Monstre.h"
#include "Entites/Monstres/Monstre2.h"
#include "Entites/Monstres/Monstre3.h"
#include "Entites/Monstres/Monstre4.h"
#include "Entites/Monstres/Monstre5.h"
#include "Entites/Monstres/Monstre7.h"
#include "Sound.h"
#include "Map.h"
#include "Lecteur.h"

class World{

public:

  World(int num);
  World(string s);
  void handlevent(int x, int y);
  sf::Sprite spriteMob(int i);
  sf::Sprite spriteMcanon(int i);
  int nbMobs();
  sf::Sprite spritePlayer();
  sf::Sprite spritePcanon();
  sf::Sprite st(int i);
  sf::Sprite sm(int i, int j);
  sf::Text jvie();
  TileMap getMap();
  int je();
  int me(int i);
  bool isgameover();
  Joueur* getPlayer();
  int geth();
  int getl();
  int getlv(int i);
  int getMT(int i);
  ~World();

private:

	Joueur* j;
  List<Entite> m;
  int nbmonstre;
	TileMap map;
  int* level;
  int height;
  int length;
  bool gameover;
};

#endif
