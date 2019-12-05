#include "Entite.h"

Entite::Entite() {

  vie = 2000;
  degats = 3;
}
Entite::Entite(int v) {

  vie = v;
  degats = 3;
}

bool Entite::mort() const {

  return vie <= 0;
}

int Entite::getdegat(){

  return degats;
}

//detection collision plus degat si vrai
void Entite::damage( Tir* m, int degats ){

  sf::FloatRect boundingBox = sperso.getGlobalBounds();
  sf::FloatRect otherBox = m->getSprite().getGlobalBounds();

  if (boundingBox.intersects(otherBox)){

    vie -= degats;
    m->setdead();
  }
}

void Entite::damage( sf::Sprite m, int degats ){

  sf::FloatRect boundingBox = sperso.getGlobalBounds();
  sf::FloatRect otherBox = m.getGlobalBounds();

  if (boundingBox.intersects(otherBox))
    vie -= degats;
}
void Entite::collision(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height){
  sf::RectangleShape rs;
  rs.setScale(32,32);

  for(int i=0; i<width; i++){
    for(int j=0; j<height; j++){
      if(tiles[i + j * width]>=3){
        rs.setPosition(sf::Vector2f(i * tileSize.x, j * tileSize.y));
        //std::cout<<rs.getPosition().x<<std::endl;
        //std::cout<<rs.getPosition().y<<std::endl;
      }
      if (sperso.getGlobalBounds().contains(rs.getPosition().x, rs.getPosition().y) || sperso.getGlobalBounds().contains(rs.getPosition().x+tileSize.x, rs.getPosition().y+tileSize.y) || sperso.getGlobalBounds().contains(rs.getPosition().x+tileSize.x, rs.getPosition().y) || sperso.getGlobalBounds().contains(rs.getPosition().x, rs.getPosition().y+tileSize.y)){
        while(sperso.getGlobalBounds().contains(rs.getPosition().x, rs.getPosition().y) || sperso.getGlobalBounds().contains(rs.getPosition().x+tileSize.x, rs.getPosition().y+tileSize.y) || sperso.getGlobalBounds().contains(rs.getPosition().x+tileSize.x, rs.getPosition().y) || sperso.getGlobalBounds().contains(rs.getPosition().x, rs.getPosition().y+tileSize.y)){
          if(mur(sperso.getPosition().x,rs.getPosition().x)>mur(sperso.getPosition().y,rs.getPosition().y)){
            if(sperso.getPosition().x<=rs.getPosition().x){
              sperso.move(-0.1,0);
            }
            else{
              sperso.move(0.1,0);
            }
          }
          else{
            if(sperso.getPosition().y<=rs.getPosition().y){
              sperso.move(0,-0.1);
            }
            else{
              sperso.move(0,0.1);
            }
          }
        }//std::cout<<"MUR"<<std::endl;
      }
    }
  }
}
//action du joueur
 void Entite::actions(int clock){

}
void Entite::actions(int clock, int z, int t){

}
//action monstre en fonction du joueur
 void Entite::actions(Entite* j, int clock){
  if (j->getEntite().getPosition().y < sperso.getPosition().y) {

    sperso.move(0, -3);
    sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if (j->getEntite().getPosition().y > sperso.getPosition().y) {

    sperso.move(0, 3);
    sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if (j->getEntite().getPosition().x < sperso.getPosition().x) {

    sperso.move(-3, 0);
    sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
  if (j->getEntite().getPosition().x > sperso.getPosition().x) {

    sperso.move(3, 0);
    sperso.setTextureRect(sf::IntRect(32 * x, y, 32, 32));
    animation(x);
  }
}

//getters
sf::Sprite Entite::getEntite(){

  return sperso;
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
int Entite::getvie(){
  return vie;
}
