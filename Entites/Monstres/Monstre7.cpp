#include "Monstre7.h"

Monstre7::Monstre7(int x, int y) : Entite() {

  if (!perso.loadFromFile("Sprites/Mobs/tank7.png")) {

    std::cout << "erreur" << std::endl;
  }

  perso.setSmooth(true);
  sperso.setTexture(perso);
  sperso.setTextureRect(sf::IntRect( 0, 0, TSIZE, TSIZE ));
  sperso.setPosition(x, y);
  if (!canon.loadFromFile("Sprites/Mobs/canon7.png"))
    std::cout << "erreur" << std::endl;

  canon.setSmooth(true);
  scanon.setTexture(canon);
  scanon.setTextureRect(sf::IntRect(0, 0, 38, 48));
  scanon.setOrigin(19, 24);
  scanon.setPosition(x+TSIZE/2, y+TSIZE/2);
  pth=8;
  type=7;
}

void Monstre7::actions(Entite* j, int* map, int h, int l) {
  rotation( &scanon, j->getEntite().getPosition().x+TSIZE/2, j->getEntite().getPosition().y+TSIZE/2);

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
  if(pth>7){
    res=pathExists(mp, (int)(sperso.getPosition().x+TSIZE/2)/TSIZE, (int)(j->getEntite().getPosition().x+TSIZE/2)/TSIZE,(int)(sperso.getPosition().y+TSIZE/2)/TSIZE, (int)(j->getEntite().getPosition().y+TSIZE/2)/TSIZE, l, h);
    pth=0;
    //printf("res=%i\n", res);
  }
  for(int i=0; i<l; i++){
    delete[] mp[i];
  }
  delete[] mp;
  if (res==3) {

    sperso.move(0, -8);
    scanon.move(0, -8);
    sens = 0;
    animation( &sperso, &anim, sens );
  }
  if (res==4) {

    sperso.move(0, 8);
    scanon.move(0, 8);
    sens = 2;
    animation( &sperso, &anim, sens );
  }
  if (res==1) {

    sperso.move(-8, 0);
    scanon.move(-8, 0);
    sens = 3;
    animation( &sperso, &anim, sens );
  }
  if (res==2) {

    sperso.move(8, 0);
    scanon.move(8, 0);
    sens = 1;
    animation( &sperso, &anim, sens );
  }
  pth++;
  rotation( &scanon, j->getEntite().getPosition().x+TSIZE/2, j->getEntite().getPosition().y+TSIZE/2);
  if (clock->getElapsedTime().asMilliseconds()>=200) {
    //action de tir
    Tir2* pew = new Tir2(sperso.getPosition().x+TSIZE/2, sperso.getPosition().y+TSIZE/2, j->getEntite().getPosition().x+TSIZE/2, j->getEntite().getPosition().y+TSIZE/2);
    rotation( pew->getSTir(), j->getEntite().getPosition().x+TSIZE/2, j->getEntite().getPosition().y+TSIZE/2);
    tirs.ajouter(pew);
    clock->restart();
  }
  for( int i = 0; i < tirs.size() ; i++ ){

    tirs.get(i)->actions();

    if(tirs.get(i)->done())
      tirs.supprimer(i);
  }
}
