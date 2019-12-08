#include "World.h"

using namespace std;

World::World(int num){

  vector<int> lv = lecteur("Maps/lv"+to_string(num)+".txt");
  j = new Joueur();
  viej = new Vie();
  gameover = false;
  nbmonstre = lv[0];

  if(lv[0]<0 || lv[1]<=0 || lv[2]<=0){
    throw string("ERREUR NB MONSTRE INVALIDE");
  }

  for( int i = 0 ; i < nbmonstre ; i++ ){

    m.ajouter(new Monstre(lv[1+i],lv[2+i]));
  }

  const int nbtile = lv[1+nbmonstre*2]*lv[2+nbmonstre*2];
  length = lv[1+nbmonstre*2];
  height = lv[2+nbmonstre*2];
  level = new int[nbtile];
  for( int i = 0 ; i < nbtile ; i++ ){

    if(lv[i+3+nbmonstre*2]<0 || lv[i+3+nbmonstre*2]>16){
      throw string("ERREUR TILESET ERRONE");
    }

    level[i]=lv[i+3+nbmonstre*2];
  }

  if (!map.load("Sprites/Map/tileset.png", sf::Vector2u(64, 64), level, length, height))
    cout << "erreur map" << endl;

}

World::World(string s){
  vector<int> sav = lecteur(s);
  j = new Joueur(sav[1+nbmonstre*2], sav[2+nbmonstre*2]);
  viej = new Vie();
  gameover = false;
  nbmonstre = sav[0];

  for( int i = 0 ; i < nbmonstre ; i++ ){

    m.ajouter(new Monstre(sav[1+i],sav[2+i]));
  }

  const int nbtile = sav[3+nbmonstre*2]*sav[4+nbmonstre*2];
  length = sav[3+nbmonstre*2];
  height = sav[4+nbmonstre*2];
  level = new int[nbtile];
  for( int i = 0 ; i < nbtile ; i++ ){
    if(sav[i+5+nbmonstre*2]<0 || sav[i+5+nbmonstre*2]>16){
      throw string("ERREUR TILESET ERRONE");
    }

    level[i]=sav[i+5+nbmonstre*2];
  }

  if (!map.load("Sprites/Map/tileset.png", sf::Vector2u(64, 64), level, length, height))
    cout << "erreur map" << endl;

}

void World::handlevent(int x, int y){
  viej->handlevie(j->getvie());
  j->actions(x, y);
  j->collision(sf::Vector2u(64, 64), level, length, height);

  for( int i = 0; i < m.size() ; i++ ){

    m.get(i)->actions(j);
  }

  for( int i = 0 ; i < m.size() ; i++ ){

    j->damage(m.get(i)->getEntite(), m.get(i)->getdegat());

    if( j->mort()){

      gameover = true;
    }
  }

  for( int i = 0 ; i < m.size() ; i++ ){
    m.get(i)->collision(sf::Vector2u(64, 64), level, length, height);
    for( int k = 0 ; k < j->gettaillet() ; k++ ){

      m.get(i)->damage(j->getTir(k), j->getdegat());
    }

    if(m.get(i)->mort())
      m.supprimer(i);
  }
  for(int x=0; x<j->gettaillet(); x++){
       j->getTir(x)->collision(sf::Vector2u(64, 64), level, length, height);
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
sf::Text World::jvie(){

  return viej->getText();
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
Joueur* World::getPlayer(){
  return j;
}
int World::geth(){
  return height;
}
int World::getl(){
  return length;
}
int World::getlv(int i){
  return level[i];
}
World::~World(){
  delete j;
  delete viej;
  delete[] level;
}
