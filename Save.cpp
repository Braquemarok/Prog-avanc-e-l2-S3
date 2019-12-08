#include "Save.h"

void writer(World* world){
  ofstream file;
    file.open ("Save/save.txt");
    file << "nbmonstre = "+std::to_string(world->nbm())+"\n";
    for(int i=0; i<world->nbm(); i++){
      file << "monstre : x="+std::to_string((int)world->sm(i).getPosition().x)+" y="+std::to_string((int)world->sm(i).getPosition().y)+"\n";
    }
    file << "joueur : x="+std::to_string((int)world->sp().getPosition().x)+" y="+std::to_string((int)world->sp().getPosition().y)+"\n";
    int* copy= new int[world->getl()*world->geth()];
    copy=world->getlv();
    file << "longueur = "+std::to_string(world->getl())+" hauteur = "+std::to_string(world->geth())+"\n";
    string s="lv ={";
    for(int i=0; i<world->geth()*world->getl(); i++){
      s+=std::to_string(copy[i])+",";
    }
    s+="}";
    file<<s;
    file.close();
    delete[] copy;
}
