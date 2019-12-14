#include "World.h"

using namespace std;

World::World(int num){

  vector<int> lv = lecteur("Maps/lv"+to_string(num)+".txt");
  j = new Joueur();
  //viej = new Vie();
  gameover = false;
  nbmonstre = lv[0];

  for( int i = 0 ; i < nbmonstre ; i++ ){
    if(lv[3+i*3]==1){
      m.ajouter(new Monstre(lv[1+i*3],lv[2+i*3]));
    }
    if(lv[3+i*3]==2){
      m.ajouter(new Monstre2(lv[1+i*3],lv[2+i*3]));
    }
    if(lv[3+i*3]==3){
      m.ajouter(new Monstre3(lv[1+i*3],lv[2+i*3]));
    }
    if(lv[3+i*3]==4){
      m.ajouter(new Monstre4(lv[1+i*3],lv[2+i*3]));
    }
    if(lv[3+i*3]==5){
      m.ajouter(new Monstre5(lv[1+i*3],lv[2+i*3]));
    }
    if(lv[3+i*3]==7){
      m.ajouter(new Monstre7(lv[1+i*3],lv[2+i*3]));
    }
  }

  const int nbtile = lv[1+nbmonstre*3]*lv[2+nbmonstre*3];
  length = lv[1+nbmonstre*3];
  height = lv[2+nbmonstre*3];
  level = new int[nbtile];
  for( int i = 0 ; i < nbtile ; i++ ){

    if(lv[i+3+nbmonstre*3]<0 || lv[i+3+nbmonstre*3]>16){
      throw string("ERREUR TILESET ERRONE");
    }

    level[i]=lv[i+3+nbmonstre*3];
  }

  if (!map.load("Sprites/Map/tileset.png", sf::Vector2u(64, 64), level, length, height))
    cout << "erreur map" << endl;

}

World::World(string s){
  vector<int> sav = lecteur(s);
  j = new Joueur(sav[1+nbmonstre*3], sav[2+nbmonstre*3]);
  gameover = false;
  nbmonstre = sav[0];

  for( int i = 0 ; i < nbmonstre ; i++ ){
    if(sav[3+i*3]==1){
      m.ajouter(new Monstre(sav[1+i*3],sav[2+i*3]));
    }
    if(sav[3+i*3]==2){
      m.ajouter(new Monstre2(sav[1+i*3],sav[2+i*3]));
    }
    if(sav[3+i*3]==3){
      m.ajouter(new Monstre3(sav[1+i*3],sav[2+i*3]));
    }
    if(sav[3+i*3]==4){
      m.ajouter(new Monstre4(sav[1+i*3],sav[2+i*3]));
    }
    if(sav[3+i*3]==5){
      m.ajouter(new Monstre5(sav[1+i*3],sav[2+i*3]));
    }
    if(sav[3+i*3]==7){
      m.ajouter(new Monstre7(sav[1+i*3],sav[2+i*3]));
    }
  }

  const int nbtile = sav[3+nbmonstre*3]*sav[4+nbmonstre*3];
  length = sav[3+nbmonstre*3];
  height = sav[4+nbmonstre*3];
  level = new int[nbtile];
  for( int i = 0 ; i < nbtile ; i++ ){
    if(sav[i+5+nbmonstre*3]<0 || sav[i+5+nbmonstre*3]>16){
      throw string("ERREUR TILESET ERRONE");
    }

    level[i]=sav[i+5+nbmonstre*3];
  }

  if (!map.load("Sprites/Map/tileset.png", sf::Vector2u(64, 64), level, length, height))
    cout << "erreur map" << endl;

}

void World::handlevent(int x, int y){


  j->actions(x, y);
  j->collision(sf::Vector2u(64, 64), level, length, height);

  for( int i = 0; i < m.size() ; i++ ){

    m.get(i)->actions(j, level, height, length);
    m.get(i)->collision(sf::Vector2u(64, 64), level, length, height);
    for(int j=i+1; j< m.size(); j++){
      m.get(i)->collision(m.get(j)->getEntite());
    }
  }

  for( int i = 0 ; i < m.size() ; i++ ){

    j->damage(m.get(i)->getEntite(), m.get(i)->getdegat());

    if( j->mort()){

      gameover = true;
    }
  }

  for( int i = 0 ; i < m.size() ; i++ ){
    for( int k = 0 ; k < j->gettaillet() ; k++ ){

      m.get(i)->damage(j->getTir(k), j->getdegat());
    }
    for(int k = 0; k < m.get(i)->gettaillet() ; k++){
      j->damage(m.get(i)->getTir(k), m.get(i)->getdegat());
      m.get(i)->getTir(k)->collision(sf::Vector2u(64, 64), level, length, height);
    }
    if(m.get(i)->mort())
      m.supprimer(i);
  }
  for(int x=0; x<j->gettaillet(); x++){
       j->getTir(x)->collision(sf::Vector2u(64, 64), level, length, height);
  }
}

sf::Sprite World::spriteMob(int i){

  return m.get(i)->getEntite();
}
sf::Sprite World::spriteMcanon(int i){

  return m.get(i)->getCanon();
}

int World::nbMobs(){

  return m.size();
}

sf::Sprite World::spritePlayer(){

  return j->getEntite();
}

sf::Sprite World::spritePcanon(){

  return j->getCanon();
}

sf::Sprite World::st(int i){

  return j->getstir(i);
}

sf::Sprite World::sm(int i, int j){

  return m.get(i)->getstir(j);
}

TileMap World::getMap(){

  return map;
}

int World::je(){

  return j->gettaillet();
}

int World::me(int i){

  return m.get(i)->gettaillet();
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
int World::getMT(int i){
  return m.get(i)->getType();
}
World::~World(){
  delete j;
  delete[] level;
}
