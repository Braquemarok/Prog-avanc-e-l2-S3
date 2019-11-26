#include "World.h"

using namespace std;

World::World(){

  vector<int> lv = lecteur("Maps/lv1.txt");
  j = new Joueur();
  gameover = false;
  nbmonstre = lv[0];

  if(lv[0]<0 || lv[1]<=0 || lv[2]<=0){
    throw string("ERREUR NB MONSTRE INVALIDE");
  }

  for( int i = 0 ; i < nbmonstre ; i++ ){

    m.ajouter(new Monstre(i*32,i*32));
  }

  const int nbtile = lv[1]*lv[2];

  for( int i = 0 ; i < nbtile ; i++ ){

    if(lv[i+3]<0 || lv[i+3]>4){
      throw string("ERREUR TILESET ERRONE");
    }

    level[i]=lv[i+3];
  }

  if (!map.load("Sprites/texture.png", sf::Vector2u(64, 64), level, lv[1], lv[2]))
    cout << "erreur map" << endl;

}

void World::handlevent(int clock, int x, int y){

  j->actions(clock, x, y);
  j->collision(sf::Vector2u(64, 64), level, 16, 8);

  for( int i = 0; i < m.size() ; i++ ){

    m.get(i)->actions(j, clock);
  }

  for( int i = 0 ; i < m.size() ; i++ ){

    j->damage(m.get(i)->getEntite(), m.get(i)->getdegat());

    if( j->mort()){

      gameover = true;
    }
  }

  for( int i = 0 ; i < m.size() ; i++ ){
    m.get(i)->collision(sf::Vector2u(64, 64), level, 16, 8);
    for( int k = 0 ; k < j->gettaillet() ; k++ ){

      m.get(i)->damage(j->getTir(k), j->getdegat());
    }

    if(m.get(i)->mort())
      m.supprimer(i);
  }
  for(int x=0; x<j->gettaillet(); x++){
       j->getTir(x)->collision(sf::Vector2u(64, 64), level, 16, 8);
  }
}

sf::Sprite World::sm(int i){

  return m.get(i)->getEntite();
}

int World::nbm(){

  return m.size();
}

sf::Sprite World::sp(){

  return j->getEntite();
}

sf::Sprite World::st(int i){

  return j->getstir(i);
}

TileMap World::getMap(){

  return map;
}

int World::je(){

  return j->gettaillet();
}

bool World::isgameover(){

  return gameover;
}
