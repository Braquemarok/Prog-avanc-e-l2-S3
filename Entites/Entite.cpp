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
void Entite::damage( Tir* m){

  sf::FloatRect boundingBox = sperso.getGlobalBounds();
  sf::FloatRect otherBox = m->getSprite().getGlobalBounds();

  if (boundingBox.intersects(otherBox)){

    alive = false;
    m->setdead();
  }
}

void Entite::damage( sf::Sprite m){

  sf::FloatRect boundingBox = sperso.getGlobalBounds();
  sf::FloatRect otherBox = m.getGlobalBounds();

  if (boundingBox.intersects(otherBox))
    alive = false;
}
void Entite::collision(const int* tiles, unsigned int width, unsigned int height){
  for(unsigned int i=0; i<width; i++){
    for(unsigned int j=0; j<height; j++){
      if(tiles[i + j * width]<3){
        sf::FloatRect* r = new sf::FloatRect(i*TSIZE,j*TSIZE,TSIZE,TSIZE);
        if (r->intersects(sperso.getGlobalBounds())){
          while(r->intersects(sperso.getGlobalBounds())){
            if(mur(sperso.getPosition().x,i*TSIZE)>mur(sperso.getPosition().y,j*TSIZE)){
              if(sperso.getPosition().x<=i*TSIZE){
                sperso.move(-0.1,0);
                scanon.move(-0.1,0);
              }
              else{
                sperso.move(0.1,0);
                scanon.move(0.1,0);
              }
            }
            else{
              if(sperso.getPosition().y<=j*TSIZE){
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
        delete r;
      }
    }
  }
}
void Entite::collision( sf::Sprite m){
  if (sperso.getGlobalBounds().intersects(m.getGlobalBounds())){
    while(sperso.getGlobalBounds().intersects(m.getGlobalBounds())){
      if(mur(sperso.getPosition().x,m.getPosition().x)>mur(sperso.getPosition().y,m.getPosition().y)){
        if(sperso.getPosition().x<=m.getPosition().x){
          sperso.move(-0.1,0);
          scanon.move(-0.1,0);
        }
        else{
          sperso.move(0.1,0);
          scanon.move(0.1,0);
        }
      }
      else{
        if(sperso.getPosition().y<=m.getPosition().y){
          sperso.move(0,-0.1);
          scanon.move(0,-0.1);
        }
        else{
          sperso.move(0,0.1);
          scanon.move(0,0.1);
        }
      }
    }
  }
}
//action du joueur
 void Entite::actions(){

}
void Entite::actions( int z, int t){
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

    sperso.move(5, 0);
    scanon.move(5, 0);
    sens = 1;
    animation( &sperso, &anim, sens );
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {

    sperso.move(-5, 0);
    scanon.move(-5, 0);
    sens = 3;
    animation( &sperso, &anim, sens );
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {

    sperso.move(0, -5);
    scanon.move(0, -5);
    sens = 0;
    animation( &sperso, &anim, sens );
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

    sperso.move(0, 5);
    scanon.move(0, 5);
    sens = 2;
    animation( &sperso, &anim, sens );
  }

  rotation( &scanon, z, t );

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock->getElapsedTime().asMilliseconds()>=500) {
    //action de tir
    Tir1* pew = new Tir1(sperso.getPosition().x+TSIZE/2, sperso.getPosition().y+TSIZE/2, z,t);
    rotation( pew->getSTir(), z, t );
    tirs.ajouter(pew);
    clock->restart();
  }

  if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && clock->getElapsedTime().asMilliseconds()>=700) {
    //action de tir
    Tir2* pew = new Tir2(sperso.getPosition().x+TSIZE/2, sperso.getPosition().y+TSIZE/2, z,t);
    rotation( pew->getSTir(), z, t );
    tirs.ajouter(pew);
    clock->restart();
  }

  for( int i = 0; i < tirs.size() ; i++ ){

    tirs.get(i)->actions();

    if(tirs.get(i)->done())
      tirs.supprimer(i);
  }
}

 void Entite::actions(Entite* j,int* map, int h, int l){
   int** mp;
   mp=new int* [l];
   for(int i=0; i<l; i++){
     mp[i]=new int[h];
   }
   for(int i=0; i<l; i++){
     for(int j=0; j<h; j++){
       mp[i][j]= map[i+j*l];
     }
   }
   if(pth>15){
     res=pathExists(mp, (int)(sperso.getPosition().x+TSIZE/2)/TSIZE, (int)(j->getEntite().getPosition().x+TSIZE/2)/TSIZE,(int)(sperso.getPosition().y+TSIZE/2)/TSIZE, (int)(j->getEntite().getPosition().y+TSIZE/2)/TSIZE, l, h);
     pth=0;
     //printf("res=%i\n", res);
   }
   for(int i=0; i<l; i++){
     delete[] mp[i];
   }
   delete[] mp;
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
int Entite::getType(){

  return type;
}

Entite::~Entite(){

  delete clock;
}
