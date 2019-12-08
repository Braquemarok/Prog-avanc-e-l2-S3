#include "Save.h"

void writer(Entite* e){
  ofstream file;
    file.open ("Save/save.txt");
    file << "Vie du joueur :"+std::to_string(e->getvie());
    file.close();
}
