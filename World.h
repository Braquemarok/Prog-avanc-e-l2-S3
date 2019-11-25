#ifndef DEF_W
#define DEF_W

#include "Entites/Joueur/Joueur.h"
#include "Entites/Monstres/Monstre.h"
#include "Entites/Liste_entite.h"
#include "Sound.h"
#include "Map.h"
#include "Lecteur.h"

class World{
  
public:

  World();
  void handlevent(int clock);
  sf::Sprite sm(int i);
  int nbm();
  sf::Sprite sp();
  sf::Sprite st(int i);
  TileMap getMap();
  int je();
  bool isgameover();

private:

	Joueur j;
	Liste_entite m;
  int nbmonstre;
	TileMap map;
  Sound mus;
  int level[128];
  bool gameover;
};

#endif
