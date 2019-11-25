#include "World.h"

using namespace std;

World::World(){

  vector<int> lv = lecteur("Maps/lv1.txt");

  gameover = false;
  nbmonstre = lv[0];

  for( int i = 0 ; i < nbmonstre ; i++ ){

    m.ajouter(new Monstre(i*32,i*32));
  }

  const int nbtile = lv[1]*lv[2];

  for( int i = 0 ; i < nbtile ; i++ ){

    level[i]=lv[i+3];
  }

  if (!map.load("Sprites/texture.png", sf::Vector2u(64, 64), level, lv[1], lv[2]))
    cout << "erreur map" << endl;
  
  mus.play();
}

void World::handlevent (int clock ){

  j.actions(clock);

  for( int i = 0; i < m.size() ; i++ ){

    m.get(i)->actions(j, clock);
  }

  for( int i = 0 ; i < m.size() ; i++ ){

    j.damage(m.get(i)->getEntite(), m.get(i)->getdegat());
    
    if( j.mort()){

      gameover = true;
      mus.stop();
    }
  }

  for( int i = 0 ; i < m.size() ; i++ ){

    for( int k = 0 ; k < j.gettaillet() ; k++ ){

      m.get(i)->damage(j.getTir(k), j.getdegat());
    }

    if(m.get(i)->mort())
      m.supprimer(i);
  }
}

sf::Sprite World::sm(int i){

  return m.get(i)->getEntite();
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
