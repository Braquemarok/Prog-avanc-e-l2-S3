#include "Save.h"

void writer(World* world){
  ofstream file;
    file.open ("Save/save.txt");
    file << "nbmonstre = "+std::to_string(world->nbMobs())+"\n";
    for(int i=0; i<world->nbMobs(); i++){
      file << "monstre : x="+std::to_string((int)world->spriteMob(i).getPosition().x)+" y="+std::to_string((int)world->spriteMob(i).getPosition().y)+"\n";
    }
    file << "joueur : x="+std::to_string((int)world->spritePlayer().getPosition().x)+" y="+std::to_string((int)world->spritePlayer().getPosition().y)+"\n";
    file << "longueur = "+std::to_string(world->getl())+" hauteur = "+std::to_string(world->geth())+"\n";
    string s="lv ={";
    for(int i=0; i<world->geth()*world->getl(); i++){
      s+=std::to_string(world->getlv(i))+",";
    }
    s+="}";
    file<<s;
    file.close();
}
