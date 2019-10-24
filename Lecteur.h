#include <fstream>

class Lecteur
{
public:
  int* map(){
    ifstream fichier("fichier.txt");

     if(fichier)
     {
       while (is.get(c)){
          std::cout << c;
        }
     }
     else
     {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
     }
   }

private:

};
