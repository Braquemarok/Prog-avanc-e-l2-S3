#ifndef DEF_W
#define DEF_W

#include <string.h>
#include "Entites/Joueur/Joueur.h"
#include "Entites/Joueur/Vie.h"
#include "Entites/Monstres/Monstre.h"
#include "Sound.h"
#include "Map.h"
#include "Lecteur.h"

class World{

public:

  World(int num);
  World(string s);
  void handlevent(int x, int y);
  sf::Sprite sm(int i);
  int nbm();
  sf::Sprite sp();
  sf::Sprite st(int i);
  sf::Text jvie();
  TileMap getMap();
  int je();
  bool isgameover();
  Joueur* getPlayer();
  int geth();
  int getl();
  int getlv(int i);
  ~World();

private:

	Joueur* j;
  Vie* viej;
  List<Entite> m;
  int nbmonstre;
	TileMap map;
  int* level;
  int height;
  int length;
  bool gameover;
};

#endif
