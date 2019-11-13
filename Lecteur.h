<<<<<<< HEAD
#ifndef DEF_L
#define DEF_L
=======
>>>>>>> v2

#include <fstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

<<<<<<< HEAD
vector<int> lecteur (string s);
#endif
=======
vector<int> lecteur (string s)
{
   ifstream fichier(s);
   vector<int> x;
   if(fichier)
   {
      string ligne;
      while(getline(fichier, ligne))
      {
        istringstream iss (ligne);
        string y=iss.str();
        for(int i=0; i<y.size(); i++){
           if((int)y.at(i)-'0'>=0 && (int)y.at(i)-'0'<=9){
             x.push_back((int)y.at(i)-'0');
           }
         }
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
   for(int i=0; i<x.size(); i++){
     printf("%i\n", x.at(i));
   }
   return x;
}
>>>>>>> v2
