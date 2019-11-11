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
  World(){

    vector<int> lv = lecteur("Maps/lv1.txt");

    gameover=false;
    nbmonstre=lv[0];
    for(int i=0; i<nbmonstre; i++){
  		m.push_back(new Monstre(i*32,i*32));
  	}
    const int nbtile = lv[1]*lv[2];
    for(int i=0; i<nbtile ; i++){
      level[i]=lv[i+3];
    }
  	if (!map.load("sprites/tileset.png", sf::Vector2u(32, 32), level, lv[1], lv[2])) {
  		std::cout << "erreur map" << std::endl;
  	}
  	mus.play();
  }
  void handlevent(int clock){
    j.actions(clock);
		for(unsigned int i=0; i<m.size(); i++){
			m[i]->actions(j, clock);
		}
    for(unsigned int i=0; i<m.size(); i++){
			j.damage(m[i]->getEntite(), m[i]->getdegat());
      if(j.mort()){
        gameover=true;
      }
		}
    for(unsigned int i=0; i<m.size(); i++){
      for(int x=0; x<j.gettaillet(); x++){
			     m[i]->damage(j.getTir(x), j.getdegat());
      }
      if(m[i]->mort()){
        m.erase(m.begin()+i);
      }
		}
  }
  sf::Sprite sm(int i){
    return m[i]->getEntite();
  }
  int nbm(){
    return m.size();
  }
  sf::Sprite sp(){
    return j.getEntite();
  }
  sf::Sprite st(int i){
    return j.getstir(i);
  }
  TileMap getMap(){
    return map;
  }
  int je(){
    return j.gettaillet();
  }
  bool isgameover(){
    return gameover;
  }

private:
	Joueur j;
	vector<Entite*> m;
  int nbmonstre;
	TileMap map;
  Sound mus;
  int level[128];
  bool gameover;
};
