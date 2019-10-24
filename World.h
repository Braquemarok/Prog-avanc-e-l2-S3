#include "Joueur.h"
#include "Monstre.h"
#include "Sound.h"
#include "Map.h"

class World
{
public:
  World(){
    gameover=false;
    for(int i=0; i<5; i++){
  		m[i]= new Monstre(i*32,i*32);
  	}
    for(int i=0; i<900; i++){
      level[i]=0;
    }
  	if (!map.load("sprites/tileset.png", sf::Vector2u(32, 32), level, 30, 30)) {
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
  int level[900];
  bool gameover;
};
