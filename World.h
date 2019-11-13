#ifndef DEF_W
#define DEF_W

#include "entite/Joueur/Joueur.h"
#include "entite/Monstres/Monstre.h"
#include "Sound.h"
#include "Map.h"
#include "Lecteur.h"
/* les noms des fonctions semblant assez explixites,
il ne parait donc pas necessaire de les detailler plus
qu'elles ne le sont deja*/
class World
{
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
	vector<Entite*> m;
  int nbmonstre;
	TileMap map;
  //Sound mus;
  int level[128];
  bool gameover;
};

#endif
