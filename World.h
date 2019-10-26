#include "Joueur.h"
#include "Monstre.h"
#include "Sound.h"
#include "Map.h"
#include "lecteur.cpp"

class World
{
public:
  World(){
    gameover=false;
    vector<int> lv=lecteur("Maps/lv1.txt");
    //const int taille=lv.at(0);
    int level[128];
    for(int i=0; i<5; i++){
  		m[i]= new Monstre(i*32,i*32);
  	}
    const int nbtile= lv.size();
    for(int i=0; i<nbtile; i++){
      level[i]=lv.at(i);
    }
  	if (!map.load("sprites/tileset.png", sf::Vector2u(32, 32), level, 16, 8)) {
  		std::cout << "erreur map" << std::endl;
  	}
  	mus.play();
  }
  void handlevent(){
    j.actions();
		for(int i=0; i<5; i++){
			m[i]->actions(j);
		}
    for(int i=0; i<5; i++){
			j.damage(m[i]->getsmonstre(), m[i]->getdegat());
      if(j.mort()){
        gameover=true;
      }
		}
    for(int i=0; i<5; i++){
      for(int x=0; x<j.gettaillet(); x++){
			     m[1]->damage(j.getstir(x), j.getdegat());
      }
      if(m[i]->mort()){
        w--;
      }
		}
  }
  sf::Sprite sm(int i){
    return m[i]->getsmonstre();
  }
  int nbm(){
    return w;
  }
  sf::Sprite sp(){
    return j.getsperso();
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
  int w=5;
	Monstre *m[5];
	TileMap map;
  Sound mus;
  bool gameover;
};
