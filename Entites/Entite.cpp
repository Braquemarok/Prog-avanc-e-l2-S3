#include "Entite.h"

Entite::Entite() {

  anim = 0;
  alive = true;
  degats = 3;
  clock = new sf::Clock();
}

bool Entite::mort() const {

  return !alive;
}

int Entite::getdegat(){

  return degats;
}

//detection collision plus degat si vrai
void Entite::damage( Tir* m, int degats ){

  sf::FloatRect boundingBox = sperso.getGlobalBounds();
  sf::FloatRect otherBox = m->getSprite().getGlobalBounds();

  if (boundingBox.intersects(otherBox)){

    alive = false;
    m->setdead();
  }
}

void Entite::damage( sf::Sprite m, int degats ){

  sf::FloatRect boundingBox = sperso.getGlobalBounds();
  sf::FloatRect otherBox = m.getGlobalBounds();

  if (boundingBox.intersects(otherBox))
    alive = false;
}
void Entite::collision(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height){
  sf::RectangleShape rs;
  rs.setScale(32,32);

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if(tiles[i + j * width]<3){
        rs.setPosition(sf::Vector2f(i * tileSize.x, j * tileSize.y));
        //std::cout<<rs.getPosition().x<<std::endl;
        //std::cout<<rs.getPosition().y<<std::endl;
      }
      if (sperso.getGlobalBounds().contains(rs.getPosition().x, rs.getPosition().y) || sperso.getGlobalBounds().contains(rs.getPosition().x+tileSize.x, rs.getPosition().y+tileSize.y) || sperso.getGlobalBounds().contains(rs.getPosition().x+tileSize.x, rs.getPosition().y) || sperso.getGlobalBounds().contains(rs.getPosition().x, rs.getPosition().y+tileSize.y)){
        while(sperso.getGlobalBounds().contains(rs.getPosition().x, rs.getPosition().y) || sperso.getGlobalBounds().contains(rs.getPosition().x+tileSize.x, rs.getPosition().y+tileSize.y) || sperso.getGlobalBounds().contains(rs.getPosition().x+tileSize.x, rs.getPosition().y) || sperso.getGlobalBounds().contains(rs.getPosition().x, rs.getPosition().y+tileSize.y)){
          if(mur(sperso.getPosition().x,rs.getPosition().x)>mur(sperso.getPosition().y,rs.getPosition().y)){
            if(sperso.getPosition().x<=rs.getPosition().x){
              sperso.move(-0.1,0);
              scanon.move(-0.1,0);
            }
            else{
              sperso.move(0.1,0);
              scanon.move(0.1,0);
            }
          }
          else{
            if(sperso.getPosition().y<=rs.getPosition().y){
              sperso.move(0,-0.1);
              scanon.move(0,-0.1);
            }
            else{
              sperso.move(0,0.1);
              scanon.move(0,0.1);
            }
          }
        }//std::cout<<"MUR"<<std::endl;
      }
    }
  }
}
//action du joueur
 void Entite::actions(){

}
void Entite::actions( int z, int t){

}

 void Entite::actions(Entite* j){
  if (j->getEntite().getPosition().y < sperso.getPosition().y) {

    sperso.move(0, -3);
  }
  if (j->getEntite().getPosition().y > sperso.getPosition().y) {

    sperso.move(0, 3);
  }
  if (j->getEntite().getPosition().x < sperso.getPosition().x) {

    sperso.move(-3, 0);
  }
  if (j->getEntite().getPosition().x > sperso.getPosition().x) {

    sperso.move(3, 0);
  }
}

//getters
sf::Sprite Entite::getEntite(){

  return sperso;
}

sf::Sprite Entite::getCanon(){

  return scanon;
}

sf::Sprite Entite::getstir(int i){

  return tirs.get(i)->getSprite();
}

int Entite::gettaillet(){

  return tirs.size();
}

Tir* Entite::getTir(int i){

  return tirs.get(i);
}

int Entite::getAlive(){

  return alive;
}

Entite::~Entite(){

  delete clock;
}
