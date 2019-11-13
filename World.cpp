#include "World.h"

World::World(){

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
  //mus.play();
}
void World::handlevent(int clock){
  j.actions(clock);
  for(unsigned int i=0; i<m.size(); i++){
    m[i]->actions(j, clock);
  }
  for(unsigned int i=0; i<m.size(); i++){
    j.damage(m[i]->getEntite(), m[i]->getdegat());
    if(j.mort()){
      gameover=true;
      //mus.stop();
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
sf::Sprite World::sm(int i){
  return m[i]->getEntite();
}
int World::nbm(){
  return m.size();
}
sf::Sprite World::sp(){
  return j.getEntite();
}
sf::Sprite World::st(int i){
  return j.getstir(i);
}
TileMap World::getMap(){
  return map;
}
int World::je(){
  return j.gettaillet();
}
bool World::isgameover(){
  return gameover;
}
