#ifndef DEF_W
#define DEF_W

#include "Entites/Joueur/Joueur.h"
#include "Entites/Joueur/Vie.h"
#include "Entites/Monstres/Monstre.h"
#include "Entites/Liste_entite.h"
#include "Sound.h"
#include "Map.h"
#include "Lecteur.h"

class World{

public:

  World();
  void handlevent(int clock, int x, int y);
  sf::Sprite sm(int i);
  int nbm();
  sf::Sprite sp();
  sf::Sprite st(int i);
  sf::Text jvie();
  TileMap getMap();
  int je();
  bool isgameover();

private:

	Joueur* j;
  Vie* viej;
	Liste_entite m;
  int nbmonstre;
	TileMap map;
  int level[128];
  bool gameover;
};

#endif
