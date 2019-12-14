#include "Monstre5.h"

Monstre5::Monstre5(int x, int y) : Entite() {

  if (!perso.loadFromFile("Sprites/Mobs/tank5.png")) {

    std::cout << "erreur" << std::endl;
  }

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect( 0, 0, 64, 64 ));
  sperso.setPosition(x, y);
  if (!canon.loadFromFile("Sprites/Mobs/canon5.png"))
    std::cout << "erreur" << std::endl;

  canon.setSmooth(true);
  scanon.setTexture(canon);
  scanon.setTextureRect(sf::IntRect(0, 0, 38, 48));
  scanon.setOrigin(19, 24);
  scanon.setPosition(x+32, y+32);
  pth=16;
  type=5;
}

void Monstre5::actions(Entite* j, int* map, int h, int l) {
  rotation( &scanon, j->getEntite().getPosition().x+32, j->getEntite().getPosition().y+32);

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
    res=pathExists(mp, (int)(sperso.getPosition().x+32)/64, (int)(j->getEntite().getPosition().x+32)/64,(int)(sperso.getPosition().y+32)/64, (int)(j->getEntite().getPosition().y+32)/64, l, h);
    pth=0;
    printf("res=%i\n", res);
  }
  for(int i=0; i<l; i++){
    delete[] mp[i];
  }
  delete[] mp;
  if (res==3) {

    sperso.move(0, -4);
    scanon.move(0, -4);
    sens = 0;
    animation( &sperso, &anim, sens );
  }
  if (res==4) {

    sperso.move(0, 4);
    scanon.move(0, 4);
    sens = 2;
    animation( &sperso, &anim, sens );
  }
  if (res==1) {

    sperso.move(-4, 0);
    scanon.move(-4, 0);
    sens = 3;
    animation( &sperso, &anim, sens );
  }
  if (res==2) {

    sperso.move(4, 0);
    scanon.move(4, 0);
    sens = 1;
    animation( &sperso, &anim, sens );
  }
  pth++;
  rotation( &scanon, j->getEntite().getPosition().x+32, j->getEntite().getPosition().y+32);
  if (clock->getElapsedTime().asMilliseconds()>=500) {
    //action de tir
    Tir1* pew = new Tir1(sperso.getPosition().x+32, sperso.getPosition().y+32, j->getEntite().getPosition().x+32, j->getEntite().getPosition().y+32);
    rotation( pew->getSTir(), j->getEntite().getPosition().x+32, j->getEntite().getPosition().y+32);
    tirs.ajouter(pew);
    clock->restart();
  }
  for( int i = 0; i < tirs.size() ; i++ ){

    tirs.get(i)->actions();

    if(tirs.get(i)->done())
      tirs.supprimer(i);
  }
}
